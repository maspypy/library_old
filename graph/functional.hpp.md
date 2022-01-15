---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
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
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n \
    \ int comp;\n  vc<int> size, par;\n  UnionFind(int n) : num(n), comp(n), size(n,\
    \ 1), par(n) {\n    iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n\
    \    while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n \
    \   }\n    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n \
    \ bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x == y)\
    \ { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x, y);\n   \
    \ size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n \
    \ }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i] = find(i);\n\
    \    return A;\n  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename\
    \ T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type\
    \ = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int>\
    \ indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\n  class OutgoingEdges\
    \ {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l),\
    \ r(r) {}\n\n    const edge_type* begin() const {\n      if (l == r) { return\
    \ 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type* end() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n\
    \  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    assert(!prepared && 0 <= frm && 0 <= to);\n    chmax(N,\
    \ frm + 1);\n    chmax(N, to + 1);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n\
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
    \    }\n  }\n};\n#line 3 \"graph/functional.hpp\"\n\r\ntemplate <typename T =\
    \ int>\r\nstruct FunctionalGraph {\r\n  int N, M;\r\n  Graph<T, 1> tree; // \u65B0\
    \u3057\u3044\u9802\u70B9 N \u3092\u6839\u3068\u3057\u3066\u8FFD\u52A0\u3057\u305F\
    \u6709\u5411\u6728\u3002\u9006\u5411\u304D\u306E\u8FBA\u306B\u306A\u308B\u3002\
    \r\n  // HLD<Graph<T, 1>> hld;\r\n  vc<int> TO;\r\n  vc<T> wt;\r\n  vc<int> root;\r\
    \n\r\n  FunctionalGraph() {}\r\n  FunctionalGraph(int N) : N(N), M(0), TO(N, -1),\
    \ wt(N), root(N, -1) {}\r\n\r\n  void add(int a, int b, T c = 1) {\r\n    assert(0\
    \ <= a && a < N);\r\n    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n\
    \    wt[a] = c;\r\n  }\r\n\r\n  void build() {\r\n    assert(N == M);\r\n    UnionFind\
    \ uf(N);\r\n    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v] = v; }\r\n    FOR(v,\
    \ N) if (root[v] == v) root[uf[v]] = v;\r\n    FOR(v, N) root[v] = root[uf[v]];\r\
    \n\r\n    tree = Graph<T, 1>(N + 1);\r\n    FOR(v, N) {\r\n      if (root[v] !=\
    \ v)\r\n        tree.add(TO[v], v);\r\n      else\r\n        tree.add(N, v);\r\
    \n    }\r\n    tree.prepare();\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    TO\", TO);\r\n    print(\"root\");\r\n    print(root);\r\n    print(\"\u6839\u3092\
    \u8FFD\u52A0\u3057\u305F\u6728 tree\");\r\n    tree.debug();\r\n  }\r\n};\r\n"
  code: "#include \"ds/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n\r\ntemplate\
    \ <typename T = int>\r\nstruct FunctionalGraph {\r\n  int N, M;\r\n  Graph<T,\
    \ 1> tree; // \u65B0\u3057\u3044\u9802\u70B9 N \u3092\u6839\u3068\u3057\u3066\u8FFD\
    \u52A0\u3057\u305F\u6709\u5411\u6728\u3002\u9006\u5411\u304D\u306E\u8FBA\u306B\
    \u306A\u308B\u3002\r\n  // HLD<Graph<T, 1>> hld;\r\n  vc<int> TO;\r\n  vc<T> wt;\r\
    \n  vc<int> root;\r\n\r\n  FunctionalGraph() {}\r\n  FunctionalGraph(int N) :\
    \ N(N), M(0), TO(N, -1), wt(N), root(N, -1) {}\r\n\r\n  void add(int a, int b,\
    \ T c = 1) {\r\n    assert(0 <= a && a < N);\r\n    assert(TO[a] == -1);\r\n \
    \   ++M;\r\n    TO[a] = b;\r\n    wt[a] = c;\r\n  }\r\n\r\n  void build() {\r\n\
    \    assert(N == M);\r\n    UnionFind uf(N);\r\n    FOR(v, N) if (!uf.merge(v,\
    \ TO[v])) { root[v] = v; }\r\n    FOR(v, N) if (root[v] == v) root[uf[v]] = v;\r\
    \n    FOR(v, N) root[v] = root[uf[v]];\r\n\r\n    tree = Graph<T, 1>(N + 1);\r\
    \n    FOR(v, N) {\r\n      if (root[v] != v)\r\n        tree.add(TO[v], v);\r\n\
    \      else\r\n        tree.add(N, v);\r\n    }\r\n    tree.prepare();\r\n  }\r\
    \n\r\n  void debug() {\r\n    print(\"TO\", TO);\r\n    print(\"root\");\r\n \
    \   print(root);\r\n    print(\"\u6839\u3092\u8FFD\u52A0\u3057\u305F\u6728 tree\"\
    );\r\n    tree.debug();\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/unionfind.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/functional.hpp
  requiredBy: []
  timestamp: '2022-01-16 04:25:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional.hpp
layout: document
redirect_from:
- /library/graph/functional.hpp
- /library/graph/functional.hpp.html
title: graph/functional.hpp
---
