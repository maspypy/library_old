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
  bundledCode: "#line 1 \"other/cumsum2d.hpp\"\ntemplate <typename T>\r\nstruct Cumsum2D\
    \ {\r\n  int H, W;\r\n  vc<vc<T>> dat;\r\n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<T>>&\
    \ A) { build(A); }\r\n\r\n  void build(vc<vc<T>>& A) {\r\n    int H = len(A);\r\
    \n    int W = (H == 0 ? 0 : len(A[0]));\r\n    dat.assign(H + 1, vc<T>(W + 1));\r\
    \n    FOR(x, H) FOR(y, W) dat[x + 1][y + 1] = A[x][y];\r\n    FOR(x, H + 1) FOR(y,\
    \ W) dat[x][y + 1] += dat[x][y];\r\n    FOR(x, H) FOR(y, W + 1) dat[x + 1][y]\
    \ += dat[x][y];\r\n  }\r\n\r\n  T get(int x1, int x2, int y1, int y2) {\r\n  \
    \  T val = T(0);\r\n    val += dat[x1][y1];\r\n    val -= dat[x1][y2];\r\n   \
    \ val -= dat[x2][y1];\r\n    val += dat[x2][y2];\r\n    return val;\r\n  }\r\n\
    };\n"
  code: "template <typename T>\r\nstruct Cumsum2D {\r\n  int H, W;\r\n  vc<vc<T>>\
    \ dat;\r\n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<T>>& A) { build(A); }\r\n\r\n\
    \  void build(vc<vc<T>>& A) {\r\n    int H = len(A);\r\n    int W = (H == 0 ?\
    \ 0 : len(A[0]));\r\n    dat.assign(H + 1, vc<T>(W + 1));\r\n    FOR(x, H) FOR(y,\
    \ W) dat[x + 1][y + 1] = A[x][y];\r\n    FOR(x, H + 1) FOR(y, W) dat[x][y + 1]\
    \ += dat[x][y];\r\n    FOR(x, H) FOR(y, W + 1) dat[x + 1][y] += dat[x][y];\r\n\
    \  }\r\n\r\n  T get(int x1, int x2, int y1, int y2) {\r\n    T val = T(0);\r\n\
    \    val += dat[x1][y1];\r\n    val -= dat[x1][y2];\r\n    val -= dat[x2][y1];\r\
    \n    val += dat[x2][y2];\r\n    return val;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/cumsum2d.hpp
  requiredBy: []
  timestamp: '2022-02-04 02:55:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/cumsum2d.hpp
layout: document
redirect_from:
- /library/other/cumsum2d.hpp
- /library/other/cumsum2d.hpp.html
title: other/cumsum2d.hpp
---
