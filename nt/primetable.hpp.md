---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: other/isqrt.hpp
    title: other/isqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/isqrt.hpp\"\nll isqrt(ll n) {\r\n  ll x = n, y = (n\
    \ + 1) / 2;\r\n  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }\r\n  return\
    \ x;\r\n}\r\n#line 2 \"nt/primetable.hpp\"\n\ntemplate <int LIM = (1 << 20)>\n\
    pair<bitset<LIM>, vc<int>> primetable() {\n  bitset<LIM> is_prime;\n  const int\
    \ S = isqrt(LIM), R = LIM / 2;\n  vc<int> primes = {2}, sieve(S + 1);\n  primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n   \
    \ if (!sieve[i]) {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <=\
    \ S; j += 2 * i) sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S)\
    \ {\n    array<bool, S> block{};\n    for (auto& [p, idx]: cp)\n      for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  for (auto&& i primes)\
    \ is_prime[i] = 1;\n  return {is_prime, primes};\n}\n"
  code: "#include \"other/isqrt.hpp\"\n\ntemplate <int LIM = (1 << 20)>\npair<bitset<LIM>,\
    \ vc<int>> primetable() {\n  bitset<LIM> is_prime;\n  const int S = isqrt(LIM),\
    \ R = LIM / 2;\n  vc<int> primes = {2}, sieve(S + 1);\n  primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n   \
    \ if (!sieve[i]) {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <=\
    \ S; j += 2 * i) sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S)\
    \ {\n    array<bool, S> block{};\n    for (auto& [p, idx]: cp)\n      for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  for (auto&& i primes)\
    \ is_prime[i] = 1;\n  return {is_prime, primes};\n}\n"
  dependsOn:
  - other/isqrt.hpp
  isVerificationFile: false
  path: nt/primetable.hpp
  requiredBy: []
  timestamp: '2021-12-27 17:43:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/primetable.hpp
layout: document
redirect_from:
- /library/nt/primetable.hpp
- /library/nt/primetable.hpp.html
title: nt/primetable.hpp
---
