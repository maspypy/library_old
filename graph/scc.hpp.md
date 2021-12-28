---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ Graph* G;\n  };\n\n  Graph() {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\
    \n  void add(int frm, int to, T cost = 1, int i = -1) {\n    if (i == -1) i =\
    \ M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n\
    \  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared = true;\n   \
    \ indptr.assign(N + 1, 0);\n    for (auto&& [frm, to, cost, id]: edges) {\n  \
    \    indptr[frm + 1]++;\n      if (!directed) indptr[to + 1]++;\n    }\n    FOR(v,\
    \ N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& [frm, to, cost, id]: edges) {\n      csr_edges[counter[frm]++]\
    \ = {frm, to, cost, id};\n      if (!directed) csr_edges[counter[to]++] = {to,\
    \ frm, cost, id};\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e);\n    } else {\n    \
    \  print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e: (*this)[v]) print(e);\n    }\n  }\n\n  int size() { return\
    \ N; }\n};\n#line 3 \"graph/scc.hpp\"\n\ntemplate <class T> struct SCC {\n  T\
    \ &G;\n  ll N;\n  ll n_comp;\n  vc<int> comp_id;\n  vc<int> low;\n  vc<int> ord;\n\
    \  vc<int> visited;\n  ll now = 0;\n\n  SCC(T &G)\n      : G(G), N(G.N), n_comp(0),\
    \ comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {\n    assert(G.directed);\n    build();\n\
    \  }\n\n  ll operator[](ll v) { return comp_id[v]; }\n\n  void dfs(int v) {\n\
    \    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n    for\
    \ (auto e : G[v]) {\n      if (ord[e.to] == -1) {\n        dfs(e.to);\n      \
    \  chmin(low[v], low[e.to]);\n      } else {\n        chmin(low[v], ord[e.to]);\n\
    \      }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        ll u\
    \ = visited.back();\n        visited.pop_back();\n        ord[u] = N;\n      \
    \  comp_id[u] = n_comp;\n        if (u == v)\n          break;\n      }\n    \
    \  ++n_comp;\n    }\n  }\n\n  void build() {\n    FOR(v, N) {\n      if (ord[v]\
    \ == -1)\n        dfs(v);\n    }\n    FOR(v, N) comp_id[v] = n_comp - 1 - comp_id[v];\n\
    \  }\n\n  vc<vc<int>> comp() {\n    if (n_comp == 0)\n      build();\n    vc<vc<int>>\
    \ res;\n    res.resize(n_comp);\n    FOR(v, N) { res[comp_id[v]].eb(v); }\n  \
    \  return res;\n  };\n};\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <class T> struct SCC\
    \ {\n  T &G;\n  ll N;\n  ll n_comp;\n  vc<int> comp_id;\n  vc<int> low;\n  vc<int>\
    \ ord;\n  vc<int> visited;\n  ll now = 0;\n\n  SCC(T &G)\n      : G(G), N(G.N),\
    \ n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {\n    assert(G.directed);\n\
    \    build();\n  }\n\n  ll operator[](ll v) { return comp_id[v]; }\n\n  void dfs(int\
    \ v) {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n\
    \    for (auto e : G[v]) {\n      if (ord[e.to] == -1) {\n        dfs(e.to);\n\
    \        chmin(low[v], low[e.to]);\n      } else {\n        chmin(low[v], ord[e.to]);\n\
    \      }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        ll u\
    \ = visited.back();\n        visited.pop_back();\n        ord[u] = N;\n      \
    \  comp_id[u] = n_comp;\n        if (u == v)\n          break;\n      }\n    \
    \  ++n_comp;\n    }\n  }\n\n  void build() {\n    FOR(v, N) {\n      if (ord[v]\
    \ == -1)\n        dfs(v);\n    }\n    FOR(v, N) comp_id[v] = n_comp - 1 - comp_id[v];\n\
    \  }\n\n  vc<vc<int>> comp() {\n    if (n_comp == 0)\n      build();\n    vc<vc<int>>\
    \ res;\n    res.resize(n_comp);\n    FOR(v, N) { res[comp_id[v]].eb(v); }\n  \
    \  return res;\n  };\n};\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-12-29 02:24:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
