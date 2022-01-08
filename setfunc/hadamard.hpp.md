---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: setfunc/xor_convolution.hpp
    title: setfunc/xor_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/hadamard.hpp\"\n\r\ntemplate <typename T>\r\nvoid\
    \ hadamard(vc<T>& A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log ==\
    \ len(A));\r\n  FOR(n, log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n\
    \    if (s < t) tie(A[s], A[t]) = mp(A[s] + A[t], A[s] - A[t]);  \r\n  }\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nvoid hadamard(vc<T>& A) {\r\n\
    \  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n, log)\
    \ FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) tie(A[s],\
    \ A[t]) = mp(A[s] + A[t], A[s] - A[t]);  \r\n  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/hadamard.hpp
  requiredBy:
  - setfunc/xor_convolution.hpp
  timestamp: '2022-01-06 02:25:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: setfunc/hadamard.hpp
layout: document
redirect_from:
- /library/setfunc/hadamard.hpp
- /library/setfunc/hadamard.hpp.html
title: setfunc/hadamard.hpp
---
