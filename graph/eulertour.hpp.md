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
  bundledCode: "#line 1 \"graph/eulertour.hpp\"\ntemplate <class T>\nstruct EulerTour\
    \ {\n  T& G;\n  int root;\n  bool calc_anc;\n  vector<int> V, VR, parent, LID,\
    \ RID, depth;\n  vector<vector<int>> ancestors;\n\n  EulerTour(){}\n  EulerTour(T&\
    \ G, int root = 0, bool calc_anc=true) : G(G), root(root), calc_anc(calc_anc)\
    \ { build(); };\n\n  void dfs(int v, int p) {\n    LID[v] = V.size();\n    V.eb(v);\n\
    \    parent[v] = p;\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\n    FORIN(e,\
    \ G[v]) {\n      int w = e.to;\n      if (w == p) continue;\n      dfs(w, v);\n\
    \    }\n    RID[v] = V.size();\n  }\n\n  void build() {\n    int N = G.N;\n  \
    \  V.reserve(N);\n    parent.resize(N);\n    LID.resize(N);\n    RID.resize(N);\n\
    \    depth.resize(N);\n    parent[root] = -1;\n    depth[root] = 0;\n    dfs(root,\
    \ -1);\n    VR = V;\n    reverse(all(VR));\n\n    if(calc_anc){\n      FOR(k,\
    \ 20) ancestors.eb(vector<int>(N));\n      ancestors[0] = parent;\n      FOR3(k,\
    \ 1, 20){\n        FOR(v, G.N){\n          int w = ancestors[k-1][v];\n      \
    \    ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);\n        }\n      }\n\
    \    }\n  }\n\n  int LCA(int a, int b){\n    assert(calc_anc);\n    if(depth[a]\
    \ > depth[b]) swap(a, b);\n    auto n = depth[b] - depth[a];\n    FOR(k, 20){\n\
    \      if(n & 1<<k) b = ancestors[k][b];\n    }\n    if(a==b) return a;\n    FOR_R(k,\
    \ 20){\n      if(ancestors[k][a] != ancestors[k][b]){\n        a = ancestors[k][a];\n\
    \        b = ancestors[k][b];\n      }\n    }\n    return parent[a];\n  }\n\n\
    \  int LA(int v, int n){\n    FOR(k, 20) if(n & 1<<k) {v = ancestors[k][v]; if\
    \ (v==-1) return -1;}\n    return v;\n  }  \n\n  int dist(int a, int b){\n   \
    \ int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\n\
    \  bool in_subtree(int a, int b){\n    return LID[b] <= LID[a] && LID[a] < RID[b];\n\
    \  }\n\n  int move(int a, int b){\n    assert(a != b);\n    return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n  }\n};\n\ntemplate <class\
    \ T>\nstruct EulerTour_e {\n  T& G;\n  int root;\n  bool calc_anc;\n  vector<int>\
    \ tour, parent, LID, RID, depth;\n  vector<vector<int>> ancestors;\n\n  EulerTour_e(T&\
    \ G, int root = 0, bool calc_anc=true) : G(G), root(root), calc_anc(calc_anc)\
    \ { build(); };\n\n  void dfs(int v, int p) {\n    LID[v] = tour.size();\n   \
    \ tour.eb(v);\n    parent[v] = p;\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\n\
    \    FORIN(e, G[v]) {\n      int w = e.to;\n      if (w == p) continue;\n    \
    \  dfs(w, v);\n    }\n    RID[v] = tour.size();\n    tour.eb(~v);\n  }\n\n  void\
    \ build() {\n    int N = G.N;\n    tour.reserve(N * 2);\n    parent.resize(N);\n\
    \    LID.resize(N);\n    RID.resize(N);\n    depth.resize(N);\n    parent[root]\
    \ = -1;\n    depth[root] = 0;\n    dfs(root, -1);\n    if(calc_anc){\n      FOR(k,\
    \ 20) ancestors.eb(vector<int>(N));\n      ancestors[0] = parent;\n      FOR3(k,\
    \ 1, 20){\n        FOR(v, G.N){\n          int w = ancestors[k-1][v];\n      \
    \    ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);\n        }\n      }\n\
    \    }\n  }\n\n  int LCA(int a, int b){\n    assert(calc_anc);\n    if(depth[a]\
    \ > depth[b]) swap(a, b);\n    auto n = depth[b] - depth[a];\n    FOR(k, 20){\n\
    \      if(n & 1<<k) b = ancestors[k][b];\n    }\n    if(a==b) return a;\n    FOR_R(k,\
    \ 20){\n      if(ancestors[k][a] != ancestors[k][b]){\n        a = ancestors[k][a];\n\
    \        b = ancestors[k][b];\n      }\n    }\n    return parent[a];\n  }\n\n\
    \  int LA(int v, int n){\n    FOR(k, 20) if(n & 1<<k) {v = ancestors[k][v]; if\
    \ (v==-1) return -1;}\n    return v;\n  }  \n\n  int dist(int a, int b){\n   \
    \ int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\n\
    \  bool in_subtree(int a, int b){\n    return LID[b] <= LID[a] && LID[a] < RID[b];\n\
    \  }\n\n  int move(int a, int b){\n    assert(a != b);\n    return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n  }\n};\n"
  code: "template <class T>\nstruct EulerTour {\n  T& G;\n  int root;\n  bool calc_anc;\n\
    \  vector<int> V, VR, parent, LID, RID, depth;\n  vector<vector<int>> ancestors;\n\
    \n  EulerTour(){}\n  EulerTour(T& G, int root = 0, bool calc_anc=true) : G(G),\
    \ root(root), calc_anc(calc_anc) { build(); };\n\n  void dfs(int v, int p) {\n\
    \    LID[v] = V.size();\n    V.eb(v);\n    parent[v] = p;\n    depth[v] = (p ==\
    \ -1 ? 0 : depth[p] + 1);\n    FORIN(e, G[v]) {\n      int w = e.to;\n      if\
    \ (w == p) continue;\n      dfs(w, v);\n    }\n    RID[v] = V.size();\n  }\n\n\
    \  void build() {\n    int N = G.N;\n    V.reserve(N);\n    parent.resize(N);\n\
    \    LID.resize(N);\n    RID.resize(N);\n    depth.resize(N);\n    parent[root]\
    \ = -1;\n    depth[root] = 0;\n    dfs(root, -1);\n    VR = V;\n    reverse(all(VR));\n\
    \n    if(calc_anc){\n      FOR(k, 20) ancestors.eb(vector<int>(N));\n      ancestors[0]\
    \ = parent;\n      FOR3(k, 1, 20){\n        FOR(v, G.N){\n          int w = ancestors[k-1][v];\n\
    \          ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);\n        }\n\
    \      }\n    }\n  }\n\n  int LCA(int a, int b){\n    assert(calc_anc);\n    if(depth[a]\
    \ > depth[b]) swap(a, b);\n    auto n = depth[b] - depth[a];\n    FOR(k, 20){\n\
    \      if(n & 1<<k) b = ancestors[k][b];\n    }\n    if(a==b) return a;\n    FOR_R(k,\
    \ 20){\n      if(ancestors[k][a] != ancestors[k][b]){\n        a = ancestors[k][a];\n\
    \        b = ancestors[k][b];\n      }\n    }\n    return parent[a];\n  }\n\n\
    \  int LA(int v, int n){\n    FOR(k, 20) if(n & 1<<k) {v = ancestors[k][v]; if\
    \ (v==-1) return -1;}\n    return v;\n  }  \n\n  int dist(int a, int b){\n   \
    \ int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\n\
    \  bool in_subtree(int a, int b){\n    return LID[b] <= LID[a] && LID[a] < RID[b];\n\
    \  }\n\n  int move(int a, int b){\n    assert(a != b);\n    return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n  }\n};\n\ntemplate <class\
    \ T>\nstruct EulerTour_e {\n  T& G;\n  int root;\n  bool calc_anc;\n  vector<int>\
    \ tour, parent, LID, RID, depth;\n  vector<vector<int>> ancestors;\n\n  EulerTour_e(T&\
    \ G, int root = 0, bool calc_anc=true) : G(G), root(root), calc_anc(calc_anc)\
    \ { build(); };\n\n  void dfs(int v, int p) {\n    LID[v] = tour.size();\n   \
    \ tour.eb(v);\n    parent[v] = p;\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\n\
    \    FORIN(e, G[v]) {\n      int w = e.to;\n      if (w == p) continue;\n    \
    \  dfs(w, v);\n    }\n    RID[v] = tour.size();\n    tour.eb(~v);\n  }\n\n  void\
    \ build() {\n    int N = G.N;\n    tour.reserve(N * 2);\n    parent.resize(N);\n\
    \    LID.resize(N);\n    RID.resize(N);\n    depth.resize(N);\n    parent[root]\
    \ = -1;\n    depth[root] = 0;\n    dfs(root, -1);\n    if(calc_anc){\n      FOR(k,\
    \ 20) ancestors.eb(vector<int>(N));\n      ancestors[0] = parent;\n      FOR3(k,\
    \ 1, 20){\n        FOR(v, G.N){\n          int w = ancestors[k-1][v];\n      \
    \    ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);\n        }\n      }\n\
    \    }\n  }\n\n  int LCA(int a, int b){\n    assert(calc_anc);\n    if(depth[a]\
    \ > depth[b]) swap(a, b);\n    auto n = depth[b] - depth[a];\n    FOR(k, 20){\n\
    \      if(n & 1<<k) b = ancestors[k][b];\n    }\n    if(a==b) return a;\n    FOR_R(k,\
    \ 20){\n      if(ancestors[k][a] != ancestors[k][b]){\n        a = ancestors[k][a];\n\
    \        b = ancestors[k][b];\n      }\n    }\n    return parent[a];\n  }\n\n\
    \  int LA(int v, int n){\n    FOR(k, 20) if(n & 1<<k) {v = ancestors[k][v]; if\
    \ (v==-1) return -1;}\n    return v;\n  }  \n\n  int dist(int a, int b){\n   \
    \ int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\n\
    \  bool in_subtree(int a, int b){\n    return LID[b] <= LID[a] && LID[a] < RID[b];\n\
    \  }\n\n  int move(int a, int b){\n    assert(a != b);\n    return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulertour.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/eulertour.hpp
layout: document
redirect_from:
- /library/graph/eulertour.hpp
- /library/graph/eulertour.hpp.html
title: graph/eulertour.hpp
---
