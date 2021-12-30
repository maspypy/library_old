---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/lca.test.cpp
    title: test/library_checker/graph/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/lca_directed.test.cpp
    title: test/library_checker/graph/lca_directed.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\n// frm, to, cap, cost\ntemplate <typename\
    \ T>\nusing Edge = tuple<int, int, T, int>;\n\ntemplate <typename T, bool directed\
    \ = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() {}\n  Graph(int N) : N(N), M(0),\
    \ prepared(0) {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n  \
    \  assert(!prepared);\n    assert(0 <= frm && frm < N && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared = true;\n\
    \    indptr.assign(N + 1, 0);\n    for (auto&& [frm, to, cost, id]: edges) {\n\
    \      indptr[frm + 1]++;\n      if (!directed) indptr[to + 1]++;\n    }\n   \
    \ FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& [frm, to, cost, id]: edges) {\n      csr_edges[counter[frm]++]\
    \ = {frm, to, cost, id};\n      if (!directed) csr_edges[counter[to]++] = {to,\
    \ frm, cost, id};\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e);\n    } else {\n    \
    \  print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e: (*this)[v]) print(e);\n    }\n  }\n\n  int size() { return\
    \ N; }\n};\n#line 3 \"graph/hld.hpp\"\n\r\ntemplate <typename Graph>\r\nstruct\
    \ HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int> LID, RID, head, V, parent,\
    \ depth;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n      : G(G),\r\n        N(G.N),\r\
    \n        LID(G.N),\r\n        RID(G.N),\r\n        head(G.N, root),\r\n     \
    \   V(G.N),\r\n        parent(G.N, -1),\r\n        depth(G.N) {\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t1);\r\n \
    \ }\r\n\r\n  void dfs_sz(int v, int p) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\
    \n    if (l + 1 < r && get<1>(csr[l]) == p) swap(csr[l], csr[l + 1]);\r\n    int\
    \ hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n      auto [frm, to, cost,\
    \ id] = csr[i];\r\n      if (to == p) {\r\n        assert(!G.is_directed());\r\
    \n        continue;\r\n      }\r\n      dfs_sz(to, v);\r\n      sz[v] += sz[to];\r\
    \n      if (chmax(hld_sz, sz[to]) && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\
    \n  }\r\n\r\n  void dfs_hld(int v, int p, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&[frm, to, cost, id]: G[v]) {\r\n      if (to == p) continue;\r\n\
    \      head[to] = (heavy ? head[v] : to);\r\n      heavy = false;\r\n      dfs_hld(to,\
    \ v, times);\r\n    }\r\n  }\r\n\r\n  int e_to_v(int e) {\r\n    auto [frm, to,\
    \ cost, id] = G.edges[e];\r\n    return (parent[frm] == to ? frm : to);\r\n  }\r\
    \n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1) {\r\n\
    \      int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\
    \n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if\
    \ (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n\
    \    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n    print(\"\
    parent\", parent);\r\n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\
    \n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\
    \u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\
    \u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\
    \u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728\
    DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include \"graph/base.hpp\"\r\n\r\ntemplate <typename Graph>\r\
    \nstruct HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int> LID, RID, head, V,\
    \ parent, depth;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n      : G(G),\r\n   \
    \     N(G.N),\r\n        LID(G.N),\r\n        RID(G.N),\r\n        head(G.N, root),\r\
    \n        V(G.N),\r\n        parent(G.N, -1),\r\n        depth(G.N) {\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t1);\r\n \
    \ }\r\n\r\n  void dfs_sz(int v, int p) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\
    \n    if (l + 1 < r && get<1>(csr[l]) == p) swap(csr[l], csr[l + 1]);\r\n    int\
    \ hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n      auto [frm, to, cost,\
    \ id] = csr[i];\r\n      if (to == p) {\r\n        assert(!G.is_directed());\r\
    \n        continue;\r\n      }\r\n      dfs_sz(to, v);\r\n      sz[v] += sz[to];\r\
    \n      if (chmax(hld_sz, sz[to]) && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\
    \n  }\r\n\r\n  void dfs_hld(int v, int p, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&[frm, to, cost, id]: G[v]) {\r\n      if (to == p) continue;\r\n\
    \      head[to] = (heavy ? head[v] : to);\r\n      heavy = false;\r\n      dfs_hld(to,\
    \ v, times);\r\n    }\r\n  }\r\n\r\n  int e_to_v(int e) {\r\n    auto [frm, to,\
    \ cost, id] = G.edges[e];\r\n    return (parent[frm] == to ? frm : to);\r\n  }\r\
    \n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1) {\r\n\
    \      int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\
    \n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if\
    \ (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n\
    \    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n    print(\"\
    parent\", parent);\r\n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\
    \n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\
    \u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\
    \u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\
    \u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728\
    DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/hld.hpp
  requiredBy:
  - graph/treemonoid.hpp
  timestamp: '2021-12-30 20:03:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/graph/lca.test.cpp
  - test/library_checker/graph/lca_directed.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: graph/hld.hpp
layout: document
redirect_from:
- /library/graph/hld.hpp
- /library/graph/hld.hpp.html
title: graph/hld.hpp
---
