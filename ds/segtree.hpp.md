---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree.hpp\"\n\ntemplate <typename T>\nstruct SegTree\
    \ {\n  using F = function<T(T, T)>;\n  int N_;\n  int N;\n  F seg_f;\n  T T_unit;\n\
    \  vector<T> dat;\n\n  SegTree(F f, T T_unit) : seg_f(f), T_unit(T_unit) {}\n\n\
    \  void init(int n_) {\n    N_ = n_;\n    N = 1;\n    while (N < n_) N <<= 1;\n\
    \    dat.assign(N << 1, T_unit);\n  }\n\n  void build(const vector<T> &v) {\n\
    \    assert(v.size() == N_);\n    FOR(i, v.size()) { dat[N + i] = v[i]; }\n  \
    \  FOR3_R(i, 1, N) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\
    \n  void set(int i, T x) {\n    assert(i < N_);\n    dat[i += N] = x;\n    while\
    \ (i >>= 1) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\n  T\
    \ fold(int L, int R) {\n    assert(L <= R);\n    assert(R <= N_);\n    T vl =\
    \ T_unit, vr = T_unit;\n    L += N;\n    R += N;\n    while (L < R) {\n      if\
    \ (L & 1) vl = seg_f(vl, dat[L++]);\n      if (R & 1) vr = seg_f(dat[--R], vr);\n\
    \      L >>= 1;\n      R >>= 1;\n    }\n    return seg_f(vl, vr);\n  }\n\n  template\
    \ <class F>\n  int max_right(F &check, int L) {\n    assert(0 <= L && L <= N_\
    \ && check(T_unit));\n    if (L == N_) return N_;\n    L += N;\n    T sm = T_unit;\n\
    \    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(seg_f(sm, dat[L])))\
    \ {\n        while (L < N) {\n          L = 2 * L;\n          if (check(seg_f(sm,\
    \ dat[L]))) {\n            sm = seg_f(sm, dat[L]);\n            L++;\n       \
    \   }\n        }\n        return L - N;\n      }\n      sm = seg_f(sm, dat[L]);\n\
    \      L++;\n    } while ((L & -L) != L);\n    return N_;\n  }\n\n  template <class\
    \ F>\n  int min_left(F &check, int R) {\n    assert(0 <= R && R <= N_ && check(T_unit));\n\
    \    if (R == 0) return 0;\n    R += N;\n    T sm = T_unit;\n    do {\n      --R;\n\
    \      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(seg_f(dat[R], sm)))\
    \ {\n        while (R < N) {\n          R = 2 * R + 1;\n          if (check(seg_f(dat[R],\
    \ sm))) {\n            sm = seg_f(dat[R], sm);\n            R--;\n          }\n\
    \        }\n        return R + 1 - N;\n      }\n      sm = seg_f(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(dat);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct SegTree {\n  using F = function<T(T,\
    \ T)>;\n  int N_;\n  int N;\n  F seg_f;\n  T T_unit;\n  vector<T> dat;\n\n  SegTree(F\
    \ f, T T_unit) : seg_f(f), T_unit(T_unit) {}\n\n  void init(int n_) {\n    N_\
    \ = n_;\n    N = 1;\n    while (N < n_) N <<= 1;\n    dat.assign(N << 1, T_unit);\n\
    \  }\n\n  void build(const vector<T> &v) {\n    assert(v.size() == N_);\n    FOR(i,\
    \ v.size()) { dat[N + i] = v[i]; }\n    FOR3_R(i, 1, N) { dat[i] = seg_f(dat[i\
    \ << 1 | 0], dat[i << 1 | 1]); }\n  }\n\n  void set(int i, T x) {\n    assert(i\
    \ < N_);\n    dat[i += N] = x;\n    while (i >>= 1) { dat[i] = seg_f(dat[i <<\
    \ 1 | 0], dat[i << 1 | 1]); }\n  }\n\n  T fold(int L, int R) {\n    assert(L <=\
    \ R);\n    assert(R <= N_);\n    T vl = T_unit, vr = T_unit;\n    L += N;\n  \
    \  R += N;\n    while (L < R) {\n      if (L & 1) vl = seg_f(vl, dat[L++]);\n\
    \      if (R & 1) vr = seg_f(dat[--R], vr);\n      L >>= 1;\n      R >>= 1;\n\
    \    }\n    return seg_f(vl, vr);\n  }\n\n  template <class F>\n  int max_right(F\
    \ &check, int L) {\n    assert(0 <= L && L <= N_ && check(T_unit));\n    if (L\
    \ == N_) return N_;\n    L += N;\n    T sm = T_unit;\n    do {\n      while (L\
    \ % 2 == 0) L >>= 1;\n      if (!check(seg_f(sm, dat[L]))) {\n        while (L\
    \ < N) {\n          L = 2 * L;\n          if (check(seg_f(sm, dat[L]))) {\n  \
    \          sm = seg_f(sm, dat[L]);\n            L++;\n          }\n        }\n\
    \        return L - N;\n      }\n      sm = seg_f(sm, dat[L]);\n      L++;\n \
    \   } while ((L & -L) != L);\n    return N_;\n  }\n\n  template <class F>\n  int\
    \ min_left(F &check, int R) {\n    assert(0 <= R && R <= N_ && check(T_unit));\n\
    \    if (R == 0) return 0;\n    R += N;\n    T sm = T_unit;\n    do {\n      --R;\n\
    \      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(seg_f(dat[R], sm)))\
    \ {\n        while (R < N) {\n          R = 2 * R + 1;\n          if (check(seg_f(dat[R],\
    \ sm))) {\n            sm = seg_f(dat[R], sm);\n            R--;\n          }\n\
    \        }\n        return R + 1 - N;\n      }\n      sm = seg_f(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(dat);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree.hpp
  requiredBy:
  - graph/treemonoid.hpp
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - test/library_checker/datastructure/point_set_range_composite.test.cpp
documentation_of: ds/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree.hpp
- /library/ds/segtree.hpp.html
title: ds/segtree.hpp
---
