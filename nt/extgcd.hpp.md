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
  bundledCode: "#line 1 \"nt/extgcd.hpp\"\ntuple<ll, ll, ll, ll> Farey_lr(ll a, ll\
    \ b) {\r\n  assert(a > 0 && b > 0);\r\n  /*\r\n  Farey \u6570\u5217\u3067\u3001\
    a/b \u304C\u6700\u521D\u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\
    \u3092\u6C42\u3081\u308B\u3002\r\n  a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7,\
    \ 8/5) \u2192 (11,7,8,5) \u3092\u8FD4\u3059\u3002\r\n  */\r\n  if (a == b)\r\n\
    \    return {0, 1, 1, 0};\r\n  ll q = (a - 1) / b;\r\n  auto [x1, y1, x2, y2]\
    \ = Farey_lr(b, a - q * b);\r\n  return {q * x2 + y2, x2, q * x1 + y1, x1};\r\n\
    }\r\n\r\ntuple<ll, ll, ll> extgcd(ll a, ll b) {\r\n  assert(a > 0);\r\n  // ax\
    \ - by = d \u306E\u6700\u5C0F\u89E3 (x, y, d) \u3092\u8FD4\u3059\u3002\r\n  if\
    \ (b == 0)\r\n    return {1, 0, a};\r\n  auto [x1, y1, x2, y2] = Farey_lr(a, b);\r\
    \n  ll d = a / (x1 + x2);\r\n  return {y1, x1, d};\r\n}\r\n\r\n"
  code: "tuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {\r\n  assert(a > 0 && b > 0);\r\
    \n  /*\r\n  Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\u521D\u306B\u73FE\u308C\
    \u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\u3081\u308B\u3002\r\n \
    \ a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5) \u3092\u8FD4\
    \u3059\u3002\r\n  */\r\n  if (a == b)\r\n    return {0, 1, 1, 0};\r\n  ll q =\
    \ (a - 1) / b;\r\n  auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);\r\n  return\
    \ {q * x2 + y2, x2, q * x1 + y1, x1};\r\n}\r\n\r\ntuple<ll, ll, ll> extgcd(ll\
    \ a, ll b) {\r\n  assert(a > 0);\r\n  // ax - by = d \u306E\u6700\u5C0F\u89E3\
    \ (x, y, d) \u3092\u8FD4\u3059\u3002\r\n  if (b == 0)\r\n    return {1, 0, a};\r\
    \n  auto [x1, y1, x2, y2] = Farey_lr(a, b);\r\n  ll d = a / (x1 + x2);\r\n  return\
    \ {y1, x1, d};\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/extgcd.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/extgcd.hpp
layout: document
redirect_from:
- /library/nt/extgcd.hpp
- /library/nt/extgcd.hpp.html
title: nt/extgcd.hpp
---
