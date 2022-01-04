---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator {\n  mt19937\
    \ mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 2 \"graph/chromatic.hpp\"\ntemplate\
    \ <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph& G) {\r\n  assert(G.is_prepared());\r\
    \n  // O(N2^N)\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\n  FOR(v, N) for (auto&&\
    \ e : G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset \u3067\u3042\u308B\
    \u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\u3052\r\n \
    \ vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1 << v) { dp[s | 1\
    \ << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\n  auto solve_p\
    \ = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s)) & 1 ?\
    \ 1 : -1);\r\n    FOR3(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1 << N)\
    \ {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\n   \
    \     sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum !=\
    \ 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\n\
    \  chmax(ANS, solve_p(0));\r\n\r\n  FOR_(TRIAL) {\r\n    RandomNumberGenerator\
    \ RNG;\r\n    int p;\r\n    while (1) {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\
    \n      if (primetest(p)) break;\r\n    }\r\n    chmax(ANS, solve_p(p));\r\n \
    \ }\r\n  return ANS;\r\n}\r\n"
  code: "#include \"other/random.hpp\"\r\ntemplate <typename Graph, int TRIAL = 0>\r\
    \nint chromatic_number(Graph& G) {\r\n  assert(G.is_prepared());\r\n  // O(N2^N)\r\
    \n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\n  FOR(v, N) for (auto&& e : G[v])\
    \ nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset \u3067\u3042\u308B\u3088\u3046\
    \u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\u3052\r\n  vc<int> dp(1\
    \ << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1 << v) { dp[s | 1 << v] = dp[s]\
    \ + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\n  auto solve_p = [&](int\
    \ p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s)) & 1 ? 1 : -1);\r\
    \n    FOR3(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1 << N) {\r\n     \
    \   pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\n        sum +=\
    \ pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum != 0) { return\
    \ k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\n  chmax(ANS,\
    \ solve_p(0));\r\n\r\n  FOR_(TRIAL) {\r\n    RandomNumberGenerator RNG;\r\n  \
    \  int p;\r\n    while (1) {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\n     \
    \ if (primetest(p)) break;\r\n    }\r\n    chmax(ANS, solve_p(p));\r\n  }\r\n\
    \  return ANS;\r\n}\r\n"
  dependsOn:
  - other/random.hpp
  isVerificationFile: false
  path: graph/chromatic.hpp
  requiredBy: []
  timestamp: '2022-01-05 00:09:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: graph/chromatic.hpp
layout: document
redirect_from:
- /library/graph/chromatic.hpp
- /library/graph/chromatic.hpp.html
title: graph/chromatic.hpp
---
