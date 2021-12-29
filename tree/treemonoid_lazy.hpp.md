---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/lazysegtree.hpp\"\n\ntemplate <typename Lazy>\nstruct\
    \ LazySegTree {\n  using Monoid_X = typename Lazy::X_structure;\n  using Monoid_A\
    \ = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
    \ Monoid_X::unit)) {}\n  LazySegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n  \
    \  while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size <<\
    \ 1, Monoid_X::unit);\n    laz.assign(size, Monoid_A::unit);\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }\n\n  void all_apply(int\
    \ k, A a) {\n    dat[k] = Lazy::act(dat[k], a);\n    if (k < size) laz[k] = Monoid_A::op(laz[k],\
    \ a);\n  }\n\n  void push(int k) {\n    all_apply(2 * k, laz[k]);\n    all_apply(2\
    \ * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit;\n  }\n\n  void set(int p, X\
    \ x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n   \
    \ p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n\
    \  }\n\n  vc<X> get_all() {\n    FOR(i, size) push(i);\n    return {dat.begin()\
    \ + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return Monoid_X::unit;\n\n    l\
    \ += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n\n    X xl = Monoid_X::unit, xr = Monoid_X::unit;\n    while\
    \ (l < r) {\n      if (l & 1) xl = Monoid_X::op(xl, dat[l++]);\n      if (r &\
    \ 1) xr = Monoid_X::op(dat[--r], xr);\n      l >>= 1;\n      r >>= 1;\n    }\n\
    \n    return Monoid_X::op(xl, xr);\n  }\n\n  X all_prod() { return dat[1]; }\n\
    \n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n    p += size;\n \
    \   if (!Monoid_A::commute)\n      for (int i = log; i >= 1; i--) push(p >> i);\n\
    \    dat[p] = Lazy::act(dat[p], a);\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <=\
    \ r && r <= n);\n    if (l == r) return;\n\n    l += size;\n    r += size;\n\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) all_apply(l++,\
    \ a);\n        if (r & 1) all_apply(--r, a);\n        l >>= 1;\n        r >>=\
    \ 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ C>\n  int max_right(C& check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(Monoid_X::unit));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = Monoid_X::unit;\n    do {\n      while (l % 2 == 0)\
    \ l >>= 1;\n      if (!check(Monoid_X::op(sm, dat[l]))) {\n        while (l <\
    \ size) {\n          push(l);\n          l = (2 * l);\n          if (check(Monoid_X::op(sm,\
    \ dat[l]))) {\n            sm = Monoid_X::op(sm, dat[l]);\n            l++;\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = Monoid_X::op(sm,\
    \ dat[l]);\n      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n \
    \ template <typename C>\n  int min_left(C& check, int r) {\n    assert(0 <= r\
    \ && r <= n);\n    assert(check(Monoid_X::unit));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = Monoid_X::unit;\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r\
    \ >>= 1;\n      if (!check(Monoid_X::op(dat[r], sm))) {\n        while (r < size)\
    \ {\n          push(r);\n          r = (2 * r + 1);\n          if (check(Monoid_X::op(dat[r],\
    \ sm))) {\n            sm = Monoid_X::op(dat[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = Monoid_X::op(dat[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  void debug() { print(\"\
    lazysegtree getall:\", get_all()); }\n};\n#line 2 \"tree/treemonoid_lazy.hpp\"\
    \n\r\ntemplate <typename HLD, typename E, typename OP, bool edge = false,\r\n\
    \          bool commute = true, bool OP_commute = false>\r\nstruct TreeMonoidLazy\
    \ {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E, OP)>;\r\n \
    \ using H = function<OP(OP, OP)>;\r\n  HLD &hld;\r\n  int N;\r\n  F seg_f;\r\n\
    \  E E_unit;\r\n  LazySegTree<E, OP, OP_commute> seg, seg_r;\r\n\r\n  TreeMonoidLazy(HLD\
    \ &hld, F seg_f, G seg_g, H seg_h, E E_unit, OP OP_unit)\r\n      : hld(hld)\r\
    \n      , N(hld.N)\r\n      , seg_f(seg_f)\r\n      , E_unit(E_unit)\r\n     \
    \ , seg(seg_f, seg_g, seg_h, E_unit, OP_unit)\r\n      , seg_r([&](E x, E y) ->\
    \ E { return seg_f(y, x); }, seg_g, seg_h, E_unit,\r\n              OP_unit) {\r\
    \n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\n  };\r\n\r\n  void init(vc<E>\
    \ &dat) {\r\n    // vertex index OR edge index\r\n    vc<E> seg_raw(N, E_unit);\r\
    \n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\n    } else\
    \ {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n        seg_raw[hld.LID[v]]\
    \ = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\n    if (!commute)\
    \ seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x) {\r\n    if (edge)\
    \ i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i, x);\r\n    if (!commute)\
    \ seg_r.set(i, x);\r\n  }\r\n\r\n  E fold_path_nc(int u, int v) {\r\n    E vl\
    \ = E_unit, vr = E_unit;\r\n    while (1) {\r\n      if (hld.head[u] == hld.head[v])\
    \ break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\n        vr = seg_f(seg.fold(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), vr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        vl = seg_f(vl, seg_r.fold(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\
    \n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    E vm =\r\n \
    \     (hld.LID[u] < hld.LID[v] ? seg.fold(hld.LID[u] + edge, hld.LID[v] + 1)\r\
    \n                               : seg_r.fold(hld.LID[v] + edge, hld.LID[u] +\
    \ 1));\r\n    return seg_f(vl, seg_f(vm, vr));\r\n  }\r\n\r\n  E fold_path(int\
    \ u, int v) {\r\n    if (!commute) return fold_path_nc(u, v);\r\n    E val = E_unit;\r\
    \n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      val = seg_f(seg.fold(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return seg_f(seg.fold(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\
    \n  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"\
    seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n\
    \  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\
    \");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\
    \u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\
    \u30D1\u30B9\u9806\u3092\u6C17\u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\
    \u3059\u308B\u3002\");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\
    \u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\
    \u9593\");\r\n    print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n\
    };\r\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n\r\ntemplate <typename HLD, typename E,\
    \ typename OP, bool edge = false,\r\n          bool commute = true, bool OP_commute\
    \ = false>\r\nstruct TreeMonoidLazy {\r\n  using F = function<E(E, E)>;\r\n  using\
    \ G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  HLD &hld;\r\
    \n  int N;\r\n  F seg_f;\r\n  E E_unit;\r\n  LazySegTree<E, OP, OP_commute> seg,\
    \ seg_r;\r\n\r\n  TreeMonoidLazy(HLD &hld, F seg_f, G seg_g, H seg_h, E E_unit,\
    \ OP OP_unit)\r\n      : hld(hld)\r\n      , N(hld.N)\r\n      , seg_f(seg_f)\r\
    \n      , E_unit(E_unit)\r\n      , seg(seg_f, seg_g, seg_h, E_unit, OP_unit)\r\
    \n      , seg_r([&](E x, E y) -> E { return seg_f(y, x); }, seg_g, seg_h, E_unit,\r\
    \n              OP_unit) {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\
    \n  };\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\
    \n    vc<E> seg_raw(N, E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\
    \n        seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\
    \n    if (!commute) seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x)\
    \ {\r\n    if (edge) i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i,\
    \ x);\r\n    if (!commute) seg_r.set(i, x);\r\n  }\r\n\r\n  E fold_path_nc(int\
    \ u, int v) {\r\n    E vl = E_unit, vr = E_unit;\r\n    while (1) {\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\
    \n        vr = seg_f(seg.fold(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);\r\n\
    \        v = hld.parent[hld.head[v]];\r\n      } else {\r\n        vl = seg_f(vl,\
    \ seg_r.fold(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\n        u = hld.parent[hld.head[u]];\r\
    \n      }\r\n    }\r\n    E vm =\r\n      (hld.LID[u] < hld.LID[v] ? seg.fold(hld.LID[u]\
    \ + edge, hld.LID[v] + 1)\r\n                               : seg_r.fold(hld.LID[v]\
    \ + edge, hld.LID[u] + 1));\r\n    return seg_f(vl, seg_f(vm, vr));\r\n  }\r\n\
    \r\n  E fold_path(int u, int v) {\r\n    if (!commute) return fold_path_nc(u,\
    \ v);\r\n    E val = E_unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = seg_f(seg.fold(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return seg_f(seg.fold(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\
    \n  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"\
    seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n\
    \  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\
    \");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\
    \u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\
    \u30D1\u30B9\u9806\u3092\u6C17\u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\
    \u3059\u308B\u3002\");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\
    \u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\
    \u9593\");\r\n    print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - ds/lazysegtree.hpp
  isVerificationFile: false
  path: tree/treemonoid_lazy.hpp
  requiredBy: []
  timestamp: '2021-12-30 04:54:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/treemonoid_lazy.hpp
layout: document
redirect_from:
- /library/tree/treemonoid_lazy.hpp
- /library/tree/treemonoid_lazy.hpp.html
title: tree/treemonoid_lazy.hpp
---
