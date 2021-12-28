---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/enumerate_primes.test.cpp
    title: test/library_checker/math/enumerate_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/primetable.hpp\"\ntemplate <int LIM = (1 << 20)>\npair<bitset<LIM>,\
    \ vc<int>> primetable() {\n  bitset<LIM> is_prime;\n  const int S = (int)round(sqrt(LIM)),\
    \ R = LIM / 2;\n  vc<int> primes = {2}, sieve(S + 1);\n  primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n   \
    \ if (!sieve[i]) {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <=\
    \ S; j += 2 * i) sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S)\
    \ {\n    array<bool, S> block{};\n    for (auto& [p, idx]: cp)\n      for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  for (auto&& i :primes)\
    \ is_prime[i] = 1;\n  return {is_prime, primes};\n}\n"
  code: "template <int LIM = (1 << 20)>\npair<bitset<LIM>, vc<int>> primetable() {\n\
    \  bitset<LIM> is_prime;\n  const int S = (int)round(sqrt(LIM)), R = LIM / 2;\n\
    \  vc<int> primes = {2}, sieve(S + 1);\n  primes.reserve(int(LIM / log(LIM) *\
    \ 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n    if (!sieve[i])\
    \ {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <= S; j += 2 * i)\
    \ sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S) {\n    array<bool,\
    \ S> block{};\n    for (auto& [p, idx]: cp)\n      for (int i = idx; i < S + L;\
    \ idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n  }\n  for (auto&& i :primes) is_prime[i] = 1;\n\
    \  return {is_prime, primes};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetable.hpp
  requiredBy: []
  timestamp: '2021-12-28 05:37:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/enumerate_primes.test.cpp
documentation_of: nt/primetable.hpp
layout: document
redirect_from:
- /library/nt/primetable.hpp
- /library/nt/primetable.hpp.html
title: nt/primetable.hpp
---