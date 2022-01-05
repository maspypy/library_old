#include "setfunc/hadamard.hpp"
template <typename T>
vc<T> xor_convolution(vc<T> A, vc<T> B) {
  hadamard(A);
  hadamard(B);
  FOR(i, len(A)) A[i] *= B[i];
  hadamard(A);
  T c = T(1) / T(len(A));
  FOR(i, len(A)) A[i] *= c;
  return A;
}
