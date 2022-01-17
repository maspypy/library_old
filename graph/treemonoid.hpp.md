---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_reverse.hpp
    title: alg/monoid_reverse.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
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
    segtree\", dat); }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename\
    \ T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type\
    \ = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int>\
    \ indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\n  class OutgoingEdges\
    \ {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l),\
    \ r(r) {}\n\n    const edge_type* begin() const {\n      if (l == r) { return\
    \ 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type* end() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n\
    \  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared\
    \ && 0 <= frm && 0 <= to);\n    chmax(N, frm + 1);\n    chmax(N, to + 1);\n  \
    \  if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared = true;\n\
    \    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 3 \"graph/hld.hpp\"\n\r\ntemplate <typename Graph>\r\n\
    struct HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int> LID, RID, head, V, parent,\
    \ depth;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n      : G(G),\r\n        N(G.N),\r\
    \n        LID(G.N),\r\n        RID(G.N),\r\n        head(G.N, root),\r\n     \
    \   V(G.N),\r\n        parent(G.N, -1),\r\n        depth(G.N) {\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t1);\r\n \
    \ }\r\n\r\n  void dfs_sz(int v, int p) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\
    \n    if (l + 1 < r && csr[l].to == p) swap(csr[l], csr[l + 1]);\r\n    int hld_sz\
    \ = 0;\r\n    for (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n    \
    \  if (e.to == p) {\r\n        assert(!G.is_directed());\r\n        continue;\r\
    \n      }\r\n      dfs_sz(e.to, v);\r\n      sz[v] += sz[e.to];\r\n      if (chmax(hld_sz,\
    \ sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void\
    \ dfs_hld(int v, int p, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] +=\
    \ LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n    for (auto &&e:\
    \ G[v]) {\r\n      if (e.to == p) continue;\r\n      head[e.to] = (heavy ? head[v]\
    \ : e.to);\r\n      heavy = false;\r\n      dfs_hld(e.to, v, times);\r\n    }\r\
    \n  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return\
    \ (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\n\r\n  int ELID(int v) { return\
    \ 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v]\
    \ - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while\
    \ (1) {\r\n      int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v]\
    \ - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n\
    \  }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n\
    \      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return\
    \ u;\r\n    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\
    \n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int\
    \ u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\
    \"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1)\
    \ {\r\n      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n\
    \        down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n  \
    \    } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\
    \u89E3\u3002O(N) \u6642\u9593\u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\
    \u3069\u306F O(logN) \u6642\u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\
    \u3067\u306F\u771F\u3063\u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\
    \n    print(\"\u2192 \u6728DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\
    \");\r\n  }\r\n};\r\n#line 1 \"alg/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit = Monoid::unit;\r\n\
    \  static const bool commute = Monoid::commute;\r\n};\r\n#line 4 \"graph/treemonoid.hpp\"\
    \n\r\ntemplate <typename HLD, typename Monoid, bool edge = false>\r\nstruct TreeMonoid\
    \ {\r\n  using RevMonoid = Monoid_Reverse<Monoid>;\r\n  using X = typename Monoid::value_type;\r\
    \n  HLD &hld;\r\n  int N;\r\n  SegTree<Monoid> seg;\r\n  SegTree<RevMonoid> seg_r;\r\
    \n\r\n  TreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {\r\n    if (!Monoid::commute)\
    \ seg_r = SegTree<RevMonoid>(hld.N);\r\n  }\r\n\r\n  TreeMonoid(HLD &hld, vc<X>\
    \ &dat) : hld(hld), N(hld.N) {\r\n    vc<X> seg_raw(N, Monoid::unit);\r\n    if\
    \ (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\n    } else {\r\
    \n      FOR(e, N - 1) {\r\n        int v = hld.e_to_v(e);\r\n        seg_raw[hld.LID[v]]\
    \ = dat[e];\r\n      }\r\n    }\r\n    seg = SegTree<Monoid>(seg_raw);\r\n   \
    \ if (!Monoid::commute) seg_r = SegTree<RevMonoid>(seg_raw);\r\n  }\r\n\r\n  void\
    \ set(int i, X x) {\r\n    if (edge) i = hld.e_to_v(i);\r\n    i = hld.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!Monoid::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path(int u, int v) {\r\n    auto pd = hld.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit;\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      val = Monoid::op(val, x);\r\n    }\r\n    return val;\r\n\
    \  }\r\n\r\n  template <class F>\r\n  int find_path(F &check, int u, int v) {\r\
    \n    /*\r\n    uv path \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\u6E80\
    \u305F\u3059\u6700\u521D\u306E x\r\n    \u306A\u3051\u308C\u3070 -1\r\n    */\r\
    \n    if (check(prod_path(u, u))) return u;\r\n    auto pd = hld.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit;\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      if (!check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val,\
    \ x);\r\n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool\
    \ { return !check(Monoid::op(val, x)); };\r\n      if (a <= b) {\r\n        auto\
    \ i = seg.max_right(check_tmp, a);\r\n        return hld.LID[i];\r\n      } else\
    \ {\r\n        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\r\n\
    \                                  : seg_r.min_left(check_tmp, a + 1));\r\n  \
    \      --i;\r\n        return hld.LID[i];\r\n      }\r\n    }\r\n    return -1;\r\
    \n  }\r\n\r\n  X prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\
    \n    return seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    tree_monoid\");\r\n    hld.debug();\r\n    seg.debug();\r\n    seg_r.debug();\r\
    \n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\
    \u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\
    \u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n  }\r\
    \n};\r\n"
  code: "#include \"ds/segtree.hpp\"\r\n#include \"graph/hld.hpp\"\r\n#include \"\
    alg/monoid_reverse.hpp\"\r\n\r\ntemplate <typename HLD, typename Monoid, bool\
    \ edge = false>\r\nstruct TreeMonoid {\r\n  using RevMonoid = Monoid_Reverse<Monoid>;\r\
    \n  using X = typename Monoid::value_type;\r\n  HLD &hld;\r\n  int N;\r\n  SegTree<Monoid>\
    \ seg;\r\n  SegTree<RevMonoid> seg_r;\r\n\r\n  TreeMonoid(HLD &hld) : hld(hld),\
    \ N(hld.N), seg(hld.N) {\r\n    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(hld.N);\r\
    \n  }\r\n\r\n  TreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {\r\n   \
    \ vc<X> seg_raw(N, Monoid::unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n    } else {\r\n      FOR(e, N - 1) {\r\n        int v = hld.e_to_v(e);\r\
    \n        seg_raw[hld.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = SegTree<Monoid>(seg_raw);\r\
    \n    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(seg_raw);\r\n  }\r\n\r\n\
    \  void set(int i, X x) {\r\n    if (edge) i = hld.e_to_v(i);\r\n    i = hld.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!Monoid::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path(int u, int v) {\r\n    auto pd = hld.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit;\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      val = Monoid::op(val, x);\r\n    }\r\n    return val;\r\n\
    \  }\r\n\r\n  template <class F>\r\n  int find_path(F &check, int u, int v) {\r\
    \n    /*\r\n    uv path \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\u6E80\
    \u305F\u3059\u6700\u521D\u306E x\r\n    \u306A\u3051\u308C\u3070 -1\r\n    */\r\
    \n    if (check(prod_path(u, u))) return u;\r\n    auto pd = hld.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit;\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      if (!check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val,\
    \ x);\r\n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool\
    \ { return !check(Monoid::op(val, x)); };\r\n      if (a <= b) {\r\n        auto\
    \ i = seg.max_right(check_tmp, a);\r\n        return hld.LID[i];\r\n      } else\
    \ {\r\n        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\r\n\
    \                                  : seg_r.min_left(check_tmp, a + 1));\r\n  \
    \      --i;\r\n        return hld.LID[i];\r\n      }\r\n    }\r\n    return -1;\r\
    \n  }\r\n\r\n  X prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\
    \n    return seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    tree_monoid\");\r\n    hld.debug();\r\n    seg.debug();\r\n    seg_r.debug();\r\
    \n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\
    \u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\
    \u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n  }\r\
    \n};\r\n"
  dependsOn:
  - ds/segtree.hpp
  - graph/hld.hpp
  - graph/base.hpp
  - alg/monoid_reverse.hpp
  isVerificationFile: false
  path: graph/treemonoid.hpp
  requiredBy: []
  timestamp: '2022-01-17 12:32:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: graph/treemonoid.hpp
layout: document
redirect_from:
- /library/graph/treemonoid.hpp
- /library/graph/treemonoid.hpp.html
title: graph/treemonoid.hpp
---
