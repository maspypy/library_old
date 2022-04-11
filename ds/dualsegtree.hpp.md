---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/dualtreemonoid.hpp
    title: graph/dualtreemonoid.hpp
  - icon: ':warning:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D_dualsegtree.test.cpp
    title: test/aoj/DSL_2_D_dualsegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/dualsegtree.hpp\"\n\ntemplate <typename Monoid>\nstruct\
    \ DualSegTree {\n  using A = typename Monoid::value_type;\n  int n, log, size;\n\
    \  vc<A> laz;\n\n  DualSegTree() : DualSegTree(0) {}\n  DualSegTree(int n) : n(n)\
    \ {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n \
    \   laz.assign(size << 1, Monoid::unit());\n  }\n\n  void all_apply(int k, A a)\
    \ { laz[k] = Monoid::op(laz[k], a); }\n\n  void push(int k) {\n    all_apply(2\
    \ * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid::unit();\n\
    \  }\n\n  A get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n  vc<A>\
    \ get_all() {\n    FOR(i, size) push(i);\n    return {laz.begin() + size, laz.begin()\
    \ + size + n};\n  }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if (l == r) return;\n\n    l += size;\n    r += size;\n\
    \n    if (!Monoid::commute) {\n      for (int i = log; i >= 1; i--) {\n      \
    \  if (((l >> i) << i) != l) push(l >> i);\n        if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n      }\n    }\n\n    {\n      int l2 = l, r2 = r;\n  \
    \    while (l < r) {\n        if (l & 1) all_apply(l++, a);\n        if (r & 1)\
    \ all_apply(--r, a);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n\
    \      r = r2;\n    }\n  }\n  void debug() { print(\"dualsegtree getall:\", get_all());\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename Monoid>\nstruct DualSegTree {\n  using\
    \ A = typename Monoid::value_type;\n  int n, log, size;\n  vc<A> laz;\n\n  DualSegTree()\
    \ : DualSegTree(0) {}\n  DualSegTree(int n) : n(n) {\n    log = 1;\n    while\
    \ ((1 << log) < n) ++log;\n    size = 1 << log;\n    laz.assign(size << 1, Monoid::unit());\n\
    \  }\n\n  void all_apply(int k, A a) { laz[k] = Monoid::op(laz[k], a); }\n\n \
    \ void push(int k) {\n    all_apply(2 * k, laz[k]);\n    all_apply(2 * k + 1,\
    \ laz[k]);\n    laz[k] = Monoid::unit();\n  }\n\n  A get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n    FOR(i, size) push(i);\n\
    \    return {laz.begin() + size, laz.begin() + size + n};\n  }\n\n  void apply(int\
    \ l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\
    \n    l += size;\n    r += size;\n\n    if (!Monoid::commute) {\n      for (int\
    \ i = log; i >= 1; i--) {\n        if (((l >> i) << i) != l) push(l >> i);\n \
    \       if (((r >> i) << i) != r) push((r - 1) >> i);\n      }\n    }\n\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) all_apply(l++,\
    \ a);\n        if (r & 1) all_apply(--r, a);\n        l >>= 1;\n        r >>=\
    \ 1;\n      }\n      l = l2;\n      r = r2;\n    }\n  }\n  void debug() { print(\"\
    dualsegtree getall:\", get_all()); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dualsegtree.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - graph/dualtreemonoid.hpp
  timestamp: '2022-04-11 19:10:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_D_dualsegtree.test.cpp
documentation_of: ds/dualsegtree.hpp
layout: document
redirect_from:
- /library/ds/dualsegtree.hpp
- /library/ds/dualsegtree.hpp.html
title: ds/dualsegtree.hpp
---
