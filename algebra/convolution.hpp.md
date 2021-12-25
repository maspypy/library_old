---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/linearrecurrence.hpp
    title: algebra/linearrecurrence.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/convolution.hpp\"\ntemplate <typename mint>\r\n\
    vector<mint> convolve(vector<mint>& A, vector<mint>& B) {\r\n  vector<mint> C(len(A)\
    \ + len(B) - 1);\r\n  FOR(i, len(A)) FOR(j, len(B)) C[i + j] += A[i] * B[j];\r\
    \n  return C;\r\n}\r\n"
  code: "#pragma once\r\ntemplate <typename mint>\r\nvector<mint> convolve(vector<mint>&\
    \ A, vector<mint>& B) {\r\n  vector<mint> C(len(A) + len(B) - 1);\r\n  FOR(i,\
    \ len(A)) FOR(j, len(B)) C[i + j] += A[i] * B[j];\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/convolution.hpp
  requiredBy:
  - algebra/linearrecurrence.hpp
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/convolution.hpp
layout: document
redirect_from:
- /library/algebra/convolution.hpp
- /library/algebra/convolution.hpp.html
title: algebra/convolution.hpp
---
