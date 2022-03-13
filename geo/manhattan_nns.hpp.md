---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid_min_idx.hpp
    title: alg/monoid_min_idx.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/103577/problem/K
  bundledCode: "#line 2 \"ds/segtree.hpp\"\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n  vc<X>\
    \ dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) :\
    \ SegTree(vc<X>(n, Monoid::unit)) {}\n  SegTree(vc<X> v) : n(len(v)) {\n    log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid::unit);\n    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1,\
    \ size) update(i);\n  }\n\n  X operator[](int i) { return dat[size + i]; }\n\n\
    \  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n\
    \  void set(int i, X x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while\
    \ (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n\
    \    assert(R <= n);\n    X vl = Monoid::unit, vr = Monoid::unit;\n    L += size,\
    \ R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n\
    \      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n  \
    \  }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return dat[1];}\n\
    \n  template <class F>\n  int max_right(F &check, int L) {\n    assert(0 <= L\
    \ && L <= n && check(Monoid::unit));\n    if (L == n) return n;\n    L += size;\n\
    \    X sm = Monoid::unit;\n    do {\n      while (L % 2 == 0) L >>= 1;\n     \
    \ if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n        \
    \  L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n            sm\
    \ = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n      \
    \  return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n      L++;\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F &check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit;\n    do {\n\
    \      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 1 \"alg/monoid_min_idx.hpp\"\
    \ntemplate <typename T, T INF = 1LL << 60>\r\nstruct Monoid_Min_Idx {\r\n  using\
    \ value_type = pair<T, ll>;\r\n  using X = value_type;\r\n  static X op(X x, X\
    \ y) { return min(x, y); }\r\n  static constexpr X unit = X(INF, -1);\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"geo/manhattan_nns.hpp\"\n\r\
    \n// https://codeforces.com/gym/103577/problem/K\r\n// \u70B9\u7FA4 FRM \u304B\
    \u3089\u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector\
    \ \u306E pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X =\
    \ ll>\r\npair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>&\
    \ TO) {\r\n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  const X INF = numeric_limits<X>::max();\r\n\r\n  vc<int> nbd_idx(N, -1);\r\
    \n  vc<X> dist(N, INF);\r\n\r\n  auto add_ans = [&](int i, int j) -> void {\r\n\
    \    if (j == -1) return;\r\n    X dx = points[i].fi - points[j].fi;\r\n    X\
    \ dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i], abs(dx) + abs(dy)))\
    \ nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\n  iota(all(I), 0);\r\
    \n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi < points[j].fi);\
    \ });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<ll, INF>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};\n"
  code: "#include \"ds/segtree.hpp\"\r\n#include \"alg/monoid_min_idx.hpp\"\r\n\r\n\
    // https://codeforces.com/gym/103577/problem/K\r\n// \u70B9\u7FA4 FRM \u304B\u3089\
    \u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector \u306E\
    \ pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X = ll>\r\n\
    pair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>& TO) {\r\
    \n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  const X INF = numeric_limits<X>::max();\r\n\r\n  vc<int> nbd_idx(N, -1);\r\
    \n  vc<X> dist(N, INF);\r\n\r\n  auto add_ans = [&](int i, int j) -> void {\r\n\
    \    if (j == -1) return;\r\n    X dx = points[i].fi - points[j].fi;\r\n    X\
    \ dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i], abs(dx) + abs(dy)))\
    \ nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\n  iota(all(I), 0);\r\
    \n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi < points[j].fi);\
    \ });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<ll, INF>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};"
  dependsOn:
  - ds/segtree.hpp
  - alg/monoid_min_idx.hpp
  isVerificationFile: false
  path: geo/manhattan_nns.hpp
  requiredBy: []
  timestamp: '2022-03-14 00:34:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/manhattan_nns.hpp
layout: document
redirect_from:
- /library/geo/manhattan_nns.hpp
- /library/geo/manhattan_nns.hpp.html
title: geo/manhattan_nns.hpp
---
