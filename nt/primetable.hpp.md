---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':x:'
    path: nt/gcd_convolution.hpp
    title: nt/gcd_convolution.hpp
  - icon: ':x:'
    path: nt/lcm_convolution.hpp
    title: nt/lcm_convolution.hpp
  - icon: ':warning:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':warning:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  - icon: ':x:'
    path: nt/multiplicative_sum.hpp
    title: nt/multiplicative_sum.hpp
  - icon: ':x:'
    path: nt/primesum.hpp
    title: nt/primesum.hpp
  - icon: ':x:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  - icon: ':x:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':x:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/counting_primes.test.cpp
    title: test/library_checker/math/counting_primes.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/enumerate_primes.test.cpp
    title: test/library_checker/math/enumerate_primes.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/gcd_convolution.test.cpp
    title: test/library_checker/math/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/lcm_convolution.test.cpp
    title: test/library_checker/math/lcm_convolution.test.cpp
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
    path: test/library_checker/math/totient_sum.test.cpp
    title: test/library_checker/math/totient_sum.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\nvc<int> primetable(int LIM) {\n  ++LIM;\n\
    \  const int S = 32768;\n  static int done = 2;\n  static vc<int> primes = {2},\
    \ sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pi> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i])\
    \ {\n        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2\
    \ * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n\
    \      array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R\
    \ - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n"
  code: "#pragma once\nvc<int> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n\
    \  static int done = 2;\n  static vc<int> primes = {2}, sieve(S + 1);\n\n  if\
    \ (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n\
    \    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n\
    \    vc<pi> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n\
    \        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i)\
    \ sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n     \
    \ array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int i\
    \ = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetable.hpp
  requiredBy:
  - mod/powertable.hpp
  - poly/poly_taylor_shift.hpp
  - seq/stirling_number_1.hpp
  - nt/lpf_table.hpp
  - nt/multiplicative_sum.hpp
  - nt/zeta.hpp
  - nt/primesum.hpp
  - nt/lcm_convolution.hpp
  - nt/gcd_convolution.hpp
  - nt/mobius_table.hpp
  timestamp: '2022-04-12 00:53:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - test/library_checker/math/enumerate_primes.test.cpp
  - test/library_checker/math/gcd_convolution.test.cpp
  - test/library_checker/math/lcm_convolution.test.cpp
  - test/library_checker/math/totient_sum.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/counting_primes.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
documentation_of: nt/primetable.hpp
layout: document
redirect_from:
- /library/nt/primetable.hpp
- /library/nt/primetable.hpp.html
title: nt/primetable.hpp
---
