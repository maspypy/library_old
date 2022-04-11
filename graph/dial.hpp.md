---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_12_B_dial.test.cpp
    title: test/aoj/ALDS1_12_B_dial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dial.hpp\"\n// not verified\r\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int\
    \ N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\
    \n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l,\
    \ int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n     \
    \ if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const\
    \ edge_type* end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared\
    \ && 0 <= frm && 0 <= to);\n    chmax(N, frm + 1);\n    chmax(N, to + 1);\n  \
    \  if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    FOR_(M) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int\
    \ off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p,\
    \ v);\n    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n\
    \    csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n     \
    \ csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n        csr_edges[counter[e.to]++]\
    \ = edge_type({e.to, e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int\
    \ v) const {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n\
    \  }\n\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 3 \"graph/dial.hpp\"\ntemplate <typename Graph>\r\npair<vector<typename\
    \ Graph::cost_type>, vector<int>> dial(Graph& G, int s) {\r\n  using COST = typename\
    \ Graph::cost_type;\r\n  assert(G.is_prepared());\r\n  ll W = 0;\r\n  ll N = G.N;\r\
    \n  for (auto&& e: G.edges) chmax(W, e.cost);\r\n  vc<int> S(N * W + 2, -1);\r\
    \n  vc<int> T(N * W + 2, -1);\r\n  vc<int> prev(N);\r\n  vc<int> nxt(N);\r\n \
    \ vc<COST> dist(N, W * N + 1);\r\n  vc<int> par(N, -1);\r\n  dist[s] = 0;\r\n\
    \  auto add = [&](ll v) -> void {\r\n    ll d = dist[v];\r\n    prev[v] = T[d];\r\
    \n    if (T[d] != -1) nxt[T[d]] = v;\r\n    T[d] = v;\r\n    if (S[d] == -1) S[d]\
    \ = v;\r\n    nxt[v] = -1;\r\n  };\r\n  auto rm = [&](ll v) -> void {\r\n    ll\
    \ d = dist[v];\r\n    if (prev[v] != -1) nxt[prev[v]] = nxt[v];\r\n    if (nxt[v]\
    \ != -1) prev[nxt[v]] = prev[v];\r\n    if (S[d] == v) S[d] = nxt[v];\r\n    if\
    \ (T[d] == v) T[d] = prev[v];\r\n  };\r\n  FOR(v, N) add(v);\r\n\r\n  FOR(d, N\
    \ * W) {\r\n    ll v = S[d];\r\n    while (v != -1) {\r\n      for (auto&& e:\
    \ G[v]) {\r\n        ll w = e.to;\r\n        ll dw = d + e.cost;\r\n        if\
    \ (dw < dist[w]) {\r\n          par[w] = v;\r\n          rm(w);\r\n          dist[w]\
    \ = dw;\r\n          add(w);\r\n        }\r\n      }\r\n      v = nxt[v];\r\n\
    \    }\r\n  }\r\n  FOR(v, N) if (dist[v] > N * W) dist[v] = -1;\r\n  return {dist,\
    \ par};\r\n}\n"
  code: "// not verified\r\n#include \"graph/base.hpp\"\r\ntemplate <typename Graph>\r\
    \npair<vector<typename Graph::cost_type>, vector<int>> dial(Graph& G, int s) {\r\
    \n  using COST = typename Graph::cost_type;\r\n  assert(G.is_prepared());\r\n\
    \  ll W = 0;\r\n  ll N = G.N;\r\n  for (auto&& e: G.edges) chmax(W, e.cost);\r\
    \n  vc<int> S(N * W + 2, -1);\r\n  vc<int> T(N * W + 2, -1);\r\n  vc<int> prev(N);\r\
    \n  vc<int> nxt(N);\r\n  vc<COST> dist(N, W * N + 1);\r\n  vc<int> par(N, -1);\r\
    \n  dist[s] = 0;\r\n  auto add = [&](ll v) -> void {\r\n    ll d = dist[v];\r\n\
    \    prev[v] = T[d];\r\n    if (T[d] != -1) nxt[T[d]] = v;\r\n    T[d] = v;\r\n\
    \    if (S[d] == -1) S[d] = v;\r\n    nxt[v] = -1;\r\n  };\r\n  auto rm = [&](ll\
    \ v) -> void {\r\n    ll d = dist[v];\r\n    if (prev[v] != -1) nxt[prev[v]] =\
    \ nxt[v];\r\n    if (nxt[v] != -1) prev[nxt[v]] = prev[v];\r\n    if (S[d] ==\
    \ v) S[d] = nxt[v];\r\n    if (T[d] == v) T[d] = prev[v];\r\n  };\r\n  FOR(v,\
    \ N) add(v);\r\n\r\n  FOR(d, N * W) {\r\n    ll v = S[d];\r\n    while (v != -1)\
    \ {\r\n      for (auto&& e: G[v]) {\r\n        ll w = e.to;\r\n        ll dw =\
    \ d + e.cost;\r\n        if (dw < dist[w]) {\r\n          par[w] = v;\r\n    \
    \      rm(w);\r\n          dist[w] = dw;\r\n          add(w);\r\n        }\r\n\
    \      }\r\n      v = nxt[v];\r\n    }\r\n  }\r\n  FOR(v, N) if (dist[v] > N *\
    \ W) dist[v] = -1;\r\n  return {dist, par};\r\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/dial.hpp
  requiredBy: []
  timestamp: '2022-03-19 16:40:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_12_B_dial.test.cpp
documentation_of: graph/dial.hpp
layout: document
redirect_from:
- /library/graph/dial.hpp
- /library/graph/dial.hpp.html
title: graph/dial.hpp
---
