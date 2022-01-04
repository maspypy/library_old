---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: polynomial/convolution.hpp
    title: polynomial/convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"sequence/linearrecurrence.hpp\"\n\r\n#line 2 \"polynomial/convolution.hpp\"\
    \ntemplate <typename mint>\r\nvector<mint> convolution(vector<mint>& A, vector<mint>&\
    \ B) {\r\n  vector<mint> C(len(A) + len(B) - 1);\r\n  FOR(i, len(A)) FOR(j, len(B))\
    \ C[i + j] += A[i] * B[j];\r\n  return C;\r\n}\r\n#line 4 \"sequence/linearrecurrence.hpp\"\
    \n\r\ntemplate <typename mint>\r\nmint coef_of_rational(vector<mint> A, vector<mint>\
    \ B, ll N) {\r\n  if(len(A)==0) return 0;\r\n  assert(B[0] == 1);\r\n  assert(len(B)\
    \ == len(A) + 1);\r\n  while (N) {\r\n    vc<mint> B1 = B;\r\n    FOR(i, len(B1))\
    \ if (i & 1) B1[i] = -B1[i];\r\n    A = convolution(A, B1);\r\n    B = convolution(B,\
    \ B1);\r\n    FOR(i, len(B1)) B[i] = B[2 * i];\r\n    if (N & 1) {\r\n      FOR(i,\
    \ len(B1) - 1) A[i] = A[2 * i | 1];\r\n    } else {\r\n      FOR(i, len(B1) -\
    \ 1) A[i] = A[2 * i];\r\n    }\r\n    A.resize(len(B1) - 1);\r\n    B.resize(len(B1));\r\
    \n    N /= 2;\r\n  }\r\n  return A[0];\r\n}\r\n\r\ntemplate <typename mint>\r\n\
    vector<mint> berlekamp_massey(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nmint interpolate_linear_recurrence(vector<mint>& A, ll N)\
    \ {\r\n  auto G = berlekamp_massey(A);\r\n  auto F = convolution(A, G);\r\n  F.resize(len(G)\
    \ - 1);\r\n  return coef_of_rational(F, G, N);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"polynomial/convolution.hpp\"\r\n\r\ntemplate\
    \ <typename mint>\r\nmint coef_of_rational(vector<mint> A, vector<mint> B, ll\
    \ N) {\r\n  if(len(A)==0) return 0;\r\n  assert(B[0] == 1);\r\n  assert(len(B)\
    \ == len(A) + 1);\r\n  while (N) {\r\n    vc<mint> B1 = B;\r\n    FOR(i, len(B1))\
    \ if (i & 1) B1[i] = -B1[i];\r\n    A = convolution(A, B1);\r\n    B = convolution(B,\
    \ B1);\r\n    FOR(i, len(B1)) B[i] = B[2 * i];\r\n    if (N & 1) {\r\n      FOR(i,\
    \ len(B1) - 1) A[i] = A[2 * i | 1];\r\n    } else {\r\n      FOR(i, len(B1) -\
    \ 1) A[i] = A[2 * i];\r\n    }\r\n    A.resize(len(B1) - 1);\r\n    B.resize(len(B1));\r\
    \n    N /= 2;\r\n  }\r\n  return A[0];\r\n}\r\n\r\ntemplate <typename mint>\r\n\
    vector<mint> berlekamp_massey(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nmint interpolate_linear_recurrence(vector<mint>& A, ll N)\
    \ {\r\n  auto G = berlekamp_massey(A);\r\n  auto F = convolution(A, G);\r\n  F.resize(len(G)\
    \ - 1);\r\n  return coef_of_rational(F, G, N);\r\n}\r\n"
  dependsOn:
  - polynomial/convolution.hpp
  isVerificationFile: false
  path: sequence/linearrecurrence.hpp
  requiredBy: []
  timestamp: '2022-01-04 19:49:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sequence/linearrecurrence.hpp
layout: document
redirect_from:
- /library/sequence/linearrecurrence.hpp
- /library/sequence/linearrecurrence.hpp.html
title: sequence/linearrecurrence.hpp
---
