---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':x:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':x:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/enumerate_primes.test.cpp
    title: test/library_checker/math/enumerate_primes.test.cpp
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
  _verificationStatusIcon: ':question:'
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
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  return primes;\n}\n"
  code: "vc<int>& primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static\
    \ int done = 2;\n  static vc<int> primes = {2}, sieve(S + 1);\n\n  if(done >=\
    \ LIM) return primes;\n  done  = LIM;\n\n  primes = {2}, sieve.assign(S + 1, 0);\n\
    \  const int R = LIM / 2;  \n  primes.reserve(int(LIM / log(LIM) * 1.1));\n  vc<pi>\
    \ cp;\n  for (int i = 3; i <= S; i += 2) {\n    if (!sieve[i]) {\n      cp.eb(i,\
    \ i * i / 2);\n      for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n \
    \   }\n  }\n  for (int L = 1; L <= R; L += S) {\n    array<bool, S> block{};\n\
    \    for (auto& [p, idx]: cp)\n      for (int i = idx; i < S + L; idx = (i +=\
    \ p)) block[i - L] = 1;\n    FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L\
    \ + i) * 2 + 1);\n  }\n  return primes;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetable.hpp
  requiredBy:
  - seq/stirling_number_1.hpp
  - poly/poly_taylor_shift.hpp
  - mod/powertable.hpp
  timestamp: '2022-01-14 13:53:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/enumerate_primes.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
documentation_of: nt/primetable.hpp
layout: document
redirect_from:
- /library/nt/primetable.hpp
- /library/nt/primetable.hpp.html
title: nt/primetable.hpp
---
