#include "polynomial/convolution.hpp"
template<typename mint>
vc<mint> convolution_huge(vc<mint>& A, vc<mint>& B) {
  int N = len(A), M = len(B);
  if (N + M - 1 <= (1 << 23)) return convolution(A, B);
  ll L = 22;
  vv(mint, C, 4, 2 << L);
  vv(mint, D, 4, 2 << L);
  int mask = (1 << L) - 1;
  FOR(i, N) C[i >> L][i & mask] = A[i];
  FOR(i, M) D[i >> L][i & mask] = B[i];
  FOR(i, 4) ntt(C[i], false);
  FOR(i, 4) ntt(D[i], false);
  vv(mint, E, 7, 2 << L);
  FOR(i, 4) FOR(j, 4) FOR(k, 2 << L) E[i + j][k] += C[i][k] * D[j][k];
  FOR(i, 7) ntt(E[i], true);
  vc<mint> ANS(8 << L);
  FOR(i, 7) FOR(k, 2 << L) ANS[(i << L) + k] += E[i][k];
  ANS.resize(N + M - 1);
  mint c = mint(1) / mint(2 << L);
  FOR(i, len(ANS)) ANS[i] *= c;
  return ANS;
}
