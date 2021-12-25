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
  bundledCode: "#line 1 \"ds/disjointsparse.hpp\"\ntemplate <typename E>\r\nstruct\
    \ DisjointSparse {\r\n  using F = function<E(E, E)>;\r\n  F f;\r\n  int N, log;\r\
    \n  vc<vc<E>> dat;\r\n\r\n  DisjointSparse(F f, vc<E> A) : f(f), N(len(A)) {\r\
    \n    log = 1;\r\n    while ((1 << log) < N) ++log;\r\n    dat.assign(log, A);\r\
    \n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\n      int B = 1 << i;\r\n\
    \      for (int M = B; M <= N; M += 2 * B) {\r\n        int L = M - B, R = min(N,\
    \ M + B);\r\n        FOR3_R(j, L + 1, M) v[j - 1] = f(v[j - 1], v[j]);\r\n   \
    \     FOR3(j, M, R - 1) v[j + 1] = f(v[j], v[j + 1]);\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  E fold(int L, int R) {\r\n    assert(L < R);\r\n    --R;\r\n   \
    \ if (L == R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n\
    \    return f(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  void debug() { FOR(i, log)\
    \ print(dat[i]); }\r\n};\n"
  code: "template <typename E>\r\nstruct DisjointSparse {\r\n  using F = function<E(E,\
    \ E)>;\r\n  F f;\r\n  int N, log;\r\n  vc<vc<E>> dat;\r\n\r\n  DisjointSparse(F\
    \ f, vc<E> A) : f(f), N(len(A)) {\r\n    log = 1;\r\n    while ((1 << log) < N)\
    \ ++log;\r\n    dat.assign(log, A);\r\n\r\n    FOR(i, log) {\r\n      auto& v\
    \ = dat[i];\r\n      int B = 1 << i;\r\n      for (int M = B; M <= N; M += 2 *\
    \ B) {\r\n        int L = M - B, R = min(N, M + B);\r\n        FOR3_R(j, L + 1,\
    \ M) v[j - 1] = f(v[j - 1], v[j]);\r\n        FOR3(j, M, R - 1) v[j + 1] = f(v[j],\
    \ v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  E fold(int L, int R) {\r\n  \
    \  assert(L < R);\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\n    int\
    \ k = 31 - __builtin_clz(L ^ R);\r\n    return f(dat[k][L], dat[k][R]);\r\n  }\r\
    \n\r\n  void debug() { FOR(i, log) print(dat[i]); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/disjointsparse.hpp
  requiredBy: []
  timestamp: '2021-12-26 06:50:04+09:00'
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
