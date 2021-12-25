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
  bundledCode: "#line 1 \"nt/primetable.hpp\"\ntemplate <int LIM=(1<<20)>\npair<bitset<LIM>,\
    \ vi> primetable() {\n  bitset<LIM> is_prime;\n  const int S = (int)round(sqrt(LIM)),\
    \ R = LIM / 2;\n  vi primes = {2}, sieve(S + 1);\n  primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2)\n    if (!sieve[i])\
    \ {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <= S; j += 2 * i)\
    \ sieve[j] = 1;\n    }\n  for (int L = 1; L <= R; L += S) {\n    array<bool, S>\
    \ block{};\n    for (auto& [p, idx] : cp)\n      for (int i = idx; i < S + L;\
    \ idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n  }\n  FORIN(i, primes) is_prime[i] = 1;\n  return\
    \ {is_prime, primes};\n}\n"
  code: "template <int LIM=(1<<20)>\npair<bitset<LIM>, vi> primetable() {\n  bitset<LIM>\
    \ is_prime;\n  const int S = (int)round(sqrt(LIM)), R = LIM / 2;\n  vi primes\
    \ = {2}, sieve(S + 1);\n  primes.reserve(int(LIM / log(LIM) * 1.1));\n  vc<pi>\
    \ cp;\n  for (int i = 3; i <= S; i += 2)\n    if (!sieve[i]) {\n      cp.eb(i,\
    \ i * i / 2);\n      for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n \
    \   }\n  for (int L = 1; L <= R; L += S) {\n    array<bool, S> block{};\n    for\
    \ (auto& [p, idx] : cp)\n      for (int i = idx; i < S + L; idx = (i += p)) block[i\
    \ - L] = 1;\n    FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 +\
    \ 1);\n  }\n  FORIN(i, primes) is_prime[i] = 1;\n  return {is_prime, primes};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetable.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/primetable.hpp
layout: document
redirect_from:
- /library/nt/primetable.hpp
- /library/nt/primetable.hpp.html
title: nt/primetable.hpp
---
