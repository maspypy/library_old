---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: linalg/mat_pow.hpp
    title: linalg/mat_pow.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/mat_mul.hpp\"\ntemplate <class T, is_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  // mod \u3092\u3068\u308B\u56DE\u6570\u3092\u6E1B\u3089\u3057\u3066\u307F\u308B\
    \r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  const\
    \ u64 MOD2 = 8ull * T::get_mod() * T::get_mod();\r\n  FOR(n, N) {\r\n    vc<u64>\
    \ tmp(K);\r\n    FOR(m, M) FOR(k, K) {\r\n      tmp[k] += u64(A[n][m].val) * B[m][k].val;\r\
    \n      if (tmp[k] >= MOD2) tmp[k] -= MOD2;\r\n    }\r\n    FOR(k, K) C[n][k]\
    \ = tmp[k];\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, is_not_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n,\
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  code: "template <class T, is_modint_t<T>* = nullptr>\r\nvc<vc<T>> mat_mul(const\
    \ vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  // mod \u3092\u3068\u308B\u56DE\u6570\
    \u3092\u6E1B\u3089\u3057\u3066\u307F\u308B\r\n  auto N = len(A), M = len(B), K\
    \ = len(B[0]);\r\n  vv(T, C, N, K);\r\n  const u64 MOD2 = 8ull * T::get_mod()\
    \ * T::get_mod();\r\n  FOR(n, N) {\r\n    vc<u64> tmp(K);\r\n    FOR(m, M) FOR(k,\
    \ K) {\r\n      tmp[k] += u64(A[n][m].val) * B[m][k].val;\r\n      if (tmp[k]\
    \ >= MOD2) tmp[k] -= MOD2;\r\n    }\r\n    FOR(k, K) C[n][k] = tmp[k];\r\n  }\r\
    \n  return C;\r\n}\r\n\r\ntemplate <class T, is_not_modint_t<T>* = nullptr>\r\n\
    vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  auto N = len(A),\
    \ M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n, N) FOR(m, M) FOR(k,\
    \ K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/mat_mul.hpp
  requiredBy:
  - linalg/mat_pow.hpp
  timestamp: '2022-01-15 19:02:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/matrix_product.test.cpp
documentation_of: linalg/mat_mul.hpp
layout: document
redirect_from:
- /library/linalg/mat_mul.hpp
- /library/linalg/mat_mul.hpp.html
title: linalg/mat_mul.hpp
---
