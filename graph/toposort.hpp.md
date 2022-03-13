---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/degree.hpp
    title: graph/degree.hpp
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
    \ b, c);\n      }\n    }\n    prepare();\n  }\n\n  void read_parent(int off =\
    \ 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p, v);\n\
    \    }\n    prepare();\n  }\n\n  void prepare() {\n    assert(!prepared);\n  \
    \  prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n\
    \      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n\
    \    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 2 \"graph/degree.hpp\"\n\r\ntemplate <typename Graph>\r\
    \nvector<int> degree(Graph& G) {\r\n  vector<int> deg(G.N);\r\n  for(auto&& e\
    \ : G.edges) deg[e.frm]++, deg[e.to]++;\r\n  return deg;\r\n}\r\n\r\ntemplate\
    \ <typename Graph>\r\npair<vector<int>, vector<int>> degree_inout(Graph& G) {\r\
    \n  vector<int> indeg(G.N), outdeg(G.N);\r\n  for (auto&& e: G.edges) { indeg[e.to]++,\
    \ outdeg[e.frm]++; }\r\n  return {indeg, outdeg};\r\n}\r\n#line 3 \"graph/toposort.hpp\"\
    \n\ntemplate <typename Graph>\nvc<int> toposort(Graph& G) {\n  // DAG \u3058\u3083\
    \u306A\u304B\u3063\u305F\u3089\u7A7A\u914D\u5217\n  assert(G.is_prepared());\n\
    \  assert(G.is_directed());\n  auto [indeg, outdeg] = degree_inout(G);\n  vc<int>\
    \ V;\n  ll N = G.N;\n  FOR(v, N) if (indeg[v] == 0) V.eb(v);\n  ll p = 0;\n  while\
    \ (p < len(V)) {\n    auto v = V[p++];\n    for (auto&& e: G[v]) {\n      if (--indeg[e.to]\
    \ == 0) V.eb(e.to);\n    }\n  }\n  if(len(V) < N) {\n    V.clear();\n  }\n  return\
    \ V;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/degree.hpp\"\n\ntemplate <typename\
    \ Graph>\nvc<int> toposort(Graph& G) {\n  // DAG \u3058\u3083\u306A\u304B\u3063\
    \u305F\u3089\u7A7A\u914D\u5217\n  assert(G.is_prepared());\n  assert(G.is_directed());\n\
    \  auto [indeg, outdeg] = degree_inout(G);\n  vc<int> V;\n  ll N = G.N;\n  FOR(v,\
    \ N) if (indeg[v] == 0) V.eb(v);\n  ll p = 0;\n  while (p < len(V)) {\n    auto\
    \ v = V[p++];\n    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) V.eb(e.to);\n\
    \    }\n  }\n  if(len(V) < N) {\n    V.clear();\n  }\n  return V;\n}\n"
  dependsOn:
  - graph/base.hpp
  - graph/degree.hpp
  isVerificationFile: false
  path: graph/toposort.hpp
  requiredBy: []
  timestamp: '2022-03-14 00:26:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/toposort.hpp
- /library/graph/toposort.hpp.html
title: graph/toposort.hpp
---
