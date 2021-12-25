---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
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
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 4 \"test/library_checker/datastructure/range_affine_range_sum.test.cpp\"\
    \n\n#line 2 \"ds/lazysegtree.hpp\"\ntemplate <typename T, typename OP, bool OP_commute\
    \ = false>\nstruct LazySegTree {\n  using F = function<T(T, T)>;\n  using G =\
    \ function<T(T, OP)>;\n  using H = function<OP(OP, OP)>;\n  int sz, n, height;\n\
    \  F f;\n  G g;\n  H h;\n  T ti;\n  OP ei;\n  vector<T> dat;\n  vector<OP> laz;\n\
    \  LazySegTree(F f, G g, H h, T ti, OP ei) : f(f), g(g), h(h), ti(ti), ei(ei)\
    \ {}\n\n  void init(int n_) {\n    sz = n_;\n    n = 1;\n    height = 0;\n   \
    \ while (n < n_) n <<= 1, height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2\
    \ * n, ei);\n  }\n\n  void build(const vector<T> &v) {\n    int n_ = v.size();\n\
    \    init(n_);\n    for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n    for (int\
    \ i = n - 1; i; i--)\n      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n\
    \  }\n\n  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);\
    \ }\n\n  inline void propagate(int k) {\n    if (laz[k] == ei) return;\n    laz[(k\
    \ << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k\
    \ << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k] = ei;\n  }\n\n  inline\
    \ void thrust(int k) {\n    for (int i = height; i; i--) propagate(k >> i);\n\
    \  }\n\n  inline void recalc(int k) {\n    while (k >>= 1) dat[k] = f(reflect((k\
    \ << 1) | 0), reflect((k << 1) | 1));\n  }\n\n  void operate_range(int a, int\
    \ b, OP x) {\n    if (a >= b) return;\n    a += n, b += n - 1;\n    if (!OP_commute)\
    \ {\n      thrust(a);\n      thrust(b);\n    }\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = h(laz[l], x), l++;\n \
    \     if (r & 1) --r, laz[r] = h(laz[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  void set(int a, T x) {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a]\
    \ = ei;\n    recalc(a);\n  }\n\n  T fold(int a, int b) {\n    if (a >= b) return\
    \ ti;\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = ti, vr = ti;\n\
    \    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl\
    \ = f(vl, reflect(l++));\n      if (r & 1) vr = f(reflect(--r), vr);\n    }\n\
    \    return f(vl, vr);\n  }\n\n  template <typename C>\n  int find(int st, C &check,\
    \ T &acc, int k, int l, int r) {\n    if (l + 1 == r) {\n      acc = f(acc, reflect(k));\n\
    \      return check(acc) ? k - n : -1;\n    }\n    propagate(k);\n    int m =\
    \ (l + r) >> 1;\n    if (m <= st) return find(st, check, acc, (k << 1) | 1, m,\
    \ r);\n    if (st <= l and !check(f(acc, dat[k]))) {\n      acc = f(acc, dat[k]);\n\
    \      return -1;\n    }\n    int vl = find(st, check, acc, (k << 1) | 0, l, m);\n\
    \    if (~vl) return vl;\n    return find(st, check, acc, (k << 1) | 1, m, r);\n\
    \  }\n\n  template <typename C>\n  int find(int st, C &check) {\n    T acc = ti;\n\
    \    return find(st, check, acc, 1, 0, n);\n  }\n\n  void debug() {\n    vc<T>\
    \ A(sz);\n    FOR(i, sz) A[i] = fold(i, i + 1);\n    print(A);\n  }\n};\n#line\
    \ 1 \"mod/modint.hpp\"\ntemplate< int mod >\nstruct modint {\n  int x;\n\n  modint()\
    \ : x(0) {}\n\n  modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) %\
    \ mod) {}\n\n  modint &operator+=(const modint &p) {\n    if((x += p.x) >= mod)\
    \ x -= mod;\n    return *this;\n  }\n\n  modint &operator-=(const modint &p) {\n\
    \    if((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  modint\
    \ &operator*=(const modint &p) {\n    x = (int) (1LL * x * p.x % mod);\n    return\
    \ *this;\n  }\n\n  modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n\
    \    return *this;\n  }\n\n  modint operator-() const { return modint(-x); }\n\
    \n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n\n\
    \  modint operator*(const modint &p) const { return modint(*this) *= p; }\n\n\
    \  modint operator/(const modint &p) const { return modint(*this) /= p; }\n\n\
    \  bool operator==(const modint &p) const { return x == p.x; }\n\n  bool operator!=(const\
    \ modint &p) const { return x != p.x; }\n\n  modint inverse() const {\n    int\
    \ a = x, b = mod, u = 1, v = 0, t;\n    while(b > 0) {\n      t = a / b;\n   \
    \   swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return modint(u);\n\
    \  }\n\n  modint pow(int64_t n) const {\n    modint ret(1), mul(x);\n    while(n\
    \ > 0) {\n      if(n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n   \
    \ }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const modint\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ modint &a) {\n    int64_t t;\n    is >> t;\n    a = modint< mod >(t);\n    return\
    \ (is);\n  }\n\n  static int get_mod() { return mod; }\n};\n\ntemplate< typename\
    \ T >\nstruct ModCalc {\n  vector<T> _fact = {1, 1};\n  vector<T> _fact_inv =\
    \ {1, 1};\n  vector<T> _inv = {0, 1};\n  \n  T pow(T a, int n){\n    T x(1);\n\
    \    while(n) {\n      if(n & 1) x *= a;\n      a *= a;\n      n >>= 1;\n    }\n\
    \    return x;\n  }\n  void expand(int n){\n    while(_fact.size() <= n){\n  \
    \    auto i = _fact.size();\n      _fact.eb(_fact[i-1] * T(i));\n      auto q\
    \ = T::get_mod() / i, r = T::get_mod() % i;\n      _inv.eb(_inv[r] * T(T::get_mod()-q));\n\
    \      _fact_inv.eb(_fact_inv[i-1] * _inv[i]);\n    }\n  }\n\n  T fact(int n){\n\
    \    if(n >= _fact.size()) expand(n);\n    return _fact[n];\n  }\n\n  T fact_inv(int\
    \ n){\n    if(n >= _fact.size()) expand(n);\n    return _fact_inv[n];\n  }\n \
    \ \n  T inv(int n){\n    if(n >= _fact.size()) expand(n);\n    return _inv[n];\n\
    \  }\n  \n  T C(ll n, ll k, bool large=false){\n    assert(n >= 0);\n    if (k\
    \ < 0 || n < k) return 0;\n    if (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);\n\
    \    k = min(k, n-k);\n    T x(1);\n    FOR(i, k){\n      x *= n - i;\n      x\
    \ *= inv(i + 1);\n    }\n    return x;\n  }\n};\n\nusing modint107 = modint<1'000'000'007>;\n\
    using modint998 = modint<998'244'353>;\n#line 7 \"test/library_checker/datastructure/range_affine_range_sum.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n\n  using E = pair<mint,\
    \ mint>;  // cnt, sum\n  using OP = pair<mint, mint>; // (a,b) of ax + b\n  const\
    \ bool OP_commute = false;\n  LazySegTree<E, OP, OP_commute> seg(\n    [&](E x,\
    \ E y) -> E {\n      return E({x.fi + y.fi, x.se + y.se});\n    },\n    [&](E\
    \ x, OP y) -> E {\n      return E({x.fi, x.se * y.fi + x.fi * y.se});\n    },\n\
    \    [&](OP x, OP y) -> OP {\n      return OP({x.fi * y.fi, x.se * y.fi + y.se});\n\
    \    },\n    E({mint(0), mint(0)}), OP({mint(1), mint(0)}));\n  seg.init(N);\n\
    \  vc<E> A(N);\n  FOR(i, N) {\n    LL(x);\n    A[i] = {1, x};\n  }\n  seg.build(A);\n\
    \n  FOR(_, Q) {\n    LL(t, L, R);\n    if (t == 0) {\n      LL(a, b);\n      seg.operate_range(L,\
    \ R, OP({mint(a), mint(b)}));\n    }\n\n    if (t == 1) {\n      auto [cnt, sum]\
    \ = seg.fold(L, R);\n      print(sum);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"my_template.hpp\"\n\n#include \"ds/lazysegtree.hpp\"\n#include\
    \ \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n\
    \n  using E = pair<mint, mint>;  // cnt, sum\n  using OP = pair<mint, mint>; //\
    \ (a,b) of ax + b\n  const bool OP_commute = false;\n  LazySegTree<E, OP, OP_commute>\
    \ seg(\n    [&](E x, E y) -> E {\n      return E({x.fi + y.fi, x.se + y.se});\n\
    \    },\n    [&](E x, OP y) -> E {\n      return E({x.fi, x.se * y.fi + x.fi *\
    \ y.se});\n    },\n    [&](OP x, OP y) -> OP {\n      return OP({x.fi * y.fi,\
    \ x.se * y.fi + y.se});\n    },\n    E({mint(0), mint(0)}), OP({mint(1), mint(0)}));\n\
    \  seg.init(N);\n  vc<E> A(N);\n  FOR(i, N) {\n    LL(x);\n    A[i] = {1, x};\n\
    \  }\n  seg.build(A);\n\n  FOR(_, Q) {\n    LL(t, L, R);\n    if (t == 0) {\n\
    \      LL(a, b);\n      seg.operate_range(L, R, OP({mint(a), mint(b)}));\n   \
    \ }\n\n    if (t == 1) {\n      auto [cnt, sum] = seg.fold(L, R);\n      print(sum);\n\
    \    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/lazysegtree.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 03:01:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/range_affine_range_sum.test.cpp
- /verify/test/library_checker/datastructure/range_affine_range_sum.test.cpp.html
title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
---
