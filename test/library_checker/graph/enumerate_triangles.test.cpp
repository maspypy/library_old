#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#include "my_template.hpp"
#include "graph/enumerate_triangles.hpp"

void solve() {
  LL(N, M);
  VEC(int, A, N);
  Graph G(N);
  FOR_(M) {
    LL(a, b);
    G.add(a, b);
  }
  i128 sum = 0;
  auto query
      = [&](int a, int b, int c) -> void { sum += i128(A[a]) * A[b] * A[c]; };
  enumerate_triangles(G, query);
  int ANS = sum % 998244353;
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
