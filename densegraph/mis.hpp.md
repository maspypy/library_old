---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: densegraph/base.hpp
    title: densegraph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/maximum_independent_set_dense.test.cpp
    title: test/library_checker/graph/maximum_independent_set_dense.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"densegraph/base.hpp\"\n\ntemplate <typename T> struct Graph\
    \ {\n  // only simple graph.\n  int N, M;\n  vector<vector<T>> G;\n  T none_val;\n\
    \  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false, T none_val =\
    \ 0)\n      : N(N), M(0), G(N, vector<int>(N, none_val)), none_val(none_val),\n\
    \        directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, bool check_mult\
    \ = true) {\n    if(check_mult) assert(G[frm][to] == none_val);\n    G[frm][to]\
    \ = cost;\n    if (!directed) {\n      G[to][frm] = cost;\n    }\n    ++M;\n \
    \ }\n\n  int size() { return N; }\n  vector<T> &operator[](int v) { return G[v];\
    \ }\n};\n#line 2 \"densegraph/mis.hpp\"\n\r\ntemplate <typename DenseGraph>\r\n\
    vector<int> maximum_independent_set(DenseGraph& G, int trial = 1000000) {\r\n\
    \  int N = G.N;\r\n  vector<uint64_t> bit(N);\r\n  assert(N <= 64);\r\n  FOR(a,\
    \ N) FOR(b, N) if (G[a][b]) bit[a] |= uint64_t(1) << b;\r\n  vector<int> ord(N);\r\
    \n  iota(begin(ord), end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  int ret = 0;\r\n  uint64_t ver;\r\n  for (int i = 0; i < trial; i++) {\r\n\
    \    shuffle(begin(ord), end(ord), mt);\r\n    uint64_t used = 0;\r\n    int add\
    \ = 0;\r\n    for (int j : ord) {\r\n      if (used & bit[j]) continue;\r\n  \
    \    used |= uint64_t(1) << j;\r\n      ++add;\r\n    }\r\n    if (ret < add)\
    \ {\r\n      ret = add;\r\n      ver = used;\r\n    }\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if ((ver >> i) & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  code: "#include \"densegraph/base.hpp\"\r\n\r\ntemplate <typename DenseGraph>\r\n\
    vector<int> maximum_independent_set(DenseGraph& G, int trial = 1000000) {\r\n\
    \  int N = G.N;\r\n  vector<uint64_t> bit(N);\r\n  assert(N <= 64);\r\n  FOR(a,\
    \ N) FOR(b, N) if (G[a][b]) bit[a] |= uint64_t(1) << b;\r\n  vector<int> ord(N);\r\
    \n  iota(begin(ord), end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  int ret = 0;\r\n  uint64_t ver;\r\n  for (int i = 0; i < trial; i++) {\r\n\
    \    shuffle(begin(ord), end(ord), mt);\r\n    uint64_t used = 0;\r\n    int add\
    \ = 0;\r\n    for (int j : ord) {\r\n      if (used & bit[j]) continue;\r\n  \
    \    used |= uint64_t(1) << j;\r\n      ++add;\r\n    }\r\n    if (ret < add)\
    \ {\r\n      ret = add;\r\n      ver = used;\r\n    }\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if ((ver >> i) & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  dependsOn:
  - densegraph/base.hpp
  isVerificationFile: false
  path: densegraph/mis.hpp
  requiredBy: []
  timestamp: '2021-12-27 04:19:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/maximum_independent_set_dense.test.cpp
documentation_of: densegraph/mis.hpp
layout: document
redirect_from:
- /library/densegraph/mis.hpp
- /library/densegraph/mis.hpp.html
title: densegraph/mis.hpp
---
