---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/algebra.hpp
    title: ds/algebra.hpp
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
  bundledCode: "#line 2 \"ds/algebra.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid\
    \ {\r\n  using F = function<E(E, E)>;\r\n  F f;\r\n  E E_unit;\r\n  bool commute;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP, bool commute, bool OP_commute>\r\
    \nstruct Monoid_OP {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E,\
    \ OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n\
    \  E E_unit;\r\n  OP OP_unit;\r\n};\r\n\r\ntemplate <typename E>\r\nstruct Group\
    \ {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\
    \n  E E_unit;\r\n  G inv;\r\n  bool commute;\r\n};\r\n\r\ntemplate <typename E>\r\
    \nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E x, E y) -> E { return min(x,\
    \ y); };\r\n  return Monoid<E>({f, INF, true});\r\n}\r\n\r\ntemplate <typename\
    \ E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto f = [](E x, E y) -> E {\
    \ return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF, true});\r\n}\r\n#line\
    \ 2 \"ds/disjointsparse.hpp\"\n\r\ntemplate <typename E>\r\nstruct DisjointSparse\
    \ {\r\n  using F = function<E(E, E)>;\r\n  F f;\r\n  int N, log;\r\n  vc<vc<E>>\
    \ dat;\r\n\r\n  DisjointSparse(Monoid<E> Mono, vc<E> A) : f(Mono.f), N(len(A))\
    \ {\r\n    log = 1;\r\n    while ((1 << log) < N) ++log;\r\n    dat.assign(log,\
    \ A);\r\n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\n      int B = 1 <<\
    \ i;\r\n      for (int M = B; M <= N; M += 2 * B) {\r\n        int L = M - B,\
    \ R = min(N, M + B);\r\n        FOR3_R(j, L + 1, M) v[j - 1] = f(v[j - 1], v[j]);\r\
    \n        FOR3(j, M, R - 1) v[j + 1] = f(v[j], v[j + 1]);\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  E prod(int L, int R) {\r\n    assert(L < R);\r\n    --R;\r\n  \
    \  if (L == R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n\
    \    return f(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  void debug() { FOR(i, log)\
    \ print(dat[i]); }\r\n};\r\n"
  code: "#include \"ds/algebra.hpp\"\r\n\r\ntemplate <typename E>\r\nstruct DisjointSparse\
    \ {\r\n  using F = function<E(E, E)>;\r\n  F f;\r\n  int N, log;\r\n  vc<vc<E>>\
    \ dat;\r\n\r\n  DisjointSparse(Monoid<E> Mono, vc<E> A) : f(Mono.f), N(len(A))\
    \ {\r\n    log = 1;\r\n    while ((1 << log) < N) ++log;\r\n    dat.assign(log,\
    \ A);\r\n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\n      int B = 1 <<\
    \ i;\r\n      for (int M = B; M <= N; M += 2 * B) {\r\n        int L = M - B,\
    \ R = min(N, M + B);\r\n        FOR3_R(j, L + 1, M) v[j - 1] = f(v[j - 1], v[j]);\r\
    \n        FOR3(j, M, R - 1) v[j + 1] = f(v[j], v[j + 1]);\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  E prod(int L, int R) {\r\n    assert(L < R);\r\n    --R;\r\n  \
    \  if (L == R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n\
    \    return f(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  void debug() { FOR(i, log)\
    \ print(dat[i]); }\r\n};\r\n"
  dependsOn:
  - ds/algebra.hpp
  isVerificationFile: false
  path: ds/disjointsparse.hpp
  requiredBy: []
  timestamp: '2021-12-26 18:49:28+09:00'
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
