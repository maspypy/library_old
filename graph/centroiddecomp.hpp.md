---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T, bool directed\
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
    \    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
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
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 2 \"graph/centroiddecomp.hpp\"\
    \ntemplate <typename Graph>\r\nvector<int> centroid_decomposition(Graph& G) {\r\
    \n  // \u91CD\u5FC3\u5206\u89E3\u6728\u306B\u304A\u3051\u308B depth \u914D\u5217\
    \u3092\u8FD4\u3059\u3002\r\n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\
    \n  int N = G.N;\r\n  vc<int> dep(N, -1);\r\n  vc<int> sz(N);\r\n  vc<int> par(N,\
    \ -1);\r\n\r\n  auto find = [&](int v) -> int {\r\n    vc<int> V = {v};\r\n  \
    \  par[v] = -1;\r\n    int p = 0;\r\n    while (p < len(V)) {\r\n      int v =\
    \ V[p++];\r\n      sz[v] = 0;\r\n      for (auto&& [frm, to, cost, id]: G[v])\
    \ {\r\n        if (to == par[v] || dep[to] != -1) continue;\r\n        par[to]\
    \ = v;\r\n        V.eb(to);\r\n      }\r\n    }\r\n    while (len(V)) {\r\n  \
    \    int v = V.back();\r\n      V.pop_back();\r\n      sz[v] += 1;\r\n      if\
    \ (p - sz[v] <= p / 2) return v;\r\n      sz[par[v]] += sz[v];\r\n    }\r\n  \
    \  return -1;\r\n  };\r\n\r\n  vc<pair<int, int>> st = {{0, 0}};\r\n  while (len(st))\
    \ {\r\n    auto [lv, v] = st.back();\r\n    st.pop_back();\r\n    auto c = find(v);\r\
    \n    dep[c] = lv;\r\n    for (auto&& [frm, to, cost, id]: G[c]) {\r\n      if\
    \ (dep[to] == -1) st.eb(lv + 1, to);\r\n    }\r\n  }\r\n  return dep;\r\n}\n"
  code: "#include \"graph/base.hpp\"\r\ntemplate <typename Graph>\r\nvector<int> centroid_decomposition(Graph&\
    \ G) {\r\n  // \u91CD\u5FC3\u5206\u89E3\u6728\u306B\u304A\u3051\u308B depth \u914D\
    \u5217\u3092\u8FD4\u3059\u3002\r\n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\
    \n  int N = G.N;\r\n  vc<int> dep(N, -1);\r\n  vc<int> sz(N);\r\n  vc<int> par(N,\
    \ -1);\r\n\r\n  auto find = [&](int v) -> int {\r\n    vc<int> V = {v};\r\n  \
    \  par[v] = -1;\r\n    int p = 0;\r\n    while (p < len(V)) {\r\n      int v =\
    \ V[p++];\r\n      sz[v] = 0;\r\n      for (auto&& [frm, to, cost, id]: G[v])\
    \ {\r\n        if (to == par[v] || dep[to] != -1) continue;\r\n        par[to]\
    \ = v;\r\n        V.eb(to);\r\n      }\r\n    }\r\n    while (len(V)) {\r\n  \
    \    int v = V.back();\r\n      V.pop_back();\r\n      sz[v] += 1;\r\n      if\
    \ (p - sz[v] <= p / 2) return v;\r\n      sz[par[v]] += sz[v];\r\n    }\r\n  \
    \  return -1;\r\n  };\r\n\r\n  vc<pair<int, int>> st = {{0, 0}};\r\n  while (len(st))\
    \ {\r\n    auto [lv, v] = st.back();\r\n    st.pop_back();\r\n    auto c = find(v);\r\
    \n    dep[c] = lv;\r\n    for (auto&& [frm, to, cost, id]: G[c]) {\r\n      if\
    \ (dep[to] == -1) st.eb(lv + 1, to);\r\n    }\r\n  }\r\n  return dep;\r\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/centroiddecomp.hpp
  requiredBy: []
  timestamp: '2021-12-31 12:24:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroiddecomp.hpp
layout: document
redirect_from:
- /library/graph/centroiddecomp.hpp
- /library/graph/centroiddecomp.hpp.html
title: graph/centroiddecomp.hpp
---
