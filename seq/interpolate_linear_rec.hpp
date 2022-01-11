#pragma once

#include "sequence/find_linear_recurrence.hpp"
#include "sequence/coef_of_rational_fps.hpp"

template <typename mint>
mint interpolate_linear_recurrence(vector<mint>& A, ll N) {
  auto G = find_linear_recurrence(A);
  auto F = convolution(A, G);
  F.resize(len(G) - 1);
  return coef_of_rational(F, G, N);
}
