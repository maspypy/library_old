---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree2d.hpp\"\ntemplate <typename E, bool SMALL = false>\r\
    \nstruct SegTree2D {\r\n  using F = function<E(E, E)>;\r\n  E E_unit;\r\n  F seg_f;\r\
    \n  int N;\r\n  int full_N;\r\n  vi keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\
    \n  vi keyY;\r\n  vc<E> dat;\r\n\r\n  SegTree2D(F f, E E_unit, vi& X, vi& Y, vc<E>&\
    \ wt) : seg_f(f), E_unit(E_unit) {\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  SegTree2D(vi&\
    \ X, vi& Y) {\r\n    vc<E> wt(len(X), E_unit);\r\n    build(X, Y, wt);\r\n  }\r\
    \n\r\n  inline int xtoi(int x) {\r\n    return (SMALL ? clamp(x - min_X, 0, N)\
    \ : LB(keyX, x));\r\n  }\r\n\r\n  void build(vi& X, vi& Y, vc<E>& wt) {\r\n  \
    \  if (!SMALL) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\
    \n    } else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X)\
    \ == 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N)\
    \ keyX[i] = min_X + i;\r\n    }\r\n\r\n    vc<vi> keyY_raw(N + N);\r\n    vc<vc<E>>\
    \ dat_raw(N + N);\r\n\r\n    auto I = argsort(Y);\r\n    FORIN(i, I) {\r\n   \
    \   int ix = xtoi(X[i]), y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\n\
    \        auto& KY = keyY_raw[ix];\r\n        if (len(KY) == 0 || KY.back() < y)\
    \ {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\n        } else\
    \ {\r\n          dat_raw[ix].back() = seg_f(dat_raw[ix].back(), wt[i]);\r\n  \
    \      }\r\n        ix >>= 1;\r\n      }\r\n    }\r\n\r\n    indptr.assign(N +\
    \ N + 1, 0);\r\n    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\
    \n    int full_N = indptr.back();\r\n    keyY.resize(full_N);\r\n    dat.assign(2\
    \ * full_N, E_unit);\r\n    FOR(i, N + N) {\r\n      int off = 2 * indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n      FOR(j, n) {\r\n        keyY[indptr[i]\
    \ + j] = keyY_raw[i][j];\r\n        dat[off + n + j] = dat_raw[i][j];\r\n    \
    \  }\r\n      FOR3_R(j, 1, n)\r\n      dat[off + j] = seg_f(dat[off + 2 * j +\
    \ 0], dat[off + 2 * j + 1]);\r\n    }\r\n  }\r\n\r\n  void multiply_i(int i, ll\
    \ y, E val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n \
    \   auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y) -\
    \ it;\r\n    assert(keyY[LID + j] == y);\r\n    int off = 2 * LID;\r\n    j +=\
    \ n;\r\n\r\n    while (j) {\r\n      dat[off + j] = seg_f(dat[off + j], val);\r\
    \n      j >>= 1;\r\n    }\r\n  }\r\n\r\n  void multiply(ll x, ll y, E val) {\r\
    \n    int i = xtoi(x);\r\n    assert(keyX[i] == x);\r\n    i += N;\r\n    while\
    \ (i) {\r\n      multiply_i(i, y, val);\r\n      i >>= 1;\r\n    }\r\n  }\r\n\r\
    \n  E prod_i(int i, ll ly, ll ry) {\r\n    E ret = 0;\r\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int\
    \ L = lower_bound(it, it + n, ly) - it;\r\n    int R = lower_bound(it, it + n,\
    \ ry) - it;\r\n    int off = 2 * LID;\r\n    L += n;\r\n    R += n;\r\n    E val\
    \ = E_unit;\r\n    while (L < R) {\r\n      if (L & 1) val = seg_f(val, dat[off\
    \ + (L++)]);\r\n      if (R & 1) val = seg_f(dat[off + (--R)], val);\r\n     \
    \ L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n  E prod(ll\
    \ lx, ll rx, ll ly, ll ry) {\r\n    int L = xtoi(lx);\r\n    int R = xtoi(rx);\r\
    \n    L += N;\r\n    R += N;\r\n    E val = E_unit;\r\n    while (L < R) {\r\n\
    \      if (L & 1) val = seg_f(val, prod_i(L++, ly, ry));\r\n      if (R & 1) val\
    \ = seg_f(prod_i(--R, ly, ry), val);\r\n      L >>= 1;\r\n      R >>= 1;\r\n \
    \   }\r\n    return val;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"keyX\"\
    , keyX);\r\n    print(\"indptr\", indptr);\r\n    print(\"keyY\", keyY);\r\n \
    \   print(\"dat\", dat);\r\n  }\r\n};\n"
  code: "template <typename E, bool SMALL = false>\r\nstruct SegTree2D {\r\n  using\
    \ F = function<E(E, E)>;\r\n  E E_unit;\r\n  F seg_f;\r\n  int N;\r\n  int full_N;\r\
    \n  vi keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\n  vi keyY;\r\n  vc<E> dat;\r\
    \n\r\n  SegTree2D(F f, E E_unit, vi& X, vi& Y, vc<E>& wt) : seg_f(f), E_unit(E_unit)\
    \ {\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  SegTree2D(vi& X, vi& Y) {\r\n    vc<E>\
    \ wt(len(X), E_unit);\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  inline int xtoi(int\
    \ x) {\r\n    return (SMALL ? clamp(x - min_X, 0, N) : LB(keyX, x));\r\n  }\r\n\
    \r\n  void build(vi& X, vi& Y, vc<E>& wt) {\r\n    if (!SMALL) {\r\n      keyX\
    \ = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\n    } else {\r\n    \
    \  min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\
    \n    }\r\n\r\n    vc<vi> keyY_raw(N + N);\r\n    vc<vc<E>> dat_raw(N + N);\r\n\
    \r\n    auto I = argsort(Y);\r\n    FORIN(i, I) {\r\n      int ix = xtoi(X[i]),\
    \ y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\
    \n        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n    \
    \      dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = seg_f(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\n  \
    \    }\r\n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N) indptr[i\
    \ + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\n\
    \    keyY.resize(full_N);\r\n    dat.assign(2 * full_N, E_unit);\r\n    FOR(i,\
    \ N + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      \
    \  dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR3_R(j, 1, n)\r\n \
    \     dat[off + j] = seg_f(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\n  \
    \  }\r\n  }\r\n\r\n  void multiply_i(int i, ll y, E val) {\r\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int\
    \ j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID + j] == y);\r\n\
    \    int off = 2 * LID;\r\n    j += n;\r\n\r\n    while (j) {\r\n      dat[off\
    \ + j] = seg_f(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n \
    \ void multiply(ll x, ll y, E val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i]\
    \ == x);\r\n    i += N;\r\n    while (i) {\r\n      multiply_i(i, y, val);\r\n\
    \      i >>= 1;\r\n    }\r\n  }\r\n\r\n  E prod_i(int i, ll ly, ll ry) {\r\n \
    \   E ret = 0;\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it, it + n, ly)\
    \ - it;\r\n    int R = lower_bound(it, it + n, ry) - it;\r\n    int off = 2 *\
    \ LID;\r\n    L += n;\r\n    R += n;\r\n    E val = E_unit;\r\n    while (L <\
    \ R) {\r\n      if (L & 1) val = seg_f(val, dat[off + (L++)]);\r\n      if (R\
    \ & 1) val = seg_f(dat[off + (--R)], val);\r\n      L >>= 1;\r\n      R >>= 1;\r\
    \n    }\r\n    return val;\r\n  }\r\n\r\n  E prod(ll lx, ll rx, ll ly, ll ry)\
    \ {\r\n    int L = xtoi(lx);\r\n    int R = xtoi(rx);\r\n    L += N;\r\n    R\
    \ += N;\r\n    E val = E_unit;\r\n    while (L < R) {\r\n      if (L & 1) val\
    \ = seg_f(val, prod_i(L++, ly, ry));\r\n      if (R & 1) val = seg_f(prod_i(--R,\
    \ ly, ry), val);\r\n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\"\
    , indptr);\r\n    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree2d.hpp
  requiredBy: []
  timestamp: '2021-12-26 17:48:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
documentation_of: ds/segtree2d.hpp
layout: document
redirect_from:
- /library/ds/segtree2d.hpp
- /library/ds/segtree2d.hpp.html
title: ds/segtree2d.hpp
---
