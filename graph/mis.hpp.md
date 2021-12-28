---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/maximum_independent_set.test.cpp
    title: test/library_checker/graph/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ N; }\n};\n#line 2 \"graph/mis.hpp\"\n\r\ntemplate <typename Graph>\r\nvector<int>\
    \ maximum_independent_set(Graph& G, int trial = 1000000) {\r\n  int N = G.N;\r\
    \n  vector<uint64_t> bit(N);\r\n  assert(N <= 64);\r\n  FOR(a, N) for (auto&&\
    \ e: G[a]) bit[a] |= uint64_t(1) << e.to;\r\n  vector<int> ord(N);\r\n  iota(begin(ord),\
    \ end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  int ret = 0;\r\n  uint64_t ver;\r\n  for (int i = 0; i < trial; i++) {\r\n\
    \    shuffle(begin(ord), end(ord), mt);\r\n    uint64_t used = 0;\r\n    int add\
    \ = 0;\r\n    for (int j: ord) {\r\n      if (used & bit[j]) continue;\r\n   \
    \   used |= uint64_t(1) << j;\r\n      ++add;\r\n    }\r\n    if (ret < add) {\r\
    \n      ret = add;\r\n      ver = used;\r\n    }\r\n  }\r\n  vector<int> ans;\r\
    \n  for (int i = 0; i < N; i++) {\r\n    if ((ver >> i) & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename Graph>\r\nvector<int>\
    \ maximum_independent_set(Graph& G, int trial = 1000000) {\r\n  int N = G.N;\r\
    \n  vector<uint64_t> bit(N);\r\n  assert(N <= 64);\r\n  FOR(a, N) for (auto&&\
    \ e: G[a]) bit[a] |= uint64_t(1) << e.to;\r\n  vector<int> ord(N);\r\n  iota(begin(ord),\
    \ end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  int ret = 0;\r\n  uint64_t ver;\r\n  for (int i = 0; i < trial; i++) {\r\n\
    \    shuffle(begin(ord), end(ord), mt);\r\n    uint64_t used = 0;\r\n    int add\
    \ = 0;\r\n    for (int j: ord) {\r\n      if (used & bit[j]) continue;\r\n   \
    \   used |= uint64_t(1) << j;\r\n      ++add;\r\n    }\r\n    if (ret < add) {\r\
    \n      ret = add;\r\n      ver = used;\r\n    }\r\n  }\r\n  vector<int> ans;\r\
    \n  for (int i = 0; i < N; i++) {\r\n    if ((ver >> i) & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/mis.hpp
  requiredBy: []
  timestamp: '2021-12-29 02:24:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/maximum_independent_set.test.cpp
documentation_of: graph/mis.hpp
layout: document
redirect_from:
- /library/graph/mis.hpp
- /library/graph/mis.hpp.html
title: graph/mis.hpp
---
