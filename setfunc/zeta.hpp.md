---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: setfunc/and_convolution.hpp
    title: setfunc/and_convolution.hpp
  - icon: ':x:'
    path: setfunc/or_convolution.hpp
    title: setfunc/or_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.hpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.hpp
  - icon: ':x:'
    path: test/library_checker/convolution/bitwise_or_convolution.test.hpp
    title: test/library_checker/convolution/bitwise_or_convolution.test.hpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/zeta.hpp\"\n\r\ntemplate <typename T>\r\nvoid superset_zeta(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) A[s]\
    \ += A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid superset_mobius(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) A[s]\
    \ -= A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_zeta(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s > t) A[s]\
    \ += A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_mobius(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s > t) A[s]\
    \ -= A[t];\r\n  }\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nvoid superset_zeta(vc<T>& A)\
    \ {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) A[s]\
    \ += A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid superset_mobius(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) A[s]\
    \ -= A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_zeta(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s > t) A[s]\
    \ += A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_mobius(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s > t) A[s]\
    \ -= A[t];\r\n  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/zeta.hpp
  requiredBy:
  - setfunc/and_convolution.hpp
  - setfunc/or_convolution.hpp
  timestamp: '2022-01-03 11:29:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/bitwise_or_convolution.test.hpp
  - test/library_checker/convolution/bitwise_and_convolution.test.hpp
documentation_of: setfunc/zeta.hpp
layout: document
redirect_from:
- /library/setfunc/zeta.hpp
- /library/setfunc/zeta.hpp.html
title: setfunc/zeta.hpp
---
