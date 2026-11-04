# Internal review summary (public)

These were internal AI-assisted checks on 4 November 2026, not human peer review. They comprised five reviewer roles (editor, methodology/proof, domain/prior art, devil's advocate with a reader's-perspective section, and re-review), an adversarial review and audit by a second model (Codex, gpt-6-astra), and a clean replay of all shipped code.

## Correctness
No reviewer found a gap in the main proof or in the 2-matroid extension. The checks covered:
- the marked-downset lemma, including the Katona parameters 1 <= t <= r;
- the boundary identity;
- closure under conditioning;
- the Kahn–Neiman hypotheses (no internal zeros in the rank sequence; positivity on every set is not needed);
- zero weights and empty or full families;
- every case of the six-element lemma.

Independent tests used exact rationals. Adversarial weight hill-climbing ran on about 29,000 random families with up to 9 elements; every labelled graph on up to 6 vertices was tested unweighted. None found a failure. The closest case, K4 with extreme weights, came within about 1.5% of equality and still holds exactly.

## Objections and how they were resolved
| Objection | Resolution |
|---|---|
| The Kahn–Neiman criterion carries the whole weighted theorem but was only paraphrased | Theorem 1 is now quoted, the APP/CAPP and CAPU definitions are given, and each hypothesis is checked in the proof. |
| Hard to read for non-specialists | Added a reader's guide, a roadmap, a worked example (two disjoint edges) and a key-terms list. |
| The abstract undersold the result and repeated itself | Rewritten: it now says the paper proves Conjecture 4.1, with the status kept separate. |
| No discussion of the Lorentzian/Mason literature | Added a related-work section, citing Anari–Liu–Oveis Gharan–Vinzant, Brändén–Huh and Liggett, and noncover-complex terminology (Kim–Kim). It explains why the M-convex-support route fails here. |
| Horrocks (2002) had been credited from its abstract only (v0.1.0) | Version 0.2.0: read in full and compared theorem by theorem. It proves ordinary log-concavity with a +p_k term, not ULC. Its pair-partition reduction to doubly dependent counts is credited as a precursor (supplement/horrocks_2002_comparison.md). |
| Proof details: the ground-set size in the marked lemma, the Katona pointer, the union bound in the rank-four case, the Maclaurin step | Each now made explicit. |
| verify.py used `assert`, so `python -O` passed vacuously | All checks are now explicit conditionals. A mutation test confirms that a wrong value fails under -O. |

## Added in revision
- A remark that ULC holds with n replaced by the number of positive-weight elements, which is a stronger statement.

## Open
- Xie–Xu Conjecture 4.4 for 2-matroids of rank 5 or more. The next step, an eight-element antipodal inequality, meets an explicit obstruction to the present method.
- Comparison with the proof technique of Horrocks (2002).
