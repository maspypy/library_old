---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/treegroup.hpp
    title: graph/treegroup.hpp
  - icon: ':heavy_check_mark:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ sm))) {\n        while (R < n) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(\"\
    segtree\", dat); }\n};\n"
  code: "#pragma once\ntemplate <class Monoid>\nstruct SegTree {\n  using X = typename\
    \ Monoid::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\
    \n  SegTree() : SegTree(0) {}\n  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit))\
    \ {}\n  SegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit);\n\
    \    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\
    \n  X operator[](int i) { return dat[size + i]; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n  void set(int i, X x) {\n  \
    \  assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n \
    \ }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n    assert(R <= n);\n  \
    \  X vl = Monoid::unit, vr = Monoid::unit;\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1)\
    \ vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  X prod_all() { return dat[1];}\n\n  template <class F>\n  int\
    \ max_right(F &check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit;\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F &check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit;\n    do {\n      --R;\n      while (R > 1 && (R % 2))\
    \ R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R < n)\
    \ {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R], sm))) {\n\
    \            sm = Monoid::op(dat[R], sm);\n            R--;\n          }\n   \
    \     }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(\"\
    segtree\", dat); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree.hpp
  requiredBy:
  - graph/treemonoid.hpp
  - graph/treegroup.hpp
  timestamp: '2022-01-16 05:01:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
documentation_of: ds/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree.hpp
- /library/ds/segtree.hpp.html
title: ds/segtree.hpp
---
