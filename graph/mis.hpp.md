---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a),\
    \ to(b), cost(c), id(d) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n  int\
    \ N, M;\n  using edge_t = Edge<T>;\n  vector<edge_t> edges;\n  vector<vector<edge_t>>\
    \ G;\n  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false) : N(N),\
    \ M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    if (i == -1) i = M;\n    auto e = edge_t(frm, to, cost, i);\n \
    \   edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n      auto e_rev =\
    \ edge_t(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n    ++M;\n  }\n\n\
    \  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v << \" :\"\
    ;\n      for (auto e: G[v]) {\n        if (detail)\n          cout << \" (\" <<\
    \ e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id << \")\";\n     \
    \   else\n          cout << \" \" << e.to;\n      }\n      cout << \"\\n\";\n\
    \    }\n  }\n\n  vector<int> degrees() {\n    vector<int> deg(N);\n    for (auto&&\
    \ e: edges) {\n      deg[e.frm]++;\n      deg[e.to]++;\n    }\n    return deg;\n\
    \  }\n\n  int size() { return N; }\n\n  vector<edge_t>& operator[](int v) { return\
    \ G[v]; }\n};\n#line 2 \"graph/mis.hpp\"\n\r\ntemplate <typename Graph>\r\nvector<int>\
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
  timestamp: '2021-12-27 18:35:27+09:00'
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
