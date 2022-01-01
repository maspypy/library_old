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
  bundledCode: "#line 1 \"ds/disjointsparse.hpp\"\ntemplate <class Monoid>\r\nstruct\
    \ DisjointSparse {\r\n  using X = typename Monoid::value_type;\r\n  using value_type\
    \ = X;\r\n  int n, log;\r\n  vc<vc<X>> dat;\r\n\r\n  DisjointSparse(vc<X>& A)\
    \ : n(len(A)) {\r\n    log = 1;\r\n    while ((1 << log) < n) ++log;\r\n    dat.assign(log,\
    \ A);\r\n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\n      int b = 1 <<\
    \ i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n        int L = m - b,\
    \ R = min(n, m + b);\r\n        FOR3_R(j, L + 1, m) v[j - 1] = Monoid::op(v[j\
    \ - 1], v[j]);\r\n        FOR3(j, m, R - 1) v[j + 1] = Monoid::op(v[j], v[j +\
    \ 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L\
    \ == R) return Monoid::unit;\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\
    \n    int k = 31 - __builtin_clz(L ^ R);\r\n    return Monoid::op(dat[k][L], dat[k][R]);\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"disjoint sparse table\");\r\n   \
    \ FOR(i, log) print(dat[i]);\r\n  }\r\n};\r\n"
  code: "template <class Monoid>\r\nstruct DisjointSparse {\r\n  using X = typename\
    \ Monoid::value_type;\r\n  using value_type = X;\r\n  int n, log;\r\n  vc<vc<X>>\
    \ dat;\r\n\r\n  DisjointSparse(vc<X>& A) : n(len(A)) {\r\n    log = 1;\r\n   \
    \ while ((1 << log) < n) ++log;\r\n    dat.assign(log, A);\r\n\r\n    FOR(i, log)\
    \ {\r\n      auto& v = dat[i];\r\n      int b = 1 << i;\r\n      for (int m =\
    \ b; m <= n; m += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n  \
    \      FOR3_R(j, L + 1, m) v[j - 1] = Monoid::op(v[j - 1], v[j]);\r\n        FOR3(j,\
    \ m, R - 1) v[j + 1] = Monoid::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  X prod(int L, int R) {\r\n    if (L == R) return Monoid::unit;\r\n   \
    \ --R;\r\n    if (L == R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L\
    \ ^ R);\r\n    return Monoid::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"disjoint sparse table\");\r\n    FOR(i, log) print(dat[i]);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/disjointsparse.hpp
  requiredBy: []
  timestamp: '2021-12-28 06:02:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/disjointsparse.hpp
layout: document
redirect_from:
- /library/ds/disjointsparse.hpp
- /library/ds/disjointsparse.hpp.html
title: ds/disjointsparse.hpp
---
