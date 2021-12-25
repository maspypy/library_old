---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dfstree.hpp\"\n\ntemplate <class T>\nstruct DfsTree\
    \ {\n  T& G;\n  int root;\n  bool calc_anc;\n  vector<int> V, VR, parent, LID,\
    \ RID, depth;\n  vector<vector<int>> ancestors;\n  vector<vector<int>> ch;\n \
    \ vector<bool> vis;\n  vector<bool> in_tree;\n\n  DfsTree(T& G, int root = 0,\
    \ bool calc_anc = true) : G(G), root(root), calc_anc(calc_anc) { build(); };\n\
    \n  void dfs(int v, int p) {\n    vis[v] = true;\n    LID[v] = V.size();\n   \
    \ V.eb(v);\n    parent[v] = p;\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\n\
    \    FORIN(e, G[v]) {\n      int w = e.to;\n      if (vis[w]) continue;\n    \
    \  in_tree[e.id] = true;\n      dfs(w, v);\n    }\n    RID[v] = V.size();\n  }\n\
    \n  void build() {\n    int N = G.N;\n    V.reserve(N);\n    parent.resize(N);\n\
    \    LID.resize(N);\n    RID.resize(N);\n    depth.resize(N);\n    vis.assign(N,\
    \ false);\n    in_tree.assign(G.M, false);\n    parent[root] = -1;\n    depth[root]\
    \ = 0;\n    dfs(root, -1);\n    VR = V;\n    reverse(all(VR));\n\n    if (calc_anc)\
    \ {\n      FOR(k, 20) ancestors.eb(vector<int>(N));\n      ancestors[0] = parent;\n\
    \      FOR3(k, 1, 20) {\n        FOR(v, G.N) {\n          int w = ancestors[k\
    \ - 1][v];\n          ancestors[k][v] = (w == -1 ? -1 : ancestors[k - 1][w]);\n\
    \        }\n      }\n    }\n  }\n\n  int LCA(int a, int b) {\n    assert(calc_anc);\n\
    \    if (depth[a] > depth[b]) swap(a, b);\n    auto n = depth[b] - depth[a];\n\
    \    FOR(k, 20) {\n      if (n & 1 << k) b = ancestors[k][b];\n    }\n    if (a\
    \ == b) return a;\n    FOR_R(k, 20) {\n      if (ancestors[k][a] != ancestors[k][b])\
    \ {\n        a = ancestors[k][a];\n        b = ancestors[k][b];\n      }\n   \
    \ }\n    return parent[a];\n  }\n\n  int LA(int v, int n) {\n    FOR(k, 20) if\
    \ (n & 1 << k) {\n      v = ancestors[k][v];\n      if (v == -1) return -1;\n\
    \    }\n    return v;\n  }\n\n  int dist(int a, int b) {\n    int c = LCA(a, b);\n\
    \    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\n\n  int move(int\
    \ a, int b) {\n    assert(a != b);\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct DfsTree {\n  T& G;\n  int root;\n\
    \  bool calc_anc;\n  vector<int> V, VR, parent, LID, RID, depth;\n  vector<vector<int>>\
    \ ancestors;\n  vector<vector<int>> ch;\n  vector<bool> vis;\n  vector<bool> in_tree;\n\
    \n  DfsTree(T& G, int root = 0, bool calc_anc = true) : G(G), root(root), calc_anc(calc_anc)\
    \ { build(); };\n\n  void dfs(int v, int p) {\n    vis[v] = true;\n    LID[v]\
    \ = V.size();\n    V.eb(v);\n    parent[v] = p;\n    depth[v] = (p == -1 ? 0 :\
    \ depth[p] + 1);\n    FORIN(e, G[v]) {\n      int w = e.to;\n      if (vis[w])\
    \ continue;\n      in_tree[e.id] = true;\n      dfs(w, v);\n    }\n    RID[v]\
    \ = V.size();\n  }\n\n  void build() {\n    int N = G.N;\n    V.reserve(N);\n\
    \    parent.resize(N);\n    LID.resize(N);\n    RID.resize(N);\n    depth.resize(N);\n\
    \    vis.assign(N, false);\n    in_tree.assign(G.M, false);\n    parent[root]\
    \ = -1;\n    depth[root] = 0;\n    dfs(root, -1);\n    VR = V;\n    reverse(all(VR));\n\
    \n    if (calc_anc) {\n      FOR(k, 20) ancestors.eb(vector<int>(N));\n      ancestors[0]\
    \ = parent;\n      FOR3(k, 1, 20) {\n        FOR(v, G.N) {\n          int w =\
    \ ancestors[k - 1][v];\n          ancestors[k][v] = (w == -1 ? -1 : ancestors[k\
    \ - 1][w]);\n        }\n      }\n    }\n  }\n\n  int LCA(int a, int b) {\n   \
    \ assert(calc_anc);\n    if (depth[a] > depth[b]) swap(a, b);\n    auto n = depth[b]\
    \ - depth[a];\n    FOR(k, 20) {\n      if (n & 1 << k) b = ancestors[k][b];\n\
    \    }\n    if (a == b) return a;\n    FOR_R(k, 20) {\n      if (ancestors[k][a]\
    \ != ancestors[k][b]) {\n        a = ancestors[k][a];\n        b = ancestors[k][b];\n\
    \      }\n    }\n    return parent[a];\n  }\n\n  int LA(int v, int n) {\n    FOR(k,\
    \ 20) if (n & 1 << k) {\n      v = ancestors[k][v];\n      if (v == -1) return\
    \ -1;\n    }\n    return v;\n  }\n\n  int dist(int a, int b) {\n    int c = LCA(a,\
    \ b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\n\n  int move(int\
    \ a, int b) {\n    assert(a != b);\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dfstree.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dfstree.hpp
layout: document
redirect_from:
- /library/graph/dfstree.hpp
- /library/graph/dfstree.hpp.html
title: graph/dfstree.hpp
---
