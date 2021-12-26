---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':question:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n\
    \  F f;\r\n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP, bool commute, bool OP_commute>\r\
    \nstruct Monoid_OP {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E,\
    \ OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n\
    \  E unit;\r\n  OP OP_unit;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_reverse(Monoid<E>\
    \ Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return Mono.f(y, x); };\r\n \
    \ return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute, Mono.has_inverse,\
    \ Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_add()\
    \ {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto g = [](E x) ->\
    \ E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\n}\r\n\r\n\
    template <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E x, E\
    \ y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true, false});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto\
    \ f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF,\
    \ true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E, E>> Monoid_affine(bool\
    \ has_inverse = false) {\r\n  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E,\
    \ E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\n  };\r\n  auto inv\
    \ = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b iff x = (1/a) y - (b/a)\r\
    \n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n    return {a, a * (-b)};\r\n \
    \ };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)), false, has_inverse, inv});\r\
    \n}\r\n#line 3 \"ds/segtree.hpp\"\n\ntemplate <typename E>\nstruct SegTree {\n\
    \  using F = function<E(E, E)>;\n  int N_;\n  int N;\n  F seg_f;\n  E unit;\n\
    \  vector<E> dat;\n\n  SegTree(Monoid<E> Mono) : seg_f(Mono.f), unit(Mono.unit)\
    \ {}\n\n  void init(int n_) {\n    N_ = n_;\n    N = 1;\n    while (N < n_) N\
    \ <<= 1;\n    dat.assign(N << 1, unit);\n  }\n\n  void build(const vector<E> &v)\
    \ {\n    assert(v.size() == N_);\n    FOR(i, v.size()) { dat[N + i] = v[i]; }\n\
    \    FOR3_R(i, 1, N) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n \
    \ }\n\n  void set(int i, E x) {\n    assert(i < N_);\n    dat[i += N] = x;\n \
    \   while (i >>= 1) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }\n  }\n\
    \n  E prod(int L, int R) {\n    assert(L <= R);\n    assert(R <= N_);\n    E vl\
    \ = unit, vr = unit;\n    L += N;\n    R += N;\n    while (L < R) {\n      if\
    \ (L & 1) vl = seg_f(vl, dat[L++]);\n      if (R & 1) vr = seg_f(dat[--R], vr);\n\
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
    \ }\n};\n#line 2 \"graph/hld.hpp\"\ntemplate <typename Graph>\r\nstruct HLD {\r\
    \n  Graph &G;\r\n  int N;\r\n  vector<int> sz, LID, RID, ELID, ERID, head, V,\
    \ parent, depth, e_to_v;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n      : G(G)\r\
    \n      , N(G.N)\r\n      , sz(G.N)\r\n      , LID(G.N)\r\n      , RID(G.N)\r\n\
    \      , ELID(G.N)\r\n      , ERID(G.N)\r\n      , head(G.N, root)\r\n      ,\
    \ V(G.N)\r\n      , parent(G.N, -1)\r\n      , depth(G.N)\r\n      , e_to_v(G.N)\
    \ {\r\n    int t1 = 0, t2 = 0;\r\n    dfs_sz(root, -1);\r\n    dfs_hld(root, -1,\
    \ t1, t2);\r\n  }\r\n\r\n  void dfs_sz(int idx, int p) {\r\n    parent[idx] =\
    \ p;\r\n    depth[idx] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[idx] = 1;\r\n\
    \    if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0], G[idx].back());\r\
    \n    for (auto &e : G[idx]) {\r\n      if (e.to == p) continue;\r\n      e_to_v[e.id]\
    \ = e.to;\r\n      dfs_sz(e.to, idx);\r\n      sz[idx] += sz[e.to];\r\n      if\
    \ (sz[G[idx][0].to] < sz[e.to]) swap(G[idx][0], e);\r\n    }\r\n  }\r\n\r\n  void\
    \ dfs_hld(int idx, int par, int &times, int&etimes) {\r\n    LID[idx] = times++;\r\
    \n    ELID[idx] = etimes++;\r\n    V[LID[idx]] = idx;\r\n    for (auto &e : G[idx])\
    \ {\r\n      if (e.to == par) continue;\r\n      head[e.to] = (G[idx][0].to ==\
    \ e.to ? head[idx] : e.to);\r\n      dfs_hld(e.to, idx, times, etimes);\r\n  \
    \  }\r\n    RID[idx] = times;\r\n    ERID[idx] = etimes++;\r\n  }\r\n\r\n  /*\
    \ k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1) {\r\n      int\
    \ u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n  \
    \    k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n\
    \  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int a, int\
    \ b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int a,\
    \ int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n    print(\"ELID\", ELID);\r\n    print(\"ERID\", ERID);\r\n  }\r\n\
    \r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\u69CB\u7BC9\
    \u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\u9593\u3002\
    \");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\u5148\u306B\
    \u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728DP\u3084\u6728\
    \u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n#line 4 \"graph/treemonoid.hpp\"\
    \n\r\ntemplate <typename Graph, typename E, bool edge = false>\r\nstruct TreeMonoid\
    \ {\r\n  using F = function<E(E, E)>;\r\n  HLD<Graph> &hld;\r\n  int N;\r\n  F\
    \ f;\r\n  E unit;\r\n  bool commute;\r\n  SegTree<E> seg, seg_r;\r\n\r\n  TreeMonoid(HLD<Graph>\
    \ &hld, Monoid<E> Mono)\r\n      : hld(hld)\r\n      , N(hld.N)\r\n      , f(Mono.f)\r\
    \n      , unit(Mono.unit)\r\n      , commute(Mono.commute)\r\n      , seg(Mono)\r\
    \n      , seg_r(Monoid_reverse<E>(Mono)) {\r\n    seg.init(N);\r\n    if (!commute)\
    \ seg_r.init(N);\r\n  };\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index\
    \ OR edge index\r\n    vc<E> seg_raw(N, unit);\r\n    if (!edge) {\r\n      FOR(v,\
    \ N) seg_raw[hld.LID[v]] = dat[v];\r\n    } else {\r\n      FOR(i, N - 1) {\r\n\
    \        int v = hld.e_to_v[i];\r\n        seg_raw[hld.LID[v]] = dat[i];\r\n \
    \     }\r\n    }\r\n    seg.build(seg_raw);\r\n    if (!commute) seg_r.build(seg_raw);\r\
    \n  }\r\n\r\n  void set(int i, E x) {\r\n    if (edge) i = hld.e_to_v[i];\r\n\
    \    i = hld.LID[i];\r\n    seg.set(i, x);\r\n    if (!commute) seg_r.set(i, x);\r\
    \n  }\r\n\r\n  E prod_path_nc(int u, int v) {\r\n    E vl = unit, vr = unit;\r\
    \n    while (1) {\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      if\
    \ (hld.LID[u] < hld.LID[v]) {\r\n        vr = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), vr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        vl = f(vl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\
    \n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    E vm =\r\n \
    \     (hld.LID[u] < hld.LID[v] ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)\r\
    \n                               : seg_r.prod(hld.LID[v] + edge, hld.LID[u] +\
    \ 1));\r\n    return f(vl, f(vm, vr));\r\n  }\r\n\r\n  E prod_path(int u, int\
    \ v) {\r\n    if (!commute) return prod_path_nc(u, v);\r\n    E val = unit;\r\n\
    \    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      val = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return f(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\n\
    \  E prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n    return\
    \ seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"seg\");\r\n    seg.debug();\r\n    print(\"\
    seg_r\");\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\
    \u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\
    \u9593\u3002\");\r\n  }\r\n};\r\n"
  code: "#include \"algebra/monoid.hpp\"\r\n#include \"ds/segtree.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n\r\ntemplate <typename Graph, typename E, bool edge = false>\r\
    \nstruct TreeMonoid {\r\n  using F = function<E(E, E)>;\r\n  HLD<Graph> &hld;\r\
    \n  int N;\r\n  F f;\r\n  E unit;\r\n  bool commute;\r\n  SegTree<E> seg, seg_r;\r\
    \n\r\n  TreeMonoid(HLD<Graph> &hld, Monoid<E> Mono)\r\n      : hld(hld)\r\n  \
    \    , N(hld.N)\r\n      , f(Mono.f)\r\n      , unit(Mono.unit)\r\n      , commute(Mono.commute)\r\
    \n      , seg(Mono)\r\n      , seg_r(Monoid_reverse<E>(Mono)) {\r\n    seg.init(N);\r\
    \n    if (!commute) seg_r.init(N);\r\n  };\r\n\r\n  void init(vc<E> &dat) {\r\n\
    \    // vertex index OR edge index\r\n    vc<E> seg_raw(N, unit);\r\n    if (!edge)\
    \ {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\n    } else {\r\n     \
    \ FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n        seg_raw[hld.LID[v]]\
    \ = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\n    if (!commute)\
    \ seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x) {\r\n    if (edge)\
    \ i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i, x);\r\n    if (!commute)\
    \ seg_r.set(i, x);\r\n  }\r\n\r\n  E prod_path_nc(int u, int v) {\r\n    E vl\
    \ = unit, vr = unit;\r\n    while (1) {\r\n      if (hld.head[u] == hld.head[v])\
    \ break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\n        vr = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), vr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        vl = f(vl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\
    \n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    E vm =\r\n \
    \     (hld.LID[u] < hld.LID[v] ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)\r\
    \n                               : seg_r.prod(hld.LID[v] + edge, hld.LID[u] +\
    \ 1));\r\n    return f(vl, f(vm, vr));\r\n  }\r\n\r\n  E prod_path(int u, int\
    \ v) {\r\n    if (!commute) return prod_path_nc(u, v);\r\n    E val = unit;\r\n\
    \    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      val = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return f(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\n\
    \  E prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n    return\
    \ seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"seg\");\r\n    seg.debug();\r\n    print(\"\
    seg_r\");\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\
    \u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\
    \u9593\u3002\");\r\n  }\r\n};\r\n"
  dependsOn:
  - algebra/monoid.hpp
  - ds/segtree.hpp
  - graph/hld.hpp
  isVerificationFile: false
  path: graph/treemonoid.hpp
  requiredBy: []
  timestamp: '2021-12-27 03:31:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: graph/treemonoid.hpp
layout: document
redirect_from:
- /library/graph/treemonoid.hpp
- /library/graph/treemonoid.hpp.html
title: graph/treemonoid.hpp
---
