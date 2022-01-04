---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/centroid.hpp
    title: graph/centroid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_all_distances.hpp
    title: graph/tree_all_distances.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/convolution_ll.hpp
    title: polynomial/convolution_ll.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/library_checker/graph/frequency_table_of_tree_distance.test.cpp\"\
    \n#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ll8 = __int128;\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
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
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR_(n) for (ll _ = 0; (_) < (ll)(n);\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 4 \"test/library_checker/graph/frequency_table_of_tree_distance.test.cpp\"\
    \n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() {}\n  Graph(int N) : N(N), M(0),\
    \ prepared(0) {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n  \
    \  assert(!prepared);\n    assert(0 <= frm && frm < N && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared = true;\n\
    \    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
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
    \  }\r\n};\r\n#line 2 \"polynomial/convolution_ll.hpp\"\nstruct CFFT {\r\n  struct\
    \ C {\r\n    double x, y;\r\n    C(double _x = 0, double _y = 0) : x(_x), y(_y)\
    \ {}\r\n    C operator~() const { return C(x, -y); }\r\n    C operator*(const\
    \ C& c) const {\r\n      return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n \
    \   }\r\n    C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n\
    \    C operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  };\r\n\
    \r\n  vector<vector<C>> w = vector<vector<C>>(1, vector<C>(1, 1));\r\n\r\n  void\
    \ init(int lg) {\r\n    for (int d = 1, m = 1; d <= lg; d++, m <<= 1)\r\n    \
    \  if (d >= (int)w.size()) {\r\n        w.emplace_back(m);\r\n        const double\
    \ th = M_PI / m;\r\n        for (int i = 0; i < m; i++)\r\n          w[d][i] =\
    \ (i & 1 ? C(cos(th * i), sin(th * i)) : w[d - 1][i >> 1]);\r\n      }\r\n  }\r\
    \n  void fft(vector<C>& f, bool inv) {\r\n    const int n = f.size();\r\n    const\
    \ int lg = __lg(n);\r\n    if (lg >= (int)w.size()) init(lg);\r\n    if (inv)\
    \ {\r\n      for (int k = 1; k <= lg; k++) {\r\n        const int d = 1 << (k\
    \ - 1);\r\n        for (int s = 0; s < n; s += 2 * d) {\r\n          for (int\
    \ i = s; i < s + d; i++) {\r\n            C x = f[i], y = ~w[k][i - s] * f[d +\
    \ i];\r\n            f[i] = x + y;\r\n            f[d + i] = x - y;\r\n      \
    \    }\r\n        }\r\n      }\r\n    } else {\r\n      for (int k = lg; k; k--)\
    \ {\r\n        const int d = 1 << (k - 1);\r\n        for (int s = 0; s < n; s\
    \ += 2 * d) {\r\n          for (int i = s; i < s + d; i++) {\r\n            C\
    \ x = f[i], y = f[d + i];\r\n            f[i] = x + y;\r\n            f[d + i]\
    \ = w[k][i - s] * (x - y);\r\n          }\r\n        }\r\n      }\r\n    }\r\n\
    \  }\r\n  vector<ll> conv(const vector<ll>& a, const vector<ll>& b) {\r\n    const\
    \ int as = a.size();\r\n    const int bs = b.size();\r\n    if (!as or !bs) return\
    \ {};\r\n    const int cs = as + bs - 1;\r\n    vector<ll> c(cs);\r\n    if (max(as,\
    \ bs) < 16) {\r\n      for (int i = 0; i < as; i++)\r\n        for (int j = 0;\
    \ j < bs; j++) { c[i + j] += (ll)a[i] * b[j]; }\r\n      return c;\r\n    }\r\n\
    \    const int n = 1 << __lg(2 * cs - 1);\r\n    vector<C> f(n);\r\n    for (int\
    \ i = 0; i < as; i++) f[i].x = a[i];\r\n    for (int i = 0; i < bs; i++) f[i].y\
    \ = b[i];\r\n    fft(f, 0);\r\n    static const C rad(0, -.25);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n      int j = i ? i ^ ((1 << __lg(i)) - 1) : 0;\r\n\
    \      if (i > j) continue;\r\n      C x = f[i] + ~f[j], y = f[i] - ~f[j];\r\n\
    \      f[i] = x * y * rad;\r\n      f[j] = ~f[i];\r\n    }\r\n    fft(f, 1);\r\
    \n    for (int i = 0; i < cs; i++) c[i] = f[i].x / n + .5;\r\n    return c;\r\n\
    \  }\r\n  vector<ll> square(const vector<ll>& a) {\r\n    const int as = a.size();\r\
    \n    if (!as) return {};\r\n    const int cs = as * 2 - 1;\r\n    vector<ll>\
    \ c(cs);\r\n    if (as < 16) {\r\n      for (int i = 0; i < as; i++)\r\n     \
    \   for (int j = 0; j < as; j++) { c[i + j] += (int)a[i] * a[j]; }\r\n      return\
    \ c;\r\n    }\r\n    const int n = 1 << __lg(cs * 2 - 1);\r\n    vector<C> f(n);\r\
    \n    for (int i = 0; i < as; i++) f[i].x = a[i];\r\n    fft(f, 0);\r\n    for\
    \ (int i = 0; i < n; i++) f[i] = f[i] * f[i];\r\n    fft(f, 1);\r\n    for (int\
    \ i = 0; i < cs; i++) c[i] = f[i].x / n + .5;\r\n    return c;\r\n  }\r\n};\r\n\
    \r\nCFFT cfft;\r\n\r\nvector<ll> convolution_ll(vector<ll>& A, vector<ll>& B)\
    \ {\r\n  if (min(len(A), len(B)) <= 60) {\r\n    vector<ll> C(len(A) + len(B)\
    \ - 1);\r\n    FOR(i, len(A)) FOR(j, len(B)) C[i + j] += A[i] * B[j];\r\n    return\
    \ C;\r\n  }\r\n  assert(SUM(A) * SUM(B) < 1e15);\r\n  return cfft.conv(A, B);\r\
    \n}\r\n\r\nvector<ll> conv_square_ll(vector<ll>& A) {\r\n  if (len(A) <= 60) {\r\
    \n    vector<ll> C(2 * len(A) - 1);\r\n    FOR(i, len(A)) FOR(j, len(A)) C[i +\
    \ j] += A[i] * A[j];\r\n    return C;\r\n  }\r\n  assert(SUM(A) * SUM(A) < 1e15);\r\
    \n  return cfft.square(A);\r\n}\r\n#line 3 \"graph/tree_all_distances.hpp\"\n\r\
    \ntemplate<typename Graph>\r\nvi tree_all_distances(Graph& G){\r\n  // frequency\
    \ table of distance of all directed pairs. \r\n  // sum of result array = N^2\r\
    \n  \r\n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\n\r\n  CentroidDecomposition\
    \ CD(G);\r\n\r\n  ll N = G.N;\r\n  vi ANS(N);\r\n  FOR(root, N) {\r\n    auto\
    \ data = CD.collect(root, 0);\r\n    FOR(i, len(data)) {\r\n      int n = 0;\r\
    \n      FOR(j, len(data[i])) chmax(n, data[i][j].se + 1);\r\n      vi A(n);\r\n\
    \      FOR(j, len(data[i])) A[data[i][j].se]++;\r\n      auto B = conv_square_ll(A);\r\
    \n      FOR(j, min(N, len(B))) ANS[j] += (i == 0 ? B[j] : -B[j]);\r\n    }\r\n\
    \  }\r\n  return ANS;\r\n}\n#line 6 \"test/library_checker/graph/frequency_table_of_tree_distance.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\n\
    \    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n\r\n  vi ANS =\
    \ tree_all_distances(G);\r\n  ANS.erase(ANS.begin());\r\n  for (auto&& x : ANS)\
    \ x /= 2;\r\n  print(ANS);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"graph/tree_all_distances.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\
    \n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n\r\n  vi ANS =\
    \ tree_all_distances(G);\r\n  ANS.erase(ANS.begin());\r\n  for (auto&& x : ANS)\
    \ x /= 2;\r\n  print(ANS);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - graph/tree_all_distances.hpp
  - graph/centroid.hpp
  - graph/base.hpp
  - polynomial/convolution_ll.hpp
  isVerificationFile: true
  path: test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 00:19:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
- /verify/test/library_checker/graph/frequency_table_of_tree_distance.test.cpp.html
title: test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
---
