#pragma once
template <typename GT, typename T>
struct TreeDoubling {
  using F = function<T(T, T)>;
  const int K = 20;
  EulerTour<GT>& ET;
  F f;
  T T_unit;
  bool edge;
  vector<vector<T>> dp;
  bool done;

  TreeDoubling(){}
  TreeDoubling(EulerTour<GT>& ET, F f, T T_unit, bool edge) : ET(ET), f(f), T_unit(T_unit), edge(edge), done(false) {
    auto N = ET.G.size();
    FOR(k, K) { dp.eb(vector<T>(N, T_unit)); }
  }

  void set(int v, T t) { dp[0][v] = t; }

  void build() {
    done = true;
    auto& anc = ET.ancestors;
    auto N = dp[0].size();
    FOR3(k, 1, K) {
      FOR(v, N) {
        int w = anc[k - 1][v];
        dp[k][v] = (w!=-1 ? f(dp[k - 1][v], dp[k - 1][w]) : dp[k-1][v]);
      }
    }
  }

  int LA(int a, int n){
    return ET.LA(a, n);
  }

  int LCA(int a, int b) { return ET.LCA(a, b); }

  T query(int a, int b) {
    assert(done);
    T res = T_unit;
    auto& anc = ET.ancestors;
    auto& dep = ET.depth;
    if (dep[a] > dep[b]) swap(a, b);
    auto n = dep[b] - dep[a];
    FOR(k, 20) {
      if (n & 1 << k) {
        res = f(res, dp[k][b]);
        b = anc[k][b];
      }
    }
    if (a == b) {
      return (edge ? res : f(res, dp[0][a]));
    }
    FOR_R(k, 20) {
      if (anc[k][a] != anc[k][b]) {
        res = f(res, dp[k][a]);
        res = f(res, dp[k][b]);
        a = anc[k][a];
        b = anc[k][b];
      }
    }
    res = f(res, dp[0][a]);
    res = f(res, dp[0][b]);
    int lca = anc[0][a];
    return (edge ? res : f(res, dp[0][lca]));
  }

  // lowest ancestor t of s, satisfying check(query(s,t))
  template<typename C>
  int max_ancestor(int s, C &check, bool edge=true){
    assert(check(T_unit));
    assert(edge);  // とりあえず
    
    auto& anc = ET.ancestors;
    T x = T_unit;
    FOR_R(k, K){
      if(anc[k][s] == -1) continue;
      T new_x = f(x, dp[k][s]);
      if(check(new_x)){
        s = anc[k][s];
        x = new_x;
      };
    }
    return s;
  }
};