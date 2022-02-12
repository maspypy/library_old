---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/tree_diameter.test.cpp
    title: test/library_checker/tree/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared && 0 <= frm && 0 <= to);\n   \
    \ chmax(N, frm + 1);\n    chmax(N, to + 1);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void\
    \ read_tree(bool wt=false, int off=1){\n    read_graph(N - 1, wt, off);\n  }\n\
    \n  void read_graph(int M, bool wt=false, int off=1){\n    FOR_(M){\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if(!wt){\n        add(a, b);\n      }\
    \ else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n   \
    \ }\n    prepare();\n  }\n\n  void read_parent(int off=1){\n    FOR3(v, 1, N){\n\
    \      INT(p);\n      add(p, v);\n    }\n    prepare();\n  }\n\n  void prepare()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 3 \"graph/bfs01.hpp\"\
    \n\ntemplate<typename Graph>\npair<vc<ll>, vc<int>> bfs01(Graph& G, ll v) {\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  vc<ll> dist(N, -1);\n  vc<int>\
    \ par(N, -1);\n  deque<int> que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while\
    \ (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n    for (auto&&\
    \ e : G[v]) {\n      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost)\
    \ {\n        dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n\
    \        if (e.cost == 0)\n          que.push_front(e.to);\n        else\n   \
    \       que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate<typename Graph>\npair<vc<ll>,\
    \ vc<int>> bfs01(Graph& G, ll v) {\n  assert(G.is_prepared());\n  int N = G.N;\n\
    \  vc<ll> dist(N, -1);\n  vc<int> par(N, -1);\n  deque<int> que;\n\n  dist[v]\
    \ = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n    auto v = que.front();\n\
    \    que.pop_front();\n    for (auto&& e : G[v]) {\n      if (dist[e.to] == -1\
    \ || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm] +\
    \ e.cost;\n        par[e.to] = e.frm;\n        if (e.cost == 0)\n          que.push_front(e.to);\n\
    \        else\n          que.push_back(e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/bfs01.hpp
  requiredBy:
  - graph/tree_diameter.hpp
  timestamp: '2022-02-12 21:55:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/tree_diameter.test.cpp
documentation_of: graph/bfs01.hpp
layout: document
redirect_from:
- /library/graph/bfs01.hpp
- /library/graph/bfs01.hpp.html
title: graph/bfs01.hpp
---
