---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/lca.test.cpp
    title: test/library_checker/tree/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/hld.hpp\"\ntemplate <typename Graph>\r\nstruct HLD\
    \ {\r\n  Graph &G;\r\n  int N;\r\n  vector<int> sz, LID, RID, head, V, parent,\
    \ depth, e_to_v;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n      : G(G)\r\n    \
    \  , N(G.N)\r\n      , sz(G.N)\r\n      , LID(G.N)\r\n      , RID(G.N)\r\n   \
    \   , head(G.N, root)\r\n      , V(G.N)\r\n      , parent(G.N, -1)\r\n      ,\
    \ depth(G.N)\r\n      , e_to_v(G.N) {\r\n    int t = 0;\r\n    dfs_sz(root, -1);\r\
    \n    dfs_hld(root, -1, t);\r\n  }\r\n\r\n  void dfs_sz(int idx, int p) {\r\n\
    \    parent[idx] = p;\r\n    depth[idx] = (p == -1 ? 0 : depth[p] + 1);\r\n  \
    \  sz[idx] = 1;\r\n    if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0],\
    \ G[idx].back());\r\n    for (auto &e : G[idx]) {\r\n      if (e.to == p) continue;\r\
    \n      e_to_v[e.id] = e.to;\r\n      dfs_sz(e.to, idx);\r\n      sz[idx] += sz[e.to];\r\
    \n      if (sz[G[idx][0].to] < sz[e.to]) swap(G[idx][0], e);\r\n    }\r\n  }\r\
    \n\r\n  void dfs_hld(int idx, int par, int &times) {\r\n    LID[idx] = times++;\r\
    \n    V[LID[idx]] = idx;\r\n    for (auto &e : G[idx]) {\r\n      if (e.to ==\
    \ par) continue;\r\n      head[e.to] = (G[idx][0].to == e.to ? head[idx] : e.to);\r\
    \n      dfs_hld(e.to, idx, times);\r\n    }\r\n    RID[idx] = times;\r\n  }\r\n\
    \r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1) {\r\n  \
    \    int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\
    \n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if\
    \ (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n\
    \    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\
    \u9593\u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN)\
    \ \u6642\u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\
    \u3063\u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192\
    \ \u6728DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n\
    };\r\n"
  code: "#pragma once\r\ntemplate <typename Graph>\r\nstruct HLD {\r\n  Graph &G;\r\
    \n  int N;\r\n  vector<int> sz, LID, RID, head, V, parent, depth, e_to_v;\r\n\r\
    \n  HLD(Graph &G, int root = 0)\r\n      : G(G)\r\n      , N(G.N)\r\n      , sz(G.N)\r\
    \n      , LID(G.N)\r\n      , RID(G.N)\r\n      , head(G.N, root)\r\n      , V(G.N)\r\
    \n      , parent(G.N, -1)\r\n      , depth(G.N)\r\n      , e_to_v(G.N) {\r\n \
    \   int t = 0;\r\n    dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t);\r\n  }\r\n\
    \r\n  void dfs_sz(int idx, int p) {\r\n    parent[idx] = p;\r\n    depth[idx]\
    \ = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[idx] = 1;\r\n    if (G[idx].size()\
    \ && G[idx][0].to == p) swap(G[idx][0], G[idx].back());\r\n    for (auto &e :\
    \ G[idx]) {\r\n      if (e.to == p) continue;\r\n      e_to_v[e.id] = e.to;\r\n\
    \      dfs_sz(e.to, idx);\r\n      sz[idx] += sz[e.to];\r\n      if (sz[G[idx][0].to]\
    \ < sz[e.to]) swap(G[idx][0], e);\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int idx,\
    \ int par, int &times) {\r\n    LID[idx] = times++;\r\n    V[LID[idx]] = idx;\r\
    \n    for (auto &e : G[idx]) {\r\n      if (e.to == par) continue;\r\n      head[e.to]\
    \ = (G[idx][0].to == e.to ? head[idx] : e.to);\r\n      dfs_hld(e.to, idx, times);\r\
    \n    }\r\n    RID[idx] = times;\r\n  }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n\r\n  int LCA(int u, int v) {\r\n   \
    \ for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\n\
    \      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int dist(int\
    \ a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2\
    \ * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int a, int b) { return LID[b] <=\
    \ LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int a, int b) {\r\n    assert(a\
    \ != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"V\", V);\r\n    print(\"parent\"\
    , parent);\r\n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\n \
    \   print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n  }\r\n\r\n  void doc()\
    \ {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\u69CB\u7BC9\u3002\");\r\
    \n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\u9593\u3002\");\r\n  \
    \  print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\u5148\u306B\u3053\u308C\
    \u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728DP\u3084\u6728\u30AF\u30A8\
    \u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hld.hpp
  requiredBy:
  - graph/treemonoid.hpp
  timestamp: '2021-12-26 20:23:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/tree/lca.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
documentation_of: graph/hld.hpp
layout: document
redirect_from:
- /library/graph/hld.hpp
- /library/graph/hld.hpp.html
title: graph/hld.hpp
---
