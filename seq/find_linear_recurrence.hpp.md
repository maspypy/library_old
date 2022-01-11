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
  bundledCode: "#line 1 \"seq/find_linear_recurrence.hpp\"\ntemplate <typename mint>\r\
    \nvector<mint> find_linear_recurrence(vector<mint>& A) {\r\n  int N = len(A);\r\
    \n  vc<mint> B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i,\
    \ N) {\r\n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j];\
    \ }\r\n    if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto\
    \ tmp = C;\r\n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(),\
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
  path: seq/find_linear_recurrence.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/find_linear_recurrence.hpp
layout: document
redirect_from:
- /library/seq/find_linear_recurrence.hpp
- /library/seq/find_linear_recurrence.hpp.html
title: seq/find_linear_recurrence.hpp
---
