#pragma once

template <typename T> struct Graph {
  // only simple graph.
  int N, M;
  vector<vector<T>> G;
  T none_val;
  bool directed;
  Graph() {}
  Graph(int N, bool bl = false, T none_val = 0)
      : N(N), M(0), G(N, vector<int>(N, none_val)), none_val(none_val),
        directed(bl) {}

  void add(int frm, int to, T cost = 1, bool check_mult = true) {
    if(check_mult) assert(G[frm][to] == none_val);
    G[frm][to] = cost;
    if (!directed) {
      G[to][frm] = cost;
    }
    ++M;
  }

  int size() { return N; }
  vector<T> &operator[](int v) { return G[v]; }
};
