---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\nvc<ll>& primetable(int LIM) {\n  ++LIM;\n\
    \  const int S = 32768;\n  static int done = 2;\n  static vc<ll> primes = {2},\
    \ sieve(S + 1);\n\n  if(done >= LIM) return primes;\n  done  = LIM;\n\n  primes\
    \ = {2}, sieve.assign(S + 1, 0);\n  const int R = LIM / 2;  \n  primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n  vc<pi> cp;\n  for (int i = 3; i <= S; i += 2) {\n   \
    \ if (!sieve[i]) {\n      cp.eb(i, i * i / 2);\n      for (int j = i * i; j <=\
    \ S; j += 2 * i) sieve[j] = 1;\n    }\n  }\n  for (int L = 1; L <= R; L += S)\
    \ {\n    array<bool, S> block{};\n    for (auto& [p, idx]: cp)\n      for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n    FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n  }\n  return primes;\n}\n#line\
    \ 3 \"nt/lpf_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1 \u304C\u5165\u308B\
    \u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = primetable(LIM);\n  vc<int>\
    \ res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n    FOR3(j,\
    \ 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include \"nt/primetable.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F\
    \ -1 \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = primetable(LIM);\n\
    \  vc<int> res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n\
    \    FOR3(j, 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/lpf_table.hpp
  requiredBy: []
  timestamp: '2022-04-10 03:06:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/lpf_table.hpp
layout: document
redirect_from:
- /library/nt/lpf_table.hpp
- /library/nt/lpf_table.hpp.html
title: nt/lpf_table.hpp
---
