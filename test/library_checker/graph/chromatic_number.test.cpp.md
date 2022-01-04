---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/library_checker/graph/chromatic_number.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\r\n#line\
    \ 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing ll8 = __int128;\nusing pi = pair<ll, ll>;\nusing\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/graph/chromatic_number.test.cpp\"\
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
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 1 \"other/random.hpp\"\n\
    struct RandomNumberGenerator {\n  mt19937 mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 2 \"nt/primetest.hpp\"\nstruct\
    \ m64 {\r\n    using i64 = int64_t;\r\n    using u64 = uint64_t;\r\n    using\
    \ u128 = __uint128_t;\r\n\r\n    inline static u64 m, r, n2; // r * m = -1 (mod\
    \ 1<<64), n2 = 1<<128 (mod m)\r\n    static void set_mod(u64 m) {\r\n        assert(m\
    \ < (1ull << 62));\r\n        assert((m & 1) == 1);\r\n        m64::m = m;\r\n\
    \        n2 = -u128(m) % m;\r\n        r = m;\r\n        FOR (_, 5) r *= 2 - m*r;\r\
    \n        r = -r;\r\n        assert(r * m == -1ull);\r\n    }\r\n    static u64\
    \ reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n    u64 x;\r\
    \n    m64() : x(0) {}\r\n    m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n    u64\
    \ val() const { u64 y = reduce(x); return y >= m ? y-m : y; }\r\n    m64 &operator+=(m64\
    \ y) {\r\n        x += y.x - (m << 1);\r\n        x = (i64(x) < 0 ? x + (m <<\
    \ 1) : x);\r\n        return *this;\r\n    }\r\n    m64 &operator-=(m64 y) {\r\
    \n        x -= y.x;\r\n        x = (i64(x) < 0 ? x + (m << 1) : x);\r\n      \
    \  return *this;\r\n    }\r\n    m64 &operator*=(m64 y) { x = reduce(u128(x) *\
    \ y.x); return *this; }\r\n    m64 operator+(m64 y) const { return m64(*this)\
    \ += y; }\r\n    m64 operator-(m64 y) const { return m64(*this) -= y; }\r\n  \
    \  m64 operator*(m64 y) const { return m64(*this) *= y; }\r\n    bool operator==(m64\
    \ y) const { return (x >= m ? x-m : x) == (y.x >= m ? y.x-m : y.x); }\r\n    bool\
    \ operator!=(m64 y) const { return not operator==(y); }\r\n    m64 pow(u64 n)\
    \ const {\r\n        m64 y = 1, z = *this;\r\n        for ( ; n; n >>= 1, z *=\
    \ z) if (n & 1) y *= z;\r\n        return y;\r\n    }\r\n};\r\n\r\nbool primetest(const\
    \ uint64_t x) {\r\n    using u64 = uint64_t;\r\n    if (x == 2 or x == 3 or x\
    \ == 5 or x == 7) return true;\r\n    if (x % 2 == 0 or x % 3 == 0 or x % 5 ==\
    \ 0 or x % 7 == 0) return false;\r\n    if (x < 121) return x > 1;\r\n    const\
    \ u64 d = (x-1) >> __builtin_ctzll(x-1);\r\n    m64::set_mod(x);\r\n    const\
    \ m64 one(1), minus_one(x-1);\r\n    auto ok = [&](u64 a) {\r\n        auto y\
    \ = m64(a).pow(d);\r\n        u64 t = d;\r\n        while (y != one and y != minus_one\
    \ and t != x-1) y *= y, t <<= 1;\r\n        if (y != minus_one and t % 2 == 0)\
    \ return false;\r\n        return true;\r\n    };\r\n    if (x < (1ull << 32))\
    \ {\r\n        for (u64 a : { 2, 7, 61 }) if (not ok(a)) return false;\r\n   \
    \ } else {\r\n        for (u64 a : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022\
    \ }) {\r\n            if (x <= a) return true;\r\n            if (not ok(a)) return\
    \ false;\r\n        }\r\n    }\r\n    return true;\r\n}\n#line 3 \"graph/chromatic.hpp\"\
    \n\r\ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph&\
    \ G) {\r\n  assert(G.is_prepared());\r\n  // O(N2^N)\r\n\r\n  int N = G.N;\r\n\
    \  vc<int> nbd(N);\r\n  FOR(v, N) for (auto&& e : G[v]) nbd[v] |= 1 << e.to;\r\
    \n\r\n  // s \u306E subset \u3067\u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\
    \u5408\u306E\u6570\u3048\u4E0A\u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\
    \n  FOR(v, N) FOR(s, 1 << v) { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\
    \n\r\n  vi pow(1 << N);\r\n  auto solve_p = [&](int p) -> int {\r\n    FOR(s,\
    \ 1 << N) pow[s] = ((N - popcnt(s)) & 1 ? 1 : -1);\r\n    FOR3(k, 1, N) {\r\n\
    \      ll sum = 0;\r\n      FOR(s, 1 << N) {\r\n        pow[s] = pow[s] * dp[s];\r\
    \n        if (p) pow[s] %= p;\r\n        sum += pow[s];\r\n      }\r\n      if\
    \ (p) sum %= p;\r\n      if (sum != 0) { return k; }\r\n    }\r\n    return N;\r\
    \n  };\r\n\r\n  int ANS = 0;\r\n  chmax(ANS, solve_p(0));\r\n\r\n  FOR_(TRIAL)\
    \ {\r\n    RandomNumberGenerator RNG;\r\n    int p;\r\n    while (1) {\r\n   \
    \   p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p)) break;\r\n    }\r\
    \n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\n#line 6 \"test/library_checker/graph/chromatic_number.test.cpp\"\
    \n\r\n\r\nvoid solve() {\r\n  LL(N, M);\r\n  Graph<int> G(N);\r\n  FOR_(M) {\r\
    \n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n  print(chromatic_number(G));\r\
    \n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\r\n\
    #include \"my_template.hpp\"\r\n\r\n#include \"graph/base.hpp\"\r\n#include \"\
    graph/chromatic.hpp\"\r\n\r\n\r\nvoid solve() {\r\n  LL(N, M);\r\n  Graph<int>\
    \ G(N);\r\n  FOR_(M) {\r\n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\
    \n  print(chromatic_number(G));\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - graph/base.hpp
  - graph/chromatic.hpp
  - other/random.hpp
  - nt/primetest.hpp
  isVerificationFile: true
  path: test/library_checker/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 04:59:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/chromatic_number.test.cpp
- /verify/test/library_checker/graph/chromatic_number.test.cpp.html
title: test/library_checker/graph/chromatic_number.test.cpp
---
