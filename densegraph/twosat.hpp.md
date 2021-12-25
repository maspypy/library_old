---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"densegraph/twosat.hpp\"\nstruct TwoSat {\r\n  vc<int> values;\r\
    \n\r\n  Graph<int> G;\r\n  TwoSat(ll n) {\r\n    G = Graph<int>(2 * n, 1);\r\n\
    \    values.assign(n, -1);\r\n  }\r\n  void add(int a, int b) {\r\n    a = (a\
    \ >= 0 ? 2 * a + 1 : 2 * (~a));\r\n    b = (b >= 0 ? 2 * b + 1 : 2 * (~b));\r\n\
    \    G.add(a ^ 1, b, 1, false);\r\n    G.add(b ^ 1, a, 1, false);\r\n  }\r\n \
    \ void set(int a) {\r\n    if (a >= 0)\r\n      values[a] = 1;\r\n    else\r\n\
    \      values[~a] = 0;\r\n    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));\r\n    G.add(a\
    \ ^ 1, a, 1, false);\r\n  }\r\n  void implies(int a, int b) { add(~a, b); }\r\n\
    \r\n  bool calc() {\r\n    ll n = len(values);\r\n    SCC<Graph<int>> scc(G);\r\
    \n    FOR(i, n) {\r\n      if (scc[2 * i] == scc[2 * i + 1]) return false;\r\n\
    \      values[i] = scc[2 * i] < scc[2 * i + 1];\r\n    }\r\n    return true;\r\
    \n  }\r\n};\n"
  code: "struct TwoSat {\r\n  vc<int> values;\r\n\r\n  Graph<int> G;\r\n  TwoSat(ll\
    \ n) {\r\n    G = Graph<int>(2 * n, 1);\r\n    values.assign(n, -1);\r\n  }\r\n\
    \  void add(int a, int b) {\r\n    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));\r\n  \
    \  b = (b >= 0 ? 2 * b + 1 : 2 * (~b));\r\n    G.add(a ^ 1, b, 1, false);\r\n\
    \    G.add(b ^ 1, a, 1, false);\r\n  }\r\n  void set(int a) {\r\n    if (a >=\
    \ 0)\r\n      values[a] = 1;\r\n    else\r\n      values[~a] = 0;\r\n    a = (a\
    \ >= 0 ? 2 * a + 1 : 2 * (~a));\r\n    G.add(a ^ 1, a, 1, false);\r\n  }\r\n \
    \ void implies(int a, int b) { add(~a, b); }\r\n\r\n  bool calc() {\r\n    ll\
    \ n = len(values);\r\n    SCC<Graph<int>> scc(G);\r\n    FOR(i, n) {\r\n     \
    \ if (scc[2 * i] == scc[2 * i + 1]) return false;\r\n      values[i] = scc[2 *\
    \ i] < scc[2 * i + 1];\r\n    }\r\n    return true;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: densegraph/twosat.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: densegraph/twosat.hpp
layout: document
redirect_from:
- /library/densegraph/twosat.hpp
- /library/densegraph/twosat.hpp.html
title: densegraph/twosat.hpp
---
