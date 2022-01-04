#pragma once

#include "polynomial/convolution.hpp"

template <typename mint>
mint coef_of_rational(vector<mint> A, vector<mint> B, ll N) {
  if(len(A)==0) return 0;
  assert(B[0] == 1);
  assert(len(B) == len(A) + 1);
  while (N) {
    vc<mint> B1 = B;
    FOR(i, len(B1)) if (i & 1) B1[i] = -B1[i];
    A = convolution(A, B1);
    B = convolution(B, B1);
    FOR(i, len(B1)) B[i] = B[2 * i];
    if (N & 1) {
      FOR(i, len(B1) - 1) A[i] = A[2 * i | 1];
    } else {
      FOR(i, len(B1) - 1) A[i] = A[2 * i];
    }
    A.resize(len(B1) - 1);
    B.resize(len(B1));
    N /= 2;
  }
  return A[0];
}

template <typename mint>
vector<mint> find_linear_recurrence(vector<mint>& A) {
  int N = len(A);
  vc<mint> B = {1}, C = {1};
  int l = 0, m = 1;
  mint p = 1;
  FOR(i, N) {
    mint d = A[i];
    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }
    if (d == 0) {
      ++m;
      continue;
    }
    auto tmp = C;
    mint q = d / p;
    if (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C), 0);
    FOR(j, len(B)) C[j + m] -= q * B[j];
    if (l + l <= i) {
      B = tmp;
      l = i + 1 - l, m = 1;
      p = d;
    } else {
      ++m;
    }
  }
  return C;
}

template <typename mint>
mint interpolate_linear_recurrence(vector<mint>& A, ll N) {
  auto G = find_linear_recurrence(A);
  auto F = convolution(A, G);
  F.resize(len(G) - 1);
  return coef_of_rational(F, G, N);
}
