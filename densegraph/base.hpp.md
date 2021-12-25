---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: densegraph/scc.hpp
    title: densegraph/scc.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"densegraph/base.hpp\"\n\ntemplate <typename T> struct Graph\
    \ {\n  // only simple graph.\n  int N, M;\n  vector<vector<T>> G;\n  T none_val;\n\
    \  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false, T none_val =\
    \ -1)\n      : N(N), M(0), G(N, vector<int>(N, none_val)), none_val(none_val),\n\
    \        directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, bool check_mult\
    \ = true) {\n    if(check_mult) assert(G[frm][to] == none_val);\n    G[frm][to]\
    \ = cost;\n    if (!directed) {\n      G[to][frm] = cost;\n    }\n    ++M;\n \
    \ }\n\n  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v <<\
    \ \" :\";\n      for (auto e : G[v]) {\n        if (detail)\n          cout <<\
    \ \" (\" << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n     \
    \          << \")\";\n        else\n          cout << \" \" << e.to;\n      }\n\
    \      cout << \"\\n\";\n    }\n  }\n\n  int size() { return N; }\n  vector<T>\
    \ &operator[](int v) { return G[v]; }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct Graph {\n  // only simple graph.\n\
    \  int N, M;\n  vector<vector<T>> G;\n  T none_val;\n  bool directed;\n  Graph()\
    \ {}\n  Graph(int N, bool bl = false, T none_val = -1)\n      : N(N), M(0), G(N,\
    \ vector<int>(N, none_val)), none_val(none_val),\n        directed(bl) {}\n\n\
    \  void add(int frm, int to, T cost = 1, bool check_mult = true) {\n    if(check_mult)\
    \ assert(G[frm][to] == none_val);\n    G[frm][to] = cost;\n    if (!directed)\
    \ {\n      G[to][frm] = cost;\n    }\n    ++M;\n  }\n\n  void debug(bool detail\
    \ = false) {\n    FOR(v, N) {\n      cout << v << \" :\";\n      for (auto e :\
    \ G[v]) {\n        if (detail)\n          cout << \" (\" << e.frm << \",\" <<\
    \ e.to << \",\" << e.cost << \",\" << e.id\n               << \")\";\n       \
    \ else\n          cout << \" \" << e.to;\n      }\n      cout << \"\\n\";\n  \
    \  }\n  }\n\n  int size() { return N; }\n  vector<T> &operator[](int v) { return\
    \ G[v]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: densegraph/base.hpp
  requiredBy:
  - densegraph/scc.hpp
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: densegraph/base.hpp
layout: document
redirect_from:
- /library/densegraph/base.hpp
- /library/densegraph/base.hpp.html
title: densegraph/base.hpp
---
