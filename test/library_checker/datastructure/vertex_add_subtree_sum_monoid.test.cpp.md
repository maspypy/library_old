---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/algebra.hpp
    title: ds/algebra.hpp
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
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\r\
    \n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing\
    \ pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T> using vc = vector<T>;\n\
    template <class T> using vvc = vector<vc<T>>;\ntemplate <class T> using vvvc =\
    \ vector<vvc<T>>;\ntemplate <class T> using vvvvc = vector<vvvc<T>>;\ntemplate\
    \ <class T> using vvvvvc = vector<vvvvc<T>>;\ntemplate <class T> using pq = priority_queue<T>;\n\
    template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\n\n#define\
    \ vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type, name,\
    \ size)                                                                      \
    \                                                            \\\n    vector<type>\
    \ name(size);                                                                \
    \                                                                   \\\n    IN(name)\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define VV(type, name, h, w)                                                 \
    \                                                                            \
    \      \\\n    vector<vector<type>> name(h, vector<type>(w));                \
    \                                                                            \
    \                 \\\n    IN(name)\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)                                                        \
    \                                                                 \\\n    vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i, m, n)\
    \ for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i = (ll)(n)-1;\
    \ (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m);\
    \ --(i))\n#define FORIN(x, A) for (auto&& x : A)\n#define FOR_nCk(s, n, k) \\\n\
    \  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \\\n  tmp_var = s | (s\
    \ - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s)\
    \ + 1))) \n#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1)\
    \ & s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n\n#define\
    \ elif else if\n\nusing ull = unsigned long long;\nusing uint = unsigned int;\n\
    int popcnt(uint x) {\n  return __builtin_popcount(x);\n}\nint popcnt(int x) {\n\
    \  return __builtin_popcount(x);\n}\nint popcnt(ull x) {\n  return __builtin_popcountll(x);\n\
    }\nint popcnt(ll x) {\n  return __builtin_popcountll(x);\n}\nint bsr(uint x) {\n\
    \  return 31 - __builtin_clz(x);\n}\nint bsr(ull x) {\n  return 63 - __builtin_clzll(x);\n\
    }\nint ctz(int x) {\n  return __builtin_ctz(x);\n}\nint ctz(ll x) {\n  return\
    \ __builtin_ctzll(x);\n}\nint ctz(ull x) {\n  return __builtin_ctzll(x);\n}\n\n\
    #define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define\
    \ MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\n#define\
    \ LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\nll ceil(ll x, ll y) {\n    assert(y >= 1);\n    return (x > 0 ?\
    \ (x + y - 1) / y : x / y);\n}\n\nll floor(ll x, ll y) {\n    assert(y >= 1);\n\
    \    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\nll mod(ll x, ll y) {\n  return\
    \ x - y * floor(x, y);\n}\n\n#define INT(...) \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define LL(...) \\\n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)\
    \ \\\n  string __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...) \\\n  char\
    \ __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define DBL(...) \\\n  long double __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\nvoid scan(int &a) { cin >> a; }\nvoid scan(long long\
    \ &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double &a) {\
    \ cin >> a; }\nvoid scan(long double &a) { cin >> a; }\nvoid scan(string &a) {\
    \ cin >> a; }\ntemplate <class T, class S> void scan(pair<T, S> &p) { scan(p.first),\
    \ scan(p.second); }\ntemplate <class T> void scan(vector<T> &a) {for(auto &i :\
    \ a) scan(i);}\ntemplate <class T> void scan(T &a) { cin >> a; }\nvoid IN() {}\n\
    template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {\n  scan(head);\n\
    \  IN(tail...);\n}\n\nll isqrt(ll n) {\n  ll x = n, y = (n + 1) / 2;\n  while\
    \ (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }\n  return x;\n}\n\nvi s_to_vi(string\
    \ S, char first_char='a'){\n  vi A(S.size());\n  FOR(i, S.size()){\n    A[i] =\
    \ S[i] - first_char;\n  }\n  return A;\n}\n\ntemplate <typename T, typename U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& A) {\n  os << A.fi << \" \"\
    \ << A.se;\n  return os;\n}\n\ntemplate <typename T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& A) {\n  for (size_t i = 0; i < A.size(); i++) {\n    if(i)\
    \ os << \" \";\n    os << A[i];\n  }\n  return os;\n}\n\nvoid print() {\n  cout\
    \ << \"\\n\";\n}\n\ntemplate <class Head, class... Tail>\nvoid print(Head&& head,\
    \ Tail&&... tail) {\n  cout << head;\n  if (sizeof...(Tail)) cout << \" \";\n\
    \  print(forward<Tail>(tail)...);\n}\n\nconst string YESNO[2] = {\"NO\", \"YES\"\
    };\nconst string YesNo[2] = {\"No\", \"Yes\"};\nconst string yesno[2] = {\"no\"\
    , \"yes\"};\nvoid YES(bool t = 1) { cout << YESNO[t] << endl; }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { cout << YesNo[t] << endl; }\nvoid\
    \ No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { cout << yesno[t] << endl;\
    \ }\nvoid no(bool t = 1) { yes(!t); }\n\ntemplate <typename T>\nvector<T> cumsum(vector<T>\
    \ A) {\n  ll N = A.size();\n  vector<T> B(N + 1);\n  B[0] = T(0);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  return B;\n}\n\nvi bin_count(vi& A, ll size)\
    \ {\n  vi C(size);\n  for (auto&& x : A) {\n    ++C[x];\n  }\n  return C;\n}\n\
    \ntemplate <typename T>\nvi argsort(vector<T>& A){\n  vi ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](ll i, ll j){\n    return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j);\n  });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check,\
    \ ll ok, ll ng) {\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    if (check(x))\n      ok = x;\n    else\n      ng = x;\n  }\n  return ok;\n\
    }\n\ntemplate <class T, class S> inline bool chmax(T &a, const S &b) { return\
    \ (a < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
    \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\ntemplate <typename T>\nvc<T>\
    \ merge_sort(vc<T>& A, vc<T>& B) {\n  vc<T> C;\n  C.reserve(A.size() + B.size());\n\
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 3 \"test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp\"\
    \n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a), to(b),\
    \ cost(c), id(d) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n  int N, M;\n\
    \  using edge_t = Edge<T>;\n  vector<edge_t> edges;\n  vector<vector<edge_t>>\
    \ G;\n  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false) : N(N),\
    \ M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    if (i == -1) i = M;\n    auto e = edge_t(frm, to, cost, i);\n \
    \   edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n      auto e_rev =\
    \ edge_t(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n    ++M;\n  }\n\n\
    \  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v << \" :\"\
    ;\n      for (auto e : G[v]) {\n        if (detail)\n          cout << \" (\"\
    \ << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n            \
    \   << \")\";\n        else\n          cout << \" \" << e.to;\n      }\n     \
    \ cout << \"\\n\";\n    }\n  }\n\n  vector<int> degrees() {\n    vector<int> deg(N);\n\
    \    FORIN(e, edges) {\n      deg[e.frm]++;\n      deg[e.to]++;\n    }\n    return\
    \ deg;\n  }\n\n  int size() { return N; }\n\n  vector<edge_t>& operator[](int\
    \ v) { return G[v]; }\n};\n#line 2 \"graph/hld.hpp\"\ntemplate <typename Graph>\r\
    \nstruct HLD {\r\n  Graph &G;\r\n  int N;\r\n  vector<int> sz, LID, RID, head,\
    \ V, parent, depth, e_to_v;\r\n\r\n  HLD(Graph &G, int root = 0)\r\n      : G(G)\r\
    \n      , N(G.N)\r\n      , sz(G.N)\r\n      , LID(G.N)\r\n      , RID(G.N)\r\n\
    \      , head(G.N, root)\r\n      , V(G.N)\r\n      , parent(G.N, -1)\r\n    \
    \  , depth(G.N)\r\n      , e_to_v(G.N) {\r\n    int t = 0;\r\n    dfs_sz(root,\
    \ -1);\r\n    dfs_hld(root, -1, t);\r\n  }\r\n\r\n  void dfs_sz(int idx, int p)\
    \ {\r\n    parent[idx] = p;\r\n    depth[idx] = (p == -1 ? 0 : depth[p] + 1);\r\
    \n    sz[idx] = 1;\r\n    if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0],\
    \ G[idx].back());\r\n    for (auto &e : G[idx]) {\r\n      if (e.to == p) continue;\r\
    \n      e_to_v[e.id] = e.to;\r\n      dfs_sz(e.to, idx);\r\n      sz[idx] += sz[e.to];\r\
    \n      if (sz[G[idx][0].to] < sz[e.to]) swap(G[idx][0], e);\r\n    }\r\n  }\r\
    \n\r\n  void dfs_hld(int idx, int par, int &times) {\r\n    LID[idx] = times++;\r\
    \n    V[LID[idx]] = idx;\r\n    for (auto &e : G[idx]) {\r\n      if (e.to ==\
    \ par) continue;\r\n      head[e.to] = (G[idx][0].to == e.to ? head[idx] : e.to);\r\
    \n      dfs_hld(e.to, idx, times);\r\n    }\r\n    RID[idx] = times;\r\n  }\r\n\
    \r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    while (1) {\r\n  \
    \    int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\
    \n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if\
    \ (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n\
    \    }\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int move(int\
    \ a, int b) {\r\n    assert(a != b);\r\n    return (in_subtree(b, a) ? LA(b, depth[b]\
    \ - depth[a] - 1) : parent[a]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3\u3002O(N) \u6642\
    \u9593\u69CB\u7BC9\u3002\");\r\n    print(\"LCA, LA \u306A\u3069\u306F O(logN)\
    \ \u6642\u9593\u3002\");\r\n    print(\"\u6728\u306E\u554F\u984C\u3067\u306F\u771F\
    \u3063\u5148\u306B\u3053\u308C\u3092\u4F5C\u308B\u3002\");\r\n    print(\"\u2192\
    \ \u6728DP\u3084\u6728\u30AF\u30A8\u30EA\u306B\u6D3E\u751F\u3002\");\r\n  }\r\n\
    };\r\n#line 2 \"ds/algebra.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid {\r\
    \n  using F = function<E(E, E)>;\r\n  F f;\r\n  E unit;\r\n  bool commute;\r\n\
    };\r\n\r\ntemplate <typename E, typename OP, bool commute, bool OP_commute>\r\n\
    struct Monoid_OP {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E,\
    \ OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n\
    \  E unit;\r\n  OP OP_unit;\r\n};\r\n\r\ntemplate <typename E>\r\nstruct Group\
    \ {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\
    \n  E E_unit;\r\n  G inv;\r\n  bool commute;\r\n};\r\n\r\ntemplate <typename E>\r\
    \nMonoid<E> Monoid_reverse(Monoid<E> Mono) {\r\n  auto rev_f = [=](E x, E y) ->\
    \ E { return Mono.f(x, y); };\r\n  return Monoid<E>({rev_f, Mono.unit, Mono.commute});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_add() {\r\n  auto f = [](E\
    \ x, E y) -> E { return x + y; };\r\n  return Monoid<E>({f, 0, true});\r\n}\r\n\
    \r\ntemplate <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E\
    \ x, E y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto\
    \ f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF,\
    \ true});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E, E>> Monoid_affine()\
    \ {\r\n  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E, E> {\r\n    return\
    \ {x.fi * y.fi, x.se * y.fi + y.se};\r\n  };\r\n  return Monoid<pair<E, E>>({f,\
    \ mp(E(1), E(0)), false});\r\n}\r\n#line 3 \"ds/segtree.hpp\"\n\ntemplate <typename\
    \ E>\nstruct SegTree {\n  using F = function<E(E, E)>;\n  int N_;\n  int N;\n\
    \  F seg_f;\n  E unit;\n  vector<E> dat;\n\n  SegTree(Monoid<E> Mono) : seg_f(Mono.f),\
    \ unit(Mono.unit) {}\n\n  void init(int n_) {\n    N_ = n_;\n    N = 1;\n    while\
    \ (N < n_) N <<= 1;\n    dat.assign(N << 1, unit);\n  }\n\n  void build(const\
    \ vector<E> &v) {\n    assert(v.size() == N_);\n    FOR(i, v.size()) { dat[N +\
    \ i] = v[i]; }\n    FOR3_R(i, 1, N) { dat[i] = seg_f(dat[i << 1 | 0], dat[i <<\
    \ 1 | 1]); }\n  }\n\n  void set(int i, E x) {\n    assert(i < N_);\n    dat[i\
    \ += N] = x;\n    while (i >>= 1) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1\
    \ | 1]); }\n  }\n\n  E prod(int L, int R) {\n    assert(L <= R);\n    assert(R\
    \ <= N_);\n    E vl = unit, vr = unit;\n    L += N;\n    R += N;\n    while (L\
    \ < R) {\n      if (L & 1) vl = seg_f(vl, dat[L++]);\n      if (R & 1) vr = seg_f(dat[--R],\
    \ vr);\n      L >>= 1;\n      R >>= 1;\n    }\n    return seg_f(vl, vr);\n  }\n\
    \n  template <class F>\n  int max_right(F &check, int L) {\n    assert(0 <= L\
    \ && L <= N_ && check(unit));\n    if (L == N_) return N_;\n    L += N;\n    E\
    \ sm = unit;\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(seg_f(sm,\
    \ dat[L]))) {\n        while (L < N) {\n          L = 2 * L;\n          if (check(seg_f(sm,\
    \ dat[L]))) {\n            sm = seg_f(sm, dat[L]);\n            L++;\n       \
    \   }\n        }\n        return L - N;\n      }\n      sm = seg_f(sm, dat[L]);\n\
    \      L++;\n    } while ((L & -L) != L);\n    return N_;\n  }\n\n  template <class\
    \ F>\n  int min_left(F &check, int R) {\n    assert(0 <= R && R <= N_ && check(unit));\n\
    \    if (R == 0) return 0;\n    R += N;\n    E sm = unit;\n    do {\n      --R;\n\
    \      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(seg_f(dat[R], sm)))\
    \ {\n        while (R < N) {\n          R = 2 * R + 1;\n          if (check(seg_f(dat[R],\
    \ sm))) {\n            sm = seg_f(dat[R], sm);\n            R--;\n          }\n\
    \        }\n        return R + 1 - N;\n      }\n      sm = seg_f(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(dat);\
    \ }\n};\n#line 3 \"graph/treemonoid.hpp\"\n\r\ntemplate <typename Graph, typename\
    \ E, bool edge = false>\r\nstruct TreeMonoid {\r\n  using F = function<E(E, E)>;\r\
    \n  HLD<Graph> &hld;\r\n  int N;\r\n  F f;\r\n  E unit;\r\n  bool commute;\r\n\
    \  SegTree<E> seg, seg_r;\r\n\r\n  TreeMonoid(HLD<Graph> &hld, Monoid<E> Mono)\r\
    \n      : hld(hld)\r\n      , N(hld.N)\r\n      , f(Mono.f)\r\n      , unit(Mono.unit)\r\
    \n      , commute(Mono.commute)\r\n      , seg(Mono)\r\n      , seg_r(Monoid_reverse<E>(Mono))\
    \ {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\n  };\r\n\r\n  void\
    \ init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n    vc<E> seg_raw(N,\
    \ unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\
    \n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n\
    \        seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\
    \n    if (!commute) seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x)\
    \ {\r\n    if (edge) i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i,\
    \ x);\r\n    if (!commute) seg_r.set(i, x);\r\n  }\r\n\r\n  E prod_path_nc(int\
    \ u, int v) {\r\n    E vl = unit, vr = unit;\r\n    while (1) {\r\n      if (hld.head[u]\
    \ == hld.head[v]) break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\n        vr\
    \ = f(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);\r\n        v = hld.parent[hld.head[v]];\r\
    \n      } else {\r\n        vl = f(vl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u]\
    \ + 1));\r\n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    E\
    \ vm =\r\n      (hld.LID[u] < hld.LID[v] ? seg.prod(hld.LID[u] + edge, hld.LID[v]\
    \ + 1)\r\n                               : seg_r.prod(hld.LID[v] + edge, hld.LID[u]\
    \ + 1));\r\n    return f(vl, f(vm, vr));\r\n  }\r\n\r\n  E prod_path(int u, int\
    \ v) {\r\n    if (!commute) return prod_path_nc(u, v);\r\n    E val = unit;\r\n\
    \    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      val = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return f(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\n\
    \  E prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n    return\
    \ seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"seg\");\r\n    seg.debug();\r\n    print(\"\
    seg_r\");\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\
    \u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\
    \u9593\u3002\");\r\n    print(\"\u95A2\u9023\");\r\n  }\r\n};\r\n#line 7 \"test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Graph<int> G(N);\r\
    \n  FOR3(v, 1, N) {\r\n    LL(p);\r\n    G.add(p, v);\r\n  }\r\n  HLD<Graph<int>>\
    \ hld(G);\r\n\r\n  TreeMonoid<Graph<int>, ll, false> TM(hld, Monoid_add<ll>());\r\
    \n  TM.init(A);\r\n\r\n  FOR(_, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n  \
    \    LL(v, x);\r\n      A[v] += x;\r\n      TM.set(v, A[v]);\r\n    } else {\r\
    \n      LL(u);\r\n      print(TM.prod_subtree(u));\r\n    }\r\n  }\r\n}\r\n\r\n\
    signed main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n \
    \ cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"graph/base.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n#include \"graph/treemonoid.hpp\"\r\n\r\nvoid solve() {\r\
    \n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Graph<int> G(N);\r\n  FOR3(v, 1, N) {\r\
    \n    LL(p);\r\n    G.add(p, v);\r\n  }\r\n  HLD<Graph<int>> hld(G);\r\n\r\n \
    \ TreeMonoid<Graph<int>, ll, false> TM(hld, Monoid_add<ll>());\r\n  TM.init(A);\r\
    \n\r\n  FOR(_, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(v, x);\r\n\
    \      A[v] += x;\r\n      TM.set(v, A[v]);\r\n    } else {\r\n      LL(u);\r\n\
    \      print(TM.prod_subtree(u));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\
    \n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - graph/base.hpp
  - graph/hld.hpp
  - graph/treemonoid.hpp
  - ds/segtree.hpp
  - ds/algebra.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 21:10:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp.html
title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
---
