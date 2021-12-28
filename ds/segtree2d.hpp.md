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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree2d.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree2d.hpp
layout: document
redirect_from:
- /library/ds/segtree2d.hpp
- /library/ds/segtree2d.hpp.html
title: ds/segtree2d.hpp
---
