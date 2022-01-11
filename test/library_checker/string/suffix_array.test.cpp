#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "my_template.hpp"

#include "string/suffixarray.hpp"

void solve() {
  STR(S);
  SuffixArray sa(S);
  print(sa.SA);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
