---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algebra/reverselazy.hpp
    title: algebra/reverselazy.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/reversemonoid.hpp
    title: algebra/reversemonoid.hpp
  - icon: ':warning:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/hld.hpp
    title: graph/hld.hpp
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
    lazysegtree getall:\", get_all()); }\n};\n#line 2 \"graph/base.hpp\"\n\n// frm,\
    \ to, cap, cost\ntemplate <typename T>\nusing Edge = tuple<int, int, T, int>;\n\
    \ntemplate <typename T, bool directed = false>\nstruct Graph {\n  int N, M;\n\
    \  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n\
    \  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\n \
    \ class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int\
    \ r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm,\
    \ int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm\
    \ && frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& [frm, to,\
    \ cost, id]: edges) {\n      indptr[frm + 1]++;\n      if (!directed) indptr[to\
    \ + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter\
    \ = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&& [frm, to,\
    \ cost, id]: edges) {\n      csr_edges[counter[frm]++] = {frm, to, cost, id};\n\
    \      if (!directed) csr_edges[counter[to]++] = {to, frm, cost, id};\n    }\n\
    \  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n   \
    \ return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e);\n   \
    \ }\n  }\n\n  int size() { return N; }\n};\n#line 3 \"graph/hld.hpp\"\n\r\ntemplate\
    \ <typename Graph>\r\nstruct HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int>\
    \ LID, RID, head, V, parent, depth;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n \
    \     : G(G),\r\n        N(G.N),\r\n        LID(G.N),\r\n        RID(G.N),\r\n\
    \        head(G.N, root),\r\n        V(G.N),\r\n        parent(G.N, -1),\r\n \
    \       depth(G.N) {\r\n    assert(G.is_prepared());\r\n    int t1 = 0;\r\n  \
    \  dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t1);\r\n  }\r\n\r\n  void dfs_sz(int\
    \ v, int p) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p\
    \ == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r =\
    \ G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    if (l + 1 < r && get<1>(csr[l])\
    \ == p) swap(csr[l], csr[l + 1]);\r\n    int hld_sz = 0;\r\n    for (int i = l;\
    \ i < r; ++i) {\r\n      auto [frm, to, cost, id] = csr[i];\r\n      if (to ==\
    \ p) {\r\n        assert(!G.is_directed());\r\n        continue;\r\n      }\r\n\
    \      dfs_sz(to, v);\r\n      sz[v] += sz[to];\r\n      if (chmax(hld_sz, sz[to])\
    \ && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int\
    \ v, int p, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n\
    \    V[LID[v]] = v;\r\n    bool heavy = true;\r\n    for (auto &&[frm, to, cost,\
    \ id]: G[v]) {\r\n      if (to == p) continue;\r\n      head[to] = (heavy ? head[v]\
    \ : to);\r\n      heavy = false;\r\n      dfs_hld(to, v, times);\r\n    }\r\n\
    \  }\r\n\r\n  int e_to_v(int e) {\r\n    auto [frm, to, cost, id] = G.edges[e];\r\
    \n    return (parent[frm] == to ? frm : to);\r\n  }\r\n\r\n  int ELID(int v) {\
    \ return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v]\
    \ - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while\
    \ (1) {\r\n      int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v]\
    \ - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n\
    \  }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n\
    \      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return\
    \ u;\r\n    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\
    \n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n    print(\"\
    parent\", parent);\r\n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\
    \n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\
    \u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\
    \u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\
    \u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728\
    DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n\
    #line 1 \"algebra/reversemonoid.hpp\"\ntemplate <class Monoid>\r\nstruct ReverseMonoid\
    \ {\r\n  using value_type = typename Monoid::value_type;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\
    \n  static constexpr X unit = Monoid::unit;\r\n  static const bool commute = Monoid::commute;\r\
    \n};\r\n#line 2 \"algebra/reverselazy.hpp\"\n\r\ntemplate <typename Lazy>\r\n\
    struct ReverseLazy {\r\n  using MX = typename Lazy::X_structure;\r\n  using MA\
    \ = typename Lazy::A_structure;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return Lazy::act(x, a); }\r\
    \n};\r\n#line 4 \"graph/lazytreemonoid.hpp\"\n\r\ntemplate <typename HLD, typename\
    \ Lazy, bool edge = false>\r\nstruct LazyTreeMonoid {\r\n  using MonoX = typename\
    \ Lazy::X_structure;\r\n  using MonoA = typename Lazy::A_structure;\r\n  using\
    \ X = typename MonoX::value_type;\r\n  using A = typename MonoA::value_type;\r\
    \n  using RevLazy = ReverseLazy<Lazy>;\r\n  HLD &hld;\r\n  int N;\r\n  LazySegTree<Lazy>\
    \ seg;\r\n  LazySegTree<RevLazy> seg_r;\r\n\r\n  LazyTreeMonoid(HLD &hld) : hld(hld),\
    \ N(hld.N), seg(hld.N) {\r\n    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(hld.N);\r\
    \n  }\r\n\r\n  LazyTreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {\r\n\
    \    vc<X> seg_raw(N, MonoX::unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n    } else {\r\n      FOR(e, N - 1) {\r\n        int v = hld.e_to_v(e);\r\
    \n        seg_raw[hld.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = LazySegTree<Lazy>(seg_raw);\r\
    \n    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(seg_raw);\r\n  }\r\n\r\
    \n  void set(int i, X x) {\r\n    if (edge) i = hld.e_to_v(i);\r\n    i = hld.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!MonoX::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path_nc(int u, int v) {\r\n    X xl = MonoX::unit, xr = MonoX::unit;\r\
    \n    while (1) {\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      if\
    \ (hld.LID[u] < hld.LID[v]) {\r\n        xr = MonoX::op(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), xr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        xl = MonoX::op(xl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u]\
    \ + 1));\r\n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    X\
    \ xm = (hld.LID[u] < hld.LID[v]\r\n                ? seg.prod(hld.LID[u] + edge,\
    \ hld.LID[v] + 1)\r\n                : seg_r.prod(hld.LID[v] + edge, hld.LID[u]\
    \ + 1));\r\n    return MonoX::op(xl, MonoX::op(xm, xr));\r\n  }\r\n\r\n  X prod_path(int\
    \ u, int v) {\r\n    if (!MonoX::commute) return prod_path_nc(u, v);\r\n    X\
    \ val = MonoX::unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = MonoX::op(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return MonoX::op(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\
    \n\r\n  X prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n\
    \    return seg.prod(l + edge, r);\r\n  }\r\n\r\n  void apply_path(int u, int\
    \ v, A a) {\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\
    \n      if (hld.head[u] == hld.head[v]) break;\r\n      seg.apply(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1, a);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n    seg.apply(hld.LID[u]\
    \ + edge, hld.LID[v] + 1, a);\r\n  }\r\n\r\n  void apply_subtree(int u, A a) {\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return seg.apply(l + edge, r,\
    \ a);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"tree_monoid\");\r\n    hld.debug();\r\
    \n    seg.debug();\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\
    \u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N)\
    \ \u6642\u9593\u3002\");\r\n  }\r\n};\r\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n#include \"graph/hld.hpp\"\r\n#include\
    \ \"algebra/reverselazy.hpp\"\r\n\r\ntemplate <typename HLD, typename Lazy, bool\
    \ edge = false>\r\nstruct LazyTreeMonoid {\r\n  using MonoX = typename Lazy::X_structure;\r\
    \n  using MonoA = typename Lazy::A_structure;\r\n  using X = typename MonoX::value_type;\r\
    \n  using A = typename MonoA::value_type;\r\n  using RevLazy = ReverseLazy<Lazy>;\r\
    \n  HLD &hld;\r\n  int N;\r\n  LazySegTree<Lazy> seg;\r\n  LazySegTree<RevLazy>\
    \ seg_r;\r\n\r\n  LazyTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {\r\
    \n    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(hld.N);\r\n  }\r\n\r\n\
    \  LazyTreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {\r\n    vc<X> seg_raw(N,\
    \ MonoX::unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\
    \n    } else {\r\n      FOR(e, N - 1) {\r\n        int v = hld.e_to_v(e);\r\n\
    \        seg_raw[hld.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = LazySegTree<Lazy>(seg_raw);\r\
    \n    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(seg_raw);\r\n  }\r\n\r\
    \n  void set(int i, X x) {\r\n    if (edge) i = hld.e_to_v(i);\r\n    i = hld.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!MonoX::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path_nc(int u, int v) {\r\n    X xl = MonoX::unit, xr = MonoX::unit;\r\
    \n    while (1) {\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      if\
    \ (hld.LID[u] < hld.LID[v]) {\r\n        xr = MonoX::op(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), xr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        xl = MonoX::op(xl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u]\
    \ + 1));\r\n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    X\
    \ xm = (hld.LID[u] < hld.LID[v]\r\n                ? seg.prod(hld.LID[u] + edge,\
    \ hld.LID[v] + 1)\r\n                : seg_r.prod(hld.LID[v] + edge, hld.LID[u]\
    \ + 1));\r\n    return MonoX::op(xl, MonoX::op(xm, xr));\r\n  }\r\n\r\n  X prod_path(int\
    \ u, int v) {\r\n    if (!MonoX::commute) return prod_path_nc(u, v);\r\n    X\
    \ val = MonoX::unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = MonoX::op(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return MonoX::op(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\
    \n\r\n  X prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n\
    \    return seg.prod(l + edge, r);\r\n  }\r\n\r\n  void apply_path(int u, int\
    \ v, A a) {\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\
    \n      if (hld.head[u] == hld.head[v]) break;\r\n      seg.apply(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1, a);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n    seg.apply(hld.LID[u]\
    \ + edge, hld.LID[v] + 1, a);\r\n  }\r\n\r\n  void apply_subtree(int u, A a) {\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return seg.apply(l + edge, r,\
    \ a);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"tree_monoid\");\r\n    hld.debug();\r\
    \n    seg.debug();\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\
    \u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N)\
    \ \u6642\u9593\u3002\");\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/lazysegtree.hpp
  - graph/hld.hpp
  - graph/base.hpp
  - algebra/reverselazy.hpp
  - algebra/reversemonoid.hpp
  isVerificationFile: false
  path: graph/lazytreemonoid.hpp
  requiredBy: []
  timestamp: '2021-12-31 00:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lazytreemonoid.hpp
layout: document
redirect_from:
- /library/graph/lazytreemonoid.hpp
- /library/graph/lazytreemonoid.hpp.html
title: graph/lazytreemonoid.hpp
---