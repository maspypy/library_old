---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ }\n};\n#line 2 \"graph/treemonoid.hpp\"\n\r\ntemplate <typename HLD, typename\
    \ E, bool edge = false, bool commute = true>\r\nstruct TreeMonoid {\r\n  using\
    \ F = function<E(E, E)>;\r\n  HLD &hld;\r\n  int N;\r\n  F seg_f;\r\n  E E_unit;\r\
    \n  SegTree<E> seg, seg_r;\r\n\r\n  TreeMonoid(HLD &hld, F seg_f, E E_unit)\r\n\
    \      : hld(hld)\r\n      , N(hld.N)\r\n      , seg_f(seg_f)\r\n      , E_unit(E_unit)\r\
    \n      , seg(seg_f, E_unit)\r\n      , seg_r([&](E x, E y) -> E { return seg_f(y,\
    \ x); }, E_unit) {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\n\
    \  };\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n\
    \    vc<E> seg_raw(N, E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
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
    \n  E fold_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n   \
    \ return seg.fold(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    hld\");\r\n    hld.debug();\r\n    print(\"seg\");\r\n    seg.debug();\r\n   \
    \ print(\"seg_r\");\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n   \
    \ print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\u30D1\u30B9\u9806\u3092\u6C17\
    \u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\u3059\u308B\u3002\
    \");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\u306A\u3089\u30D1\
    \u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\u9593\");\r\n   \
    \ print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n};\r\n"
  code: "#include \"ds/segtree.hpp\"\r\n\r\ntemplate <typename HLD, typename E, bool\
    \ edge = false, bool commute = true>\r\nstruct TreeMonoid {\r\n  using F = function<E(E,\
    \ E)>;\r\n  HLD &hld;\r\n  int N;\r\n  F seg_f;\r\n  E E_unit;\r\n  SegTree<E>\
    \ seg, seg_r;\r\n\r\n  TreeMonoid(HLD &hld, F seg_f, E E_unit)\r\n      : hld(hld)\r\
    \n      , N(hld.N)\r\n      , seg_f(seg_f)\r\n      , E_unit(E_unit)\r\n     \
    \ , seg(seg_f, E_unit)\r\n      , seg_r([&](E x, E y) -> E { return seg_f(y, x);\
    \ }, E_unit) {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\n  };\r\
    \n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n    vc<E>\
    \ seg_raw(N, E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
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
    \n  E fold_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n   \
    \ return seg.fold(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    hld\");\r\n    hld.debug();\r\n    print(\"seg\");\r\n    seg.debug();\r\n   \
    \ print(\"seg_r\");\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n   \
    \ print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\u30D1\u30B9\u9806\u3092\u6C17\
    \u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\u3059\u308B\u3002\
    \");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\u306A\u3089\u30D1\
    \u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\u9593\");\r\n   \
    \ print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/segtree.hpp
  isVerificationFile: false
  path: graph/treemonoid.hpp
  requiredBy: []
  timestamp: '2021-12-26 04:58:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
documentation_of: graph/treemonoid.hpp
layout: document
redirect_from:
- /library/graph/treemonoid.hpp
- /library/graph/treemonoid.hpp.html
title: graph/treemonoid.hpp
---
