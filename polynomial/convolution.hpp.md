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
  bundledCode: "#line 2 \"polynomial/convolution.hpp\"\ntemplate <typename mint>\r\
    \nvector<mint> convolution(vector<mint>& A, vector<mint>& B) {\r\n  vector<mint>\
    \ C(len(A) + len(B) - 1);\r\n  FOR(i, len(A)) FOR(j, len(B)) C[i + j] += A[i]\
    \ * B[j];\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\ntemplate <typename mint>\r\nvector<mint> convolution(vector<mint>&\
    \ A, vector<mint>& B) {\r\n  vector<mint> C(len(A) + len(B) - 1);\r\n  FOR(i,\
    \ len(A)) FOR(j, len(B)) C[i + j] += A[i] * B[j];\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/convolution.hpp
  requiredBy: []
  timestamp: '2022-01-03 11:29:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/convolution.hpp
layout: document
redirect_from:
- /library/polynomial/convolution.hpp
- /library/polynomial/convolution.hpp.html
title: polynomial/convolution.hpp
---
