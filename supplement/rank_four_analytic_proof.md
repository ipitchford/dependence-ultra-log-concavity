# Analytic six-point antipodal-pairs lemma for additive 2-matroids

Prepared 2 November 2026. Analytic replacement for the six-element exhaustive certificate, checked in two further internal proof audits. These are internal checks, not external peer review. The exhaustive certificate is retained as corroboration. This note imports the graph antipodal-pairs theorem already proved in the main manuscript; it does not import or infer the general 2-matroid conjecture.

## Conventions and target

An additive 2-matroid here means a nonempty downset \(\mathcal I\subseteq 2^V\) satisfying

\[
S,T\in\mathcal I,\quad |T|\ge |S|+2
\quad\Longrightarrow\quad
S\cup\{x\}\in\mathcal I\text{ for some }x\in T\setminus S.
\]

Assume \(|V|=6\). Define

\[
F_j=\{S\in\mathcal I:|S|=j,\ V\setminus S\in\mathcal I\}.
\]

Let \(r=|F_2|\). Let \(m\) be the number of **unordered** partitions \(V=A\mathbin{\dot\cup}B\), with \(|A|=|B|=3\), for which both parts are feasible. Thus \(|F_3|=2m\): each such partition contributes both of its triple parts to \(F_3\). The desired antipodal-pairs inequality is

\[
3|F_3|\ge4|F_2|,
\quad\text{equivalently}\quad
3m\ge2r. \tag{1}
\]

No rank bound is needed for the six-point lemma itself. Only the feasible pairs, triples and four-sets enter the proof.

## An auxiliary graph

Define a simple graph \(R\) on \(V\) by

\[
E(R)=F_2.
\]

In particular, for every edge \(e\in E(R)\), both \(e\) and its complementary four-set \(V\setminus e\) are feasible. The graph has exactly \(r\) edges. The case \(r=0\) is immediate, so suppose \(r>0\).

Call a balanced unordered partition an **edge-on-both-sides partition** if each of its two triple parts contains an edge of \(R\). Let \(g\) be the number of these partitions. Every such partition is feasible: if \(e\subseteq A\) and \(f\subseteq B\) are edges of \(R\), then

\[
A\subseteq V\setminus f\in\mathcal I,
\qquad B\subseteq V\setminus e\in\mathcal I,
\]

so downward closure gives \(A,B\in\mathcal I\). Hence \(m\ge g\).

### Case I: no edge of \(R\) is a vertex cover

For the ordinary graph \(R\), let

\[
b_j(R)=\#\{S\subseteq V:|S|=j,\ R[S]\text{ and }R[V\setminus S]
\text{ both contain an edge}\}.
\]

An edge is a vertex cover precisely when its complementary four-set contains no edge. Under the present assumption, every edge of \(R\) has an edge in its complement. Therefore

\[
b_2(R)=r,\qquad b_3(R)=2g.
\]

The established graph antipodal-pairs theorem from the main manuscript, applied on six vertices at the middle rank, gives

\[
3b_3(R)\ge4b_2(R).
\]

Thus \(6g\ge4r\), so \(3m\ge3g\ge2r\), proving (1) in this case. This uses exactly the main theorem's unweighted normalised two-colouring inequality, not any assertion about 2-matroid rank sequences.

### Case II: an edge of \(R\) is a vertex cover

Choose such an edge \(ab\). Let \(L=V\setminus\{a,b\}\), so \(|L|=4\). Since \(ab\) covers all edges, \(L\) is independent in \(R\). Put

\[
A=N_R(a)\cap L,\quad B=N_R(b)\cap L,
\quad p=|A|,\quad q=|B|.
\]

Swap \(a,b\) if necessary so that \(0\le q\le p\le4\). Every edge of \(R\) is either \(ab\), an edge from \(a\) to \(A\), or an edge from \(b\) to \(B\). Therefore

\[
r=1+p+q. \tag{2}
\]

There is always at least one additional feasible balanced partition with \(a,b\) in the same triple. Indeed, \(ab\in\mathcal I\) and \(L\in\mathcal I\), so 2-augmentation supplies \(x\in L\) with \(\{a,b,x\}\in\mathcal I\). Its complement \(L\setminus\{x\}\) is feasible by downward closure. Because that complement lies in the independent set \(L\) of \(R\), this partition is not counted by \(g\). Consequently

\[
m\ge g+1. \tag{3}
\]

If \(q=0\), \(R\) is a star together with isolated vertices; this is handled below. Suppose now \(q\ge1\).

Every edge-on-both-sides partition must separate \(a\) and \(b\). The six such balanced partitions are parametrised uniquely by the two-element set \(X\subseteq L\) placed with \(a\); the other triple is \(\{b\}\cup(L\setminus X)\). It is counted by \(g\) precisely when

\[
X\cap A\ne\varnothing,
\qquad (L\setminus X)\cap B\ne\varnothing.
\]

The number failing the first condition is \(\binom{4-p}{2}\), and the number failing the second is \(\binom{4-q}{2}\). A union bound therefore gives

\[
g\ge 6-\binom{4-p}{2}-\binom{4-q}{2}. \tag{4}
\]

If \(p=q=1\) and \(A\ne B\), the two distinct marked leaves must be placed on their respective centre's side. Exactly two choices for the other leaf placed with \(a\) remain, so \(g=2\). If \(p=q=1\) and \(A=B\), the graph is a triangle together with three isolated vertices, treated below.

All remaining possibilities with \(q\ge1\) are the following finite list. The last column verifies (1) using (2) and (3). The bounds for \(g\) are (4), apart from the explicitly counted first row.

| \(p\) | \(q\) | Additional condition | Lower bound \(g_0\) for \(g\) | \(3(g_0+1)-2(1+p+q)\) |
|---:|---:|:---|---:|---:|
| 1 | 1 | \(A\ne B\) | 2 | 3 |
| 2 | 1 | any overlap | 2 | 1 |
| 3 | 1 | any overlap | 3 | 2 |
| 4 | 1 | any overlap | 3 | 0 |
| 2 | 2 | any overlap | 4 | 5 |
| 3 | 2 | any overlap | 5 | 6 |
| 4 | 2 | any overlap | 5 | 4 |
| 3 | 3 | any overlap | 6 | 7 |
| 4 | 3 | any overlap | 6 | 5 |
| 4 | 4 | any overlap | 6 | 3 |

For completeness, the table exhausts all integer pairs \(1\le q\le p\le4\), except the triangle case just isolated. The only graph configurations outside this table are therefore stars and a triangle with isolated vertices.

## Exceptional star case

Suppose \(R\) is a star with centre \(a\), nonempty leaf set \(U\), and possible isolated vertices. Write \(d=|U|=r\), and let \(W=V\setminus\{a\}\), so \(|W|=5\).

Define an auxiliary graph \(J\) on \(W\): a pair \(ux\) is an edge of \(J\) exactly when the triple \(\{a,u,x\}\) is feasible. For every \(u\in U\), its degree in \(J\) is positive. To see this, apply 2-augmentation to the feasible pair \(\{a,u\}\) and its feasible complementary four-set.

Moreover, if \(u\in U\) has degree one in \(J\), its unique neighbour lies outside \(U\). Indeed, for each \(v\in U\), the set \(V\setminus\{a,v\}\) is a feasible four-set. Applying 2-augmentation to \(\{a,u\}\) and that four-set supplies an extension \(x\notin\{u,v\}\). Thus the neighbours of \(u\) cannot be contained in \(\{v\}\) for any \(v\in U\).

Each vertex \(u\in U\) now distributes a total charge of one equally among its incident edges of \(J\). An edge whose two ends lie in \(U\) receives at most one, because both endpoints then have degree at least two. An edge with exactly one endpoint in \(U\) receives at most one; an edge with neither endpoint in \(U\) receives zero. Consequently

\[
\#\{e\in E(J):e\cap U\ne\varnothing\}\ge |U|=d. \tag{5}
\]

Every edge \(ux\) counted in (5) gives a feasible balanced partition: choose \(u\in U\), so \(\{a,u,x\}\) is feasible by the definition of \(J\), and its complement is a three-subset of the feasible four-set \(V\setminus\{a,u\}\). Distinct edges give distinct unordered partitions, because the triple containing \(a\) identifies the pair \(ux\) uniquely. Hence

\[
m\ge d=r,
\]

which is stronger than (1).

## Exceptional triangle case

Suppose \(R\) is a triangle on \(a,b,c\), with three isolated vertices \(L\). For each edge, say \(ab\), apply 2-augmentation to the feasible pair \(ab\) and the feasible four-set \(V\setminus ac=\{b\}\cup L\). The extension must be an element \(x\in L\), so \(abx\) is feasible. Its complementary triple is a subset of the feasible four-set \(V\setminus ab\), and is therefore feasible too.

The three triangle edges yield three distinct unordered balanced partitions: in each resulting partition, the part with two triangle vertices identifies the original triangle edge uniquely. Therefore \(m\ge3=r\), again proving (1).

## Weighted consequences

Every additive 2-matroid on six elements satisfies the middle antipodal-pairs inequality. Together with the existing analytic two- and four-element arguments and closure under deletion and contraction, this proves the conditional antipodal-pairs property for additive 2-matroids of rank at most four. For any larger even conditional ground set of size \(2k\ge8\), a feasible complementary \((k-1)\)-set and \((k+1)\)-set cannot occur when the rank is at most four, so the right side of APP is zero.

Positive product weights cancel in antipodal products. Kahn–Neiman's criterion and interval rank support therefore give the weighted ultra-log-concavity conclusion of the original reduction, now with an analytic proof throughout. Nonnegative weights follow by continuity.

The independent exhaustive certificate remains useful as a corroborating check and should be retained as such. This argument does not prove the eight-element APP inequality or the unrestricted 2-matroid conjecture. Its no-edge-cover case makes an essential, explicit use of the graph theorem established in the main manuscript.

### All systems on at most seven elements

Every additive 2-matroid on at most seven ground elements has CAPP. Indeed, every positive-probability coordinate restriction is a deletion followed by contraction by a feasible fixed set, so it remains an additive 2-matroid. Every even-sized remaining ground set has size at most six. The two-, four- and six-point APP lemmas therefore cover all conditionings required by CAPP, regardless of rank.

Consequently its product-weight rank sequence is ultra-log-concave of ambient order \(n\), for arbitrary nonnegative element weights.

### The first five coefficients in arbitrary rank

Let \(\mathcal I\) be any additive 2-matroid on \(n\) ground elements. Its rank-four truncation

\[
\mathcal I^{\le4}=\{S\in\mathcal I:|S|\le4\}
\]

is a 2-matroid on the **same** ground set. In fact, if \(S,T\in\mathcal I^{\le4}\) and \(|T|\ge|S|+2\), an augmentation in the original system has size \(|S|+1\le|T|-1\le3\), and therefore remains in the truncation.

For nonnegative element weights, put

\[
A_j=\sum_{\substack{S\in\mathcal I\\|S|=j}}\prod_{v\in S}w_v.
\]

The truncated system has exactly the same coefficients \(A_0,\ldots,A_{\min(4,n)}\). Its rank is at most four, so the result just proved gives

\[
k(n-k)A_k^2\ge(k+1)(n-k+1)A_{k-1}A_{k+1}
\qquad(1\le k\le\min(3,n-1)).
\]

Equivalently, the first \(\min(5,n+1)\) entries of the original binomially normalised sequence are log-concave. The normalisation is \(\binom nj\), using the original ambient cardinality; it is not replaced by \(\binom4j\). This corollary uses rank truncation and the rank-four theorem, with no additional external theorem.
