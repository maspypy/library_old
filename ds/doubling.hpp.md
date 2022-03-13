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
  bundledCode: "#line 1 \"ds/doubling.hpp\"\ntemplate <typename Monoid, int LOG>\r\
    \nstruct Doubling {\r\n  /*\r\n  \u72B6\u614B a \u304B\u3089 1 \u56DE\u64CD\u4F5C\
    \u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\u3057\u3001\u30E2\u30CE\
    \u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\r\n  */\r\n  using X\
    \ = typename Monoid::value_type;\r\n  int N;\r\n  bool is_prepared;\r\n  vvc<int>\
    \ TO;\r\n  vvc<X> DP;\r\n\r\n  Doubling(int N) : N(N), is_prepared(0) {\r\n  \
    \  TO.assign(LOG, vc<int>(N, -1));\r\n    DP.assign(LOG, vc<X>(N, Monoid::unit));\r\
    \n  }\r\n\r\n  void set(int i, int to, X x) {\r\n    assert(!is_prepared);\r\n\
    \    assert(-1 <= to && to < N);\r\n    TO[0][i] = to;\r\n    DP[0][i] = x;\r\n\
    \  }\r\n\r\n  void build() {\r\n    if (is_prepared) return;\r\n    is_prepared\
    \ = 1;\r\n    FOR(k, LOG - 1) {\r\n      FOR(v, N) {\r\n        int w = TO[k][v];\r\
    \n        if (w == -1) {\r\n          TO[k + 1][v] = -1;\r\n          DP[k + 1][v]\
    \ = DP[k][v];\r\n          continue;\r\n        }\r\n        TO[k + 1][v] = TO[k][w];\r\
    \n        DP[k + 1][v] = Monoid::op(DP[k][v], DP[k][w]);\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  pair<int, X> calc(int i, ll step) {\r\n    assert(is_prepared);\r\
    \n    assert(step < (1 << LOG));\r\n    X x = Monoid::unit;\r\n    FOR(k, LOG)\
    \ {\r\n      if (i == -1) break;\r\n      if (step && 1 << k) {\r\n        x =\
    \ Monoid::op(x, DP[k][i]);\r\n        i = TO[k][i];\r\n      }\r\n    }\r\n  \
    \  return {i, x};\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_step(F check,\
    \ int i) {\r\n    assert(is_prepared);\r\n    // step\u6570\r\n    X x = Monoid::unit;\r\
    \n    ll step = 0;\r\n    assert(check(x));\r\n    FOR_R(k, LOG) {\r\n      int\
    \ j = TO[k][i];\r\n      X y = Monoid::op(x, DP[k][i]);\r\n      if (check(y))\
    \ {\r\n        step |= 1 << k;\r\n        i = j;\r\n        x = y;\r\n       \
    \ assert(i != -1);\r\n      }\r\n    }\r\n    return step;\r\n  }\r\n\r\n  void\
    \ debug() {\r\n    print(\"TO\");\r\n    FOR(k, LOG) print(TO[k]);\r\n    print(\"\
    DP\");\r\n    FOR(k, LOG) print(DP[k]);\r\n  }\r\n};\n"
  code: "template <typename Monoid, int LOG>\r\nstruct Doubling {\r\n  /*\r\n  \u72B6\
    \u614B a \u304B\u3089 1 \u56DE\u64CD\u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B\
    \ b \u306B\u9077\u79FB\u3057\u3001\u30E2\u30CE\u30A4\u30C9\u306E\u5143 x \u3092\
    \u52A0\u3048\u308B\u3002\r\n  */\r\n  using X = typename Monoid::value_type;\r\
    \n  int N;\r\n  bool is_prepared;\r\n  vvc<int> TO;\r\n  vvc<X> DP;\r\n\r\n  Doubling(int\
    \ N) : N(N), is_prepared(0) {\r\n    TO.assign(LOG, vc<int>(N, -1));\r\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::unit));\r\n  }\r\n\r\n  void set(int i, int to, X x) {\r\n\
    \    assert(!is_prepared);\r\n    assert(-1 <= to && to < N);\r\n    TO[0][i]\
    \ = to;\r\n    DP[0][i] = x;\r\n  }\r\n\r\n  void build() {\r\n    if (is_prepared)\
    \ return;\r\n    is_prepared = 1;\r\n    FOR(k, LOG - 1) {\r\n      FOR(v, N)\
    \ {\r\n        int w = TO[k][v];\r\n        if (w == -1) {\r\n          TO[k +\
    \ 1][v] = -1;\r\n          DP[k + 1][v] = DP[k][v];\r\n          continue;\r\n\
    \        }\r\n        TO[k + 1][v] = TO[k][w];\r\n        DP[k + 1][v] = Monoid::op(DP[k][v],\
    \ DP[k][w]);\r\n      }\r\n    }\r\n  }\r\n\r\n  pair<int, X> calc(int i, ll step)\
    \ {\r\n    assert(is_prepared);\r\n    assert(step < (1 << LOG));\r\n    X x =\
    \ Monoid::unit;\r\n    FOR(k, LOG) {\r\n      if (i == -1) break;\r\n      if\
    \ (step && 1 << k) {\r\n        x = Monoid::op(x, DP[k][i]);\r\n        i = TO[k][i];\r\
    \n      }\r\n    }\r\n    return {i, x};\r\n  }\r\n\r\n  template <typename F>\r\
    \n  ll max_step(F check, int i) {\r\n    assert(is_prepared);\r\n    // step\u6570\
    \r\n    X x = Monoid::unit;\r\n    ll step = 0;\r\n    assert(check(x));\r\n \
    \   FOR_R(k, LOG) {\r\n      int j = TO[k][i];\r\n      X y = Monoid::op(x, DP[k][i]);\r\
    \n      if (check(y)) {\r\n        step |= 1 << k;\r\n        i = j;\r\n     \
    \   x = y;\r\n        assert(i != -1);\r\n      }\r\n    }\r\n    return step;\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"TO\");\r\n    FOR(k, LOG) print(TO[k]);\r\
    \n    print(\"DP\");\r\n    FOR(k, LOG) print(DP[k]);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/doubling.hpp
  requiredBy: []
  timestamp: '2022-03-14 01:33:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/doubling.hpp
layout: document
redirect_from:
- /library/ds/doubling.hpp
- /library/ds/doubling.hpp.html
title: ds/doubling.hpp
---
