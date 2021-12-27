---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing\
    \ pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint = unsigned int;\nusing\
    \ ull = unsigned long long;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type,\
    \ name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n#define vv(type,\
    \ name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  IN(name)\n#define vvv(type, name, h, w, ...) \\\n  vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i, m, n)\
    \ for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i = (ll)(n)-1;\
    \ (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m);\
    \ --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t\
    \ - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n\
    #define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ mt make_tuple\n#define fi first\n#define se second\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(uint x) { return __builtin_popcount(x);\
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
    \  sort(all(ids), [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i\
    \ < j); });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check, ll\
    \ ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x\
    \ = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n      ng = x;\n\
    \  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a,\
    \ const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp\"\
    \n\n#line 2 \"ds/segtree.hpp\"\ntemplate <class Monoid>\nstruct SegTree {\n  using\
    \ X = typename Monoid::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int\
    \ n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) : SegTree(vc<X>(n,\
    \ Monoid::unit)) {}\n  SegTree(vc<X> &v) : n(len(v)) {\n    log = 1;\n    while\
    \ ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit);\n\
    \    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\
    \n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n\
    \  void set(int i, X x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while\
    \ (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n\
    \    assert(R <= n);\n    X vl = Monoid::unit, vr = Monoid::unit;\n    L += size,\
    \ R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n\
    \      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n  \
    \  }\n    return Monoid::op(vl, vr);\n  }\n\n  template <class F>\n  int max_right(F\
    \ &check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit));\n   \
    \ if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit;\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < n) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - n;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F &check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit));\n    if (R == 0) return 0;\n    R += n;\n  \
    \  X sm = Monoid::unit;\n    do {\n      --R;\n      while (R > 1 && (R % 2))\
    \ R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R < n)\
    \ {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R], sm))) {\n\
    \            sm = Monoid::op(dat[R], sm);\n            R--;\n          }\n   \
    \     }\n        return R + 1 - n;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(\"\
    segtree\", dat); }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n  int frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c,\
    \ int d) : frm(a), to(b), cost(c), id(d) {}\n};\n\ntemplate <typename T>\nstruct\
    \ Graph {\n  int N, M;\n  using edge_t = Edge<T>;\n  vector<edge_t> edges;\n \
    \ vector<vector<edge_t>> G;\n  bool directed;\n  Graph() {}\n  Graph(int N, bool\
    \ bl = false) : N(N), M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to,\
    \ T cost = 1, int i = -1) {\n    if (i == -1) i = M;\n    auto e = edge_t(frm,\
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
    \u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n};\r\n#line 1 \"mod/modint.hpp\"\
    \ntemplate< int mod >\nstruct modint {\n  int x;\n\n  modint() : x(0) {}\n\n \
    \ modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n  modint\
    \ &operator+=(const modint &p) {\n    if((x += p.x) >= mod) x -= mod;\n    return\
    \ *this;\n  }\n\n  modint &operator-=(const modint &p) {\n    if((x += mod - p.x)\
    \ >= mod) x -= mod;\n    return *this;\n  }\n\n  modint &operator*=(const modint\
    \ &p) {\n    x = (int) (1LL * x * p.x % mod);\n    return *this;\n  }\n\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n\n  modint operator-() const { return modint(-x); }\n\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n\n  modint operator-(const\
    \ modint &p) const { return modint(*this) -= p; }\n\n  modint operator*(const\
    \ modint &p) const { return modint(*this) *= p; }\n\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n\n  bool operator==(const modint\
    \ &p) const { return x == p.x; }\n\n  bool operator!=(const modint &p) const {\
    \ return x != p.x; }\n\n  modint inverse() const {\n    int a = x, b = mod, u\
    \ = 1, v = 0, t;\n    while(b > 0) {\n      t = a / b;\n      swap(a -= t * b,\
    \ b);\n      swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n\n  modint\
    \ pow(int64_t n) const {\n    modint ret(1), mul(x);\n    while(n > 0) {\n   \
    \   if(n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const modint &p) {\n\
    \    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is, modint\
    \ &a) {\n    int64_t t;\n    is >> t;\n    a = modint< mod >(t);\n    return (is);\n\
    \  }\n\n  static int get_mod() { return mod; }\n};\n\ntemplate< typename T >\n\
    struct ModCalc {\n  vector<T> _fact = {1, 1};\n  vector<T> _fact_inv = {1, 1};\n\
    \  vector<T> _inv = {0, 1};\n  \n  T pow(T a, int n){\n    T x(1);\n    while(n)\
    \ {\n      if(n & 1) x *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return\
    \ x;\n  }\n  void expand(int n){\n    while(_fact.size() <= n){\n      auto i\
    \ = _fact.size();\n      _fact.eb(_fact[i-1] * T(i));\n      auto q = T::get_mod()\
    \ / i, r = T::get_mod() % i;\n      _inv.eb(_inv[r] * T(T::get_mod()-q));\n  \
    \    _fact_inv.eb(_fact_inv[i-1] * _inv[i]);\n    }\n  }\n\n  T fact(int n){\n\
    \    if(n >= _fact.size()) expand(n);\n    return _fact[n];\n  }\n\n  T fact_inv(int\
    \ n){\n    if(n >= _fact.size()) expand(n);\n    return _fact_inv[n];\n  }\n \
    \ \n  T inv(int n){\n    if(n >= _fact.size()) expand(n);\n    return _inv[n];\n\
    \  }\n  \n  T C(ll n, ll k, bool large=false){\n    assert(n >= 0);\n    if (k\
    \ < 0 || n < k) return 0;\n    if (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);\n\
    \    k = min(k, n-k);\n    T x(1);\n    FOR(i, k){\n      x *= n - i;\n      x\
    \ *= inv(i + 1);\n    }\n    return x;\n  }\n};\n\nusing modint107 = modint<1'000'000'007>;\n\
    using modint998 = modint<998'244'353>;\n#line 8 \"test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp\"\
    \n\nusing mint = modint998;\n\ntemplate <typename Graph, typename E, bool edge\
    \ = false>\nstruct TreeGroup {\n  using F = function<E(E, E)>;\n  using G = function<E(E)>;\n\
    \n  HLD<Graph> &hld;\n  int N;\n  F f;\n  G inverse;\n  E unit;\n  const bool\
    \ commute;\n  const bool path_query;\n  const bool subtree_query;\n  SegTree<E>\
    \ seg, seg_r, seg_subtree;\n\n  TreeGroup(HLD<Graph> &hld, Monoid<E> Mono, bool\
    \ path_query,\n            bool subtree_query)\n      : hld(hld)\n      , N(hld.N)\n\
    \      , f(Mono.f)\n      , inverse(Mono.inverse)\n      , unit(Mono.unit)\n \
    \     , commute(Mono.commute)\n      , path_query(path_query)\n      , subtree_query(subtree_query)\n\
    \      , seg(Mono)\n      , seg_r(Monoid_reverse<E>(Mono))\n      , seg_subtree(Mono)\
    \ {\n    assert(Mono.has_inverse);\n    if (path_query) {\n      seg.init(N +\
    \ N);\n      if (!commute) seg_r.init(N + N);\n    }\n    if (subtree_query) {\n\
    \      assert(Mono.commute);\n      seg_subtree.init(N);\n    }\n  };\n\n  void\
    \ init_path(vc<E> &dat) {\n    vc<E> seg_raw(N + N, unit);\n    if (!edge) {\n\
    \      FOR(v, N) {\n        seg_raw[hld.ELID[v]] = dat[v];\n        seg_raw[hld.ERID[v]]\
    \ = inverse(dat[v]);\n      }\n    } else {\n      FOR(i, N - 1) {\n        int\
    \ v = hld.e_to_v[i];\n        seg_raw[hld.ELID[v]] = dat[i];\n        seg_raw[hld.ERID[v]]\
    \ = inverse(dat[i]);\n      }\n    }\n    seg.build(seg_raw);\n    if (!commute)\
    \ seg_r.build(seg_raw);\n  }\n\n  void init_subtree(vc<E> &dat) {\n    vc<E> seg_raw(N,\
    \ unit);\n    if (!edge) {\n      FOR(v, N) { seg_raw[hld.LID[v]] = dat[v]; }\n\
    \    } else {\n      FOR(i, N - 1) {\n        int v = hld.e_to_v[i];\n       \
    \ seg_raw[hld.LID[v]] = dat[i];\n      }\n    }\n    seg_subtree.build(seg_raw);\n\
    \  }\n\n  void init(vc<E> &dat) {\n    // vertex index OR edge index\n    if (path_query)\
    \ init_path(dat);\n    if (subtree_query) init_subtree(dat);\n  }\n\n  void set_path(int\
    \ v, E x) {\n    seg.set(hld.ELID[v], x);\n    seg.set(hld.ERID[v], inverse(x));\n\
    \    if (!commute) {\n      seg_r.set(hld.ELID[v], x);\n      seg_r.set(hld.ERID[v],\
    \ inverse(x));\n    }\n  }\n\n  void set_subtree(int v, E x) { seg_subtree.set(hld.LID[v],\
    \ x); }\n\n  void set(int i, E x) {\n    int v = (edge ? hld.e_to_v[i] : i);\n\
    \    if (path_query) set_path(v, x);\n    if (subtree_query) set_subtree(v, x);\n\
    \  }\n\n  E prod_path(int frm, int to) {\n    int lca = hld.LCA(frm, to);\n  \
    \  // [frm, lca)\n    E x1 = (commute ? seg.prod(hld.ELID[lca] + 1, hld.ELID[frm]\
    \ + 1)\n                    : seg_r.prod(hld.ELID[lca] + 1, hld.ELID[frm] + 1));\n\
    \    // edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\n    E\
    \ x2 = seg.prod(hld.ELID[lca] + edge, hld.ELID[to] + 1);\n    return f(x1, x2);\n\
    \  }\n\n  E prod_subtree(int u) {\n    assert(subtree_query);\n    int l = hld.LID[u],\
    \ r = hld.RID[u];\n    return seg_subtree.prod(l + edge, r);\n  }\n\n  void debug()\
    \ {\n    print(\"hld\");\n    hld.debug();\n    print(\"seg\");\n    seg.debug();\n\
    \    print(\"seg_r\");\n    seg_r.debug();\n    print(\"seg_subtree\");\n    seg_subtree.debug();\n\
    \  }\n\n  void doc() {\n    print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\n\
    \    print(\"\u9006\u5143\u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\u3002\");\n    print(\"\
    \u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\
    \u30A8\u30EA O(logN) \u6642\u9593\u3002\");\n  }\n};\n\nvoid solve() {\n  LL(N,\
    \ Q);\n  using E = pair<mint, mint>;\n  vc<E> A(N);\n  FOR(i, N) {\n    LL(a,\
    \ b);\n    A[i] = mp(mint(a), mint(b));\n  }\n\n  Graph<int> G(N);\n  FOR(_, N\
    \ - 1) {\n    LL(a, b);\n    G.add(a, b);\n  }\n\n  HLD<Graph<int>> hld(G);\n\
    \  TreeGroup<Graph<int>, E, false> TG(hld, Monoid_affine<mint>(true), true,\n\
    \                                     false);\n  TG.init(A);\n\n  FOR(_, Q) {\n\
    \    LL(t);\n    if (t == 0) {\n      LL(v, c, d);\n      TG.set(v, E({mint(c),\
    \ mint(d)}));\n    } else {\n      LL(u, v, x);\n      auto e = TG.prod_path(u,\
    \ v);\n      print(e.fi * mint(x) + e.se);\n    }\n  }\n}\n\nsigned main() {\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"my_template.hpp\"\n\n#include \"ds/segtree.hpp\"\n#include \"graph/base.hpp\"\
    \n#include \"graph/hld.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\
    \ntemplate <typename Graph, typename E, bool edge = false>\nstruct TreeGroup {\n\
    \  using F = function<E(E, E)>;\n  using G = function<E(E)>;\n\n  HLD<Graph> &hld;\n\
    \  int N;\n  F f;\n  G inverse;\n  E unit;\n  const bool commute;\n  const bool\
    \ path_query;\n  const bool subtree_query;\n  SegTree<E> seg, seg_r, seg_subtree;\n\
    \n  TreeGroup(HLD<Graph> &hld, Monoid<E> Mono, bool path_query,\n            bool\
    \ subtree_query)\n      : hld(hld)\n      , N(hld.N)\n      , f(Mono.f)\n    \
    \  , inverse(Mono.inverse)\n      , unit(Mono.unit)\n      , commute(Mono.commute)\n\
    \      , path_query(path_query)\n      , subtree_query(subtree_query)\n      ,\
    \ seg(Mono)\n      , seg_r(Monoid_reverse<E>(Mono))\n      , seg_subtree(Mono)\
    \ {\n    assert(Mono.has_inverse);\n    if (path_query) {\n      seg.init(N +\
    \ N);\n      if (!commute) seg_r.init(N + N);\n    }\n    if (subtree_query) {\n\
    \      assert(Mono.commute);\n      seg_subtree.init(N);\n    }\n  };\n\n  void\
    \ init_path(vc<E> &dat) {\n    vc<E> seg_raw(N + N, unit);\n    if (!edge) {\n\
    \      FOR(v, N) {\n        seg_raw[hld.ELID[v]] = dat[v];\n        seg_raw[hld.ERID[v]]\
    \ = inverse(dat[v]);\n      }\n    } else {\n      FOR(i, N - 1) {\n        int\
    \ v = hld.e_to_v[i];\n        seg_raw[hld.ELID[v]] = dat[i];\n        seg_raw[hld.ERID[v]]\
    \ = inverse(dat[i]);\n      }\n    }\n    seg.build(seg_raw);\n    if (!commute)\
    \ seg_r.build(seg_raw);\n  }\n\n  void init_subtree(vc<E> &dat) {\n    vc<E> seg_raw(N,\
    \ unit);\n    if (!edge) {\n      FOR(v, N) { seg_raw[hld.LID[v]] = dat[v]; }\n\
    \    } else {\n      FOR(i, N - 1) {\n        int v = hld.e_to_v[i];\n       \
    \ seg_raw[hld.LID[v]] = dat[i];\n      }\n    }\n    seg_subtree.build(seg_raw);\n\
    \  }\n\n  void init(vc<E> &dat) {\n    // vertex index OR edge index\n    if (path_query)\
    \ init_path(dat);\n    if (subtree_query) init_subtree(dat);\n  }\n\n  void set_path(int\
    \ v, E x) {\n    seg.set(hld.ELID[v], x);\n    seg.set(hld.ERID[v], inverse(x));\n\
    \    if (!commute) {\n      seg_r.set(hld.ELID[v], x);\n      seg_r.set(hld.ERID[v],\
    \ inverse(x));\n    }\n  }\n\n  void set_subtree(int v, E x) { seg_subtree.set(hld.LID[v],\
    \ x); }\n\n  void set(int i, E x) {\n    int v = (edge ? hld.e_to_v[i] : i);\n\
    \    if (path_query) set_path(v, x);\n    if (subtree_query) set_subtree(v, x);\n\
    \  }\n\n  E prod_path(int frm, int to) {\n    int lca = hld.LCA(frm, to);\n  \
    \  // [frm, lca)\n    E x1 = (commute ? seg.prod(hld.ELID[lca] + 1, hld.ELID[frm]\
    \ + 1)\n                    : seg_r.prod(hld.ELID[lca] + 1, hld.ELID[frm] + 1));\n\
    \    // edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\n    E\
    \ x2 = seg.prod(hld.ELID[lca] + edge, hld.ELID[to] + 1);\n    return f(x1, x2);\n\
    \  }\n\n  E prod_subtree(int u) {\n    assert(subtree_query);\n    int l = hld.LID[u],\
    \ r = hld.RID[u];\n    return seg_subtree.prod(l + edge, r);\n  }\n\n  void debug()\
    \ {\n    print(\"hld\");\n    hld.debug();\n    print(\"seg\");\n    seg.debug();\n\
    \    print(\"seg_r\");\n    seg_r.debug();\n    print(\"seg_subtree\");\n    seg_subtree.debug();\n\
    \  }\n\n  void doc() {\n    print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\n\
    \    print(\"\u9006\u5143\u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\u3002\");\n    print(\"\
    \u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\
    \u30A8\u30EA O(logN) \u6642\u9593\u3002\");\n  }\n};\n\nvoid solve() {\n  LL(N,\
    \ Q);\n  using E = pair<mint, mint>;\n  vc<E> A(N);\n  FOR(i, N) {\n    LL(a,\
    \ b);\n    A[i] = mp(mint(a), mint(b));\n  }\n\n  Graph<int> G(N);\n  FOR(_, N\
    \ - 1) {\n    LL(a, b);\n    G.add(a, b);\n  }\n\n  HLD<Graph<int>> hld(G);\n\
    \  TreeGroup<Graph<int>, E, false> TG(hld, Monoid_affine<mint>(true), true,\n\
    \                                     false);\n  TG.init(A);\n\n  FOR(_, Q) {\n\
    \    LL(t);\n    if (t == 0) {\n      LL(v, c, d);\n      TG.set(v, E({mint(c),\
    \ mint(d)}));\n    } else {\n      LL(u, v, x);\n      auto e = TG.prod_path(u,\
    \ v);\n      print(e.fi * mint(x) + e.se);\n    }\n  }\n}\n\nsigned main() {\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/segtree.hpp
  - graph/base.hpp
  - graph/hld.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 06:02:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
- /verify/test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp.html
title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
---
