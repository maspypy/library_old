---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group_add.hpp
    title: algebra/group_add.hpp
  - icon: ':x:'
    path: algebra/group_mul.hpp
    title: algebra/group_mul.hpp
  - icon: ':x:'
    path: algebra/lazy_add_mul.hpp
    title: algebra/lazy_add_mul.hpp
  - icon: ':question:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/bfsnumbering.hpp
    title: graph/bfsnumbering.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/899
    links:
    - https://yukicoder.me/problems/no/899
  bundledCode: "#line 1 \"test/yukicoder/899_bfsnumbering.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/899\"\r\n#line 2 \"my_template.hpp\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing ll8\
    \ = __int128;\nusing ld = long double;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\n\
    using uint = unsigned int;\nusing ull = unsigned long long;\n\ntemplate <class\
    \ T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define VEC(type, name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 2 \"graph/base.hpp\"\
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
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 2 \"graph/bfsnumbering.hpp\"\
    \n\r\ntemplate <typename Graph>\r\nstruct BFSNumbering {\r\n  Graph& G;\r\n  int\
    \ root;\r\n  vector<int> V;\r\n  vector<int> ID;\r\n  vector<int> depth;\r\n \
    \ vector<int> parent;\r\n  vector<int> LID, RID;\r\n  vector<int> LID_seq;\r\n\
    \  vector<int> dep_ids;\r\n  int cnt;\r\n\r\n  BFSNumbering(Graph& G, int root\
    \ = 0) : G(G), root(root), cnt(0) { build(); }\r\n\r\n  void bfs() {\r\n    deque<int>\
    \ que = {root};\r\n    while (!que.empty()) {\r\n      int v = que.front();\r\n\
    \      que.pop_front();\r\n      ID[v] = V.size();\r\n      V.eb(v);\r\n     \
    \ for(auto&& [frm,to,cost,id] : G[v]) {\r\n        if (to == parent[v]) continue;\r\
    \n        que.emplace_back(to);\r\n        parent[to] = v;\r\n        depth[to]\
    \ = depth[v] + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n  void dfs(int v) {\r\n  \
    \  LID[v] = cnt++;\r\n    for(auto&& [frm,to,cost,id] : G[v]) {\r\n      if (to\
    \ == parent[v]) continue;\r\n      dfs(to);\r\n    }\r\n    RID[v] = cnt;\r\n\
    \  }\r\n\r\n  void build() {\r\n    int N = G.N;\r\n    V.reserve(N);\r\n    parent.assign(N,\
    \ -1);\r\n    ID.assign(N, 0);\r\n    LID.assign(N, 0);\r\n    RID.assign(N, 0);\r\
    \n    depth.assign(N, 0);\r\n    bfs();\r\n    dfs(root);\r\n    int D = MAX(depth);\r\
    \n    dep_ids.resize(D + 2);\r\n    FOR(v, N) dep_ids[depth[v] + 1]++;\r\n   \
    \ FOR(d, D + 1) dep_ids[d + 1] += dep_ids[d];\r\n    LID_seq.reserve(N);\r\n \
    \   FOR(i, N) LID_seq.eb(LID[V[i]]);\r\n  }\r\n\r\n  int bs(int L, int R, int\
    \ x) {\r\n    while (L + 1 < R) {\r\n      int M = (L + R) / 2;\r\n      if (LID_seq[M]\
    \ >= x)\r\n        R = M;\r\n      else\r\n        L = M;\r\n    }\r\n    return\
    \ R;\r\n  }\r\n\r\n  pair<int, int> calc_range(int v, int dep) {\r\n    assert(dep\
    \ >= depth[v]);\r\n    if (dep >= len(dep_ids) - 1) return {0, 0};\r\n    int\
    \ l = LID[v], r = RID[v];\r\n    int L = dep_ids[dep], R = dep_ids[dep + 1];\r\
    \n    int a = bs(L - 1, R, l);\r\n    int b = bs(L - 1, R, r);\r\n    return {a,\
    \ b};\r\n  }\r\n};\r\n#line 2 \"ds/lazysegtree.hpp\"\n\ntemplate <typename Lazy>\n\
    struct LazySegTree {\n  using Monoid_X = typename Lazy::X_structure;\n  using\
    \ Monoid_A = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
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
    \n    return Monoid_X::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\
    \n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n    p += size;\n \
    \   dat[p] = Lazy::act(dat[p], a);\n    for (int i = 1; i <= log; i++) update(p\
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
    lazysegtree getall:\", get_all()); }\n};\n#line 2 \"algebra/group_add.hpp\"\n\
    template <class X, X ZERO = X(0)>\r\nstruct Group_Add {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return n * x; }\r\n\
    \  static constexpr X unit = ZERO;\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 1 \"algebra/group_mul.hpp\"\ntemplate <class X, X ONE = X(1)>\r\n\
    struct Group_Mul {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit = ONE;\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 3 \"algebra/lazy_add_mul.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Lazy_Add_Mul {\r\n  using MX = Group_Add<E>;\r\
    \n  using MA = Group_Mul<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return x * a; }\r\n};\r\n\
    #line 6 \"test/yukicoder/899_bfsnumbering.test.cpp\"\n\r\nvoid solve() {\r\n \
    \ LL(N);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\n    LL(a, b);\r\n    G.add(a,\
    \ b);\r\n  }\r\n  G.prepare();\r\n\r\n  BFSNumbering BFS(G);\r\n  auto &ID = BFS.ID;\r\
    \n  vi seg_raw(N);\r\n\r\n  FOR(v, N) {\r\n    LL(a);\r\n    seg_raw[ID[v]] =\
    \ a;\r\n  }\r\n\r\n  using Lazy = Lazy_Add_Mul<ll>;\r\n  LazySegTree<Lazy> seg(seg_raw);\r\
    \n\r\n  LL(Q);\r\n  FOR(_, Q) {\r\n    LL(v);\r\n    ll p = BFS.parent[v];\r\n\
    \    ll pp = (p == -1 ? -1 : BFS.parent[p]);\r\n    ll x = 0;\r\n    if (pp >=\
    \ 0) x += seg.get(ID[pp]), seg.set(ID[pp], 0);\r\n    if (p >= 0) {\r\n      x\
    \ += seg.get(ID[p]), seg.set(ID[p], 0);\r\n      auto [l, r] = BFS.calc_range(p,\
    \ BFS.depth[p] + 1);\r\n      x += seg.prod(l, r), seg.apply(l, r, 0);\r\n   \
    \ }\r\n    FOR(d, 3) {\r\n      auto [l, r] = BFS.calc_range(v, BFS.depth[v] +\
    \ d);\r\n      x += seg.prod(l, r), seg.apply(l, r, 0);\r\n    }\r\n    print(x);\r\
    \n    seg.set(ID[v], x);\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  ll T\
    \ = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/899\"\r\n#include \"my_template.hpp\"\
    \r\n#include \"graph/bfsnumbering.hpp\"\r\n#include \"ds/lazysegtree.hpp\"\r\n\
    #include \"algebra/lazy_add_mul.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int>\
    \ G(N);\r\n  FOR(_, N - 1) {\r\n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n \
    \ G.prepare();\r\n\r\n  BFSNumbering BFS(G);\r\n  auto &ID = BFS.ID;\r\n  vi seg_raw(N);\r\
    \n\r\n  FOR(v, N) {\r\n    LL(a);\r\n    seg_raw[ID[v]] = a;\r\n  }\r\n\r\n  using\
    \ Lazy = Lazy_Add_Mul<ll>;\r\n  LazySegTree<Lazy> seg(seg_raw);\r\n\r\n  LL(Q);\r\
    \n  FOR(_, Q) {\r\n    LL(v);\r\n    ll p = BFS.parent[v];\r\n    ll pp = (p ==\
    \ -1 ? -1 : BFS.parent[p]);\r\n    ll x = 0;\r\n    if (pp >= 0) x += seg.get(ID[pp]),\
    \ seg.set(ID[pp], 0);\r\n    if (p >= 0) {\r\n      x += seg.get(ID[p]), seg.set(ID[p],\
    \ 0);\r\n      auto [l, r] = BFS.calc_range(p, BFS.depth[p] + 1);\r\n      x +=\
    \ seg.prod(l, r), seg.apply(l, r, 0);\r\n    }\r\n    FOR(d, 3) {\r\n      auto\
    \ [l, r] = BFS.calc_range(v, BFS.depth[v] + d);\r\n      x += seg.prod(l, r),\
    \ seg.apply(l, r, 0);\r\n    }\r\n    print(x);\r\n    seg.set(ID[v], x);\r\n\
    \  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  ll T = 1;\r\n  // LL(T);\r\n  FOR(_, T)\
    \ solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - graph/bfsnumbering.hpp
  - graph/base.hpp
  - ds/lazysegtree.hpp
  - algebra/lazy_add_mul.hpp
  - algebra/group_add.hpp
  - algebra/group_mul.hpp
  isVerificationFile: true
  path: test/yukicoder/899_bfsnumbering.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 02:47:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/899_bfsnumbering.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/899_bfsnumbering.test.cpp
- /verify/test/yukicoder/899_bfsnumbering.test.cpp.html
title: test/yukicoder/899_bfsnumbering.test.cpp
---
