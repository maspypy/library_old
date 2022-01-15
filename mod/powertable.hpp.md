---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':x:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/primetable.hpp\"\nvc<int>& primetable(int LIM) {\n  ++LIM;\n\
    \  const int S = 32768;\n  static int done = 2;\n  static vc<int> primes = {2},\
    \ sieve(S + 1);\n\n  if(done >= LIM) return primes;\n  done  = LIM;\n\n  primes\
    \ = {2}, sieve.assign(S + 1, 0);\n  const int R = LIM / 2;  \n  primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n   \
    \ if (!sieve[i]) {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <=\
    \ S; j += 2 * i) sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S)\
    \ {\n    array<bool, S> block{};\n    for (auto& [p, idx]: cp)\n      for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  return primes;\n}\n#line\
    \ 2 \"mod/powertable.hpp\"\n\r\ntemplate<typename mint>\r\nvc<mint> powertable_1(mint\
    \ a, ll N) {\r\n  // table of a^i\r\n  vc<mint> f(N, 1);\r\n  FOR(i, N - 1) f[i\
    \ + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\ntemplate<typename mint>\r\nvc<mint>\
    \ powertable_2(ll e, ll N) {\r\n  // table of i^e. N \u4EE5\u4E0B\u306E\u7D20\u6570\
    \u30C6\u30FC\u30D6\u30EB\u3092\u5229\u7528\u3059\u308B. \r\n  auto& primes = primetable(N);\r\
    \n  vc<mint> f(N, 1);\r\n  f[0] = mint(0).pow(e);\r\n  for(auto&& p : primes){\r\
    \n    if(p > N) break;\r\n    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\n\
    \    while(pp < N){\r\n      ll i = pp;\r\n      while(i < N){\r\n        f[i]\
    \ *= xp;\r\n        i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n  }\r\n\
    \  return f;\r\n}\r\n\r\n"
  code: "#include \"nt/primetable.hpp\"\r\n\r\ntemplate<typename mint>\r\nvc<mint>\
    \ powertable_1(mint a, ll N) {\r\n  // table of a^i\r\n  vc<mint> f(N, 1);\r\n\
    \  FOR(i, N - 1) f[i + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\ntemplate<typename\
    \ mint>\r\nvc<mint> powertable_2(ll e, ll N) {\r\n  // table of i^e. N \u4EE5\u4E0B\
    \u306E\u7D20\u6570\u30C6\u30FC\u30D6\u30EB\u3092\u5229\u7528\u3059\u308B. \r\n\
    \  auto& primes = primetable(N);\r\n  vc<mint> f(N, 1);\r\n  f[0] = mint(0).pow(e);\r\
    \n  for(auto&& p : primes){\r\n    if(p > N) break;\r\n    mint xp = mint(p).pow(e);\r\
    \n    ll pp = p;\r\n    while(pp < N){\r\n      ll i = pp;\r\n      while(i <\
    \ N){\r\n        f[i] *= xp;\r\n        i += pp;\r\n      }\r\n      pp *= p;\r\
    \n    }\r\n  }\r\n  return f;\r\n}\r\n\r\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: mod/powertable.hpp
  requiredBy:
  - seq/stirling_number_1.hpp
  - poly/poly_taylor_shift.hpp
  timestamp: '2022-01-14 13:53:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
documentation_of: mod/powertable.hpp
layout: document
redirect_from:
- /library/mod/powertable.hpp
- /library/mod/powertable.hpp.html
title: mod/powertable.hpp
---