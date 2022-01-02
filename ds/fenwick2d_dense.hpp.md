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
  bundledCode: "#line 1 \"ds/fenwick2d_dense.hpp\"\n// \u8981\u308B\u3068\u601D\u3063\
    \u305F\u554F\u984C\u3067\u4F7F\u3048\u306A\u304B\u3063\u305F\u305F\u3081\u3001\
    \u4E00\u5EA6\u3082\u52D5\u4F5C\u78BA\u8A8D\u3057\u3066\u3044\u306A\u3044\uFF01\
    \r\ntemplate <typename AbelGroup>\r\nstruct Fenwick2D_dense {\r\n  using E = typename\
    \ AbelGroup::value_type;\r\n  int H, W;\r\n  vc<vc<E>> dat;\r\n\r\n  Fenwick2D_dense()\
    \ {}\r\n  Fenwick2D_dense(int H, int W) : H(H), W(W), dat(H + 1, vc<E>(W + 1))\
    \ {}\r\n\r\n  void add_x(int x, int y, E val) {\r\n    ++y;\r\n    while (y <=\
    \ W) {\r\n      dat[x][y] = AbelGroup::op(dat[x][y], val);\r\n      y += y & -y;\r\
    \n    }\r\n  }\r\n\r\n  void add(int x, int y, E val) {\r\n    ++x;\r\n    while\
    \ (x <= H) {\r\n      add_x(x, y, val);\r\n      x += x & -x;\r\n    }\r\n  }\r\
    \n\r\n  E sum_x(int x, int ly, int ry) {\r\n    ly++, ry++;\r\n    E pos = AbelGroup::unit;\r\
    \n    E neg = AbelGroup::unit;\r\n    while (ly < ry) {\r\n      pos = AbelGroup::op(pos,\
    \ dat[x][ry]);\r\n      ry -= ry & -ry;\r\n    }\r\n    while (ry < ly) {\r\n\
    \      neg = AbelGroup::op(neg, dat[x][ly]);\r\n      ly -= ly & -ly;\r\n    }\r\
    \n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E sum(int\
    \ lx, int rx, int ly, int ry) {\r\n    lx++, rx++;\r\n    E pos = AbelGroup::unit;\r\
    \n    E neg = AbelGroup::unit;\r\n    while (lx < rx) {\r\n      pos = AbelGroup::op(pos,\
    \ sum_x(rx, ly, ry));\r\n      rx -= rx & -rx;\r\n    }\r\n    while (rx < lx)\
    \ {\r\n      neg = AbelGroup::op(neg, sum_x(lx, ly, ry));\r\n      lx -= lx &\
    \ -lx;\r\n    }\r\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n\
    \  }\r\n};\r\n"
  code: "// \u8981\u308B\u3068\u601D\u3063\u305F\u554F\u984C\u3067\u4F7F\u3048\u306A\
    \u304B\u3063\u305F\u305F\u3081\u3001\u4E00\u5EA6\u3082\u52D5\u4F5C\u78BA\u8A8D\
    \u3057\u3066\u3044\u306A\u3044\uFF01\r\ntemplate <typename AbelGroup>\r\nstruct\
    \ Fenwick2D_dense {\r\n  using E = typename AbelGroup::value_type;\r\n  int H,\
    \ W;\r\n  vc<vc<E>> dat;\r\n\r\n  Fenwick2D_dense() {}\r\n  Fenwick2D_dense(int\
    \ H, int W) : H(H), W(W), dat(H + 1, vc<E>(W + 1)) {}\r\n\r\n  void add_x(int\
    \ x, int y, E val) {\r\n    ++y;\r\n    while (y <= W) {\r\n      dat[x][y] =\
    \ AbelGroup::op(dat[x][y], val);\r\n      y += y & -y;\r\n    }\r\n  }\r\n\r\n\
    \  void add(int x, int y, E val) {\r\n    ++x;\r\n    while (x <= H) {\r\n   \
    \   add_x(x, y, val);\r\n      x += x & -x;\r\n    }\r\n  }\r\n\r\n  E sum_x(int\
    \ x, int ly, int ry) {\r\n    ly++, ry++;\r\n    E pos = AbelGroup::unit;\r\n\
    \    E neg = AbelGroup::unit;\r\n    while (ly < ry) {\r\n      pos = AbelGroup::op(pos,\
    \ dat[x][ry]);\r\n      ry -= ry & -ry;\r\n    }\r\n    while (ry < ly) {\r\n\
    \      neg = AbelGroup::op(neg, dat[x][ly]);\r\n      ly -= ly & -ly;\r\n    }\r\
    \n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E sum(int\
    \ lx, int rx, int ly, int ry) {\r\n    lx++, rx++;\r\n    E pos = AbelGroup::unit;\r\
    \n    E neg = AbelGroup::unit;\r\n    while (lx < rx) {\r\n      pos = AbelGroup::op(pos,\
    \ sum_x(rx, ly, ry));\r\n      rx -= rx & -rx;\r\n    }\r\n    while (rx < lx)\
    \ {\r\n      neg = AbelGroup::op(neg, sum_x(lx, ly, ry));\r\n      lx -= lx &\
    \ -lx;\r\n    }\r\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n\
    \  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwick2d_dense.hpp
  requiredBy: []
  timestamp: '2022-01-03 02:37:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwick2d_dense.hpp
layout: document
redirect_from:
- /library/ds/fenwick2d_dense.hpp
- /library/ds/fenwick2d_dense.hpp.html
title: ds/fenwick2d_dense.hpp
---
