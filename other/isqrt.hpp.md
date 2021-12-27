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
  bundledCode: "#line 2 \"other/isqrt.hpp\"\nll isqrt(ll n) {\r\n  ll x = n, y = (n\
    \ + 1) / 2;\r\n  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }\r\n  return\
    \ x;\r\n}\r\n"
  code: "#pragma once\r\nll isqrt(ll n) {\r\n  ll x = n, y = (n + 1) / 2;\r\n  while\
    \ (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }\r\n  return x;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/isqrt.hpp
  requiredBy: []
  timestamp: '2021-12-27 17:43:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/isqrt.hpp
layout: document
redirect_from:
- /library/other/isqrt.hpp
- /library/other/isqrt.hpp.html
title: other/isqrt.hpp
---
