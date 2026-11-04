# A precise obstruction to the next hypergraph step

Prepared 2 November 2026. This example concerns the proof mechanism, not the validity of the general additive 2-matroid conjecture. It has not been presented as a separately documented open-problem resolution or a historical-priority claim.

## The hypergraph

Partition an eight-element ground set as

\[
V=E\mathbin{\dot\cup}\{v\}\mathbin{\dot\cup}A,
\qquad |E|=3,\quad |A|=4.
\]

Take the three-uniform hypergraph

\[
\mathcal H=\{E\}\cup
\bigl\{\{v\}\cup P:P\in\tbinom A2\bigr\}.
\]

There are seven hyperedges. Each has a disjoint hyperedge: the edge \(E\) is disjoint from each of the other six. In particular, no hyperedge is a vertex cover of \(\mathcal H\).

Let a set be dependent when it contains a hyperedge, and let

\[
b_j=\#\{S\subseteq V:|S|=j,\ S\text{ and }V\setminus S
\text{ are both dependent}\}.
\]

Every hyperedge has a dependent complement, so \(b_3=7\). In a successful balanced partition, one side must contain \(E\): the other six hyperedges all contain \(v\), and so cannot appear on opposite sides. The side containing \(E\) is \(E\cup\{x\}\). If \(x=v\), the other side is \(A\), which is independent. If \(x\in A\), the other side is \(\{v\}\cup(A\setminus\{x\})\), which contains a hyperedge. Thus there are exactly four unordered successful balanced partitions, giving \(b_4=8\).

Consequently the middle antipodal-pairs inequality fails:

\[
4b_4=32<35=5b_3.
\]

Equivalently, \(b_4/\binom84=8/70<7/56=b_3/\binom83\). This failure persists despite the absence of a hyperedge vertex cover.

## Why this is not a 2-matroid counterexample

The natural complementary downset

\[
\mathcal I=\{S\subseteq V:S\subseteq V\setminus h
\text{ for some }h\in\mathcal H\}
\]

has the same antipodal counts, but it fails additive 2-augmentation. Its maximal five-sets are \(\{v\}\cup A\) and the six sets \(E\cup P\), \(P\in\binom A2\). Choose \(e\in E\) and distinct \(a_1,a_2\in A\). Then

\[
S=\{e,a_1,a_2\},\qquad T=\{v\}\cup A
\]

are feasible, with \(|T|=|S|+2\). Adding \(v\) to \(S\) creates a set containing both \(v\) and an element of \(E\), which lies in no maximal set. Adding either of the remaining elements of \(A\) creates a set with an element of \(E\) and three elements of \(A\), again lying in no maximal set. No permitted augmentation exists.

## Interpretation and verification

For a 2-matroid on eight elements, the analogous auxiliary object has as its hyperedges the feasible triples with feasible complementary five-sets. The six-element proof would need to control balanced four-set partitions. The example above shows that the graph antipodal-pairs theorem cannot simply be replaced by an assertion for arbitrary three-uniform hypergraphs, even in the case where every hyperedge has a disjoint hyperedge. Further 2-matroid augmentation constraints would have to force additional balanced feasible sets. The existing argument supplies no such mechanism.

An independent exact enumeration of all 256 subsets verified

\[
(b_0,\ldots,b_8)=(0,0,0,7,8,7,0,0,0),
\]

the absence of a hyperedge vertex cover, the identical antipodal counts of the complementary downset, and the explicit augmentation failure above. No floating-point computation was used. This identifies the point at which the present analytic continuation stops; it does not settle the unrestricted rank-five or general 2-matroid problem.
