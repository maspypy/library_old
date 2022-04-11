---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/disjointsparse.hpp\"\ntemplate <class Monoid>\r\nstruct\
    \ DisjointSparse {\r\n  using X = typename Monoid::value_type;\r\n  using value_type\
    \ = X;\r\n  int n, log;\r\n  vc<X> dat;\r\n\r\n  DisjointSparse(const vc<X>& A)\
    \ : n(len(A)) {\r\n    log = 1;\r\n    while ((1 << log) < n) ++log;\r\n    dat.reserve(log\
    \ * n);\r\n    FOR(i, log) FOR(j, n) dat.eb(A[j]);\r\n\r\n    FOR(i, log) {\r\n\
    \      int s = n * i;\r\n      int b = 1 << i;\r\n      for (int m = b; m <= n;\
    \ m += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n        FOR3_R(j,\
    \ L + 1, m) {\r\n          dat[s + j - 1] = Monoid::op(dat[s + j - 1], dat[s +\
    \ j]);\r\n        }\r\n        FOR3(j, m, R - 1) {\r\n          dat[s + j + 1]\
    \ = Monoid::op(dat[s + j], dat[s + j + 1]);\r\n        }\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L == R) return Monoid::unit();\r\
    \n    --R;\r\n    if (L == R) return dat[L];\r\n    int k = 31 - __builtin_clz(L\
    \ ^ R);\r\n    return Monoid::op(dat[n * k + L], dat[n * k + R]);\r\n  }\r\n\r\
    \n  void debug() {\r\n    print(\"disjoint sparse table\");\r\n    FOR(i, log)\
    \ {\r\n      vc<X> tmp = {dat.begin() + n * i, dat.begin() + n * (i + 1)};\r\n\
    \      print(tmp);\r\n    }\r\n  }\r\n};\r\n"
  code: "template <class Monoid>\r\nstruct DisjointSparse {\r\n  using X = typename\
    \ Monoid::value_type;\r\n  using value_type = X;\r\n  int n, log;\r\n  vc<X> dat;\r\
    \n\r\n  DisjointSparse(const vc<X>& A) : n(len(A)) {\r\n    log = 1;\r\n    while\
    \ ((1 << log) < n) ++log;\r\n    dat.reserve(log * n);\r\n    FOR(i, log) FOR(j,\
    \ n) dat.eb(A[j]);\r\n\r\n    FOR(i, log) {\r\n      int s = n * i;\r\n      int\
    \ b = 1 << i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n        int L\
    \ = m - b, R = min(n, m + b);\r\n        FOR3_R(j, L + 1, m) {\r\n          dat[s\
    \ + j - 1] = Monoid::op(dat[s + j - 1], dat[s + j]);\r\n        }\r\n        FOR3(j,\
    \ m, R - 1) {\r\n          dat[s + j + 1] = Monoid::op(dat[s + j], dat[s + j +\
    \ 1]);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\
    \n    if (L == R) return Monoid::unit();\r\n    --R;\r\n    if (L == R) return\
    \ dat[L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n    return Monoid::op(dat[n\
    \ * k + L], dat[n * k + R]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"disjoint\
    \ sparse table\");\r\n    FOR(i, log) {\r\n      vc<X> tmp = {dat.begin() + n\
    \ * i, dat.begin() + n * (i + 1)};\r\n      print(tmp);\r\n    }\r\n  }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: ds/disjointsparse.hpp
  requiredBy: []
  timestamp: '2022-04-11 13:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
documentation_of: ds/disjointsparse.hpp
layout: document
redirect_from:
- /library/ds/disjointsparse.hpp
- /library/ds/disjointsparse.hpp.html
title: ds/disjointsparse.hpp
---
