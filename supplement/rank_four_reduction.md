# Additional result: weighted ultra log-concavity for 2-matroids of rank at most four

Date: 2 November 2026. This note is separate from the main graph theorem. Both the rank-three and rank-four results now have analytic proofs. The two- and four-element reductions are given below; the six-element analytic proof is in `rank_four_analytic_proof.md` and imports the main manuscript's graph antipodal-pairs theorem. The complete exact enumeration on six labelled elements is retained as independent corroboration, not as a proof dependency. No historical-priority claim or proof-assistant formalisation is asserted.

## Definitions and reduction to antipodal pairs

An independence system is a nonempty downset I on a finite ground set V. Its rank is the largest cardinality of a member. In Xie and Xu's terminology it is a 2-matroid if, whenever S,T are feasible and |T| >= |S|+2, some x in T minus S makes S union {x} feasible.

Deletion and contraction preserve this axiom. For contraction by a feasible fixed set P, apply the original axiom to P union S and P union T; their cardinality difference is unchanged. Conditioning some elements to be absent is deletion. A zero-mass conditioning event need not be considered. Rank does not increase under these operations.

On a 2k-element ground set put

F_j = {S in I : |S|=j and V minus S in I}.

The antipodal-pairs inequality is

k |F_k| >= (k+1) |F_(k-1)|.

For the product-weight measure proportional to 1_(S in I) product_(v in S) w_v, complementary products of weights equal product_(v in V) w_v. Thus the antipodal-pairs inequality is independent of positive element weights. If every deletion/contraction has the inequality, the Kahn–Neiman conditional-antipodal-pairs criterion gives ultra log-concavity of the weighted rank sequence. A downset has interval rank support. Nonnegative weights follow by continuity.

If rank(I) <= r, the right-hand side is zero whenever k+1>r. Consequently rank at most three needs only two- and four-point inequalities; rank at most four needs only two-, four- and six-point inequalities. The two-point inequality is automatic for every downset.

## Analytic four-point lemma

Suppose |V|=4. If F_1 is nonempty, then all four singletons are feasible: a feasible singleton and its feasible complementary triple cover V. Let t be the number of feasible triples, so |F_1|=t. Feasible pairs form a graph.

If t=1, apply 2-augmentation to the singleton outside the feasible triple and that triple. The outside vertex has a feasible pair with some vertex of the triple; the remaining pair lies inside the triple and is feasible. These two complementary pairs give |F_2|>=2>=3t/2.

If t=2, the shadows of the two distinct triples contain all edges of K4 except at most one. There are at least two perfect matchings, giving |F_2|>=4>=3t/2. If t>=3, all six pairs are feasible, so |F_2|=6>=3t/2. If F_1 is empty, the inequality is immediate.

This proves CAPP, and hence the weighted rank inequality, for every 2-matroid of rank at most three.

## Analytic six-point lemma and retained exhaustive cross-check

The accompanying analytic proof establishes the middle antipodal-pairs inequality for every additive 2-matroid on six elements, without a rank bound. It uses the graph whose edges are the feasible pairs with feasible four-element complements. If no edge of this graph is a vertex cover, the main graph APU theorem applies directly. Otherwise a covering edge reduces the graph to two stars with a common central edge; a small explicit table and analytic star and triangle arguments complete the proof. The proof has been independently audited within this collaboration. It is not external peer review.

This lemma completes the rank-at-most-four CAPP reduction above analytically. The remaining subsection preserves the original exhaustive argument, which provides a separately implemented finite cross-check of the same six-point inequality for rank-at-most-four systems.

### Exhaustive reduction

Let |V|=6 and rank(I)<=4. Only the inequality

3 |F_3| >= 4 |F_2|

is nontrivial. If F_2 is nonempty, all six singletons are feasible, by downward closure of a complementary feasible 2-set/4-set pair. If no 4-set is feasible, F_2 is empty.

It therefore suffices to consider systems containing all singletons, with a nonempty chosen family Q of feasible 4-sets. There are 15 possible 4-sets and 20 possible 3-sets.

Fix Q. Its 3-shadow must belong to the feasible triple family T; any of the remaining triples can be included or omitted. For each such T, define the largest allowed feasible-pair family P_max by

S in P_max iff, for every Q in Q, there is x in Q minus S such that S union {x} belongs to T.

Every actual feasible pair S must be in P_max, by the 2-augmentation axiom applied to S and each feasible 4-set. Conversely, increasing a feasible-pair family up to P_max does not spoil the pair-versus-4-set augmentation requirement. It can only help singleton-versus-triple augmentation. It leaves F_3 unchanged and can only increase F_2. Thus, for a worst-case test of the inequality at fixed Q,T, it is enough to use P_max.

This maximal completion is a downset and a 2-matroid exactly when:

1. Every pair in every triple T belongs to P_max (downward closure).
2. For every vertex v outside a chosen triple T, at least one pair {v,u}, u in T, belongs to P_max (singleton-versus-triple augmentation).

All other augmentation instances reduce to these or to the defining pair-versus-4-set condition. Indeed, if |T|>|S|+2, choose a feasible subset T' of T of size |S|+2. The cases with S empty hold because all singletons are feasible. There are no feasible sets of size greater than four.

For a valid completion,

|F_2| = number of chosen 4-sets whose complementary pair belongs to P_max,

|F_3| = number of chosen triples whose complementary triple is also chosen.

The program `check_six.cpp` enumerates all 2^15-1 nonempty Q and all triple supersets of their mandatory shadows. It derives P_max, tests exactly the two conditions above, and evaluates the integer margin 3|F_3|-4|F_2|. It uses no floating-point computation, random sampling, optimisation oracle or external graph catalogue.

### Exhaustive output

Compiled with `c++ -O2 -std=c++17 -Wall -Wextra -pedantic check_six.cpp -o check_six` and run as `./check_six`. The compiler produced no warnings. The accompanying `rank_four_results.json` records the checked counts, source checksum and exact command.

```
checked=2653437 valid=1723681 minmargin=0
```

The program exits with status 1 and prints a full bit-mask witness if it finds any negative margin. The completed run exited with status 0. There were 2,653,437 four-set/triple-family combinations, 1,723,681 valid maximal-edge completions, and no violation. The minimum margin was zero.

The SHA-256 checksum of the formatted certificate source is `7de3eab7c82525a3125ab581f8a490982873892b8100b1fa0d6bc98416917a59`. The descriptive-name and comment revision preserved the enumeration and reproduced the original output. The implementation uses the GCC/Clang `__builtin_popcount` integer intrinsic; it otherwise uses the C++17 standard library.

This exhaustive result agrees with the new analytic proof. The weighted rank inequality for 2-matroids of rank at most four no longer depends on executing or trusting this enumeration. Neither argument establishes Conjecture 4.4 for unrestricted rank.

## Sources and status

- Xie, Y.-T., & Xu, S.-J. (2026 revision). Ultra log-concavity and real-rootedness of dependence polynomials. The Electronic Journal of Combinatorics, 33(4), P4.9. Conjecture 4.4 and the definition preceding it. https://arxiv.org/html/2408.09152v2 and https://doi.org/10.37236/13310
- Kahn, J., & Neiman, M. (2011). A strong log-concavity property for measures on Boolean algebras. Journal of Combinatorial Theory, Series A, 118(6), 1749–1760. https://arxiv.org/pdf/0907.0243 and https://doi.org/10.1016/j.jcta.2011.02.007

A bounded search on 2 November 2026 for `2-matroid rank three`, `2-matroid rank 3`, `hereditary independence gap rank three`, and `dominating triangles log-concavity` found no matching rank-three or rank-four statement. This is a limited novelty screen, not an exhaustive priority audit. Li's September 2026 counterexamples concern augmentation parameter three and the older rank-dependent conjecture, not this parameter-two result.
