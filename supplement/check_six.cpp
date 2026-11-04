// Exact six-element antipodal-pairs check for 2-matroids of rank at most four.
//
// Build: c++ -O2 -std=c++17 check_six.cpp -o check_six
// Run:   ./check_six
//
// All arithmetic is integer arithmetic. The reduction proving why this finite
// enumeration is sufficient is in rank_four_reduction.md. No external graph or
// simplicial-complex catalogue is used.
//
// A subset of {0,...,5} is represented by a six-bit integer. Families of pairs,
// triples and four-sets use 15, 20 and 15 bits respectively. The four-set with
// index j is deliberately the complement of the pair with index j. Therefore
// popcount(four_family & pair_family) counts antipodal feasible pair/four-set
// incidences without a separate permutation of bit positions.

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {

constexpr unsigned kFullSet = (1u << 6) - 1;
constexpr unsigned kPairCount = 15;
constexpr unsigned kTripleCount = 20;
constexpr unsigned kPairFamilyCount = 1u << kPairCount;
constexpr unsigned kTripleFamilyCount = 1u << kTripleCount;
constexpr unsigned kAllTriples = kTripleFamilyCount - 1;

int population_count(unsigned mask) {
    return __builtin_popcount(mask);
}

}  // namespace

int main() {
    std::vector<unsigned> pairs;
    std::vector<unsigned> triples;
    for (unsigned subset = 0; subset <= kFullSet; ++subset) {
        if (population_count(subset) == 2) {
            pairs.push_back(subset);
        }
        if (population_count(subset) == 3) {
            triples.push_back(subset);
        }
    }

    std::array<int, 64> pair_index;
    std::array<int, 64> triple_index;
    pair_index.fill(-1);
    triple_index.fill(-1);
    for (unsigned i = 0; i < kPairCount; ++i) {
        pair_index[pairs[i]] = static_cast<int>(i);
    }
    for (unsigned i = 0; i < kTripleCount; ++i) {
        triple_index[triples[i]] = static_cast<int>(i);
    }

    // four_shadow[j] is the triple shadow of the jth four-set Q_j.
    // extensions[p][j] comprises all triples S_p + v with v in Q_j \ S_p.
    // A feasible pair S_p can coexist with Q_j only if the selected triple
    // family contains at least one such extension (the gap-two augmentation).
    std::array<unsigned, kPairCount> four_shadow{};
    std::array<std::array<unsigned, kPairCount>, kPairCount> extensions{};
    for (unsigned j = 0; j < kPairCount; ++j) {
        const unsigned four_set = kFullSet ^ pairs[j];
        for (unsigned i = 0; i < kTripleCount; ++i) {
            if ((triples[i] & four_set) == triples[i]) {
                four_shadow[j] |= 1u << i;
            }
        }
        for (unsigned p = 0; p < kPairCount; ++p) {
            for (unsigned vertex = 0; vertex < 6; ++vertex) {
                const unsigned vertex_bit = 1u << vertex;
                if ((four_set & vertex_bit) && !(pairs[p] & vertex_bit)) {
                    const unsigned triple = pairs[p] | vertex_bit;
                    extensions[p][j] |= 1u << triple_index[triple];
                }
            }
        }
    }

    // For each pair family P, record precisely those triples that satisfy:
    // (i) all their pairs lie in P (heredity), and
    // (ii) every singleton outside the triple has an extension into that
    //      triple using a pair in P (singleton/triple augmentation).
    std::vector<unsigned> valid_triples(kPairFamilyCount, 0);
    for (unsigned pair_family = 0; pair_family < kPairFamilyCount;
         ++pair_family) {
        for (unsigned i = 0; i < kTripleCount; ++i) {
            bool valid = true;
            for (unsigned p = 0; p < kPairCount; ++p) {
                if ((pairs[p] & triples[i]) == pairs[p] &&
                    !(pair_family & (1u << p))) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                continue;
            }

            for (unsigned vertex = 0; vertex < 6; ++vertex) {
                const unsigned vertex_bit = 1u << vertex;
                if (triples[i] & vertex_bit) {
                    continue;
                }
                bool has_extension = false;
                for (unsigned other = 0; other < 6; ++other) {
                    const unsigned other_bit = 1u << other;
                    if (triples[i] & other_bit) {
                        const int p = pair_index[vertex_bit | other_bit];
                        if (pair_family & (1u << p)) {
                            has_extension = true;
                        }
                    }
                }
                if (!has_extension) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                valid_triples[pair_family] |= 1u << i;
            }
        }
    }

    // bad_four_sets[T][p] records the four-sets that would violate pair/four
    // augmentation for pair p when T is the selected triple family. Thus p
    // belongs to P_max(T,Q) exactly when Q has empty intersection with this
    // mask. antipodal_triples[T] is |F_3|, counting both complementary triples.
    std::vector<std::array<std::uint16_t, kPairCount>> bad_four_sets(
        kTripleFamilyCount);
    std::vector<int> antipodal_triples(kTripleFamilyCount, 0);
    for (unsigned triple_family = 0; triple_family < kTripleFamilyCount;
         ++triple_family) {
        for (unsigned p = 0; p < kPairCount; ++p) {
            std::uint16_t bad = 0;
            for (unsigned j = 0; j < kPairCount; ++j) {
                if (!(triple_family & extensions[p][j])) {
                    bad |= 1u << j;
                }
            }
            bad_four_sets[triple_family][p] = bad;
        }
        for (unsigned i = 0; i < kTripleCount; ++i) {
            const int complement = triple_index[kFullSet ^ triples[i]];
            if ((triple_family & (1u << i)) &&
                (triple_family & (1u << complement))) {
                ++antipodal_triples[triple_family];
            }
        }
    }

    std::uint64_t completions_checked = 0;
    std::uint64_t valid_completions = 0;
    int minimum_margin = 999;

    // The empty four-family has |F_2| = 0, making the target inequality
    // automatic. For each nonempty Q, enumerate every T containing its triple
    // shadow. This enumerates the remaining subsets of the 20 triples exactly
    // once, by the standard submask recurrence.
    for (unsigned four_family = 1; four_family < kPairFamilyCount;
         ++four_family) {
        unsigned required_triples = 0;
        for (unsigned j = 0; j < kPairCount; ++j) {
            if (four_family & (1u << j)) {
                required_triples |= four_shadow[j];
            }
        }
        const unsigned optional_triples = kAllTriples ^ required_triples;
        unsigned chosen_optional = optional_triples;

        while (true) {
            const unsigned triple_family = required_triples | chosen_optional;
            ++completions_checked;

            // Every feasible pair family is contained in P_max. Replacing it
            // by P_max preserves validity and can only increase |F_2| while
            // leaving |F_3| unchanged. Hence this is the adverse completion.
            unsigned maximal_pair_family = 0;
            for (unsigned p = 0; p < kPairCount; ++p) {
                if (!(four_family & bad_four_sets[triple_family][p])) {
                    maximal_pair_family |= 1u << p;
                }
            }

            if (!(triple_family & ~valid_triples[maximal_pair_family])) {
                ++valid_completions;
                const int f2 = population_count(four_family & maximal_pair_family);
                const int f3 = antipodal_triples[triple_family];
                const int margin = 3 * f3 - 4 * f2;
                minimum_margin = std::min(minimum_margin, margin);
                if (margin < 0) {
                    std::cout << "COUNTER " << four_family << ' '
                              << triple_family << ' ' << maximal_pair_family
                              << ' ' << f3 << ' ' << f2 << ' ' << margin << '\n';
                    return 1;
                }
            }

            if (chosen_optional == 0) {
                break;
            }
            chosen_optional = (chosen_optional - 1) & optional_triples;
        }
    }

    std::cout << "checked=" << completions_checked
              << " valid=" << valid_completions
              << " minmargin=" << minimum_margin << '\n';
    return 0;
}
