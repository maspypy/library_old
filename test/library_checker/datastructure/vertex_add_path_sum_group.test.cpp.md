---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group_add.hpp
    title: algebra/group_add.hpp
  - icon: ':x:'
    path: algebra/group_reverse.hpp
    title: algebra/group_reverse.hpp
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  - icon: ':x:'
    path: graph/treegroup.hpp
    title: graph/treegroup.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\n\
    #line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing\
    \ pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint = unsigned int;\nusing\
    \ ull = unsigned long long;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type,\
    \ name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n#define vv(type,\
    \ name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  IN(name)\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR0(n) for (ll _ = 0; (_) < (ll)(n);\
    \ ++(_))\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i,\
    \ m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i\
    \ = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1;\
    \ (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t =\
    \ (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x)\
    \ ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(uint x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(ull x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return 31 - __builtin_clz(x); }\nint topbit(uint x) { return\
    \ 31 - __builtin_clz(x); }\nint topbit(ll x) { return 63 - __builtin_clzll(x);\
    \ }\nint topbit(ull x) { return 63 - __builtin_clzll(x); }\n// (0, 1, 2, 3, 4)\
    \ -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(uint x) { return 31 - __builtin_clz(x); }\nint lowbit(ll x) {\
    \ return 63 - __builtin_clzll(x); }\nint lowbit(ull x) { return 63 - __builtin_clzll(x);\
    \ }\n\nll ceil(ll x, ll y) { return (x > 0 ? (x + y - 1) / y : x / y); }\nll floor(ll\
    \ x, ll y) { return (x > 0 ? x / y : (x - y + 1) / y); }\npi divmod(ll x, ll y)\
    \ {\n  ll q = floor(x, y);\n  return {q, x - q * y};\n}\n\n#define INT(...)  \
    \ \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__; \\\n\
    \  IN(__VA_ARGS__)\n#define CHR(...)    \\\n  char __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define DBL(...)           \\\n  long double __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    void scan(int &a) { cin >> a; }\nvoid scan(long long &a) { cin >> a; }\nvoid scan(char\
    \ &a) { cin >> a; }\nvoid scan(double &a) { cin >> a; }\nvoid scan(long double\
    \ &a) { cin >> a; }\nvoid scan(string &a) { cin >> a; }\ntemplate <class T>\n\
    void scan(pair<T, T> &p) {\n  scan(p.first), scan(p.second);\n}\ntemplate <class\
    \ T>\nvoid scan(tuple<T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));\n\
    }\ntemplate <class T>\nvoid scan(tuple<T, T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)),\
    \ scan(get<2>(p)), scan(get<3>(p));\n}\ntemplate <class T>\nvoid scan(vector<T>\
    \ &a) {\n  for (auto &i: a) scan(i);\n}\ntemplate <class T>\nvoid scan(T &a) {\n\
    \  cin >> a;\n}\nvoid IN() {}\ntemplate <class Head, class... Tail>\nvoid IN(Head\
    \ &head, Tail &... tail) {\n  scan(head);\n  IN(tail...);\n}\n\nvi s_to_vi(string\
    \ S, char first_char = 'a') {\n  vi A(S.size());\n  FOR(i, S.size()) { A[i] =\
    \ S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &A) {\n  os << A.fi << \" \"\
    \ << A.se;\n  return os;\n}\ntemplate <typename T1, typename T2, typename T3>\n\
    ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &t) {\n  os << get<0>(t)\
    \ << \" \" << get<1>(t) << \" \" << get<2>(t);\n  return os;\n}\ntemplate <typename\
    \ T1, typename T2, typename T3, typename T4>\nostream &operator<<(ostream &os,\
    \ const tuple<T1, T2, T3, T4> &t) {\n  os << get<0>(t) << \" \" << get<1>(t) <<\
    \ \" \" << get<2>(t) << \" \" << get<3>(t);\n  return os;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &A) {\n  for (size_t i\
    \ = 0; i < A.size(); i++) {\n    if (i) os << \" \";\n    os << A[i];\n  }\n \
    \ return os;\n}\n\nvoid print() { cout << \"\\n\"; }\ntemplate <class Head, class...\
    \ Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  cout << head;\n  if (sizeof...(Tail))\
    \ cout << \" \";\n  print(forward<Tail>(tail)...);\n}\n\nvoid YES(bool t = 1)\
    \ { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t);\
    \ }\n\ntemplate <typename T>\nvector<T> cumsum(vector<T> &A) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  B[0] = T(0);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  return B;\n}\n\nvc<int> bin_count(vi &A, int size) {\n  vc<int> C(size);\n\
    \  for (auto &x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int>\
    \ argsort(vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids), 0);\n\
    \  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j); });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check,\
    \ ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n      ng = x;\n\
    \  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a,\
    \ const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp\"\
    \n\r\n#line 2 \"algebra/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\n\
    struct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/segtree.hpp\"\ntemplate\
    \ <class Monoid>\nstruct SegTree {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0)\
    \ {}\n  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit)) {}\n  SegTree(vc<X> v)\
    \ : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, Monoid::unit);\n    FOR(i, n) dat[size +\
    \ i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int i) {\
    \ dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n  void set(int i, X x)\
    \ {\n    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n    assert(R <= n);\n \
    \   X vl = Monoid::unit, vr = Monoid::unit;\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1)\
    \ vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  X prod_all() { return dat[1];}\n\n  template <class F>\n  int\
    \ max_right(F &check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit;\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F &check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit;\n    do {\n      --R;\n      while (R > 1 && (R % 2))\
    \ R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R < n)\
    \ {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R], sm))) {\n\
    \            sm = Monoid::op(dat[R], sm);\n            R--;\n          }\n   \
    \     }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
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
    #line 1 \"algebra/group_reverse.hpp\"\ntemplate <class Group>\r\nstruct Group_Reverse\
    \ {\r\n  using value_type = typename Group::value_type;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return Group::op(y, x); }\r\
    \n  static constexpr X inverse(const X &x) { return Group::inverse(x); }\r\n \
    \ static constexpr X unit = Group::unit;\r\n  static const bool commute = Group::commute;\r\
    \n};\r\n#line 4 \"graph/treegroup.hpp\"\n\r\n// \u4F5C\u3063\u3066\u307F\u305F\
    \u3082\u306E\u306E\u3001HLD(log^2N)\u3088\u308A\u9045\u3044\u304C\u3061\uFF1F\r\
    \ntemplate <typename HLD, typename Group, bool edge = false,\r\n          bool\
    \ path_query = true, bool subtree_query = false>\r\nstruct TreeGroup {\r\n  using\
    \ RevGroup = Group_Reverse<Group>;\r\n  using X = typename Group::value_type;\r\
    \n  HLD &hld;\r\n  int N;\r\n  SegTree<Group> seg, seg_subtree;\r\n  SegTree<RevGroup>\
    \ seg_r;\r\n\r\n  TreeGroup(HLD &hld) : hld(hld), N(hld.N) {\r\n    if (path_query)\
    \ {\r\n      seg = SegTree<Group>(2 * N);\r\n      if (!Group::commute) seg_r\
    \ = SegTree<RevGroup>(2 * N);\r\n    }\r\n    if (subtree_query) {\r\n      assert(Group::commute);\r\
    \n      seg_subtree = SegTree<Group>(N);\r\n    }\r\n  }\r\n\r\n  TreeGroup(HLD\
    \ &hld, vc<X> dat) : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      vc<X>\
    \ seg_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat) == N);\r\n\
    \        FOR(v, N) {\r\n          seg_raw[hld.ELID(v)] = dat[v];\r\n         \
    \ seg_raw[hld.ERID(v)] = Group::inverse(dat[v]);\r\n        }\r\n      } else\
    \ {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1) {\r\n     \
    \     int v = hld.e_to_v(e);\r\n          seg_raw[hld.ELID(v)] = dat[e];\r\n \
    \         seg_raw[hld.ERID(v)] = Group::inverse(dat[e]);\r\n        }\r\n    \
    \  }\r\n      seg = SegTree<Group>(seg_raw);\r\n      if (!Group::commute) seg_r\
    \ = SegTree<RevGroup>(seg_raw);\r\n    }\r\n    if (subtree_query) {\r\n     \
    \ assert(Group::commute);\r\n      vc<X> seg_raw(N);\r\n      if (!edge) {\r\n\
    \        assert(len(dat) == N);\r\n        FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = hld.e_to_v(e);\r\n          seg_raw[hld.LID[v]] = dat[e];\r\
    \n        }\r\n      }\r\n      seg_subtree = SegTree<Group>(seg_raw);\r\n   \
    \ }\r\n  }\r\n\r\n  void set_path(int v, X x) {\r\n    X inv_x = Group::inverse(x);\r\
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
    \ \u6642\u9593\u3002\");\r\n  }\r\n};\n#line 7 \"test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Graph<int> G(N);\r\
    \n  FOR(_, N - 1) {\r\n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\
    \n\r\n  HLD<Graph<int>> hld(G);\r\n  using Group = Group_Add<ll>;\r\n  TreeGroup<decltype(hld),\
    \ Group, false, true, false> TG(hld, A);\r\n\r\n  FOR(_, Q) {\r\n    LL(t);\r\n\
    \    if (t == 0) {\r\n      LL(v, x);\r\n      A[v] += x;\r\n      TG.set(v, A[v]);\r\
    \n    } else {\r\n      LL(u, v);\r\n      print(TG.prod_path(u, v));\r\n    }\r\
    \n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\
    \n#include \"my_template.hpp\"\r\n\r\n#include \"algebra/group_add.hpp\"\r\n#include\
    \ \"ds/segtree.hpp\"\r\n#include \"graph/treegroup.hpp\"\r\n\r\nvoid solve() {\r\
    \n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\
    \n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n\r\n  HLD<Graph<int>>\
    \ hld(G);\r\n  using Group = Group_Add<ll>;\r\n  TreeGroup<decltype(hld), Group,\
    \ false, true, false> TG(hld, A);\r\n\r\n  FOR(_, Q) {\r\n    LL(t);\r\n    if\
    \ (t == 0) {\r\n      LL(v, x);\r\n      A[v] += x;\r\n      TG.set(v, A[v]);\r\
    \n    } else {\r\n      LL(u, v);\r\n      print(TG.prod_path(u, v));\r\n    }\r\
    \n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - algebra/group_add.hpp
  - ds/segtree.hpp
  - graph/treegroup.hpp
  - graph/hld.hpp
  - graph/base.hpp
  - algebra/group_reverse.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 02:47:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
- /verify/test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp.html
title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
---
