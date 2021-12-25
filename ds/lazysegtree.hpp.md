---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/treemonoid_lazy.hpp
    title: graph/treemonoid_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/lazysegtree.hpp\"\ntemplate <typename T, typename OP,\
    \ bool OP_commute = false>\nstruct LazySegTree {\n  using F = function<T(T, T)>;\n\
    \  using G = function<T(T, OP)>;\n  using H = function<OP(OP, OP)>;\n  int sz,\
    \ n, height;\n  F f;\n  G g;\n  H h;\n  T ti;\n  OP ei;\n  vector<T> dat;\n  vector<OP>\
    \ laz;\n  LazySegTree(F f, G g, H h, T ti, OP ei) : f(f), g(g), h(h), ti(ti),\
    \ ei(ei) {}\n\n  void init(int n_) {\n    sz = n_;\n    n = 1;\n    height = 0;\n\
    \    while (n < n_) n <<= 1, height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2\
    \ * n, ei);\n  }\n\n  void build(const vector<T> &v) {\n    int n_ = v.size();\n\
    \    init(n_);\n    for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n    for (int\
    \ i = n - 1; i; i--)\n      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n\
    \  }\n\n  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);\
    \ }\n\n  inline void propagate(int k) {\n    if (laz[k] == ei) return;\n    laz[(k\
    \ << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k\
    \ << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k] = ei;\n  }\n\n  inline\
    \ void thrust(int k) {\n    for (int i = height; i; i--) propagate(k >> i);\n\
    \  }\n\n  inline void recalc(int k) {\n    while (k >>= 1) dat[k] = f(reflect((k\
    \ << 1) | 0), reflect((k << 1) | 1));\n  }\n\n  void operate_range(int a, int\
    \ b, OP x) {\n    if (a >= b) return;\n    a += n, b += n - 1;\n    if (!OP_commute)\
    \ {\n      thrust(a);\n      thrust(b);\n    }\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = h(laz[l], x), l++;\n \
    \     if (r & 1) --r, laz[r] = h(laz[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  void set(int a, T x) {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a]\
    \ = ei;\n    recalc(a);\n  }\n\n  T fold(int a, int b) {\n    if (a >= b) return\
    \ ti;\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = ti, vr = ti;\n\
    \    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl\
    \ = f(vl, reflect(l++));\n      if (r & 1) vr = f(reflect(--r), vr);\n    }\n\
    \    return f(vl, vr);\n  }\n\n  template <typename C>\n  int find(int st, C &check,\
    \ T &acc, int k, int l, int r) {\n    if (l + 1 == r) {\n      acc = f(acc, reflect(k));\n\
    \      return check(acc) ? k - n : -1;\n    }\n    propagate(k);\n    int m =\
    \ (l + r) >> 1;\n    if (m <= st) return find(st, check, acc, (k << 1) | 1, m,\
    \ r);\n    if (st <= l and !check(f(acc, dat[k]))) {\n      acc = f(acc, dat[k]);\n\
    \      return -1;\n    }\n    int vl = find(st, check, acc, (k << 1) | 0, l, m);\n\
    \    if (~vl) return vl;\n    return find(st, check, acc, (k << 1) | 1, m, r);\n\
    \  }\n\n  template <typename C>\n  int find(int st, C &check) {\n    T acc = ti;\n\
    \    return find(st, check, acc, 1, 0, n);\n  }\n\n  void debug() {\n    vc<T>\
    \ A(sz);\n    FOR(i, sz) A[i] = fold(i, i + 1);\n    print(A);\n  }\n};\n"
  code: "#pragma once\ntemplate <typename T, typename OP, bool OP_commute = false>\n\
    struct LazySegTree {\n  using F = function<T(T, T)>;\n  using G = function<T(T,\
    \ OP)>;\n  using H = function<OP(OP, OP)>;\n  int sz, n, height;\n  F f;\n  G\
    \ g;\n  H h;\n  T ti;\n  OP ei;\n  vector<T> dat;\n  vector<OP> laz;\n  LazySegTree(F\
    \ f, G g, H h, T ti, OP ei) : f(f), g(g), h(h), ti(ti), ei(ei) {}\n\n  void init(int\
    \ n_) {\n    sz = n_;\n    n = 1;\n    height = 0;\n    while (n < n_) n <<= 1,\
    \ height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2 * n, ei);\n  }\n\n \
    \ void build(const vector<T> &v) {\n    int n_ = v.size();\n    init(n_);\n  \
    \  for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n    for (int i = n - 1; i;\
    \ i--)\n      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n  }\n\n  inline\
    \ T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }\n\n \
    \ inline void propagate(int k) {\n    if (laz[k] == ei) return;\n    laz[(k <<\
    \ 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k <<\
    \ 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k] = ei;\n  }\n\n  inline\
    \ void thrust(int k) {\n    for (int i = height; i; i--) propagate(k >> i);\n\
    \  }\n\n  inline void recalc(int k) {\n    while (k >>= 1) dat[k] = f(reflect((k\
    \ << 1) | 0), reflect((k << 1) | 1));\n  }\n\n  void operate_range(int a, int\
    \ b, OP x) {\n    if (a >= b) return;\n    a += n, b += n - 1;\n    if (!OP_commute)\
    \ {\n      thrust(a);\n      thrust(b);\n    }\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = h(laz[l], x), l++;\n \
    \     if (r & 1) --r, laz[r] = h(laz[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  void set(int a, T x) {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a]\
    \ = ei;\n    recalc(a);\n  }\n\n  T fold(int a, int b) {\n    if (a >= b) return\
    \ ti;\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = ti, vr = ti;\n\
    \    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl\
    \ = f(vl, reflect(l++));\n      if (r & 1) vr = f(reflect(--r), vr);\n    }\n\
    \    return f(vl, vr);\n  }\n\n  template <typename C>\n  int find(int st, C &check,\
    \ T &acc, int k, int l, int r) {\n    if (l + 1 == r) {\n      acc = f(acc, reflect(k));\n\
    \      return check(acc) ? k - n : -1;\n    }\n    propagate(k);\n    int m =\
    \ (l + r) >> 1;\n    if (m <= st) return find(st, check, acc, (k << 1) | 1, m,\
    \ r);\n    if (st <= l and !check(f(acc, dat[k]))) {\n      acc = f(acc, dat[k]);\n\
    \      return -1;\n    }\n    int vl = find(st, check, acc, (k << 1) | 0, l, m);\n\
    \    if (~vl) return vl;\n    return find(st, check, acc, (k << 1) | 1, m, r);\n\
    \  }\n\n  template <typename C>\n  int find(int st, C &check) {\n    T acc = ti;\n\
    \    return find(st, check, acc, 1, 0, n);\n  }\n\n  void debug() {\n    vc<T>\
    \ A(sz);\n    FOR(i, sz) A[i] = fold(i, i + 1);\n    print(A);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/lazysegtree.hpp
  requiredBy:
  - graph/treemonoid_lazy.hpp
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
documentation_of: ds/lazysegtree.hpp
layout: document
redirect_from:
- /library/ds/lazysegtree.hpp
- /library/ds/lazysegtree.hpp.html
title: ds/lazysegtree.hpp
---
