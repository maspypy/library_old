---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid_max.hpp
    title: alg/monoid_max.hpp
  - icon: ':question:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  - icon: ':x:'
    path: alg/monoid_reverse.hpp
    title: alg/monoid_reverse.hpp
  - icon: ':heavy_check_mark:'
    path: ds/dualsegtree.hpp
    title: ds/dualsegtree.hpp
  - icon: ':question:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  - icon: ':x:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':x:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':warning:'
    path: graph/dualtreemonoid.hpp
    title: graph/dualtreemonoid.hpp
  - icon: ':x:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  - icon: ':x:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/828/problem/F
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n \
    \ int comp;\n  vc<int> size, par;\n  UnionFind(int n) : num(n), comp(n), size(n,\
    \ 1), par(n) {\n    iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n\
    \    while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n \
    \   }\n    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n \
    \ bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x == y)\
    \ { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x, y);\n   \
    \ size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n \
    \ }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i] = find(i);\n\
    \    return A;\n  }\n\n  void reset(){\n    comp = num;\n    size.assign(num,\
    \ 1);\n    iota(all(par), 0);\n  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using\
    \ cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n \
    \ vector<int> indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared\
    \ && 0 <= frm && 0 <= to);\n    chmax(N, frm + 1);\n    chmax(N, to + 1);\n  \
    \  if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    FOR_(M) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int\
    \ off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p,\
    \ v);\n    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n\
    \    csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n     \
    \ csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n        csr_edges[counter[e.to]++]\
    \ = edge_type({e.to, e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int\
    \ v) const {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n\
    \  }\n\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 3 \"graph/hld.hpp\"\n\r\ntemplate <typename Graph>\r\n\
    struct HLD {\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\
    \u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\
    \u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\
    \u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728\
    DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n    print(\"\"\
    );\r\n    print(\"\u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082\u4F7F\
    \u3048\u308B\u3088\u3046\u306B\u3057\u305F\u3002dfs\u9806\u5E8F\u3084\u89AA\u304C\
    \u3068\u308C\u308B\u3002\");\r\n    print(\"edge idx -> in_tree (\u8FBA\u304C\
    \ tree \u306B\u5165\u3063\u3066\u3044\u308B\u304B) \u3082\u3068\u308C\u308B\u3002\
    \");\r\n    print(\"LCA \u3068\u304B\u306F\u4ECA\u306E\u3068\u3053\u308D\u58CA\
    \u308C\u3066\u3044\u308B\u3002\");\r\n  }\r\n\r\n  Graph &G;\r\n  int N;\r\n \
    \ vector<int> LID, RID, head, V, parent, depth, root;\r\n  vector<bool> in_tree;\r\
    \n\r\n  HLD(Graph &G, int r = -1)\r\n      : G(G),\r\n        N(G.N),\r\n    \
    \    LID(G.N),\r\n        RID(G.N),\r\n        head(G.N, r),\r\n        V(G.N),\r\
    \n        parent(G.N, -1),\r\n        depth(G.N, -1),\r\n        root(G.N, -1),\r\
    \n        in_tree(G.M, 0) {\r\n    assert(G.is_prepared());\r\n    int t1 = 0;\r\
    \n    if (r != -1) {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r, t1);\r\n    }\
    \ else {\r\n      FOR(r, N) if (parent[r] == -1) {\r\n        head[r] = r;\r\n\
    \        dfs_sz(r, -1);\r\n        dfs_hld(r, t1);\r\n      }\r\n    }\r\n   \
    \ for (auto &&v: V) root[v] = (parent[v] == -1 ? v : root[parent[v]]);\r\n  }\r\
    \n\r\n  void dfs_sz(int v, int p) {\r\n    auto &sz = RID;\r\n    parent[v] =\
    \ p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n   \
    \ int l = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n\
    \    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    FOR3_R(i, l, r - 1) {\r\n      if (depth[csr[i + 1].to] == -1) swap(csr[i],\
    \ csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i)\
    \ {\r\n      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n  \
    \    in_tree[e.id] = 1;\r\n      dfs_sz(e.to, v);\r\n      sz[v] += sz[e.to];\r\
    \n      if (chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\n  \
    \  }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (!in_tree[e.id] || depth[e.to] <= depth[v])\
    \ continue;\r\n      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\
    \n      dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  int e_to_v(int eid) {\r\
    \n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ? e.frm : e.to);\r\
    \n  }\r\n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int\
    \ v) { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int\
    \ LA(int v, int k) {\r\n    while (1) {\r\n      int u = head[v];\r\n      if\
    \ (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] +\
    \ 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n  int LCA(int u, int v) {\r\
    \n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\
    \n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int subtree_size(int\
    \ v) { return RID[v] - LID[v]; }\r\n\r\n  int dist(int a, int b) {\r\n    int\
    \ c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\
    \n  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b];\
    \ }\r\n\r\n  int move(int a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  vc<pair<int,\
    \ int>> get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9\
    , \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>>\
    \ up, down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n   \
    \   if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n     \
    \   v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"V\", V);\r\n  \
    \  print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n    print(\"parent\", parent);\r\
    \n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\n    print(\"in_tree(edge)\"\
    , in_tree);\r\n    print(\"root\", root);\r\n  }\r\n};\r\n#line 2 \"ds/segtree.hpp\"\
    \ntemplate <class Monoid>\nstruct SegTree {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0)\
    \ {}\n  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit())) {}\n  SegTree(vc<X>\
    \ v) : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  X operator[](int i)\
    \ { return dat[size + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n\n  void set(int i, X x) {\n    assert(i < n);\n \
    \   dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L,\
    \ int R) {\n    assert(L <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(),\
    \ vr = Monoid::unit();\n    L += size, R += size;\n    while (L < R) {\n     \
    \ if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R],\
    \ vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n\
    \  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int max_right(F\
    \ &check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n \
    \   if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F &check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit()));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit();\n    do {\n      --R;\n      while (R > 1 && (R %\
    \ 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R\
    \ < size) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(\"\
    segtree\", dat); }\n};\n#line 1 \"alg/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n#line 4 \"graph/treemonoid.hpp\"\
    \n\r\ntemplate <typename HLD, typename Monoid, bool edge = false>\r\nstruct TreeMonoid\
    \ {\r\n  using RevMonoid = Monoid_Reverse<Monoid>;\r\n  using X = typename Monoid::value_type;\r\
    \n  HLD &hld;\r\n  int N;\r\n  SegTree<Monoid> seg;\r\n  SegTree<RevMonoid> seg_r;\r\
    \n\r\n  TreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {\r\n    if (!Monoid::commute)\
    \ seg_r = SegTree<RevMonoid>(hld.N);\r\n  }\r\n\r\n  TreeMonoid(HLD &hld, vc<X>\
    \ &dat) : hld(hld), N(hld.N) {\r\n    vc<X> seg_raw(N, Monoid::unit());\r\n  \
    \  if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\n    } else\
    \ {\r\n      FOR(e, N - 1) {\r\n        int v = hld.e_to_v(e);\r\n        seg_raw[hld.LID[v]]\
    \ = dat[e];\r\n      }\r\n    }\r\n    seg = SegTree<Monoid>(seg_raw);\r\n   \
    \ if (!Monoid::commute) seg_r = SegTree<RevMonoid>(seg_raw);\r\n  }\r\n\r\n  void\
    \ set(int i, X x) {\r\n    if (edge) i = hld.e_to_v(i);\r\n    i = hld.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!Monoid::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path(int u, int v) {\r\n    auto pd = hld.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      val = Monoid::op(val, x);\r\n    }\r\n    return val;\r\n\
    \  }\r\n\r\n  // uv path \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\u6E80\
    \u305F\u3059\u6700\u5F8C\u306E x\r\n  // \u306A\u3051\u308C\u3070 -1\r\n  // https://codeforces.com/contest/1059/problem/E\r\
    \n  template <class F>\r\n  int max_path(F &check, int u, int v) {\r\n    if (!check(prod_path(u,\
    \ u))) return -1;\r\n    auto pd = hld.get_path_decomposition(u, v, edge);\r\n\
    \    X val = Monoid::unit();\r\n    for (auto &&[a, b]: pd) {\r\n      X x = (a\
    \ <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute ? seg.prod(b,\
    \ a + 1)\r\n                                       : seg_r.prod(b, a + 1)));\r\
    \n      if (check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val, x);\r\
    \n        u = (hld.V[b]);\r\n        continue;\r\n      }\r\n      auto check_tmp\
    \ = [&](X x) -> bool { return check(Monoid::op(val, x)); };\r\n      if (a <=\
    \ b) {\r\n        auto i = seg.max_right(check_tmp, a);\r\n        return (i ==\
    \ a ? u : hld.V[i - 1]);\r\n      } else {\r\n        auto i = (Monoid::commute\
    \ ? seg.min_left(check_tmp, a + 1)\r\n                                  : seg_r.min_left(check_tmp,\
    \ a + 1));\r\n        return (i == a + 1 ? u : hld.V[i]);\r\n      }\r\n    }\r\
    \n    return v;\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n    int l = hld.LID[u],\
    \ r = hld.RID[u];\r\n    return seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"tree_monoid\");\r\n    hld.debug();\r\n    seg.debug();\r\n\
    \    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\
    \ + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\
    \u9593\u3002\");\r\n  }\r\n};\r\n#line 2 \"ds/lazysegtree.hpp\"\n\ntemplate <typename\
    \ Lazy>\nstruct LazySegTree {\n  using Monoid_X = typename Lazy::X_structure;\n\
    \  using Monoid_A = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
    \ Monoid_X::unit())) {}\n  LazySegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid_X::unit());\n    laz.assign(size, Monoid_A::unit());\n    FOR(i,\
    \ n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int\
    \ k) { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }\n\n  void all_apply(int\
    \ k, A a) {\n    dat[k] = Lazy::act(dat[k], a);\n    if (k < size) laz[k] = Monoid_A::op(laz[k],\
    \ a);\n  }\n\n  void push(int k) {\n    all_apply(2 * k, laz[k]);\n    all_apply(2\
    \ * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit();\n  }\n\n  void set(int p,\
    \ X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n   \
    \ p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n\
    \  }\n\n  vc<X> get_all() {\n    FOR(i, size) push(i);\n    return {dat.begin()\
    \ + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return Monoid_X::unit();\n\n   \
    \ l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if\
    \ (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    X xl = Monoid_X::unit(), xr = Monoid_X::unit();\n\
    \    while (l < r) {\n      if (l & 1) xl = Monoid_X::op(xl, dat[l++]);\n    \
    \  if (r & 1) xr = Monoid_X::op(dat[--r], xr);\n      l >>= 1;\n      r >>= 1;\n\
    \    }\n\n    return Monoid_X::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1];\
    \ }\n\n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n    p += size;\n\
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
    \ C>\n  int max_right(C& check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(Monoid_X::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = Monoid_X::unit();\n    do {\n      while (l % 2 ==\
    \ 0) l >>= 1;\n      if (!check(Monoid_X::op(sm, dat[l]))) {\n        while (l\
    \ < size) {\n          push(l);\n          l = (2 * l);\n          if (check(Monoid_X::op(sm,\
    \ dat[l]))) {\n            sm = Monoid_X::op(sm, dat[l]);\n            l++;\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = Monoid_X::op(sm,\
    \ dat[l]);\n      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n \
    \ template <typename C>\n  int min_left(C& check, int r) {\n    assert(0 <= r\
    \ && r <= n);\n    assert(check(Monoid_X::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = Monoid_X::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2))\
    \ r >>= 1;\n      if (!check(Monoid_X::op(dat[r], sm))) {\n        while (r <\
    \ size) {\n          push(r);\n          r = (2 * r + 1);\n          if (check(Monoid_X::op(dat[r],\
    \ sm))) {\n            sm = Monoid_X::op(dat[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = Monoid_X::op(dat[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  void debug() { print(\"\
    lazysegtree getall:\", get_all()); }\n};\n#line 2 \"ds/dualsegtree.hpp\"\n\ntemplate\
    \ <typename Monoid>\nstruct DualSegTree {\n  using A = typename Monoid::value_type;\n\
    \  int n, log, size;\n  vc<A> laz;\n\n  DualSegTree() : DualSegTree(0) {}\n  DualSegTree(int\
    \ n) : n(n) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 <<\
    \ log;\n    laz.assign(size << 1, Monoid::unit());\n  }\n\n  void all_apply(int\
    \ k, A a) { laz[k] = Monoid::op(laz[k], a); }\n\n  void push(int k) {\n    all_apply(2\
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
    \ }\n};\n#line 4 \"graph/dualtreemonoid.hpp\"\n\r\ntemplate <typename HLD, typename\
    \ Monoid, bool edge = false>\r\nstruct DualTreeMonoid {\r\n  using X = typename\
    \ Monoid::value_type;\r\n  HLD &hld;\r\n  int N;\r\n  DualSegTree<Monoid> seg;\r\
    \n\r\n  DualTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {}\r\n\r\n \
    \ X get(int i) {\r\n    int v = i;\r\n    if (edge) {\r\n      auto &&e = hld.G.edges[i];\r\
    \n      v = (hld.parent[e.frm] == e.to ? e.frm : e.to);\r\n    }\r\n    return\
    \ seg.get(hld.LID[v]);\r\n  }\r\n\r\n  vc<X> get_all() {\r\n    vc<X> tmp = seg.get_all();\r\
    \n    vc<X> res;\r\n    FOR(i, N) {\r\n      if (edge && i == N - 1) break;\r\n\
    \      int v = i;\r\n      if (edge) {\r\n        auto &&e = hld.G.edges[i];\r\
    \n        v = (hld.parent[e.frm] == e.to ? e.frm : e.to);\r\n      }\r\n     \
    \ res.eb(tmp[hld.LID[i]]);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  void apply_path(int\
    \ u, int v, X x) {\r\n    auto pd = hld.get_path_decomposition(u, v, edge);\r\n\
    \    for (auto &&[a, b]: pd) {\r\n      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b,\
    \ a + 1, x));\r\n    }\r\n    return;\r\n  }\r\n\r\n  void apply_subtree(int u,\
    \ X x) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n    return seg.apply(l\
    \ + edge, r, x);\r\n  }\r\n};\r\n#line 1 \"alg/monoid_min.hpp\"\ntemplate <class\
    \ X, X INF>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return INF; }\r\n  static constexpr bool commute = true;\r\n};\r\n\
    #line 1 \"alg/monoid_max.hpp\"\ntemplate <class X, X INF>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return -INF;\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 8 \"graph/minimum_spanning_tree.hpp\"\
    \n\r\n// return : {T mst_cost, vc<bool> in_mst, Graph MST}\r\ntemplate <typename\
    \ T>\r\ntuple<T, vc<bool>, Graph<T>> minimum_spanning_tree(Graph<T>& G) {\r\n\
    \  int N = G.N;\r\n  int M = len(G.edges);\r\n  vc<pair<T, int>> edges;\r\n  FOR(i,\
    \ M) {\r\n    auto& e = G.edges[i];\r\n    edges.eb(e.cost, i);\r\n  }\r\n  sort(all(edges));\r\
    \n  vc<bool> in_mst(M);\r\n  UnionFind uf(N);\r\n  T mst_cost = T(0);\r\n  Graph<T>\
    \ MST(N);\r\n  for (auto&& [cost, i]: edges) {\r\n    auto& e = G.edges[i];\r\n\
    \    if (uf.merge(e.frm, e.to)) {\r\n      in_mst[i] = 1;\r\n      mst_cost +=\
    \ e.cost;\r\n    }\r\n  }\r\n  FOR(i, M) if (in_mst[i]) {\r\n    auto& e = G.edges[i];\r\
    \n    MST.add(e.frm, e.to, e.cost);\r\n  }\r\n  MST.prepare();\r\n  return {mst_cost,\
    \ in_mst, MST};\r\n}\r\n\r\n// https://codeforces.com/contest/828/problem/F\r\n\
    // return : {T mst_cost, vc<bool> in_mst, Graph MST, vc<T> dat}\r\n// dat : \u8FBA\
    \u3054\u3068\u306B\u3001\u4ED6\u306E\u8FBA\u3092\u4FDD\u3063\u305F\u3068\u304D\
    \u306B MST \u8FBA\u306B\u306A\u308B\u6700\u5927\u91CD\u307F\r\ntemplate <typename\
    \ T, T INF = (1LL << 60)>\r\ntuple<T, vc<bool>, Graph<T>, vc<T>> minimum_spanning_tree_cycle_data(\r\
    \n    Graph<T>& G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  auto [mst_cost,\
    \ in_mst, MST] = minimum_spanning_tree(G);\r\n  HLD hld(MST);\r\n  vc<T> dat;\r\
    \n  FOR(i, M) if (in_mst[i]) dat.eb(G.edges[i].cost);\r\n  TreeMonoid<decltype(hld),\
    \ Monoid_Max<T, INF>, 1> TM1(hld, dat);\r\n  DualTreeMonoid<decltype(hld), Monoid_Min<T,\
    \ INF>, 1> TM2(hld);\r\n  FOR(i, M) {\r\n    if (!in_mst[i]) {\r\n      auto&\
    \ e = G.edges[i];\r\n      TM2.apply_path(e.frm, e.to, e.cost);\r\n    }\r\n \
    \ }\r\n  vc<T> ANS(M);\r\n  int m = 0;\r\n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\
    \n    if (in_mst[i])\r\n      ANS[i] = TM2.get(m++);\r\n    else\r\n      ANS[i]\
    \ = TM1.prod_path(e.frm, e.to);\r\n  }\r\n  return {mst_cost, in_mst, MST, ANS};\r\
    \n}\n"
  code: "#include \"ds/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n#include \"graph/treemonoid.hpp\"\r\n#include \"graph/dualtreemonoid.hpp\"\
    \r\n#include \"alg/monoid_min.hpp\"\r\n#include \"alg/monoid_max.hpp\"\r\n\r\n\
    // return : {T mst_cost, vc<bool> in_mst, Graph MST}\r\ntemplate <typename T>\r\
    \ntuple<T, vc<bool>, Graph<T>> minimum_spanning_tree(Graph<T>& G) {\r\n  int N\
    \ = G.N;\r\n  int M = len(G.edges);\r\n  vc<pair<T, int>> edges;\r\n  FOR(i, M)\
    \ {\r\n    auto& e = G.edges[i];\r\n    edges.eb(e.cost, i);\r\n  }\r\n  sort(all(edges));\r\
    \n  vc<bool> in_mst(M);\r\n  UnionFind uf(N);\r\n  T mst_cost = T(0);\r\n  Graph<T>\
    \ MST(N);\r\n  for (auto&& [cost, i]: edges) {\r\n    auto& e = G.edges[i];\r\n\
    \    if (uf.merge(e.frm, e.to)) {\r\n      in_mst[i] = 1;\r\n      mst_cost +=\
    \ e.cost;\r\n    }\r\n  }\r\n  FOR(i, M) if (in_mst[i]) {\r\n    auto& e = G.edges[i];\r\
    \n    MST.add(e.frm, e.to, e.cost);\r\n  }\r\n  MST.prepare();\r\n  return {mst_cost,\
    \ in_mst, MST};\r\n}\r\n\r\n// https://codeforces.com/contest/828/problem/F\r\n\
    // return : {T mst_cost, vc<bool> in_mst, Graph MST, vc<T> dat}\r\n// dat : \u8FBA\
    \u3054\u3068\u306B\u3001\u4ED6\u306E\u8FBA\u3092\u4FDD\u3063\u305F\u3068\u304D\
    \u306B MST \u8FBA\u306B\u306A\u308B\u6700\u5927\u91CD\u307F\r\ntemplate <typename\
    \ T, T INF = (1LL << 60)>\r\ntuple<T, vc<bool>, Graph<T>, vc<T>> minimum_spanning_tree_cycle_data(\r\
    \n    Graph<T>& G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  auto [mst_cost,\
    \ in_mst, MST] = minimum_spanning_tree(G);\r\n  HLD hld(MST);\r\n  vc<T> dat;\r\
    \n  FOR(i, M) if (in_mst[i]) dat.eb(G.edges[i].cost);\r\n  TreeMonoid<decltype(hld),\
    \ Monoid_Max<T, INF>, 1> TM1(hld, dat);\r\n  DualTreeMonoid<decltype(hld), Monoid_Min<T,\
    \ INF>, 1> TM2(hld);\r\n  FOR(i, M) {\r\n    if (!in_mst[i]) {\r\n      auto&\
    \ e = G.edges[i];\r\n      TM2.apply_path(e.frm, e.to, e.cost);\r\n    }\r\n \
    \ }\r\n  vc<T> ANS(M);\r\n  int m = 0;\r\n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\
    \n    if (in_mst[i])\r\n      ANS[i] = TM2.get(m++);\r\n    else\r\n      ANS[i]\
    \ = TM1.prod_path(e.frm, e.to);\r\n  }\r\n  return {mst_cost, in_mst, MST, ANS};\r\
    \n}"
  dependsOn:
  - ds/unionfind.hpp
  - graph/base.hpp
  - graph/hld.hpp
  - graph/treemonoid.hpp
  - ds/segtree.hpp
  - alg/monoid_reverse.hpp
  - graph/dualtreemonoid.hpp
  - ds/lazysegtree.hpp
  - ds/dualsegtree.hpp
  - alg/monoid_min.hpp
  - alg/monoid_max.hpp
  isVerificationFile: false
  path: graph/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2022-04-14 18:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimum_spanning_tree.hpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_tree.hpp
- /library/graph/minimum_spanning_tree.hpp.html
title: graph/minimum_spanning_tree.hpp
---
