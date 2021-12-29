#pragma once
#include "graph/base.hpp"

template <typename Graph>
struct HLD {
  Graph &G;
  int N;
  vector<int> LID, RID, head, V, parent, depth;

  HLD(Graph &G, int root = 0)
      : G(G),
        N(G.N),
        LID(G.N),
        RID(G.N),
        head(G.N, root),
        V(G.N),
        parent(G.N, -1),
        depth(G.N) {
    assert(G.is_prepared());
    int t1 = 0;
    dfs_sz(root, -1);
    dfs_hld(root, -1, t1);
  }

  void dfs_sz(int v, int p) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    if (l + 1 < r && get<1>(csr[l]) == p) swap(csr[l], csr[l + 1]);
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto [frm, to, cost, id] = csr[i];
      if (to == p) {
        assert(!G.is_directed());
        continue;
      }
      dfs_sz(to, v);
      sz[v] += sz[to];
      if (chmax(hld_sz, sz[to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int p, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&[frm, to, cost, id]: G[v]) {
      if (to == p) continue;
      head[to] = (heavy ? head[v] : to);
      heavy = false;
      dfs_hld(to, v, times);
    }
  }

  int e_to_v(int e) {
    auto [frm, to, cost, id] = G.edges[e];
    return (parent[frm] == to ? frm : to);
  }

  /* k: 0-indexed */
  int LA(int v, int k) {
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }

  int LCA(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int move(int a, int b) {
    assert(a != b);
    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
  }

  void debug() {
    print("V", V);
    print("LID", LID);
    print("RID", RID);
    print("parent", parent);
    print("depth", depth);
    print("head", head);
  }

  void doc() {
    print("HL分解。O(N) 時間構築。");
    print("LCA, LA などは O(logN) 時間。");
    print("木の問題では真っ先にこれを作る。");
    print("→ 木DPや木クエリに派生。");
  }
};
