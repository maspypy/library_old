---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/gcd_convolution.hpp
    title: nt/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lcm_convolution.hpp
    title: nt/lcm_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/gcd_convolution.test.cpp
    title: test/library_checker/math/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/lcm_convolution.test.cpp
    title: test/library_checker/math/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/primetable.hpp\"\nvc<ll>& primetable(int LIM) {\n  ++LIM;\n\
    \  const int S = 32768;\n  static int done = 2;\n  static vc<ll> primes = {2},\
    \ sieve(S + 1);\n\n  if(done >= LIM) return primes;\n  done  = LIM;\n\n  primes\
    \ = {2}, sieve.assign(S + 1, 0);\n  const int R = LIM / 2;  \n  primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n   \
    \ if (!sieve[i]) {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <=\
    \ S; j += 2 * i) sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S)\
    \ {\n    array<bool, S> block{};\n    for (auto& [p, idx]: cp)\n      for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  return primes;\n}\n#line\
    \ 3 \"nt/zeta.hpp\"\n\r\ntemplate <typename T>\r\nvoid divisor_zeta(vc<T>& A)\
    \ {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto& P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3(x, 1, N / p + 1) A[p * x] += A[x]; }\r\n}\r\n\r\n\
    template <typename T>\r\nvoid divisor_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\
    \n  int N = len(A) - 1;\r\n  auto& P = primetable(N);\r\n  for (auto&& p: P) {\
    \ FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A)\
    \ - 1;\r\n  auto& P = primetable(N);\r\n  for (auto&& p: P) { FOR3_R(x, 1, N /\
    \ p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid multiplier_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto& P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3(x, 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n"
  code: "#pragma once\r\n#include \"nt/primetable.hpp\"\r\n\r\ntemplate <typename\
    \ T>\r\nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A)\
    \ - 1;\r\n  auto& P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x, 1, N / p\
    \ + 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid divisor_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto& P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] ==\
    \ 0);\r\n  int N = len(A) - 1;\r\n  auto& P = primetable(N);\r\n  for (auto&&\
    \ p: P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N\
    \ = len(A) - 1;\r\n  auto& P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/zeta.hpp
  requiredBy:
  - nt/lcm_convolution.hpp
  - nt/gcd_convolution.hpp
  timestamp: '2022-02-06 02:56:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/lcm_convolution.test.cpp
  - test/library_checker/math/gcd_convolution.test.cpp
documentation_of: nt/zeta.hpp
layout: document
redirect_from:
- /library/nt/zeta.hpp
- /library/nt/zeta.hpp.html
title: nt/zeta.hpp
---
