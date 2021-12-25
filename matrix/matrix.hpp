#pragma once
#include "my_template.hpp"
template <typename T>
struct Matrix {
  int H, W;
  vector<vector<T>> data;

  Matrix(int H, int W) : H(H), W(W), data(H, vector<T>(W, 0)){};
  vector<T>& operator[](int i) { return data[i]; }
  Matrix<T> operator*(Matrix<T>& other) {
    assert(W == other.H);
    int a = H, b = W, c = other.W;
    Matrix<T> C(a, c);
    FOR(i, a) {
      FOR(j, b) {
        FOR(k, c) { C[i][k] += data[i][j] * other[j][k]; }
      }
    }
    return C;
  }
  void eye() { FOR(i, H) FOR(j, W) data[i][j] = (i == j ? 1 : 0); }
  Matrix<T> pow(ll K) {
    Matrix<T> P(H, H);
    P.eye();
    Matrix<T> Q(H, H);
    FOR(i, H) FOR(j, H) Q[i][j] = data[i][j];
    while (K) {
      if (K & 1) P = P * Q;
      Q = Q * Q;
      K >>= 1;
    }
    return P;
  }
};


template <class T>
bool is_zero(const T& a) {
  return a == T(0);
}

template <class T>
int row_reduce(std::vector<std::vector<T>>& a, int limit = -1) {
  int h = std::size(a);
  if (h == 0) return 0;
  int w = std::size(a[0]), rank = 0;
  if (limit < 0 or w < limit) limit = w;
  for (int p = 0; p < limit; ++p) {
    for (int i = rank + 1; i < h; ++i)
      if constexpr (std::is_floating_point_v<T>) {
        if (std::abs(a[rank][p]) < std::abs(a[i][p])) std::swap(a[rank], a[i]);
      } else if (not is_zero(a[i][p])) {
        std::swap(a[rank], a[i]);
        break;
      }
    if (is_zero(a[rank][p])) continue;
    T inv = T(1) / a[rank][p];
    for (auto&& e : a[rank]) e *= inv;
    for (int i = 0; i < h; ++i)
      if (i != rank and not is_zero(a[i][p])) {
        for (int j = p + 1; j < w; ++j) a[i][j] -= a[rank][j] * a[i][p];
        a[i][p] = 0;
      }
    if (++rank == h) break;
  }
  return rank;
}

template <class T>
std::pair<std::vector<T>, std::vector<std::vector<T>>> solve_linear(
  std::vector<std::vector<T>> a, const std::vector<T>& b) {
  assert(std::size(a) == std::size(b));
  assert(not std::empty(a));
  int h = std::size(a), w = std::size(a[0]);
  for (int i = 0; i < h; ++i) a[i].push_back(b[i]);
  int rank = row_reduce(a, w);
  for (int i = rank; i < h; ++i)
    if (not is_zero(a[i][w])) return {};
  std::vector<T> x(w);
  std::vector pivot(w, -1);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (is_zero(a[i][j])) ++j;
    x[j] = a[i][w];
    pivot[j] = i;
  }
  std::vector<std::vector<T>> basis;
  for (int p = 0; p < w; ++p)
    if (pivot[p] == -1) {
      basis.emplace_back(w);
      basis.back()[p] = -1;
      for (int j = 0; j < p; ++j)
        if (pivot[j] != -1) basis.back()[j] = a[pivot[j]][p];
    }
  return {x, basis};
}
