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
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a),\
    \ to(b), cost(c), id(d) {}\n};\n\ntemplate <typename T, bool directed = false>\n\
    struct Graph {\n  int N, M;\n  using value_type = T;\n  using edge_type = Edge<T>;\n\
    \  vector<edge_type> edges;\n  vector<vector<edge_type>> G;\n  Graph() {}\n  Graph(int\
    \ N) : N(N), M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    if (i == -1) i = M;\n    auto e = edge_type(frm, to,\
    \ cost, i);\n    edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n     \
    \ auto e_rev = edge_type(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n \
    \   ++M;\n  }\n\n  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout\
    \ << v << \" :\";\n      for (auto e: G[v]) {\n        if (detail)\n         \
    \ cout << \" (\" << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n\
    \               << \")\";\n        else\n          cout << \" \" << e.to;\n  \
    \    }\n      cout << \"\\n\";\n    }\n  }\n  int size() { return N; }\n\n  vector<edge_type>&\
    \ operator[](int v) { return G[v]; }\n};\n#line 2 \"graph/degree.hpp\"\n\r\ntemplate\
    \ <typename Graph>\r\nvector<int> degree(Graph& G) {\r\n  vector<int> deg(N);\r\
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
  timestamp: '2021-12-29 00:40:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/degree.hpp
layout: document
redirect_from:
- /library/graph/degree.hpp
- /library/graph/degree.hpp.html
title: graph/degree.hpp
---
