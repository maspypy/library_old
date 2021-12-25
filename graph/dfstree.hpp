#pragma once

template <class T>
struct DfsTree {
  T& G;
  int root;
  bool calc_anc;
  vector<int> V, VR, parent, LID, RID, depth;
  vector<vector<int>> ancestors;
  vector<vector<int>> ch;
  vector<bool> vis;
  vector<bool> in_tree;

  DfsTree(T& G, int root = 0, bool calc_anc = true) : G(G), root(root), calc_anc(calc_anc) { build(); };

  void dfs(int v, int p) {
    vis[v] = true;
    LID[v] = V.size();
    V.eb(v);
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    FORIN(e, G[v]) {
      int w = e.to;
      if (vis[w]) continue;
      in_tree[e.id] = true;
      dfs(w, v);
    }
    RID[v] = V.size();
  }

  void build() {
    int N = G.N;
    V.reserve(N);
    parent.resize(N);
    LID.resize(N);
    RID.resize(N);
    depth.resize(N);
    vis.assign(N, false);
    in_tree.assign(G.M, false);
    parent[root] = -1;
    depth[root] = 0;
    dfs(root, -1);
    VR = V;
    reverse(all(VR));

    if (calc_anc) {
      FOR(k, 20) ancestors.eb(vector<int>(N));
      ancestors[0] = parent;
      FOR3(k, 1, 20) {
        FOR(v, G.N) {
          int w = ancestors[k - 1][v];
          ancestors[k][v] = (w == -1 ? -1 : ancestors[k - 1][w]);
        }
      }
    }
  }

  int LCA(int a, int b) {
    assert(calc_anc);
    if (depth[a] > depth[b]) swap(a, b);
    auto n = depth[b] - depth[a];
    FOR(k, 20) {
      if (n & 1 << k) b = ancestors[k][b];
    }
    if (a == b) return a;
    FOR_R(k, 20) {
      if (ancestors[k][a] != ancestors[k][b]) {
        a = ancestors[k][a];
        b = ancestors[k][b];
      }
    }
    return parent[a];
  }

  int LA(int v, int n) {
    FOR(k, 20) if (n & 1 << k) {
      v = ancestors[k][v];
      if (v == -1) return -1;
    }
    return v;
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
};
