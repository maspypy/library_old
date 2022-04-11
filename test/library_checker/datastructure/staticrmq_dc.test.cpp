#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/divide_conquer_range_query.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  using Data = int;
  Divide_Conquer_Range_Query<Data> DC(N);
  const int INF = 1 << 30;
  FOR_(Q) {
    LL(l, r);
    DC.add(l, r);
  }

  vc<int> ANS(Q);
  auto add = [&](int i, Data x) -> Data { return min(x, A[i]); };
  auto calc = [&](int q, Data& xl, Data& xr) -> void { ANS[q] = min(xl, xr); };
  DC.calc(INF, add, add, calc);
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();

  return 0;
}
