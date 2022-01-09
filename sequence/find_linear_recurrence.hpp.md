---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  - icon: ':x:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':x:'
    path: sequence/linearrecurrence.hpp
    title: sequence/linearrecurrence.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/find_linear_recurrence.test.cpp
    title: test/library_checker/math/find_linear_recurrence.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"sequence/find_linear_recurrence.hpp\"\ntemplate <typename\
    \ mint>\r\nvector<mint> find_linear_recurrence(vector<mint>& A) {\r\n  int N =\
    \ len(A);\r\n  vc<mint> B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p =\
    \ 1;\r\n  FOR(i, N) {\r\n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j]\
    \ * A[i - j]; }\r\n    if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\
    \n    auto tmp = C;\r\n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(),\
    \ len(B) + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n   \
    \ if (l + l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n     \
    \ p = d;\r\n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n"
  code: "template <typename mint>\r\nvector<mint> find_linear_recurrence(vector<mint>&\
    \ A) {\r\n  int N = len(A);\r\n  vc<mint> B = {1}, C = {1};\r\n  int l = 0, m\
    \ = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\n    mint d = A[i];\r\n    FOR3(j,\
    \ 1, l + 1) { d += C[j] * A[i - j]; }\r\n    if (d == 0) {\r\n      ++m;\r\n \
    \     continue;\r\n    }\r\n    auto tmp = C;\r\n    mint q = d / p;\r\n    if\
    \ (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C), 0);\r\n    FOR(j,\
    \ len(B)) C[j + m] -= q * B[j];\r\n    if (l + l <= i) {\r\n      B = tmp;\r\n\
    \      l = i + 1 - l, m = 1;\r\n      p = d;\r\n    } else {\r\n      ++m;\r\n\
    \    }\r\n  }\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: sequence/find_linear_recurrence.hpp
  requiredBy:
  - linalg/spmat_min_poly.hpp
  - linalg/spmat_det.hpp
  - sequence/linearrecurrence.hpp
  timestamp: '2022-01-10 07:43:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/library_checker/math/find_linear_recurrence.test.cpp
documentation_of: sequence/find_linear_recurrence.hpp
layout: document
redirect_from:
- /library/sequence/find_linear_recurrence.hpp
- /library/sequence/find_linear_recurrence.hpp.html
title: sequence/find_linear_recurrence.hpp
---
