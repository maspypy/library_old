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
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 2 \"graph/eulerwalk.hpp\"\
    \n\r\ntemplate <typename T>\r\nvi euler_walk(Graph<T>& G) {\r\n  /*\r\n  \u9802\
    \u70B9\u756A\u53F7\u306E\u5217\u3092\u8FD4\u3059\u3002\u6709\u5411\u30FB\u7121\
    \u5411\u4E21\u5BFE\u5FDC\u3002\r\n  \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306B\u306F\u3001\u7A7A\u3092\u8FD4\u3059\u3002\r\n  \u8FBA\u304C 0 \u500B\u306E\
    \u5834\u5408\u306B\u306F {0} \u3092\u8FD4\u3059\u3002\r\n  */\r\n  ll N = G.N,\
    \ M = G.M;\r\n  if (M == 0) return {0};\r\n  vi deg(N);\r\n  for (auto&& e: G.edges)\
    \ {\r\n    if (G.directed) {\r\n      deg[e.frm]++, deg[e.to]--;\r\n    } else\
    \ {\r\n      deg[e.frm]++, deg[e.to]++;\r\n    }\r\n  }\r\n\r\n  ll s = max_element(all(deg))\
    \ - deg.begin();\r\n  if (deg[s] == 0) s = G.edges[0].frm;\r\n\r\n  vi D(N), its(N),\
    \ eu(M), ret, st = {s};\r\n  ++D[s];\r\n  while (!st.empty()) {\r\n    ll x =\
    \ st.back(), y, e, &it = its[x], end = len(G[x]);\r\n    if (it == end) {\r\n\
    \      ret.eb(x);\r\n      st.pop_back();\r\n      continue;\r\n    }\r\n    auto\
    \ ee = G[x][it++];\r\n    y = ee.to, e = ee.id;\r\n    if (!eu[e]) {\r\n     \
    \ D[x]--, D[y]++;\r\n      eu[e] = 1;\r\n      st.eb(y);\r\n    }\r\n  }\r\n \
    \ for (auto&& x: D)\r\n    if (x < 0) return {};\r\n  if (len(ret) != M + 1) return\
    \ {};\r\n  reverse(all(ret));\r\n  return ret;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename T>\r\nvi euler_walk(Graph<T>&\
    \ G) {\r\n  /*\r\n  \u9802\u70B9\u756A\u53F7\u306E\u5217\u3092\u8FD4\u3059\u3002\
    \u6709\u5411\u30FB\u7121\u5411\u4E21\u5BFE\u5FDC\u3002\r\n  \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306B\u306F\u3001\u7A7A\u3092\u8FD4\u3059\u3002\r\n \
    \ \u8FBA\u304C 0 \u500B\u306E\u5834\u5408\u306B\u306F {0} \u3092\u8FD4\u3059\u3002\
    \r\n  */\r\n  ll N = G.N, M = G.M;\r\n  if (M == 0) return {0};\r\n  vi deg(N);\r\
    \n  for (auto&& e: G.edges) {\r\n    if (G.directed) {\r\n      deg[e.frm]++,\
    \ deg[e.to]--;\r\n    } else {\r\n      deg[e.frm]++, deg[e.to]++;\r\n    }\r\n\
    \  }\r\n\r\n  ll s = max_element(all(deg)) - deg.begin();\r\n  if (deg[s] == 0)\
    \ s = G.edges[0].frm;\r\n\r\n  vi D(N), its(N), eu(M), ret, st = {s};\r\n  ++D[s];\r\
    \n  while (!st.empty()) {\r\n    ll x = st.back(), y, e, &it = its[x], end = len(G[x]);\r\
    \n    if (it == end) {\r\n      ret.eb(x);\r\n      st.pop_back();\r\n      continue;\r\
    \n    }\r\n    auto ee = G[x][it++];\r\n    y = ee.to, e = ee.id;\r\n    if (!eu[e])\
    \ {\r\n      D[x]--, D[y]++;\r\n      eu[e] = 1;\r\n      st.eb(y);\r\n    }\r\
    \n  }\r\n  for (auto&& x: D)\r\n    if (x < 0) return {};\r\n  if (len(ret) !=\
    \ M + 1) return {};\r\n  reverse(all(ret));\r\n  return ret;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/eulerwalk.hpp
  requiredBy: []
  timestamp: '2022-01-01 12:00:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/eulerwalk.hpp
layout: document
redirect_from:
- /library/graph/eulerwalk.hpp
- /library/graph/eulerwalk.hpp.html
title: graph/eulerwalk.hpp
---
