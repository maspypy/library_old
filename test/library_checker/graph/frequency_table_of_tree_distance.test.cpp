#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "my_template.hpp"

#include "graph/centroid.hpp"
#include "polynomial/convolution_ll.hpp"

void solve() {
  LL(N);
  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(a, b);
  }
  G.prepare();

  CentroidDecomposition CD(G);

  auto cdep = CD.cdep;
  FOR(i, len(cdep)) assert(cdep[i] <= 20);

  CFFT fft;
  vi ANS(N + N);
  FOR(root, N) {
    auto data = CD.collect(root, 0);
    FOR(i, len(data)) {
      int n = len(data[i]) + 1;
      vi A(n);
      FOR(j, len(data[i])) A[data[i][j].se]++;
      while (A.back() == 0) A.pop_back();
      auto B = conv_square_ll(A);
      FOR(j, len(B)) ANS[j] += (i == 0 ? B[j] : -B[j]);
    }
  }
  ANS.resize(N);
  ANS.erase(ANS.begin());
  for (auto&& x : ANS) x /= 2;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
