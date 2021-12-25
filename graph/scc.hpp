#pragma once
#include "graph/base.hpp"

template <class T> struct SCC {
  T &G;
  ll N;
  ll n_comp;
  vc<int> comp_id;
  vc<int> low;
  vc<int> ord;
  vc<int> visited;
  ll now = 0;

  SCC(T &G)
      : G(G), N(G.N), n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {
    assert(G.directed);
    build();
  }

  ll operator[](ll v) { return comp_id[v]; }

  void dfs(int v) {
    low[v] = now;
    ord[v] = now;
    ++now;
    visited.eb(v);
    for (auto e : G[v]) {
      if (ord[e.to] == -1) {
        dfs(e.to);
        chmin(low[v], low[e.to]);
      } else {
        chmin(low[v], ord[e.to]);
      }
    }
    if (low[v] == ord[v]) {
      while (1) {
        ll u = visited.back();
        visited.pop_back();
        ord[u] = N;
        comp_id[u] = n_comp;
        if (u == v)
          break;
      }
      ++n_comp;
    }
  }

  void build() {
    FOR(v, N) {
      if (ord[v] == -1)
        dfs(v);
    }
    FOR(v, N) comp_id[v] = n_comp - 1 - comp_id[v];
  }

  vc<vc<int>> comp() {
    if (n_comp == 0)
      build();
    vc<vc<int>> res;
    res.resize(n_comp);
    FOR(v, N) { res[comp_id[v]].eb(v); }
    return res;
  };
};
