---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n\
    \  F f;\r\n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP>\r\nstruct Monoid_OP {\r\n  using\
    \ F = function<E(E, E)>;\r\n  using G = function<E(E, OP)>;\r\n  using H = function<OP(OP,\
    \ OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n  E unit;\r\n  OP OP_unit;\r\n  bool\
    \ commute;\r\n  bool OP_commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_reverse(Monoid<E> Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return\
    \ Mono.f(y, x); };\r\n  return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute,\
    \ Mono.has_inverse, Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_add() {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto\
    \ g = [](E x) -> E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f\
    \ = [](E x, E y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true,\
    \ false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF)\
    \ {\r\n  auto f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f,\
    \ MINUS_INF, true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E,\
    \ E>> Monoid_affine(bool has_inverse = false) {\r\n  auto f = [](pair<E, E> x,\
    \ pair<E, E> y) -> pair<E, E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\
    \n  };\r\n  auto inv = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b\
    \ iff x = (1/a) y - (b/a)\r\n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n   \
    \ return {a, a * (-b)};\r\n  };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)),\
    \ false, has_inverse, inv});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid_OP<pair<E,\
    \ E>, pair<E, E>> Monoid_cnt_sum_affine() {\r\n  using P = pair<E, E>;\r\n  auto\
    \ f = [](P x, P y) -> P { return P({x.fi + y.fi, x.se + y.se}); };\r\n  auto g\
    \ = [](P x, P y) -> P { return P({x.fi, x.fi * y.se + x.se * y.fi}); };\r\n  auto\
    \ h = [](P x, P y) -> P { return P({x.fi * y.fi, x.se * y.fi + y.se}); };\r\n\
    \  return Monoid_OP<P, P>({f, g, h, P({0, 0}), P({1, 0}), true, false});\r\n}\r\
    \n#line 2 \"ds/segtree2d.hpp\"\n\r\ntemplate <typename E, bool SMALL = false>\r\
    \nstruct SegTree2D {\r\n  using F = function<E(E, E)>;\r\n  E unit;\r\n  F f;\r\
    \n  int N;\r\n  int full_N;\r\n  vi keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\
    \n  vi keyY;\r\n  vc<E> dat;\r\n\r\n  SegTree2D(Monoid<E> Mono, vi& X, vi& Y,\
    \ vc<E>& wt) : f(Mono.f), unit(Mono.unit) {\r\n    assert(Mono.commute); // \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\u306E\u307F\r\n    build(X, Y, wt);\r\n  }\r\n\r\
    \n  SegTree2D(Monoid<E> Mono, vi& X, vi& Y) : f(Mono.f), unit(Mono.unit) {\r\n\
    \    assert(Mono.commute); // \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u306E\u307F\
    \r\n    vc<E> wt(len(X), unit);\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  inline\
    \ int xtoi(int x) { return (SMALL ? clamp(x - min_X, 0, N) : LB(keyX, x)); }\r\
    \n\r\n  void build(vi& X, vi& Y, vc<E>& wt) {\r\n    if (!SMALL) {\r\n      keyX\
    \ = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\n    } else {\r\n    \
    \  min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\
    \n    }\r\n\r\n    vc<vi> keyY_raw(N + N);\r\n    vc<vc<E>> dat_raw(N + N);\r\n\
    \r\n    auto I = argsort(Y);\r\n    for (auto&& i: I) {\r\n      int ix = xtoi(X[i]),\
    \ y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\
    \n        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n    \
    \      dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = f(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\n      }\r\
    \n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N) indptr[i\
    \ + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\n\
    \    keyY.resize(full_N);\r\n    dat.assign(2 * full_N, unit);\r\n    FOR(i, N\
    \ + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      \
    \  dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR3_R(j, 1, n)\r\n \
    \     dat[off + j] = f(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\n    }\r\
    \n  }\r\n\r\n  void multiply_i(int i, ll y, E val) {\r\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int\
    \ j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID + j] == y);\r\n\
    \    int off = 2 * LID;\r\n    j += n;\r\n\r\n    while (j) {\r\n      dat[off\
    \ + j] = f(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n  void\
    \ multiply(ll x, ll y, E val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i]\
    \ == x);\r\n    i += N;\r\n    while (i) {\r\n      multiply_i(i, y, val);\r\n\
    \      i >>= 1;\r\n    }\r\n  }\r\n\r\n  E prod_i(int i, ll ly, ll ry) {\r\n \
    \   E ret = 0;\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it, it + n, ly)\
    \ - it;\r\n    int R = lower_bound(it, it + n, ry) - it;\r\n    int off = 2 *\
    \ LID;\r\n    L += n;\r\n    R += n;\r\n    E val = unit;\r\n    while (L < R)\
    \ {\r\n      if (L & 1) val = f(val, dat[off + (L++)]);\r\n      if (R & 1) val\
    \ = f(dat[off + (--R)], val);\r\n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n\
    \    return val;\r\n  }\r\n\r\n  E prod(ll lx, ll rx, ll ly, ll ry) {\r\n    int\
    \ L = xtoi(lx);\r\n    int R = xtoi(rx);\r\n    L += N;\r\n    R += N;\r\n   \
    \ E val = unit;\r\n    while (L < R) {\r\n      if (L & 1) val = f(val, prod_i(L++,\
    \ ly, ry));\r\n      if (R & 1) val = f(prod_i(--R, ly, ry), val);\r\n      L\
    \ >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n    print(\"\
    keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n};\n"
  code: "#include \"algebra/monoid.hpp\"\r\n\r\ntemplate <typename E, bool SMALL =\
    \ false>\r\nstruct SegTree2D {\r\n  using F = function<E(E, E)>;\r\n  E unit;\r\
    \n  F f;\r\n  int N;\r\n  int full_N;\r\n  vi keyX;\r\n  int min_X;\r\n  vc<int>\
    \ indptr;\r\n  vi keyY;\r\n  vc<E> dat;\r\n\r\n  SegTree2D(Monoid<E> Mono, vi&\
    \ X, vi& Y, vc<E>& wt) : f(Mono.f), unit(Mono.unit) {\r\n    assert(Mono.commute);\
    \ // \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u306E\u307F\r\n    build(X, Y, wt);\r\
    \n  }\r\n\r\n  SegTree2D(Monoid<E> Mono, vi& X, vi& Y) : f(Mono.f), unit(Mono.unit)\
    \ {\r\n    assert(Mono.commute); // \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u306E\
    \u307F\r\n    vc<E> wt(len(X), unit);\r\n    build(X, Y, wt);\r\n  }\r\n\r\n \
    \ inline int xtoi(int x) { return (SMALL ? clamp(x - min_X, 0, N) : LB(keyX, x));\
    \ }\r\n\r\n  void build(vi& X, vi& Y, vc<E>& wt) {\r\n    if (!SMALL) {\r\n  \
    \    keyX = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\n    } else {\r\
    \n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\
    \n    }\r\n\r\n    vc<vi> keyY_raw(N + N);\r\n    vc<vc<E>> dat_raw(N + N);\r\n\
    \r\n    auto I = argsort(Y);\r\n    for (auto&& i: I) {\r\n      int ix = xtoi(X[i]),\
    \ y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\
    \n        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n    \
    \      dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = f(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\n      }\r\
    \n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N) indptr[i\
    \ + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\n\
    \    keyY.resize(full_N);\r\n    dat.assign(2 * full_N, unit);\r\n    FOR(i, N\
    \ + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      \
    \  dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR3_R(j, 1, n)\r\n \
    \     dat[off + j] = f(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\n    }\r\
    \n  }\r\n\r\n  void multiply_i(int i, ll y, E val) {\r\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int\
    \ j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID + j] == y);\r\n\
    \    int off = 2 * LID;\r\n    j += n;\r\n\r\n    while (j) {\r\n      dat[off\
    \ + j] = f(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n  void\
    \ multiply(ll x, ll y, E val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i]\
    \ == x);\r\n    i += N;\r\n    while (i) {\r\n      multiply_i(i, y, val);\r\n\
    \      i >>= 1;\r\n    }\r\n  }\r\n\r\n  E prod_i(int i, ll ly, ll ry) {\r\n \
    \   E ret = 0;\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it, it + n, ly)\
    \ - it;\r\n    int R = lower_bound(it, it + n, ry) - it;\r\n    int off = 2 *\
    \ LID;\r\n    L += n;\r\n    R += n;\r\n    E val = unit;\r\n    while (L < R)\
    \ {\r\n      if (L & 1) val = f(val, dat[off + (L++)]);\r\n      if (R & 1) val\
    \ = f(dat[off + (--R)], val);\r\n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n\
    \    return val;\r\n  }\r\n\r\n  E prod(ll lx, ll rx, ll ly, ll ry) {\r\n    int\
    \ L = xtoi(lx);\r\n    int R = xtoi(rx);\r\n    L += N;\r\n    R += N;\r\n   \
    \ E val = unit;\r\n    while (L < R) {\r\n      if (L & 1) val = f(val, prod_i(L++,\
    \ ly, ry));\r\n      if (R & 1) val = f(prod_i(--R, ly, ry), val);\r\n      L\
    \ >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n    print(\"\
    keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n};"
  dependsOn:
  - algebra/monoid.hpp
  isVerificationFile: false
  path: ds/segtree2d.hpp
  requiredBy: []
  timestamp: '2021-12-27 17:43:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
documentation_of: ds/segtree2d.hpp
layout: document
redirect_from:
- /library/ds/segtree2d.hpp
- /library/ds/segtree2d.hpp.html
title: ds/segtree2d.hpp
---
