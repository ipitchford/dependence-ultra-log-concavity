# Independent proof note: conditional antipodal unimodality for graph dependence

Prepared 2 November 2026. This is a mathematical proof audit and extension, not an external peer-review certificate or historical-priority claim.

## Statement

Let `V` be an `n`-element set. Let `E` be a family of two-element subsets of `V`, and let `L` be a set of marked vertices, interpreted as singleton witnesses (or loops). Define

\[
 f(S)=\mathbf1\{S\cap L\ne\varnothing\ \text{or}\ \exists e\in E:e\subseteq S\},\qquad S\subseteq V.
\]

Call `S` dependent if `f(S)=1`, and independent otherwise. Thus an independent set contains no looped vertex and no edge.

Put

\[
 b_j=\#\{S\subseteq V:|S|=j,\ f(S)=f(V\setminus S)=1\}.
\]

**Theorem A.** The sequence `b_j / binom(n,j)` is symmetric and nondecreasing for `0 <= j <= floor(n/2)`, hence unimodal.

For arbitrary positive vertex weights `w_v`, put

\[
 Z=\sum_{S\subseteq V}f(S)\prod_{v\in S}w_v,
 \qquad
 \mu(S)=Z^{-1}f(S)\prod_{v\in S}w_v.
\]

When `Z>0`, this measure is conditionally antipodal pairs unimodal (CAPU), in the terminology of Kahn and Neiman. It therefore has the conditional antipodal pairs property (CAPP), and its rank sequence is ultra-log-concave. Explicitly, if

\[
 d_j(w)=\sum_{\substack{|S|=j\\f(S)=1}}\prod_{v\in S}w_v,
\]

then

\[
 \left(\frac{d_j(w)}{\binom nj}\right)^2
 \ge
 \frac{d_{j-1}(w)}{\binom n{j-1}}
 \frac{d_{j+1}(w)}{\binom n{j+1}}
 \qquad (1\le j\le n-1).
\]

The same non-strict inequalities extend to nonnegative weights by continuity. With no loops and all weights one, this is the graph dependence-polynomial conjecture.

## Two shadow facts

For a family `F` of `r`-subsets of an `N`-set, its shadow at level `l <= r` is

\[
 \partial_l\mathcal F=\{B:|B|=l,\ B\subseteq A\text{ for some }A\in\mathcal F\}.
\]

**Ordinary shadow bound.** Double counting pairs `(B,A)` with `B subset A`, `|B|=l`, gives

\[
 |\partial_l\mathcal F|\ge
 \frac{\binom Nl}{\binom Nr}|\mathcal F|.
\]

Indeed each `A` contributes `binom(r,l)` pairs, while each `B` belongs to at most `binom(N-l,r-l)` members. In particular, if `l<=r` and `l+r>=N`, then `binom(N,l)>=binom(N,r)`, so `|partial_l F|>=|F|`. The binomial comparison follows because `N-r<=l<=r` and binomial coefficients increase towards the middle and are symmetric.

**Katona's intersecting-shadow theorem, needed endpoint.** If `F` is a `t`-intersecting family of `r`-sets, with `1<=t<=r`, then

\[
 |\partial_{r-t}\mathcal F|\ge|\mathcal F|.
\]

This is the endpoint `l=r-t` of Katona's more precise factor

\[
 |\partial_l\mathcal F|\ge
 \frac{\binom{2r-t}{l}}{\binom{2r-t}{r}}|\mathcal F|,
 \qquad r-t\le l\le r.
\]

At the endpoint the ratio is one. The `t=r` case is elementary: a nonempty `r`-intersecting family of `r`-sets has one member and its zero-shadow has one member.

## First-hit lemma

The following abstract form, identified independently by the combinatorics proof audit, avoids graph-specific cases.

Let `J` be a downset of subsets of an `m`-element set `W`, and assume

\[
 I\cup J\ne W\qquad\text{for all }I,J\in\mathcal J.
\]

For a marked set `A subset W`, let

\[
 \beta_j=\#\{I\in\mathcal J:|I|=j,\ I\cap A\ne\varnothing\}.
\]

**Lemma B (marked reflection).** If `0<=a<=b` and `a+b=m`, then `beta_a>=beta_b`.

**Proof.** The cases `A` empty or `a=b` are immediate. If `a=0`, the empty set misses `A` and the full set cannot belong to `J`, so both counts vanish. We may assume `1<=a<b`.

Order the marks `A={u_1,...,u_h}` and partition sets by their first mark. In class `i`, write a set as `{u_i} union K`, where

\[
 R_i=W\setminus\{u_1,\ldots,u_i\},\qquad
 \mathcal D_i=\{K\subseteq R_i:\{u_i\}\cup K\in\mathcal J\}.
\]

Each `D_i` is a downset. Its upper and lower levels to compare are

\[
 r=b-1,\qquad l=a-1,\qquad r+l=m-2.
\]

For `i>=2`, the ambient size `|R_i|=m-i<=m-2=r+l`. The ordinary shadow bound gives `|D_{i,l}|>=|D_{i,r}|`. If the upper level is empty this is immediate; otherwise the levels are within the ambient range and the binomial comparison applies.

For `i=1`, the residual downset `D_1` retains the property that no two members have union `R_1`: otherwise their unions with `{u_1}` would violate the hypothesis on `J`. Its upper layer `F=D_{1,r}` is consequently `t`-intersecting for

\[
 t=2r-|R_1|+1=2(b-1)-(m-1)+1=b-a\ge1.
\]

Indeed two upper-layer members have union of size at most `|R_1|-1`. As `r-t=a-1=l>=0`, Katona's theorem gives `|partial_l F|>=|F|`; the downset property puts this shadow inside `D_{1,l}`. Summing over the disjoint first-hit classes proves the lemma. QED.

For any downset, without a no-union or marked-set hypothesis, the unmarked reflected-layer bound

\[
 |\mathcal J\cap\tbinom Wa|\ge|\mathcal J\cap\tbinom Wb|
 \quad(a\le b,\ a+b=m)
\]

follows directly from the ordinary shadow bound, since the two binomial coefficients agree.

**Application to graphs with loops.** On `W=V(H)`, let

\[
 \mathcal J(H)=\{I\subseteq W:I\text{ is independent in }H,
 \ W\setminus I\text{ is dependent in }H\}.
\]

This is a downset: decreasing `I` preserves its independence and enlarges its dependent complement. No two members have union `W`: if `I union J=W`, then `W\I subset J` would be independent, contrary to the defining property of `I`.

Taking `m=n-1`, `a=k-1`, `b=n-k`, Lemma B gives, for any marked set `A`,

\[
 \#\{I\in\mathcal J(H):|I|=k-1,\ I\cap A\ne\varnothing\}
 \ge
 \#\{I\in\mathcal J(H):|I|=n-k,\ I\cap A\ne\varnothing\},
\]

for every `1<=k<=floor(n/2)`. The unmarked reflected-layer inequality holds as well.

## Critical-vertex identity and proof of Theorem A

For a dependent set `T`, define

\[
 c(T)=\#\{v\in T:f(T\setminus\{v\})=0\}.
\]

These are vertices whose removal destroys every dependence witness in `T`. Let

\[
 \mathcal B_j=\{S\subseteq V:|S|=j,\ f(S)=f(V\setminus S)=1\},
 \qquad b_j=|\mathcal B_j|.
\]

Count inclusion pairs `(S,T)` with `S in B_{k-1}`, `T in B_k`, and `S subset T`. A set `T in B_k` has exactly `k-c(T)` such predecessors, since the complement remains dependent after adding a vertex. A set `S in B_{k-1}` has exactly `n-k+1-c(V\S)` such successors. Therefore

\[
 k b_k-(n-k+1)b_{k-1}
 =\sum_{T\in\mathcal B_k}c(T)
  -\sum_{S\in\mathcal B_{k-1}}c(V\setminus S). \tag{1}
\]

We compare the two sums separately for each critical vertex `v`. Let `H` be the graph with loops induced on `W=V\{v}`.

On the first sum, removing `v` leaves an independent set `I` of size `k-1` such that `W\I` is dependent and adding `v` makes `I` dependent. On the second sum the same conditions hold for an independent set `I` of size `n-k`.

If `v` is looped, the condition concerning adding `v` is automatic, and the unmarked version of Lemma B compares the counts. If `v` is not looped, adding `v` creates a witness precisely when `I` hits `A=N_G(v)\setminus L_H`; any looped neighbour is already forbidden from `I`. The marked version of Lemma B compares these counts. Thus every individual vertex contributes a nonnegative amount to the right side of (1).

It follows that

\[
 k b_k\ge(n-k+1)b_{k-1}
 \quad\Longleftrightarrow\quad
 \frac{b_k}{\binom nk}\ge\frac{b_{k-1}}{\binom n{k-1}}
 \qquad(1\le k\le\lfloor n/2\rfloor).
\]

The complement map gives `b_j=b_{n-j}`, completing the proof. For `n=0,1` the asserted symmetry/unimodality is immediate. The preceding proof handles `n=2,3` through the explicit `k=1` boundary case of Lemma B. If there are no witnesses, all `b_j` are zero. QED.

## External fields, conditioning and ultra-log-concavity

For positive weights and `Z>0`, Kahn–Neiman's antipodal quantities are

\[
 \alpha_j(\mu)=\binom nj^{-1}
 \sum_{|S|=j}\mu(S)\mu(V\setminus S)
 =\frac{\prod_{v\in V}w_v}{Z^2}\frac{b_j}{\binom nj}.
\]

The factor in front is independent of `j`, so Theorem A gives APU for every external field.

Now condition on a set `P` of coordinates being present and a disjoint set `Q` being absent. The free ground set is `R=V\(P union Q)`. If `P` already contains a witness, the conditioned law is a product measure on `R`; its antipodal sequence is constant. Otherwise `P` is independent. A free set `S subset R` completes a witness precisely when it contains an original loop, an endpoint of an edge from `P` to `R`, or an original edge lying inside `R`. Thus the conditioned law, after discarding its fixed weight factor, has exactly the same graph-plus-loops form with the inherited positive weights. Restrictions of zero mass are not conditioning events and need not be considered.

Every positive-probability restriction is therefore APU: the original measure is CAPU and hence CAPP.

The support of a nonzero graph-plus-loops measure is an upset generated by witnesses of size one or two. If the smallest witness has size `r`, then the rank support is precisely `{r,r+1,...,n}`; all weights are positive, so there are no internal rank zeros. Kahn–Neiman Theorem 1 (CAPP plus no internal rank zeros implies ULC), or their Corollary 12 for CAPU, gives the asserted rank inequalities. A conditioned law already satisfied by `P` instead has all ranks in its support.

Finally each rank coefficient is a polynomial in the weights. Taking limits from strictly positive weights proves the inequalities for nonnegative weights, including when the total weighted polynomial becomes zero. This limiting statement concerns coefficient inequalities; a zero total mass does not define a probability measure.

## Scope limits

The proof establishes CAPU for conditioning and positive external fields. It does not establish preservation under marginalisation, the Rayleigh property, negative association, real-rootedness, stability, or Lorentzian structure. Those stronger properties cannot be silently inferred from CAPU.

The proof uses witness size at most two at exactly one point: after removing a critical nonlooped vertex, creating a witness becomes the condition of hitting a set of individual neighbours. Higher-order witnesses instead require hitting a family of larger subsets; the first-hit proof above does not cover that situation.

## Exact boundary at witness size three

These examples delimit the theorem. They are not being presented as resolutions of separately documented open problems.

### An unweighted example with witnesses of sizes one and three

On five vertices, declare a set successful when it contains a distinguished vertex `v`, or contains at least three of the other four vertices. The minimal witnesses are `{v}` and the four triples of `V\{v}`. The rank sequence is

\[
 (d_0,\ldots,d_5)=(0,1,4,10,5,1),
 \qquad
 (d_j/\tbinom5j)=(0,1/5,2/5,1,1,1).
\]

At rank two, `(2/5)^2=4/25<1/5`; equivalently, the integer form of ULC would require `96>=120`.

### A weighted four-vertex example

The event consisting of a distinguished singleton or the complementary triple, with weights `(1,2,2,2)`, has coefficients

\[
 (0,1,6,20,8).
\]

The rank-two ULC inequality would require `4*6^2>=9*1*20`, but `144<180`.

### A weighted matching of two three-element witnesses

The uniform-hypergraph extension fails even for two disjoint triples. On six vertices take witnesses

\[
 \{1,2,3\},\qquad\{4,5,6\}
\]

and weights `(1,M,M,3,3,3)`, where `M>0`. Inclusion–exclusion gives

\[
 D_M(x)=M^2x^3(1+3x)^3
       +27x^3(1+x)(1+Mx)^2
       -27M^2x^6.
\]

Thus

\[
 (d_3,d_4,d_5,d_6)
 =(M^2+27,\ 9M^2+54M+27,\ 54M^2+54M,\ 27M^2).
\]

The only potentially failing ULC inequality is the one at rank four. Its exact defect is

\[
 \begin{aligned}
 8d_4^2-15d_3d_5
 &=162\bigl(-M^4+43M^3+33M^2+9M+36\bigr).
 \end{aligned}
\]

For positive integer `M`, this is negative **exactly when `M>=44`**. For `1<=M<=43`, write the first two terms as `M^3(43-M)`; all terms are nonnegative and at least one is positive. For `M>=44`,

\[
 M^3(M-43)\ge M^3\ge44M^2>33M^2+9M+36,
\]

where the last strict inequality follows from `11M^2-9M-36>0` for `M>=44`.

For positive real `M`, there is exactly one positive zero of this quartic: Descartes' sign rule gives at most one, its values at 43 and 44 have opposite signs, and its leading coefficient is negative. The ULC threshold is this unique root, lying strictly between 43 and 44.

At `M=44`, the rank coefficients are

\[
 (0,0,0,1963,19827,106920,52272),
\]

and the violated inequality is the exact integer comparison

\[
 8(19827)^2=3\,144\,879\,432
 <3\,148\,259\,400=15(1963)(106920).
\]

The rank-five defect is always positive:

\[
 5d_5^2-12d_4d_6
 =2916M^2(4M^2+4M+2)>0,
\]

and all remaining ULC inequalities are immediate from the leading zeros. Thus the stated threshold describes the whole sequence, not only one isolated failed check. As `M` tends to infinity, the ratio of the two sides at rank four tends to `4/5`, so the failure does not rely on a vanishing numerical margin.

### Six vertices are minimal for weighted three-uniform hypergraphs

For `n<=4`, a nonzero dependence polynomial of a three-uniform hypergraph has at most two consecutive nonzero coefficients, so all ULC inequalities are automatic. Consider `n=5`, with strictly positive vertex weights, and let `W` be their product. Replace each three-element hyperedge by its two-element complement, obtaining a graph `K` on the same five vertices. Put `y_v=1/w_v`, and let `U` be the set of nonisolated vertices of `K`. For a nonempty hypergraph, the reversed dependence polynomial is

\[
 x^5D(1/x)
 =W\left(1+a_1x+a_2x^2\right),
 \quad a_1=\sum_{v\in U}y_v,
 \quad a_2=\sum_{uv\in E(K)}y_uy_v.
\]

This follows directly: a four-set is dependent exactly when its missing vertex belongs to a complementary edge; a three-set is dependent exactly when its complementary pair is an edge of `K`.

Let `p=|U|<=5`. By adding missing edges and then using Cauchy–Schwarz,

\[
 a_2\le\sum_{\{u,v\}\subseteq U}y_uy_v
 =\frac12\left(a_1^2-\sum_{v\in U}y_v^2\right)
 \le\frac{p-1}{2p}a_1^2
 \le\frac25a_1^2.
\]

Therefore `a_1^2>=(5/2)a_2`, exactly the only nontrivial ULC inequality at order five. Empty hypergraphs give the zero polynomial; nonnegative weights follow by continuity. Hence no weighted three-uniform counterexample can have fewer than six vertices, and the disjoint-triples construction attains this minimum.

### Bounded prior-art search for the boundary examples

On 2 November 2026, web searches used the exact query families `"weighted" "dependence polynomial" "ultra"`, `"weighted" "hypergraph" "dependent" "log-concavity"`, `"hypergraph" "dependence polynomial" "log-concave"`, `"dependent sets" "weights" "ultra-log-concave"`, and `"disjoint triples" "log-concavity"`. No matching prior statement or example was located. This negative evidence is bounded and does not establish priority. The examples should be described as explicit limitations proved in this work, without a separate historical-first claim.

## Inspected sources

- Kahn, J., & Neiman, M. (2009 preprint; published 2011). *A strong log-concavity property for measures on Boolean algebras*. Theorem 1, definitions in Section 1, and CAPU/Corollary 12 in Section 4. https://arxiv.org/pdf/0907.0243
- Frankl, P. (2016). Linear independence, a unifying approach to shadow theorems. *European Journal of Combinatorics, 57*, 36–39. https://doi.org/10.1016/j.ejc.2016.04.001 . Page 1 of the inspected author manuscript gives the full Katona intersecting-shadow inequality, including the endpoint used here: https://www.renyi.hu/~pfrankl/2016-3.pdf . Volume and pages were verified against the publisher record and https://real.mtak.hu/44215/ .
- Liu, X., & Mubayi, D. (2020 preprint; published 2021). *Tight bounds for Katona's shadow intersection theorem*. Theorem 1.2 restates the classical theorem. https://homepages.math.uic.edu/~mubayi/papers/tight_katona_intersection.pdf
- Xie, Y.-T., & Xu, S.-J. (2026 revision of 2024 preprint). *Ultra log-concavity and real-rootedness of dependence polynomials*. https://arxiv.org/html/2408.09152v2

The graph conjecture and its weighted strengthening require a separate prior-art audit; none of the above source checks by itself establishes historical novelty.
