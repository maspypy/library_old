---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/group_reverse.hpp
    title: alg/group_reverse.hpp
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int\
    \ N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\
    \n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l,\
    \ int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n     \
    \ if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const\
    \ edge_type* end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
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
    , in_tree);\r\n    print(\"root\", root);\r\n  }\r\n};\r\n#line 1 \"alg/group_reverse.hpp\"\
    \ntemplate <class Group>\r\nstruct Group_Reverse {\r\n  using value_type = typename\
    \ Group::value_type;\r\n  using X = value_type;\r\n  static constexpr X op(const\
    \ X &x, const X &y) { return Group::op(y, x); }\r\n  static constexpr X inverse(const\
    \ X &x) { return Group::inverse(x); }\r\n  static constexpr X unit = Group::unit;\r\
    \n  static const bool commute = Group::commute;\r\n};\r\n#line 4 \"graph/treegroup.hpp\"\
    \n\r\n// \u4F5C\u3063\u3066\u307F\u305F\u3082\u306E\u306E\u3001HLD(log^2N)\u3088\
    \u308A\u9045\u3044\u304C\u3061\uFF1F\r\ntemplate <typename HLD, typename Group,\
    \ bool edge = false,\r\n          bool path_query = true, bool subtree_query =\
    \ false>\r\nstruct TreeGroup {\r\n  using RevGroup = Group_Reverse<Group>;\r\n\
    \  using X = typename Group::value_type;\r\n  HLD &hld;\r\n  int N;\r\n  SegTree<Group>\
    \ seg, seg_subtree;\r\n  SegTree<RevGroup> seg_r;\r\n\r\n  TreeGroup(HLD &hld)\
    \ : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      seg = SegTree<Group>(2\
    \ * N);\r\n      if (!Group::commute) seg_r = SegTree<RevGroup>(2 * N);\r\n  \
    \  }\r\n    if (subtree_query) {\r\n      assert(Group::commute);\r\n      seg_subtree\
    \ = SegTree<Group>(N);\r\n    }\r\n  }\r\n\r\n  TreeGroup(HLD &hld, vc<X> dat)\
    \ : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      vc<X> seg_raw(2 * N);\r\
    \n      if (!edge) {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) {\r\
    \n          seg_raw[hld.ELID(v)] = dat[v];\r\n          seg_raw[hld.ERID(v)] =\
    \ Group::inverse(dat[v]);\r\n        }\r\n      } else {\r\n        assert(len(dat)\
    \ == N - 1);\r\n        FOR(e, N - 1) {\r\n          int v = hld.e_to_v(e);\r\n\
    \          seg_raw[hld.ELID(v)] = dat[e];\r\n          seg_raw[hld.ERID(v)] =\
    \ Group::inverse(dat[e]);\r\n        }\r\n      }\r\n      seg = SegTree<Group>(seg_raw);\r\
    \n      if (!Group::commute) seg_r = SegTree<RevGroup>(seg_raw);\r\n    }\r\n\
    \    if (subtree_query) {\r\n      assert(Group::commute);\r\n      vc<X> seg_raw(N);\r\
    \n      if (!edge) {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n      } else {\r\n        assert(len(dat) == N - 1);\r\n      \
    \  FOR(e, N - 1) {\r\n          int v = hld.e_to_v(e);\r\n          seg_raw[hld.LID[v]]\
    \ = dat[e];\r\n        }\r\n      }\r\n      seg_subtree = SegTree<Group>(seg_raw);\r\
    \n    }\r\n  }\r\n\r\n  void set_path(int v, X x) {\r\n    X inv_x = Group::inverse(x);\r\
    \n    seg.set(hld.ELID(v), x);\r\n    seg.set(hld.ERID(v), inv_x);\r\n    if (!Group::commute)\
    \ {\r\n      seg_r.set(hld.ELID(v), x);\r\n      seg_r.set(hld.ERID(v), inv_x);\r\
    \n    }\r\n  }\r\n\r\n  void set_subtree(int v, X x) { seg_subtree.set(hld.LID[v],\
    \ x); }\r\n\r\n  void set(int i, X x) {\r\n    int v = (edge ? hld.e_to_v(i) :\
    \ i);\r\n    if (path_query) set_path(v, x);\r\n    if (subtree_query) set_subtree(v,\
    \ x);\r\n  }\r\n\r\n  X prod_path(int frm, int to) {\r\n    assert(path_query);\r\
    \n    int lca = hld.LCA(frm, to);\r\n    // [frm, lca)\r\n    X x1 = (Group::commute\
    \ ? seg.prod(hld.ELID(lca) + 1, hld.ELID(frm) + 1)\r\n                       \
    \    : seg_r.prod(hld.ELID(lca) + 1, hld.ELID(frm) + 1));\r\n    // edge \u306A\
    \u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\n    X x2 = seg.prod(hld.ELID(lca)\
    \ + edge, hld.ELID(to) + 1);\r\n    return Group::op(x1, x2);\r\n  }\r\n\r\n \
    \ X prod_subtree(int u) {\r\n    assert(subtree_query);\r\n    int l = hld.LID[u],\
    \ r = hld.RID[u];\r\n    return seg_subtree.prod(l + edge, r);\r\n  }\r\n\r\n\
    \  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"seg\"\
    );\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n    print(\"\
    seg_subtree\");\r\n    seg_subtree.debug();\r\n  }\r\n\r\n  void doc() {\r\n \
    \   print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u9006\u5143\
    \u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\u3092 O(logN)\
    \ \u6642\u9593\u3067\u884C\u3046\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\
    \u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(logN)\
    \ \u6642\u9593\u3002\");\r\n  }\r\n};\n"
  code: "#include \"ds/segtree.hpp\"\r\n#include \"graph/hld.hpp\"\r\n#include \"\
    alg/group_reverse.hpp\"\r\n\r\n// \u4F5C\u3063\u3066\u307F\u305F\u3082\u306E\u306E\
    \u3001HLD(log^2N)\u3088\u308A\u9045\u3044\u304C\u3061\uFF1F\r\ntemplate <typename\
    \ HLD, typename Group, bool edge = false,\r\n          bool path_query = true,\
    \ bool subtree_query = false>\r\nstruct TreeGroup {\r\n  using RevGroup = Group_Reverse<Group>;\r\
    \n  using X = typename Group::value_type;\r\n  HLD &hld;\r\n  int N;\r\n  SegTree<Group>\
    \ seg, seg_subtree;\r\n  SegTree<RevGroup> seg_r;\r\n\r\n  TreeGroup(HLD &hld)\
    \ : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      seg = SegTree<Group>(2\
    \ * N);\r\n      if (!Group::commute) seg_r = SegTree<RevGroup>(2 * N);\r\n  \
    \  }\r\n    if (subtree_query) {\r\n      assert(Group::commute);\r\n      seg_subtree\
    \ = SegTree<Group>(N);\r\n    }\r\n  }\r\n\r\n  TreeGroup(HLD &hld, vc<X> dat)\
    \ : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      vc<X> seg_raw(2 * N);\r\
    \n      if (!edge) {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) {\r\
    \n          seg_raw[hld.ELID(v)] = dat[v];\r\n          seg_raw[hld.ERID(v)] =\
    \ Group::inverse(dat[v]);\r\n        }\r\n      } else {\r\n        assert(len(dat)\
    \ == N - 1);\r\n        FOR(e, N - 1) {\r\n          int v = hld.e_to_v(e);\r\n\
    \          seg_raw[hld.ELID(v)] = dat[e];\r\n          seg_raw[hld.ERID(v)] =\
    \ Group::inverse(dat[e]);\r\n        }\r\n      }\r\n      seg = SegTree<Group>(seg_raw);\r\
    \n      if (!Group::commute) seg_r = SegTree<RevGroup>(seg_raw);\r\n    }\r\n\
    \    if (subtree_query) {\r\n      assert(Group::commute);\r\n      vc<X> seg_raw(N);\r\
    \n      if (!edge) {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n      } else {\r\n        assert(len(dat) == N - 1);\r\n      \
    \  FOR(e, N - 1) {\r\n          int v = hld.e_to_v(e);\r\n          seg_raw[hld.LID[v]]\
    \ = dat[e];\r\n        }\r\n      }\r\n      seg_subtree = SegTree<Group>(seg_raw);\r\
    \n    }\r\n  }\r\n\r\n  void set_path(int v, X x) {\r\n    X inv_x = Group::inverse(x);\r\
    \n    seg.set(hld.ELID(v), x);\r\n    seg.set(hld.ERID(v), inv_x);\r\n    if (!Group::commute)\
    \ {\r\n      seg_r.set(hld.ELID(v), x);\r\n      seg_r.set(hld.ERID(v), inv_x);\r\
    \n    }\r\n  }\r\n\r\n  void set_subtree(int v, X x) { seg_subtree.set(hld.LID[v],\
    \ x); }\r\n\r\n  void set(int i, X x) {\r\n    int v = (edge ? hld.e_to_v(i) :\
    \ i);\r\n    if (path_query) set_path(v, x);\r\n    if (subtree_query) set_subtree(v,\
    \ x);\r\n  }\r\n\r\n  X prod_path(int frm, int to) {\r\n    assert(path_query);\r\
    \n    int lca = hld.LCA(frm, to);\r\n    // [frm, lca)\r\n    X x1 = (Group::commute\
    \ ? seg.prod(hld.ELID(lca) + 1, hld.ELID(frm) + 1)\r\n                       \
    \    : seg_r.prod(hld.ELID(lca) + 1, hld.ELID(frm) + 1));\r\n    // edge \u306A\
    \u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\n    X x2 = seg.prod(hld.ELID(lca)\
    \ + edge, hld.ELID(to) + 1);\r\n    return Group::op(x1, x2);\r\n  }\r\n\r\n \
    \ X prod_subtree(int u) {\r\n    assert(subtree_query);\r\n    int l = hld.LID[u],\
    \ r = hld.RID[u];\r\n    return seg_subtree.prod(l + edge, r);\r\n  }\r\n\r\n\
    \  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"seg\"\
    );\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n    print(\"\
    seg_subtree\");\r\n    seg_subtree.debug();\r\n  }\r\n\r\n  void doc() {\r\n \
    \   print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u9006\u5143\
    \u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\u3092 O(logN)\
    \ \u6642\u9593\u3067\u884C\u3046\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\
    \u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(logN)\
    \ \u6642\u9593\u3002\");\r\n  }\r\n};"
  dependsOn:
  - ds/segtree.hpp
  - graph/hld.hpp
  - graph/base.hpp
  - alg/group_reverse.hpp
  isVerificationFile: false
  path: graph/treegroup.hpp
  requiredBy: []
  timestamp: '2022-03-19 16:40:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
documentation_of: graph/treegroup.hpp
layout: document
redirect_from:
- /library/graph/treegroup.hpp
- /library/graph/treegroup.hpp.html
title: graph/treegroup.hpp
---
