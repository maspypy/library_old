---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C_warshallfloyd.test.cpp
    title: test/aoj/GRL_1_C_warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/17_warshall_floyd.test.cpp
    title: test/yukicoder/17_warshall_floyd.test.cpp
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
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  FOR_(M) {\n      INT(a, b);\n      a -= off, b -= off;\n      if (!wt) {\n\
    \        add(a, b);\n      } else {\n        T c;\n        read(c);\n        add(a,\
    \ b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int off = 1)\
    \ {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p, v);\n \
    \   }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 3 \"graph/warshall_floyd.hpp\"\n\n/*\n\u8CA0\u8FBA\u304C\
    \u3042\u3063\u3066\u3082\u8CA0\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070\u6B63\
    \u3057\u304F\u52D5\u4F5C\u3059\u308B\u3002\n\u8CA0\u9589\u8DEF\u304C\u3042\u308B\
    \u304B\u3069\u3046\u304B\u306F\u3001dist[v][v] < 0 \u3068\u306A\u308B v \u304C\
    \u3042\u308B\u304B\u3069\u3046\u304B\u3067\u5224\u5B9A\u3002\n*/\ntemplate <typename\
    \ T, T INF, typename Graph>\nvc<vc<T>> warshall_floyd(Graph& G) {\n  ll N = G.N;\n\
    \  vv(T, dist, N, N, INF);\n  FOR(v, N) {\n    dist[v][v] = 0;\n    for (auto&&\
    \ e: G[v]) dist[v][e.to] = e.cost;\n  }\n  FOR(k, N) FOR(i, N) {\n    if (dist[i][k]\
    \ == INF) continue;\n    FOR(j, N) {\n      if (dist[k][j] == INF) continue;\n\
    \      chmin(dist[i][j], dist[i][k] + dist[k][j]);\n    }\n  }\n  return dist;\n\
    }\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\n/*\n\u8CA0\u8FBA\u304C\u3042\
    \u3063\u3066\u3082\u8CA0\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070\u6B63\u3057\
    \u304F\u52D5\u4F5C\u3059\u308B\u3002\n\u8CA0\u9589\u8DEF\u304C\u3042\u308B\u304B\
    \u3069\u3046\u304B\u306F\u3001dist[v][v] < 0 \u3068\u306A\u308B v \u304C\u3042\
    \u308B\u304B\u3069\u3046\u304B\u3067\u5224\u5B9A\u3002\n*/\ntemplate <typename\
    \ T, T INF, typename Graph>\nvc<vc<T>> warshall_floyd(Graph& G) {\n  ll N = G.N;\n\
    \  vv(T, dist, N, N, INF);\n  FOR(v, N) {\n    dist[v][v] = 0;\n    for (auto&&\
    \ e: G[v]) dist[v][e.to] = e.cost;\n  }\n  FOR(k, N) FOR(i, N) {\n    if (dist[i][k]\
    \ == INF) continue;\n    FOR(j, N) {\n      if (dist[k][j] == INF) continue;\n\
    \      chmin(dist[i][j], dist[i][k] + dist[k][j]);\n    }\n  }\n  return dist;\n\
    }"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2022-04-15 04:57:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/17_warshall_floyd.test.cpp
  - test/aoj/GRL_1_C_warshallfloyd.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
