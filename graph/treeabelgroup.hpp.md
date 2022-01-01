---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/addgroup.hpp
    title: algebra/addgroup.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/addgroup.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\n\ntemplate\
    \ <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n\
    \  FenwickTree(int n) : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n\
    \    dat.assign(n, AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)),\
    \ total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat = v;\n  \
    \  FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j -\
    \ 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n  E sum(int k) {\n\
    \    E ret = AbelGroup::unit;\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit;\n\
    \    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -=\
    \ R & -R;\n    }\n    E neg = AbelGroup::unit;\n    while (R < L) {\n      neg\
    \ = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\n  }\n\n  E sum_all() { return total; }\n\n  void\
    \ add(int k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <=\
    \ n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  template\
    \ <class F>\n  int max_right(F& check) {\n    assert(f(E(0)));\n    ll i = 0;\n\
    \    E s = AbelGroup::unit;\n    int k = 1;\n    int N = len(dat) + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E\
    \ k) {\n    auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"graph/base.hpp\"\
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
    \  Graph() {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm,\
    \ int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm\
    \ && frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n\
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
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 3 \"graph/hld.hpp\"\n\r\n\
    template <typename Graph>\r\nstruct HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int>\
    \ LID, RID, head, V, parent, depth;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n \
    \     : G(G),\r\n        N(G.N),\r\n        LID(G.N),\r\n        RID(G.N),\r\n\
    \        head(G.N, root),\r\n        V(G.N),\r\n        parent(G.N, -1),\r\n \
    \       depth(G.N) {\r\n    assert(G.is_prepared());\r\n    int t1 = 0;\r\n  \
    \  dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t1);\r\n  }\r\n\r\n  void dfs_sz(int\
    \ v, int p) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p\
    \ == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r =\
    \ G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    if (l + 1 < r && csr[l].to\
    \ == p) swap(csr[l], csr[l + 1]);\r\n    int hld_sz = 0;\r\n    for (int i = l;\
    \ i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (e.to == p) {\r\n      \
    \  assert(!G.is_directed());\r\n        continue;\r\n      }\r\n      dfs_sz(e.to,\
    \ v);\r\n      sz[v] += sz[e.to];\r\n      if (chmax(hld_sz, sz[e.to]) && l <\
    \ i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int\
    \ p, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n    V[LID[v]]\
    \ = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\n      if (e.to\
    \ == p) continue;\r\n      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy\
    \ = false;\r\n      dfs_hld(e.to, v, times);\r\n    }\r\n  }\r\n\r\n  int e_to_v(int\
    \ eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ?\
    \ e.frm : e.to);\r\n  }\r\n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v];\
    \ }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k:\
    \ 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1) {\r\n      int u =\
    \ head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n      k\
    \ -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n  int\
    \ LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int a, int\
    \ b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int a,\
    \ int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n    print(\"\
    parent\", parent);\r\n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\
    \n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\
    \u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\
    \u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\
    \u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728\
    DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n\
    #line 3 \"graph/treeabelgroup.hpp\"\n\r\ntemplate <typename HLD, typename AbelGroup,\
    \ bool edge = false,\r\n          bool path_query = true, bool subtree_query =\
    \ false>\r\nstruct TreeAbelGroup {\r\n  using X = typename AbelGroup::value_type;\r\
    \n  HLD &hld;\r\n  int N;\r\n  FenwickTree<AbelGroup> bit, bit_subtree;\r\n\r\n\
    \  TreeAbelGroup(HLD &hld) : hld(hld), N(hld.N) {\r\n    if (path_query) { bit\
    \ = FenwickTree<AbelGroup>(2 * N); }\r\n    if (subtree_query) { bit_subtree =\
    \ FenwickTree<AbelGroup>(N); }\r\n  }\r\n\r\n  TreeAbelGroup(HLD &hld, vc<X> dat)\
    \ : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      vc<X> bit_raw(2 * N);\r\
    \n      if (!edge) {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) {\r\
    \n          bit_raw[hld.ELID(v)] = dat[v];\r\n          bit_raw[hld.ERID(v)] =\
    \ AbelGroup::inverse(dat[v]);\r\n        }\r\n      } else {\r\n        assert(len(dat)\
    \ == N - 1);\r\n        FOR(e, N - 1) {\r\n          int v = hld.e_to_v(e);\r\n\
    \          bit_raw[hld.ELID(v)] = dat[e];\r\n          bit_raw[hld.ERID(v)] =\
    \ AbelGroup::inverse(dat[e]);\r\n        }\r\n      }\r\n      bit = FenwickTree<AbelGroup>(bit_raw);\r\
    \n    }\r\n    if (subtree_query) {\r\n      vc<X> bit_raw(N);\r\n      if (!edge)\
    \ {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) bit_raw[hld.LID[v]]\
    \ = dat[v];\r\n      } else {\r\n        assert(len(dat) == N - 1);\r\n      \
    \  FOR(e, N - 1) {\r\n          int v = hld.e_to_v(e);\r\n          bit_raw[hld.LID[v]]\
    \ = dat[e];\r\n        }\r\n      }\r\n      bit_subtree = FenwickTree<AbelGroup>(bit_raw);\r\
    \n    }\r\n  }\r\n\r\n  void add(int i, X x) {\r\n    int v = (edge ? hld.e_to_v(i)\
    \ : i);\r\n    if (path_query) {\r\n      X inv_x = AbelGroup::inverse(x);\r\n\
    \      bit.add(hld.ELID(v), x);\r\n      bit.add(hld.ERID(v), inv_x);\r\n    }\r\
    \n    if (subtree_query) bit_subtree.add(hld.LID[v], x);\r\n  }\r\n\r\n  X sum_path(int\
    \ frm, int to) {\r\n    assert(path_query);\r\n    int lca = hld.LCA(frm, to);\r\
    \n    // [frm, lca)\r\n    X x1 = bit.sum(hld.ELID(lca) + 1, hld.ELID(frm) + 1);\r\
    \n    // edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\n  \
    \  X x2 = bit.sum(hld.ELID(lca) + edge, hld.ELID(to) + 1);\r\n    return AbelGroup::op(x1,\
    \ x2);\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n    assert(subtree_query);\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return bit_subtree.sum(l + edge,\
    \ r);\r\n  }\r\n\r\n  void debug() {\r\n    hld.debug();\r\n    bit.debug();\r\
    \n    bit_subtree.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"EulerTour\
    \ + FenwickTree\u3002\");\r\n    print(\"\u9006\u5143\u3092\u5229\u7528\u3057\u3066\
    \u3001\u30D1\u30B9\u30AF\u30A8\u30EA\u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\
    \u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\
    \u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3002\");\r\n  }\r\n\
    };\n"
  code: "#include \"ds/fenwick.hpp\"\r\n#include \"graph/hld.hpp\"\r\n\r\ntemplate\
    \ <typename HLD, typename AbelGroup, bool edge = false,\r\n          bool path_query\
    \ = true, bool subtree_query = false>\r\nstruct TreeAbelGroup {\r\n  using X =\
    \ typename AbelGroup::value_type;\r\n  HLD &hld;\r\n  int N;\r\n  FenwickTree<AbelGroup>\
    \ bit, bit_subtree;\r\n\r\n  TreeAbelGroup(HLD &hld) : hld(hld), N(hld.N) {\r\n\
    \    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }\r\n    if (subtree_query)\
    \ { bit_subtree = FenwickTree<AbelGroup>(N); }\r\n  }\r\n\r\n  TreeAbelGroup(HLD\
    \ &hld, vc<X> dat) : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      vc<X>\
    \ bit_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat) == N);\r\n\
    \        FOR(v, N) {\r\n          bit_raw[hld.ELID(v)] = dat[v];\r\n         \
    \ bit_raw[hld.ERID(v)] = AbelGroup::inverse(dat[v]);\r\n        }\r\n      } else\
    \ {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1) {\r\n     \
    \     int v = hld.e_to_v(e);\r\n          bit_raw[hld.ELID(v)] = dat[e];\r\n \
    \         bit_raw[hld.ERID(v)] = AbelGroup::inverse(dat[e]);\r\n        }\r\n\
    \      }\r\n      bit = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\n    if (subtree_query)\
    \ {\r\n      vc<X> bit_raw(N);\r\n      if (!edge) {\r\n        assert(len(dat)\
    \ == N);\r\n        FOR(v, N) bit_raw[hld.LID[v]] = dat[v];\r\n      } else {\r\
    \n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1) {\r\n          int\
    \ v = hld.e_to_v(e);\r\n          bit_raw[hld.LID[v]] = dat[e];\r\n        }\r\
    \n      }\r\n      bit_subtree = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\n\
    \  }\r\n\r\n  void add(int i, X x) {\r\n    int v = (edge ? hld.e_to_v(i) : i);\r\
    \n    if (path_query) {\r\n      X inv_x = AbelGroup::inverse(x);\r\n      bit.add(hld.ELID(v),\
    \ x);\r\n      bit.add(hld.ERID(v), inv_x);\r\n    }\r\n    if (subtree_query)\
    \ bit_subtree.add(hld.LID[v], x);\r\n  }\r\n\r\n  X sum_path(int frm, int to)\
    \ {\r\n    assert(path_query);\r\n    int lca = hld.LCA(frm, to);\r\n    // [frm,\
    \ lca)\r\n    X x1 = bit.sum(hld.ELID(lca) + 1, hld.ELID(frm) + 1);\r\n    //\
    \ edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\n    X x2 =\
    \ bit.sum(hld.ELID(lca) + edge, hld.ELID(to) + 1);\r\n    return AbelGroup::op(x1,\
    \ x2);\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n    assert(subtree_query);\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return bit_subtree.sum(l + edge,\
    \ r);\r\n  }\r\n\r\n  void debug() {\r\n    hld.debug();\r\n    bit.debug();\r\
    \n    bit_subtree.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"EulerTour\
    \ + FenwickTree\u3002\");\r\n    print(\"\u9006\u5143\u3092\u5229\u7528\u3057\u3066\
    \u3001\u30D1\u30B9\u30AF\u30A8\u30EA\u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\
    \u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\
    \u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3002\");\r\n  }\r\n\
    };"
  dependsOn:
  - ds/fenwick.hpp
  - algebra/addgroup.hpp
  - graph/hld.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/treeabelgroup.hpp
  requiredBy: []
  timestamp: '2022-01-01 19:12:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
documentation_of: graph/treeabelgroup.hpp
layout: document
redirect_from:
- /library/graph/treeabelgroup.hpp
- /library/graph/treeabelgroup.hpp.html
title: graph/treeabelgroup.hpp
---
