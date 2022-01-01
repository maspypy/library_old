---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group_add.hpp
    title: algebra/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/centroid.hpp
    title: graph/centroid.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1038
    links:
    - https://yukicoder.me/problems/no/1038
  bundledCode: "#line 1 \"test/yukicoder/1038_centroid.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1038\"\r\n#line 2 \"my_template.hpp\"\n#include\
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
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n);\
    \ ++(i))\n#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define\
    \ FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n)\
    \ for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for\
    \ (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(uint x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(ull x) { return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4)\
    \ -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - __builtin_clz(x); }\nint\
    \ topbit(uint x) { return 31 - __builtin_clz(x); }\nint topbit(ll x) { return\
    \ 63 - __builtin_clzll(x); }\nint topbit(ull x) { return 63 - __builtin_clzll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return\
    \ 31 - __builtin_clz(x); }\nint lowbit(uint x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(ll x) { return 63 - __builtin_clzll(x); }\nint lowbit(ull x) {\
    \ return 63 - __builtin_clzll(x); }\n\nll ceil(ll x, ll y) { return (x > 0 ? (x\
    \ + y - 1) / y : x / y); }\nll floor(ll x, ll y) { return (x > 0 ? x / y : (x\
    \ - y + 1) / y); }\npi divmod(ll x, ll y) {\n  ll q = floor(x, y);\n  return {q,\
    \ x - q * y};\n}\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define LL(...)   \\\n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)\
    \      \\\n  string __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...)    \\\
    \n  char __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define DBL(...)           \\\n \
    \ long double __VA_ARGS__; \\\n  IN(__VA_ARGS__)\nvoid scan(int &a) { cin >> a;\
    \ }\nvoid scan(long long &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\n\
    void scan(double &a) { cin >> a; }\nvoid scan(long double &a) { cin >> a; }\n\
    void scan(string &a) { cin >> a; }\ntemplate <class T>\nvoid scan(pair<T, T> &p)\
    \ {\n  scan(p.first), scan(p.second);\n}\ntemplate <class T>\nvoid scan(tuple<T,\
    \ T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));\n}\ntemplate\
    \ <class T>\nvoid scan(tuple<T, T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)),\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/yukicoder/1038_centroid.test.cpp\"\
    \n\r\n#line 2 \"algebra/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\n\
    struct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
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
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 2 \"graph/centroid.hpp\"\n\
    template <typename Graph, typename E = int>\r\nstruct CentroidDecomposition {\r\
    \n  using edge_type = typename Graph::edge_type;\r\n  using F = function<E(E,\
    \ edge_type)>;\r\n  Graph& G;\r\n  F f; // (E path value, edge e) -> E new_path_value\r\
    \n  int N;\r\n  vector<int> cdep; // depth in centroid tree\r\n  vc<int> sz;\r\
    \n  vc<int> par;\r\n\r\n  CentroidDecomposition(\r\n      Graph& G, F f = [](int\
    \ x, edge_type e) { return x + e.cost; })\r\n      : G(G), N(G.N), f(f), sz(G.N),\
    \ par(G.N), cdep(G.N, -1) {\r\n    build();\r\n  }\r\n\r\n  int find(int v) {\r\
    \n    vc<int> V = {v};\r\n    par[v] = -1;\r\n    int p = 0;\r\n    while (p <\
    \ len(V)) {\r\n      int v = V[p++];\r\n      sz[v] = 0;\r\n      for (auto&&\
    \ e: G[v]) {\r\n        if (e.to == par[v] || cdep[e.to] != -1) continue;\r\n\
    \        par[e.to] = v;\r\n        V.eb(e.to);\r\n      }\r\n    }\r\n    while\
    \ (len(V)) {\r\n      int v = V.back();\r\n      V.pop_back();\r\n      sz[v]\
    \ += 1;\r\n      if (p - sz[v] <= p / 2) return v;\r\n      sz[par[v]] += sz[v];\r\
    \n    }\r\n    return -1;\r\n  }\r\n\r\n  void build() {\r\n    assert(G.is_prepared());\r\
    \n    assert(!G.is_directed());\r\n    int N = G.N;\r\n\r\n    vc<pair<int, int>>\
    \ st = {{0, 0}};\r\n    while (len(st)) {\r\n      auto [lv, v] = st.back();\r\
    \n      st.pop_back();\r\n      auto c = find(v);\r\n      cdep[c] = lv;\r\n \
    \     for (auto&& [frm, to, cost, id]: G[c]) {\r\n        if (cdep[to] == -1)\
    \ st.eb(lv + 1, to);\r\n      }\r\n    }\r\n  }\r\n\r\n  vc<vc<pair<int, E>>>\
    \ collect(int root, E root_val) {\r\n    /*\r\n    root \u3092\u91CD\u5FC3\u3068\
    \u3059\u308B\u6728\u306B\u304A\u3044\u3066\u3001(v, path data v) \u306E vector\
    \ \u3092\u3001\u65B9\u5411\u3054\u3068\u306B\u96C6\u3081\u3066\u8FD4\u3059\r\n\
    \    \u30FB0 \u756A\u76EE\uFF1Aroot \u304B\u3089\u306E\u30D1\u30B9\u3059\u3079\
    \u3066\uFF08root \u3092\u542B\u3080\uFF09\r\n    \u30FBi \u756A\u76EE\uFF1Ai \u756A\
    \u76EE\u306E\u65B9\u5411\r\n    */\r\n    vc<vc<pair<int, E>>> res = {{{root,\
    \ root_val}}};\r\n    for (auto&& e: G[root]) {\r\n      int nxt = e.to;\r\n \
    \     if (cdep[nxt] < cdep[root]) continue;\r\n      vc<pair<int, E>> dat;\r\n\
    \      int p = 0;\r\n      dat.eb(nxt, f(root_val, e));\r\n      par[nxt] = root;\r\
    \n      while (p < len(dat)) {\r\n        auto [v, val] = dat[p++];\r\n      \
    \  for (auto&& e: G[v]) {\r\n          if (e.to == par[v]) continue;\r\n     \
    \     if (cdep[e.to] < cdep[root]) continue;\r\n          par[e.to] = v;\r\n \
    \         dat.eb(e.to, f(val, e));\r\n        }\r\n      }\r\n      res.eb(dat);\r\
    \n      res[0].insert(res[0].end(), all(dat));\r\n    }\r\n    return res;\r\n\
    \  }\r\n};\r\n#line 6 \"test/yukicoder/1038_centroid.test.cpp\"\n\r\nvoid solve()\
    \ {\r\n  LL(N, Q);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\n    LL(a, b);\r\
    \n    G.add(--a, --b);\r\n  }\r\n  G.prepare();\r\n\r\n  using T = tuple<ll, ll,\
    \ ll>;\r\n  VEC(T, query, Q);\r\n  for (auto&& [a, b, c]: query) --a;\r\n\r\n\
    \  // \u9802\u70B9 -> \u30AF\u30A8\u30EA\r\n  vc<vi> query_at(N);\r\n  FOR(q,\
    \ Q) query_at[get<0>(query[q])].eb(q);\r\n\r\n  CentroidDecomposition CD(G);\r\
    \n  vi ANS(Q);\r\n  FenwickTree<Group_Add<ll>> bit(N + 10);\r\n\r\n  FOR(root,\
    \ N) {\r\n    auto dats = CD.collect(root, 0);\r\n    FOR(i, len(dats)) {\r\n\
    \      auto dat = dats[i];\r\n      // qid, v, dv\r\n      vc<T> event;\r\n  \
    \    for (auto&& [v, dv]: dat) {\r\n        for (auto&& q: query_at[v]) { event.eb(q,\
    \ v, dv); }\r\n      }\r\n      sort(all(event));\r\n      for (auto&& [qid, v,\
    \ dv]: event) {\r\n        auto [_, y, z] = query[qid];\r\n        ll add = bit.sum(0,\
    \ dv + 1);\r\n        ANS[qid] += (i == 0 ? add : -add);\r\n        if (dv <=\
    \ y) {\r\n          bit.add(0, z);\r\n          bit.add(y - dv + 1, -z);\r\n \
    \       }\r\n      }\r\n      for (auto&& [qid, v, dv]: event) {\r\n        auto\
    \ [_, y, z] = query[qid];\r\n        if (dv <= y) {\r\n          bit.add(0, -z);\r\
    \n          bit.add(y - dv + 1, +z);\r\n        }\r\n      }\r\n    }\r\n  }\r\
    \n  for (auto&& x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  ll T\
    \ = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1038\"\r\n#include \"\
    my_template.hpp\"\r\n\r\n#include \"ds/fenwick.hpp\"\r\n#include \"graph/centroid.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1)\
    \ {\r\n    LL(a, b);\r\n    G.add(--a, --b);\r\n  }\r\n  G.prepare();\r\n\r\n\
    \  using T = tuple<ll, ll, ll>;\r\n  VEC(T, query, Q);\r\n  for (auto&& [a, b,\
    \ c]: query) --a;\r\n\r\n  // \u9802\u70B9 -> \u30AF\u30A8\u30EA\r\n  vc<vi> query_at(N);\r\
    \n  FOR(q, Q) query_at[get<0>(query[q])].eb(q);\r\n\r\n  CentroidDecomposition\
    \ CD(G);\r\n  vi ANS(Q);\r\n  FenwickTree<Group_Add<ll>> bit(N + 10);\r\n\r\n\
    \  FOR(root, N) {\r\n    auto dats = CD.collect(root, 0);\r\n    FOR(i, len(dats))\
    \ {\r\n      auto dat = dats[i];\r\n      // qid, v, dv\r\n      vc<T> event;\r\
    \n      for (auto&& [v, dv]: dat) {\r\n        for (auto&& q: query_at[v]) { event.eb(q,\
    \ v, dv); }\r\n      }\r\n      sort(all(event));\r\n      for (auto&& [qid, v,\
    \ dv]: event) {\r\n        auto [_, y, z] = query[qid];\r\n        ll add = bit.sum(0,\
    \ dv + 1);\r\n        ANS[qid] += (i == 0 ? add : -add);\r\n        if (dv <=\
    \ y) {\r\n          bit.add(0, z);\r\n          bit.add(y - dv + 1, -z);\r\n \
    \       }\r\n      }\r\n      for (auto&& [qid, v, dv]: event) {\r\n        auto\
    \ [_, y, z] = query[qid];\r\n        if (dv <= y) {\r\n          bit.add(0, -z);\r\
    \n          bit.add(y - dv + 1, +z);\r\n        }\r\n      }\r\n    }\r\n  }\r\
    \n  for (auto&& x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  ll T\
    \ = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - ds/fenwick.hpp
  - algebra/group_add.hpp
  - graph/centroid.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test/yukicoder/1038_centroid.test.cpp
  requiredBy: []
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/1038_centroid.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1038_centroid.test.cpp
- /verify/test/yukicoder/1038_centroid.test.cpp.html
title: test/yukicoder/1038_centroid.test.cpp
---
