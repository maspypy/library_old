---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/shortest_path.test.cpp
    title: test/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ prepare() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n\
    \    auto counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for\
    \ (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 3 \"graph/dijkstra.hpp\"\
    \n\ntemplate <typename Graph>\npair<vector<typename Graph::cost_type>, vector<int>>\
    \ dijkstra(Graph& G, int v) {\n  auto N = G.N;\n  using T = typename Graph::cost_type;\n\
    \  vector<T> dist(N, -1);\n  vector<int> par(N, -1);\n  using P = pair<T, int>;\n\
    \n  priority_queue<P, vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n  que.push(mp(T(0),\
    \ v));\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n\
    \    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == -1 || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to], e.to));\n\
    \      }\n    }\n  }\n  return mp(dist, par);\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename Graph>\n\
    pair<vector<typename Graph::cost_type>, vector<int>> dijkstra(Graph& G, int v)\
    \ {\n  auto N = G.N;\n  using T = typename Graph::cost_type;\n  vector<T> dist(N,\
    \ -1);\n  vector<int> par(N, -1);\n  using P = pair<T, int>;\n\n  priority_queue<P,\
    \ vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n  que.push(mp(T(0), v));\n  while\
    \ (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n    if (dv\
    \ > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (dist[e.to] == -1\
    \ || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm] +\
    \ e.cost;\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to], e.to));\n\
    \      }\n    }\n  }\n  return mp(dist, par);\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-01-17 12:32:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/shortest_path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
