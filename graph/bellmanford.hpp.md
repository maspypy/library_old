---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \    }\n  }\n};\n#line 3 \"graph/bellmanford.hpp\"\n\n// \u5358\u4E00\u59CB\u70B9\
    \u6700\u77ED\u8DEF\u3002\u8CA0\u9589\u8DEF\u3042\u308A\u3067\u3082\u3088\u3044\
    \u3002O(NM) \u6642\u9593\u3002\n// \u5230\u9054\u4E0D\u53EF\u80FD\uFF1AINF\n//\
    \ \u8CA0\u9589\u8DEF\u3092\u7D4C\u7531\u3057\u3066\u3044\u304F\u3089\u3067\u3082\
    \u5C0F\u3055\u304F\u3067\u304D\u308B\uFF1A-INF\ntemplate <typename T, T INF, typename\
    \ Graph>\nvc<T> BellmanFord(Graph& G, int s) {\n  int N = G.N;\n  vc<T> dist(N,\
    \ INF);\n  dist[s] = 0;\n  int loop = 0;\n  while (1) {\n    ++loop;\n    bool\
    \ upd = 0;\n    FOR(v, N) {\n      if (dist[v] == INF) continue;\n      for (auto&&\
    \ e: G[v]) {\n        T before = dist[e.to];\n        T after = dist[v] + e.cost;\n\
    \        chmax(after, -INF);\n        if (before > after) {\n          upd = 1;\n\
    \          if (loop >= N) after = -INF;\n          dist[e.to] = after;\n     \
    \   }\n      }\n    }\n    if (!upd) break;\n  }\n  return dist;\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\n// \u5358\u4E00\u59CB\u70B9\u6700\
    \u77ED\u8DEF\u3002\u8CA0\u9589\u8DEF\u3042\u308A\u3067\u3082\u3088\u3044\u3002\
    O(NM) \u6642\u9593\u3002\n// \u5230\u9054\u4E0D\u53EF\u80FD\uFF1AINF\n// \u8CA0\
    \u9589\u8DEF\u3092\u7D4C\u7531\u3057\u3066\u3044\u304F\u3089\u3067\u3082\u5C0F\
    \u3055\u304F\u3067\u304D\u308B\uFF1A-INF\ntemplate <typename T, T INF, typename\
    \ Graph>\nvc<T> BellmanFord(Graph& G, int s) {\n  int N = G.N;\n  vc<T> dist(N,\
    \ INF);\n  dist[s] = 0;\n  int loop = 0;\n  while (1) {\n    ++loop;\n    bool\
    \ upd = 0;\n    FOR(v, N) {\n      if (dist[v] == INF) continue;\n      for (auto&&\
    \ e: G[v]) {\n        T before = dist[e.to];\n        T after = dist[v] + e.cost;\n\
    \        chmax(after, -INF);\n        if (before > after) {\n          upd = 1;\n\
    \          if (loop >= N) after = -INF;\n          dist[e.to] = after;\n     \
    \   }\n      }\n    }\n    if (!upd) break;\n  }\n  return dist;\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/bellmanford.hpp
  requiredBy: []
  timestamp: '2022-04-14 18:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellmanford.hpp
layout: document
redirect_from:
- /library/graph/bellmanford.hpp
- /library/graph/bellmanford.hpp.html
title: graph/bellmanford.hpp
---
