---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/scc.test.cpp
    title: test/library_checker/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \  assert(!prepared);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to,\
    \ cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& [frm, to,\
    \ cost, id]: edges) {\n      indptr[frm + 1]++;\n      if (!directed) indptr[to\
    \ + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter\
    \ = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&& [frm, to,\
    \ cost, id]: edges) {\n      csr_edges[counter[frm]++] = {frm, to, cost, id};\n\
    \      if (!directed) csr_edges[counter[to]++] = {to, frm, cost, id};\n    }\n\
    \  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n   \
    \ return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e);\n   \
    \ }\n  }\n\n  int size() { return N; }\n};\n#line 3 \"graph/scc.hpp\"\n\ntemplate\
    \ <typename Graph>\nstruct SCC {\n  Graph &G;\n  int N;\n  int cnt;\n  vc<int>\
    \ comp;\n  vc<int> low;\n  vc<int> ord;\n  vc<int> visited;\n  int now = 0;\n\n\
    \  SCC(Graph &G)\n      : G(G), N(G.N), cnt(0), comp(G.N, 0), low(G.N, 0), ord(G.N,\
    \ -1) {\n    assert(G.is_directed());\n    assert(G.is_prepared());\n    build();\n\
    \  }\n\n  int operator[](int v) { return comp[v]; }\n\n  void dfs(int v) {\n \
    \   low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n    for\
    \ (auto &&[frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n        dfs(to);\n\
    \        chmin(low[v], low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n\
    \      }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        int u\
    \ = visited.back();\n        visited.pop_back();\n        ord[u] = N;\n      \
    \  comp[u] = cnt;\n        if (u == v) break;\n      }\n      ++cnt;\n    }\n\
    \  }\n\n  void build() {\n    FOR(v, N) {\n      if (ord[v] == -1) dfs(v);\n \
    \   }\n    FOR(v, N) comp[v] = cnt - 1 - comp[v];\n  }\n};\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename Graph>\n\
    struct SCC {\n  Graph &G;\n  int N;\n  int cnt;\n  vc<int> comp;\n  vc<int> low;\n\
    \  vc<int> ord;\n  vc<int> visited;\n  int now = 0;\n\n  SCC(Graph &G)\n     \
    \ : G(G), N(G.N), cnt(0), comp(G.N, 0), low(G.N, 0), ord(G.N, -1) {\n    assert(G.is_directed());\n\
    \    assert(G.is_prepared());\n    build();\n  }\n\n  int operator[](int v) {\
    \ return comp[v]; }\n\n  void dfs(int v) {\n    low[v] = now;\n    ord[v] = now;\n\
    \    ++now;\n    visited.eb(v);\n    for (auto &&[frm, to, cost, id]: G[v]) {\n\
    \      if (ord[to] == -1) {\n        dfs(to);\n        chmin(low[v], low[to]);\n\
    \      } else {\n        chmin(low[v], ord[to]);\n      }\n    }\n    if (low[v]\
    \ == ord[v]) {\n      while (1) {\n        int u = visited.back();\n        visited.pop_back();\n\
    \        ord[u] = N;\n        comp[u] = cnt;\n        if (u == v) break;\n   \
    \   }\n      ++cnt;\n    }\n  }\n\n  void build() {\n    FOR(v, N) {\n      if\
    \ (ord[v] == -1) dfs(v);\n    }\n    FOR(v, N) comp[v] = cnt - 1 - comp[v];\n\
    \  }\n};\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-12-29 03:03:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---