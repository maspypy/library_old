#pragma once
template <typename mint>
vector<mint> convolution(vector<mint>& A, vector<mint>& B) {
  vector<mint> C(len(A) + len(B) - 1);
  FOR(i, len(A)) FOR(j, len(B)) C[i + j] += A[i] * B[j];
  return C;
}
