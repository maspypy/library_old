---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842_fenwick2d_dense.test.cpp
    title: test/aoj/2842_fenwick2d_dense.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fenwick2d_dense.hpp\"\n\
    template <typename AbelGroup>\r\nstruct Fenwick2D_dense {\r\n  using E = typename\
    \ AbelGroup::value_type;\r\n  int H, W;\r\n  vc<vc<E>> dat;\r\n\r\n  Fenwick2D_dense()\
    \ {}\r\n  Fenwick2D_dense(int H, int W) : H(H), W(W), dat(H + 1, vc<E>(W + 1))\
    \ {}\r\n\r\n  void add_x(int x, int y, E val) {\r\n    ++y;\r\n    while (y <=\
    \ W) {\r\n      dat[x][y] = AbelGroup::op(dat[x][y], val);\r\n      y += y & -y;\r\
    \n    }\r\n  }\r\n\r\n  void add(int x, int y, E val) {\r\n    ++x;\r\n    while\
    \ (x <= H) {\r\n      add_x(x, y, val);\r\n      x += x & -x;\r\n    }\r\n  }\r\
    \n\r\n  E sum_x(int x, int ly, int ry) {\r\n    E pos = AbelGroup::unit;\r\n \
    \   E neg = AbelGroup::unit;\r\n    while (ly < ry) {\r\n      pos = AbelGroup::op(pos,\
    \ dat[x][ry]);\r\n      ry -= ry & -ry;\r\n    }\r\n    while (ry < ly) {\r\n\
    \      neg = AbelGroup::op(neg, dat[x][ly]);\r\n      ly -= ly & -ly;\r\n    }\r\
    \n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E sum(int\
    \ lx, int ly, int rx, int ry) {\r\n    E pos = AbelGroup::unit;\r\n    E neg =\
    \ AbelGroup::unit;\r\n    while (lx < rx) {\r\n      pos = AbelGroup::op(pos,\
    \ sum_x(rx, ly, ry));\r\n      rx -= rx & -rx;\r\n    }\r\n    while (rx < lx)\
    \ {\r\n      neg = AbelGroup::op(neg, sum_x(lx, ly, ry));\r\n      lx -= lx &\
    \ -lx;\r\n    }\r\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n\
    \  }\r\n\r\n  void debug(){\r\n    print(\"Fenwick2d dat\");\r\n    FOR(x, H +\
    \ 1) print(dat[x]);\r\n  }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\ntemplate <typename AbelGroup>\r\nstruct\
    \ Fenwick2D_dense {\r\n  using E = typename AbelGroup::value_type;\r\n  int H,\
    \ W;\r\n  vc<vc<E>> dat;\r\n\r\n  Fenwick2D_dense() {}\r\n  Fenwick2D_dense(int\
    \ H, int W) : H(H), W(W), dat(H + 1, vc<E>(W + 1)) {}\r\n\r\n  void add_x(int\
    \ x, int y, E val) {\r\n    ++y;\r\n    while (y <= W) {\r\n      dat[x][y] =\
    \ AbelGroup::op(dat[x][y], val);\r\n      y += y & -y;\r\n    }\r\n  }\r\n\r\n\
    \  void add(int x, int y, E val) {\r\n    ++x;\r\n    while (x <= H) {\r\n   \
    \   add_x(x, y, val);\r\n      x += x & -x;\r\n    }\r\n  }\r\n\r\n  E sum_x(int\
    \ x, int ly, int ry) {\r\n    E pos = AbelGroup::unit;\r\n    E neg = AbelGroup::unit;\r\
    \n    while (ly < ry) {\r\n      pos = AbelGroup::op(pos, dat[x][ry]);\r\n   \
    \   ry -= ry & -ry;\r\n    }\r\n    while (ry < ly) {\r\n      neg = AbelGroup::op(neg,\
    \ dat[x][ly]);\r\n      ly -= ly & -ly;\r\n    }\r\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E sum(int lx, int ly, int rx, int\
    \ ry) {\r\n    E pos = AbelGroup::unit;\r\n    E neg = AbelGroup::unit;\r\n  \
    \  while (lx < rx) {\r\n      pos = AbelGroup::op(pos, sum_x(rx, ly, ry));\r\n\
    \      rx -= rx & -rx;\r\n    }\r\n    while (rx < lx) {\r\n      neg = AbelGroup::op(neg,\
    \ sum_x(lx, ly, ry));\r\n      lx -= lx & -lx;\r\n    }\r\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n  }\r\n\r\n  void debug(){\r\n    print(\"Fenwick2d\
    \ dat\");\r\n    FOR(x, H + 1) print(dat[x]);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  isVerificationFile: false
  path: ds/fenwick2d_dense.hpp
  requiredBy: []
  timestamp: '2022-02-16 23:22:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842_fenwick2d_dense.test.cpp
documentation_of: ds/fenwick2d_dense.hpp
layout: document
redirect_from:
- /library/ds/fenwick2d_dense.hpp
- /library/ds/fenwick2d_dense.hpp.html
title: ds/fenwick2d_dense.hpp
---
