---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
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
  bundledCode: "#line 2 \"algebra/monoid.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n\
    \  F f;\r\n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP>\r\nstruct Monoid_OP {\r\n  using\
    \ F = function<E(E, E)>;\r\n  using G = function<E(E, OP)>;\r\n  using H = function<OP(OP,\
    \ OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n  E unit;\r\n  OP OP_unit;\r\n  bool\
    \ commute;\r\n  bool OP_commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_reverse(Monoid<E> Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return\
    \ Mono.f(y, x); };\r\n  return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute,\
    \ Mono.has_inverse, Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_add() {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto\
    \ g = [](E x) -> E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f\
    \ = [](E x, E y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true,\
    \ false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF)\
    \ {\r\n  auto f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f,\
    \ MINUS_INF, true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E,\
    \ E>> Monoid_affine(bool has_inverse = false) {\r\n  auto f = [](pair<E, E> x,\
    \ pair<E, E> y) -> pair<E, E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\
    \n  };\r\n  auto inv = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b\
    \ iff x = (1/a) y - (b/a)\r\n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n   \
    \ return {a, a * (-b)};\r\n  };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)),\
    \ false, has_inverse, inv});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid_OP<pair<E,\
    \ E>, pair<E, E>> Monoid_cnt_sum_affine() {\r\n  using P = pair<E, E>;\r\n  auto\
    \ f = [](P x, P y) -> P { return P({x.fi + y.fi, x.se + y.se}); };\r\n  auto g\
    \ = [](P x, P y) -> P { return P({x.fi, x.fi * y.se + x.se * y.fi}); };\r\n  auto\
    \ h = [](P x, P y) -> P { return P({x.fi * y.fi, x.se * y.fi + y.se}); };\r\n\
    \  return Monoid_OP<P, P>({f, g, h, P({0, 0}), P({1, 0}), true, false});\r\n}\r\
    \n#line 2 \"ds/fenwick.hpp\"\ntemplate <typename T>\nstruct FenwickTree {\n  vector<T>\
    \ data;\n  T total;\n\n  FenwickTree() : total(0) {}\n  FenwickTree(int sz) :\
    \ total(0) { data.assign(++sz, 0); }\n\n  void init(int n) { data.assign(++n,\
    \ 0); }\n\n  void build(vector<T>& raw_data) {\n    assert(len(data) == len(raw_data)\
    \ + 1);\n    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];\n    FOR(i, len(data))\
    \ {\n      int j = i + (i & -i);\n      if (j < len(data)) data[j] += data[i];\n\
    \    }\n  }\n\n  T sum(int k) {\n    T ret = 0;\n    for (; k > 0; k -= k & -k)\
    \ ret += data[k];\n    return (ret);\n  }\n\n  T sum(int L, int R) {\n    T ret\
    \ = 0;\n    while (L < R) {\n      ret += data[R];\n      R -= R & -R;\n    }\n\
    \    while (R < L) {\n      ret -= data[L];\n      L -= L & -L;\n    }\n    return\
    \ ret;\n  }\n\n  T sum_all() { return total; }\n\n  void add(int k, T x) {\n \
    \   total += x;\n    for (++k; k < len(data); k += k & -k) data[k] += x;\n  }\n\
    \n  template <class F>\n  int max_right(F& check) {\n    assert(f(T(0)));\n  \
    \  ll i = 0;\n    T s = 0;\n    int k = 1;\n    int N = len(data);\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(s + data[i\
    \ + k])) {\n        i += k;\n        s += data[i];\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(T k) {\n    auto check =\
    \ [&](T x) -> bool { return x < k; };\n    return max_right(check);\n  }\n\n \
    \ void debug() { print(data); }\n};\n\ntemplate <typename T>\nstruct Fenwick_RAQ\
    \ {\n  int N;\n  FenwickTree<T> bit0;\n  FenwickTree<T> bit1;\n\n  Fenwick_RAQ(int\
    \ N) : N(N), bit0(N), bit1(N) {}\n  Fenwick_RAQ() {}\n\n  void init(int n) {\n\
    \    N = n;\n    bit0.init(n);\n    bit1.init(n);\n  }\n\n  void build(vc<T>&\
    \ v) { bit0.build(v); }\n\n  void add_at(ll i, T val) { bit0.add(i, val); }\n\n\
    \  void add_range(ll L, ll R, T val) {\n    bit0.add(L, -val * L);\n    bit1.add(L,\
    \ +val);\n    bit0.add(R, +val * R);\n    bit1.add(R, -val);\n  }\n\n  T sum(ll\
    \ L, ll R) {\n    T sum_R = R * bit1.sum(R) + bit0.sum(R);\n    T sum_L = L *\
    \ bit1.sum(L) + bit0.sum(L);\n    return sum_R - sum_L;\n  }\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    \  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}\n};\n\ntemplate\
    \ <typename T>\nstruct Graph {\n  int N, M;\n  using edge_t = Edge<T>;\n  vector<edge_t>\
    \ edges;\n  vector<vector<edge_t>> G;\n  bool directed;\n  Graph() {}\n  Graph(int\
    \ N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}\n\n  void add(int frm,\
    \ int to, T cost = 1, int i = -1) {\n    if (i == -1) i = M;\n    auto e = edge_t(frm,\
    \ to, cost, i);\n    edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n \
    \     auto e_rev = edge_t(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n\
    \    ++M;\n  }\n\n  void debug(bool detail = false) {\n    FOR(v, N) {\n     \
    \ cout << v << \" :\";\n      for (auto e: G[v]) {\n        if (detail)\n    \
    \      cout << \" (\" << e.frm << \",\" << e.to << \",\" << e.cost << \",\" <<\
    \ e.id << \")\";\n        else\n          cout << \" \" << e.to;\n      }\n  \
    \    cout << \"\\n\";\n    }\n  }\n\n  vector<int> degrees() {\n    vector<int>\
    \ deg(N);\n    for (auto&& e: edges) {\n      deg[e.frm]++;\n      deg[e.to]++;\n\
    \    }\n    return deg;\n  }\n\n  int size() { return N; }\n\n  vector<edge_t>&\
    \ operator[](int v) { return G[v]; }\n};\n#line 3 \"graph/hld.hpp\"\n\r\ntemplate\
    \ <typename Graph>\r\nstruct HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int>\
    \ sz, LID, RID, ELID, ERID, head, V, parent, depth, e_to_v;\r\n\r\n  HLD(Graph\
    \ &G, int root = 0)\r\n      : G(G),\r\n        N(G.N),\r\n        sz(G.N),\r\n\
    \        LID(G.N),\r\n        RID(G.N),\r\n        ELID(G.N),\r\n        ERID(G.N),\r\
    \n        head(G.N, root),\r\n        V(G.N),\r\n        parent(G.N, -1),\r\n\
    \        depth(G.N),\r\n        e_to_v(G.N) {\r\n    int t1 = 0, t2 = 0;\r\n \
    \   dfs_sz(root, -1);\r\n    dfs_hld(root, -1, t1, t2);\r\n  }\r\n\r\n  void dfs_sz(int\
    \ idx, int p) {\r\n    parent[idx] = p;\r\n    depth[idx] = (p == -1 ? 0 : depth[p]\
    \ + 1);\r\n    sz[idx] = 1;\r\n    if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0],\
    \ G[idx].back());\r\n    for (auto &e: G[idx]) {\r\n      if (e.to == p) continue;\r\
    \n      e_to_v[e.id] = e.to;\r\n      dfs_sz(e.to, idx);\r\n      sz[idx] += sz[e.to];\r\
    \n      if (sz[G[idx][0].to] < sz[e.to]) swap(G[idx][0], e);\r\n    }\r\n  }\r\
    \n\r\n  void dfs_hld(int idx, int par, int &times, int &etimes) {\r\n    LID[idx]\
    \ = times++;\r\n    ELID[idx] = etimes++;\r\n    V[LID[idx]] = idx;\r\n    for\
    \ (auto &e: G[idx]) {\r\n      if (e.to == par) continue;\r\n      head[e.to]\
    \ = (G[idx][0].to == e.to ? head[idx] : e.to);\r\n      dfs_hld(e.to, idx, times,\
    \ etimes);\r\n    }\r\n    RID[idx] = times;\r\n    ERID[idx] = etimes++;\r\n\
    \  }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1)\
    \ {\r\n      int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v]\
    \ - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n\
    \  }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n\
    \      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return\
    \ u;\r\n    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\
    \n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n    print(\"ELID\", ELID);\r\n    print(\"ERID\", ERID);\r\n  }\r\n\
    \r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\u9593\u69CB\u7BC9\
    \u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN) \u6642\u9593\u3002\
    \");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\u3063\u5148\u306B\
    \u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192 \u6728DP\u3084\u6728\
    \u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n#line 4 \"graph/treeabel.hpp\"\
    \n\r\ntemplate <typename Graph, typename E, bool edge = false>\r\nstruct TreeAbelGroup\
    \ {\r\n  HLD<Graph> &hld;\r\n  int N;\r\n  FenwickTree<E> bit_path, bit_subtree;\r\
    \n  bool path_sum, subtree_sum;\r\n\r\n  TreeAbelGroup(HLD<Graph> &hld, bool path_sum,\
    \ bool subtree_sum)\r\n      : hld(hld), N(hld.N), path_sum(path_sum), subtree_sum(subtree_sum)\
    \ {\r\n    if (path_sum) bit_path.init(N + N);\r\n    if (subtree_sum) bit_subtree.init(N);\r\
    \n  }\r\n\r\n  void init_path(vc<E> &dat) {\r\n    vc<E> fenwick_raw(N + N);\r\
    \n    if (!edge) {\r\n      FOR(v, N) {\r\n        fenwick_raw[hld.ELID[v]] =\
    \ dat[v];\r\n        fenwick_raw[hld.ERID[v]] = -dat[v];\r\n      }\r\n    } else\
    \ {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n        fenwick_raw[hld.ELID[v]]\
    \ = dat[i];\r\n        fenwick_raw[hld.ERID[v]] = -dat[i];\r\n      }\r\n    }\r\
    \n    bit_path.build(fenwick_raw);\r\n  }\r\n\r\n  void init_subtree(vc<E> &dat)\
    \ {\r\n    vc<E> fenwick_raw(N);\r\n    if (!edge) {\r\n      FOR(v, N) { fenwick_raw[hld.LID[v]]\
    \ = dat[v]; }\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\
    \n        fenwick_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    bit_subtree.build(fenwick_raw);\r\
    \n  }\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n\
    \    if (path_sum) init_path(dat);\r\n    if (subtree_sum) init_subtree(dat);\r\
    \n  }\r\n\r\n  void add(int i, E x) {\r\n    int v = (edge ? hld.e_to_v[i] : i);\r\
    \n    if (path_sum) {\r\n      bit_path.add(hld.ELID[v], x);\r\n      bit_path.add(hld.ERID[v],\
    \ -x);\r\n    }\r\n    if (subtree_sum) { bit_subtree.add(hld.LID[v], x); }\r\n\
    \  }\r\n\r\n  E sum_path(int frm, int to) {\r\n    int lca = hld.LCA(frm, to);\r\
    \n    E x1 = bit_path.sum(hld.ELID[lca] + 1, hld.ELID[frm] + 1);\r\n    E x2 =\
    \ bit_path.sum(hld.ELID[lca] + edge, hld.ELID[to] + 1);\r\n    return x1 + x2;\r\
    \n  }\r\n\r\n  E sum_subtree(int v) {\r\n    return bit_subtree.sum(hld.LID[v]\
    \ + edge, hld.RID[v]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"bit_path\");\r\n    bit_path.debug();\r\n  \
    \  print(\"bit_subtree\");\r\n    bit_subtree.debug();\r\n  }\r\n\r\n  void doc()\
    \ {\r\n    print(\"EulerTour + FenwickTree\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(logN) \u6642\u9593\u3002\");\r\n    print(\"\u30A2\u30FC\u30D9\u30EB\u7FA4\
    \u3067\u3042\u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3092 O(logN) \u6642\u9593\u306B\u3059\u308B\u3002\");\r\n    print(\"\
    operator +- \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\u306A\
    \u3069\u304C\u3042\u308B\");\r\n  }\r\n};\r\n"
  code: "#include \"algebra/monoid.hpp\"\r\n#include \"ds/fenwick.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n\r\ntemplate <typename Graph, typename E, bool edge = false>\r\
    \nstruct TreeAbelGroup {\r\n  HLD<Graph> &hld;\r\n  int N;\r\n  FenwickTree<E>\
    \ bit_path, bit_subtree;\r\n  bool path_sum, subtree_sum;\r\n\r\n  TreeAbelGroup(HLD<Graph>\
    \ &hld, bool path_sum, bool subtree_sum)\r\n      : hld(hld), N(hld.N), path_sum(path_sum),\
    \ subtree_sum(subtree_sum) {\r\n    if (path_sum) bit_path.init(N + N);\r\n  \
    \  if (subtree_sum) bit_subtree.init(N);\r\n  }\r\n\r\n  void init_path(vc<E>\
    \ &dat) {\r\n    vc<E> fenwick_raw(N + N);\r\n    if (!edge) {\r\n      FOR(v,\
    \ N) {\r\n        fenwick_raw[hld.ELID[v]] = dat[v];\r\n        fenwick_raw[hld.ERID[v]]\
    \ = -dat[v];\r\n      }\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int\
    \ v = hld.e_to_v[i];\r\n        fenwick_raw[hld.ELID[v]] = dat[i];\r\n       \
    \ fenwick_raw[hld.ERID[v]] = -dat[i];\r\n      }\r\n    }\r\n    bit_path.build(fenwick_raw);\r\
    \n  }\r\n\r\n  void init_subtree(vc<E> &dat) {\r\n    vc<E> fenwick_raw(N);\r\n\
    \    if (!edge) {\r\n      FOR(v, N) { fenwick_raw[hld.LID[v]] = dat[v]; }\r\n\
    \    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n \
    \       fenwick_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    bit_subtree.build(fenwick_raw);\r\
    \n  }\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n\
    \    if (path_sum) init_path(dat);\r\n    if (subtree_sum) init_subtree(dat);\r\
    \n  }\r\n\r\n  void add(int i, E x) {\r\n    int v = (edge ? hld.e_to_v[i] : i);\r\
    \n    if (path_sum) {\r\n      bit_path.add(hld.ELID[v], x);\r\n      bit_path.add(hld.ERID[v],\
    \ -x);\r\n    }\r\n    if (subtree_sum) { bit_subtree.add(hld.LID[v], x); }\r\n\
    \  }\r\n\r\n  E sum_path(int frm, int to) {\r\n    int lca = hld.LCA(frm, to);\r\
    \n    E x1 = bit_path.sum(hld.ELID[lca] + 1, hld.ELID[frm] + 1);\r\n    E x2 =\
    \ bit_path.sum(hld.ELID[lca] + edge, hld.ELID[to] + 1);\r\n    return x1 + x2;\r\
    \n  }\r\n\r\n  E sum_subtree(int v) {\r\n    return bit_subtree.sum(hld.LID[v]\
    \ + edge, hld.RID[v]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"bit_path\");\r\n    bit_path.debug();\r\n  \
    \  print(\"bit_subtree\");\r\n    bit_subtree.debug();\r\n  }\r\n\r\n  void doc()\
    \ {\r\n    print(\"EulerTour + FenwickTree\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(logN) \u6642\u9593\u3002\");\r\n    print(\"\u30A2\u30FC\u30D9\u30EB\u7FA4\
    \u3067\u3042\u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3092 O(logN) \u6642\u9593\u306B\u3059\u308B\u3002\");\r\n    print(\"\
    operator +- \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\u306A\
    \u3069\u304C\u3042\u308B\");\r\n  }\r\n};\r\n"
  dependsOn:
  - algebra/monoid.hpp
  - ds/fenwick.hpp
  - graph/hld.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/treeabel.hpp
  requiredBy: []
  timestamp: '2021-12-27 18:40:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
documentation_of: graph/treeabel.hpp
layout: document
redirect_from:
- /library/graph/treeabel.hpp
- /library/graph/treeabel.hpp.html
title: graph/treeabel.hpp
---
