---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 2 \"ds/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int num;\n  int comp;\n  vc<int> size, par;\n  UnionFind(int\
    \ n) : num(n), comp(n), size(n, 1), par(n) {\n    iota(par.begin(), par.end(),\
    \ 0);\n  }\n  int find(int x) {\n    while (par[x] != x) {\n      par[x] = par[par[x]];\n\
    \      x = par[x];\n    }\n    return x;\n  }\n\n  int operator[](int x) { return\
    \ find(x); }\n\n  bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n\
    \    if (x == y) { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x,\
    \ y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return\
    \ true;\n  }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i]\
    \ = find(i);\n    return A;\n  }\n};\n#line 3 \"graph/check_bipartite.hpp\"\n\r\
    \ntemplate <typename Graph>\r\nvc<int> check_bipartite(Graph& G) {\r\n  // \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u5224\u5B9A + \u5FA9\u5143\r\n  // \u4E8C\u90E8\u30B0\
    \u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\u306F\u3001-1 \u57CB\
    \u3081\r\n  assert(G.is_prepared());\r\n\r\n  int n = G.N;\r\n  UnionFind uf(2\
    \ * n);\r\n  for (auto&& e: G.edges) {\r\n    int u = e.frm, v = e.to;\r\n   \
    \ if (e.cost == 0) uf.merge(u, v), uf.merge(u + n, v + n);\r\n    if (e.cost !=\
    \ 0) uf.merge(u + n, v), uf.merge(u, v + n);\r\n  }\r\n\r\n  vc<int> color(2 *\
    \ n, -1);\r\n  FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {\r\n    color[uf[v]]\
    \ = 0;\r\n    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v, n) color[v] = color[uf[v]];\r\
    \n  color.resize(n);\r\n  FOR(v, n) if (uf[v] == uf[v + n]) return {};\r\n  return\
    \ color;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n#include \"ds/unionfind.hpp\"\r\n\r\ntemplate\
    \ <typename Graph>\r\nvc<int> check_bipartite(Graph& G) {\r\n  // \u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u5224\u5B9A + \u5FA9\u5143\r\n  // \u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\u306F\u3001-1 \u57CB\u3081\
    \r\n  assert(G.is_prepared());\r\n\r\n  int n = G.N;\r\n  UnionFind uf(2 * n);\r\
    \n  for (auto&& e: G.edges) {\r\n    int u = e.frm, v = e.to;\r\n    if (e.cost\
    \ == 0) uf.merge(u, v), uf.merge(u + n, v + n);\r\n    if (e.cost != 0) uf.merge(u\
    \ + n, v), uf.merge(u, v + n);\r\n  }\r\n\r\n  vc<int> color(2 * n, -1);\r\n \
    \ FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {\r\n    color[uf[v]] = 0;\r\n\
    \    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v, n) color[v] = color[uf[v]];\r\n\
    \  color.resize(n);\r\n  FOR(v, n) if (uf[v] == uf[v + n]) return {};\r\n  return\
    \ color;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  - ds/unionfind.hpp
  isVerificationFile: false
  path: graph/check_bipartite.hpp
  requiredBy:
  - flow/bipartite.hpp
  timestamp: '2022-02-12 21:55:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/bipartitematching.test.cpp
documentation_of: graph/check_bipartite.hpp
layout: document
redirect_from:
- /library/graph/check_bipartite.hpp
- /library/graph/check_bipartite.hpp.html
title: graph/check_bipartite.hpp
---
