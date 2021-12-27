---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/treegroup.hpp
    title: graph/treegroup.hpp
  - icon: ':x:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \n#line 3 \"ds/segtree.hpp\"\n\ntemplate <typename E>\nstruct SegTree {\n  using\
    \ F = function<E(E, E)>;\n  int N_;\n  int N;\n  F seg_f;\n  E unit;\n  vector<E>\
    \ dat;\n\n  SegTree(Monoid<E> Mono) : seg_f(Mono.f), unit(Mono.unit) {}\n\n  void\
    \ init(int n_) {\n    N_ = n_;\n    N = 1;\n    while (N < n_) N <<= 1;\n    dat.assign(N\
    \ << 1, unit);\n  }\n\n  void build(const vector<E> &v) {\n    assert(len(v) ==\
    \ N_);\n    FOR(i, len(v)) { dat[N + i] = v[i]; }\n    FOR3_R(i, 1, N) { dat[i]\
    \ = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\n  void set(int i, E x)\
    \ {\n    assert(i < N_);\n    dat[i += N] = x;\n    while (i >>= 1) { dat[i] =\
    \ seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\n  E prod(int L, int R) {\n\
    \    assert(L <= R);\n    assert(R <= N_);\n    E vl = unit, vr = unit;\n    L\
    \ += N;\n    R += N;\n    while (L < R) {\n      if (L & 1) vl = seg_f(vl, dat[L++]);\n\
    \      if (R & 1) vr = seg_f(dat[--R], vr);\n      L >>= 1;\n      R >>= 1;\n\
    \    }\n    return seg_f(vl, vr);\n  }\n\n  template <class F>\n  int max_right(F\
    \ &check, int L) {\n    assert(0 <= L && L <= N_ && check(unit));\n    if (L ==\
    \ N_) return N_;\n    L += N;\n    E sm = unit;\n    do {\n      while (L % 2\
    \ == 0) L >>= 1;\n      if (!check(seg_f(sm, dat[L]))) {\n        while (L < N)\
    \ {\n          L = 2 * L;\n          if (check(seg_f(sm, dat[L]))) {\n       \
    \     sm = seg_f(sm, dat[L]);\n            L++;\n          }\n        }\n    \
    \    return L - N;\n      }\n      sm = seg_f(sm, dat[L]);\n      L++;\n    }\
    \ while ((L & -L) != L);\n    return N_;\n  }\n\n  template <class F>\n  int min_left(F\
    \ &check, int R) {\n    assert(0 <= R && R <= N_ && check(unit));\n    if (R ==\
    \ 0) return 0;\n    R += N;\n    E sm = unit;\n    do {\n      --R;\n      while\
    \ (R > 1 && (R % 2)) R >>= 1;\n      if (!check(seg_f(dat[R], sm))) {\n      \
    \  while (R < N) {\n          R = 2 * R + 1;\n          if (check(seg_f(dat[R],\
    \ sm))) {\n            sm = seg_f(dat[R], sm);\n            R--;\n          }\n\
    \        }\n        return R + 1 - N;\n      }\n      sm = seg_f(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(dat);\
    \ }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid.hpp\"\n\ntemplate <typename E>\n\
    struct SegTree {\n  using F = function<E(E, E)>;\n  int N_;\n  int N;\n  F seg_f;\n\
    \  E unit;\n  vector<E> dat;\n\n  SegTree(Monoid<E> Mono) : seg_f(Mono.f), unit(Mono.unit)\
    \ {}\n\n  void init(int n_) {\n    N_ = n_;\n    N = 1;\n    while (N < n_) N\
    \ <<= 1;\n    dat.assign(N << 1, unit);\n  }\n\n  void build(const vector<E> &v)\
    \ {\n    assert(len(v) == N_);\n    FOR(i, len(v)) { dat[N + i] = v[i]; }\n  \
    \  FOR3_R(i, 1, N) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\
    \n  void set(int i, E x) {\n    assert(i < N_);\n    dat[i += N] = x;\n    while\
    \ (i >>= 1) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\n  E\
    \ prod(int L, int R) {\n    assert(L <= R);\n    assert(R <= N_);\n    E vl =\
    \ unit, vr = unit;\n    L += N;\n    R += N;\n    while (L < R) {\n      if (L\
    \ & 1) vl = seg_f(vl, dat[L++]);\n      if (R & 1) vr = seg_f(dat[--R], vr);\n\
    \      L >>= 1;\n      R >>= 1;\n    }\n    return seg_f(vl, vr);\n  }\n\n  template\
    \ <class F>\n  int max_right(F &check, int L) {\n    assert(0 <= L && L <= N_\
    \ && check(unit));\n    if (L == N_) return N_;\n    L += N;\n    E sm = unit;\n\
    \    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(seg_f(sm, dat[L])))\
    \ {\n        while (L < N) {\n          L = 2 * L;\n          if (check(seg_f(sm,\
    \ dat[L]))) {\n            sm = seg_f(sm, dat[L]);\n            L++;\n       \
    \   }\n        }\n        return L - N;\n      }\n      sm = seg_f(sm, dat[L]);\n\
    \      L++;\n    } while ((L & -L) != L);\n    return N_;\n  }\n\n  template <class\
    \ F>\n  int min_left(F &check, int R) {\n    assert(0 <= R && R <= N_ && check(unit));\n\
    \    if (R == 0) return 0;\n    R += N;\n    E sm = unit;\n    do {\n      --R;\n\
    \      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(seg_f(dat[R], sm)))\
    \ {\n        while (R < N) {\n          R = 2 * R + 1;\n          if (check(seg_f(dat[R],\
    \ sm))) {\n            sm = seg_f(dat[R], sm);\n            R--;\n          }\n\
    \        }\n        return R + 1 - N;\n      }\n      sm = seg_f(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(dat);\
    \ }\n};\n"
  dependsOn:
  - algebra/monoid.hpp
  isVerificationFile: false
  path: ds/segtree.hpp
  requiredBy:
  - graph/treegroup.hpp
  - graph/treemonoid.hpp
  timestamp: '2021-12-27 09:14:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: ds/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree.hpp
- /library/ds/segtree.hpp.html
title: ds/segtree.hpp
---
