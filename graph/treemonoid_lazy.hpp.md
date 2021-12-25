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
    \ A(sz);\n    FOR(i, sz) A[i] = fold(i, i + 1);\n    print(A);\n  }\n};\n#line\
    \ 2 \"graph/treemonoid_lazy.hpp\"\n\r\ntemplate <typename HLD, typename E, typename\
    \ OP, bool edge = false,\r\n          bool commute = true, bool OP_commute = false>\r\
    \nstruct TreeMonoidLazy {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E,\
    \ OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  HLD &hld;\r\n  int N;\r\n  F\
    \ seg_f;\r\n  E E_unit;\r\n  LazySegTree<E, OP, OP_commute> seg, seg_r;\r\n\r\n\
    \  TreeMonoidLazy(HLD &hld, F seg_f, G seg_g, H seg_h, E E_unit, OP OP_unit)\r\
    \n      : hld(hld)\r\n      , N(hld.N)\r\n      , seg_f(seg_f)\r\n      , E_unit(E_unit)\r\
    \n      , seg(seg_f, seg_g, seg_h, E_unit, OP_unit)\r\n      , seg_r([&](E x,\
    \ E y) -> E { return seg_f(y, x); }, seg_g, seg_h, E_unit,\r\n              OP_unit)\
    \ {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\n  };\r\n\r\n  void\
    \ init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n    vc<E> seg_raw(N,\
    \ E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\
    \n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n\
    \        seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\
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
  path: graph/treemonoid_lazy.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treemonoid_lazy.hpp
layout: document
redirect_from:
- /library/graph/treemonoid_lazy.hpp
- /library/graph/treemonoid_lazy.hpp.html
title: graph/treemonoid_lazy.hpp
---
