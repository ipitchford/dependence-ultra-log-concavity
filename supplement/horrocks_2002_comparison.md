# Comparison with Horrocks (2002)

Source read in full (all six pages, 180-185): D. G. C. Horrocks, "The Numbers of Dependent k-Sets in a Graph Are Log Concave", J. Combin. Theory Ser. B 84 (2002) 180-185, doi:10.1006/jctb.2001.2077. Compared on 4 November 2026.

## What Horrocks proves

- **Theorem 2.5.** For every simple graph G, p_k(G)^2 >= p_{k-1}(G) p_{k+1}(G) + p_k(G), where p_k counts dependent k-vertex sets. This is ordinary log-concavity with an additive +p_k term. It is unweighted and has no binomial normalisation.
- **Lemma 2.1** (the core). Pairs (X, Y) are partitioned by A = X∩Y and B = X∪Y, following Hamidoune's (1990) technique. Within each class, the (k-1, k+1) pairs are at most the (k, k) pairs. Case 1: A dependent, so the comparison is binomial unimodality. Case 2: A independent and N(A) ∩ B empty. Then the count is doubly dependent sets of G[B\A] at the two middle ranks. It uses Lemma 2.2 = Horrocks (2000): d_m >= d_{m-1} on 2m vertices. Case 2 with N(A) nonempty reduces to independent-set counts of H = G[(B\A)\N(A)].
- **Lemma 2.3.** For a graph on at most 2n-1 vertices, 2a_n - a_{n-1} - a_{n+1} <= C(2n,n)/(n+1). The proof uses Lemma 2.4 (Horrocks 1999 / Zha 1989: max p_k at the middle on 2r+1 vertices) and a join with K_r.

## What Horrocks does not prove

- **Not ULC.** He does not prove k(n-k)A_k^2 >= (k+1)(n-k+1)A_{k-1}A_{k+1} (Xie-Xu Conjecture 4.1), weighted or unweighted. His +p_k slack is far smaller than ULC needs. Example: one edge on n=10 vertices, so p_k = C(8,k-2), at k=5. Horrocks's bound gives 3136 >= 2016. ULC needs 3136 >= 2822.4. The additive slack 56 does not cover the required 862, so his bound cannot imply the ULC inequality.
- **No weights.** He has no weights, no loops or singleton witnesses as a hypothesis, and no 2-matroid or triple-witness results.
- **No normalised two-colouring theorem.** He uses only the raw middle-rank comparison d_m >= d_{m-1} (from H00). He does not show that b_k/C(n,k) is symmetric and unimodal, nor that k b_k >= (n-k+1) b_{k-1} survives every conditioning.
- **No downset lemma, double count or Kahn-Neiman step.** He has no marked-downset or Katona-shadow lemma, no critical-element count, and no Kahn-Neiman criterion. Kahn-Neiman 2011 postdates his paper.

## Method overlap (credited in v0.2.0)

The architectures are genuinely parallel.

1. Both arguments condition on the pair (X∩Y, X∪Y).
2. Both reduce the rank comparison to a two-colouring (doubly dependent) count on the free part B\A.
3. In that reduction, the elements adjacent to A act as singleton witnesses. This is the "graphs with loops" closure.

In this paper, Kahn-Neiman's antipodal-pairs criterion plays the role of Horrocks's partition. The new ingredient is the binomially normalised two-colouring inequality for all conditionings, which Horrocks's unnormalised H00 input cannot supply. Version 0.2.0 credits Horrocks (and Hamidoune) with this pair-partition reduction to doubly dependent counts. It states that the binomial factor is what this paper adds.

## Verdict

Horrocks does not prove the main theorem (ULC) or the normalised two-colouring theorem, and no lemma of his anticipates them. Horrocks 2000 (AJC 22, open access) was already read in v0.1. No further load-bearing source is paywalled. Version 0.2.0 records this comparison; no theorem, proof or computation changed.
