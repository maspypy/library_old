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
  bundledCode: "#line 1 \"mod/mod_inv.hpp\"\nll mod_inv(ll val, ll mod) {\r\n  int\
    \ a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n\
    \    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\
    \n  return u;\r\n}\r\n"
  code: "ll mod_inv(ll val, ll mod) {\r\n  int a = val, b = mod, u = 1, v = 0, t;\r\
    \n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\n  return u;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_inv.hpp
  requiredBy: []
  timestamp: '2022-01-14 01:43:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_inv.hpp
layout: document
redirect_from:
- /library/mod/mod_inv.hpp
- /library/mod/mod_inv.hpp.html
title: mod/mod_inv.hpp
---
