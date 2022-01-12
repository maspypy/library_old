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
  bundledCode: "#line 1 \"mod/mod_pow.hpp\"\nll mod_pow(ll a, ll n, int mod){\r\n\
    \  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while(n){\r\n    if(n & 1) v =\
    \ v * p % mod;\r\n    p = p * p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\
    \n}\n"
  code: "ll mod_pow(ll a, ll n, int mod){\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v\
    \ = 1;\r\n  while(n){\r\n    if(n & 1) v = v * p % mod;\r\n    p = p * p % mod;\r\
    \n    n >>= 1;\r\n  }\r\n  return v;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_pow.hpp
  requiredBy: []
  timestamp: '2022-01-13 04:04:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_pow.hpp
layout: document
redirect_from:
- /library/mod/mod_pow.hpp
- /library/mod/mod_pow.hpp.html
title: mod/mod_pow.hpp
---
