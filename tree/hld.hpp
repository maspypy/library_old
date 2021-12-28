#pragma once
#include "graph/base.hpp"

template <typename Graph>
struct HLD {
  Graph &G;
  int N;
  vector<int> sz, LID, RID, ELID, ERID, head, V, parent, depth, e_to_v;

  HLD(Graph &G, int root = 0)
      : G(G),
        N(G.N),
        sz(G.N),
        LID(G.N),
        RID(G.N),
        ELID(G.N),
        ERID(G.N),
        head(G.N, root),
        V(G.N),
        parent(G.N, -1),
        depth(G.N),
        e_to_v(G.N) {
    int t1 = 0, t2 = 0;
    dfs_sz(root, -1);
    dfs_hld(root, -1, t1, t2);
  }

  void dfs_sz(int idx, int p) {
    parent[idx] = p;
    depth[idx] = (p == -1 ? 0 : depth[p] + 1);
    sz[idx] = 1;
    if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0], G[idx].back());
    for (auto &e: G[idx]) {
      if (e.to == p) continue;
      e_to_v[e.id] = e.to;
      dfs_sz(e.to, idx);
      sz[idx] += sz[e.to];
      if (sz[G[idx][0].to] < sz[e.to]) swap(G[idx][0], e);
    }
  }

  void dfs_hld(int idx, int par, int &times, int &etimes) {
    LID[idx] = times++;
    ELID[idx] = etimes++;
    V[LID[idx]] = idx;
    for (auto &e: G[idx]) {
      if (e.to == par) continue;
      head[e.to] = (G[idx][0].to == e.to ? head[idx] : e.to);
      dfs_hld(e.to, idx, times, etimes);
    }
    RID[idx] = times;
    ERID[idx] = etimes++;
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
    print("parent", parent);
    print("depth", depth);
    print("head", head);
    print("LID", LID);
    print("RID", RID);
    print("ELID", ELID);
    print("ERID", ERID);
  }

  void doc() {
    print("HL分解。O(N) 時間構築。");
    print("LCA, LA などは O(logN) 時間。");
    print("木の問題では真っ先にこれを作る。");
    print("→ 木DPや木クエリに派生。");
  }
};
