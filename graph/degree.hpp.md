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
    \ }\n  }\n\n  int size() { return N; }\n};\n#line 2 \"graph/degree.hpp\"\n\r\n\
    template <typename Graph>\r\nvector<int> degree(Graph& G) {\r\n  vector<int> deg(N);\r\
    \n  FOR(v, N) deg[v] = len(G[v]);\r\n  return deg;\r\n}\r\n\r\ntemplate <typename\
    \ Graph>\r\npair<vector<int>, vector<int>> degree_inout(Graph& G) {\r\n  vector<int>\
    \ indeg(N), outdeg(N);\r\n  for (auto&& e: G.edges) { indeg[e.to]++, outdeg[e.frm]++;\
    \ }\r\n  return {indeg, outdeg};\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename Graph>\r\nvector<int>\
    \ degree(Graph& G) {\r\n  vector<int> deg(N);\r\n  FOR(v, N) deg[v] = len(G[v]);\r\
    \n  return deg;\r\n}\r\n\r\ntemplate <typename Graph>\r\npair<vector<int>, vector<int>>\
    \ degree_inout(Graph& G) {\r\n  vector<int> indeg(N), outdeg(N);\r\n  for (auto&&\
    \ e: G.edges) { indeg[e.to]++, outdeg[e.frm]++; }\r\n  return {indeg, outdeg};\r\
    \n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/degree.hpp
  requiredBy: []
  timestamp: '2021-12-29 03:03:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/degree.hpp
layout: document
redirect_from:
- /library/graph/degree.hpp
- /library/graph/degree.hpp.html
title: graph/degree.hpp
---
