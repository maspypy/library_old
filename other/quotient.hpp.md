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
  bundledCode: "#line 1 \"other/quotient.hpp\"\nstruct QuotientGenerator {\r\n  ll\
    \ N;\r\n  ll R;\r\n  QuotientGenerator(ll N) : N(N), R(N){};\r\n  operator bool()\
    \ const { return R > 0; }\r\n  tuple<ll, ll, ll> operator()() {\r\n    ll q =\
    \ N / R;\r\n    ll L = N / (q + 1);\r\n    tuple<ll, ll, ll> t = mt(q, L + 1,\
    \ R + 1);\r\n    R = L;\r\n    return t;\r\n  }\r\n};\n"
  code: "struct QuotientGenerator {\r\n  ll N;\r\n  ll R;\r\n  QuotientGenerator(ll\
    \ N) : N(N), R(N){};\r\n  operator bool() const { return R > 0; }\r\n  tuple<ll,\
    \ ll, ll> operator()() {\r\n    ll q = N / R;\r\n    ll L = N / (q + 1);\r\n \
    \   tuple<ll, ll, ll> t = mt(q, L + 1, R + 1);\r\n    R = L;\r\n    return t;\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/quotient.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/quotient.hpp
layout: document
redirect_from:
- /library/other/quotient.hpp
- /library/other/quotient.hpp.html
title: other/quotient.hpp
---
