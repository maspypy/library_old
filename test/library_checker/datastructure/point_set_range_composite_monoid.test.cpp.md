---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp\"\
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
    segtree\", dat); }\n};\n#line 1 \"mod/modint.hpp\"\ntemplate< int mod >\nstruct\
    \ modint {\n  int x;\n\n  constexpr modint(const ll x = 0) noexcept : x(x >= 0\
    \ ? x % mod : (mod - (-x) % mod) % mod) {}\n\n  modint &operator+=(const modint\
    \ &p) {\n    if((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  modint\
    \ &operator-=(const modint &p) {\n    if((x += mod - p.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n\n  modint &operator*=(const modint &p) {\n    x = (int)\
    \ (1LL * x * p.x % mod);\n    return *this;\n  }\n\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n\n  modint\
    \ operator-() const { return modint(-x); }\n\n  modint operator+(const modint\
    \ &p) const { return modint(*this) += p; }\n\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n\n  modint operator*(const modint\
    \ &p) const { return modint(*this) *= p; }\n\n  modint operator/(const modint\
    \ &p) const { return modint(*this) /= p; }\n\n  bool operator==(const modint &p)\
    \ const { return x == p.x; }\n\n  bool operator!=(const modint &p) const { return\
    \ x != p.x; }\n\n  modint inverse() const {\n    int a = x, b = mod, u = 1, v\
    \ = 0, t;\n    while(b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n\
    \      swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n\n  modint pow(int64_t\
    \ n) const {\n    modint ret(1), mul(x);\n    while(n > 0) {\n      if(n & 1)\
    \ ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\
    \n  friend ostream &operator<<(ostream &os, const modint &p) {\n    return os\
    \ << p.x;\n  }\n\n  friend istream &operator>>(istream &is, modint &a) {\n   \
    \ int64_t t;\n    is >> t;\n    a = modint< mod >(t);\n    return (is);\n  }\n\
    \n  static int get_mod() { return mod; }\n};\n\ntemplate< typename T >\nstruct\
    \ ModCalc {\n  vector<T> _fact = {1, 1};\n  vector<T> _fact_inv = {1, 1};\n  vector<T>\
    \ _inv = {0, 1};\n  \n  T pow(T a, int n){\n    T x(1);\n    while(n) {\n    \
    \  if(n & 1) x *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return x;\n  }\n\
    \  void expand(int n){\n    while(_fact.size() <= n){\n      auto i = _fact.size();\n\
    \      _fact.eb(_fact[i-1] * T(i));\n      auto q = T::get_mod() / i, r = T::get_mod()\
    \ % i;\n      _inv.eb(_inv[r] * T(T::get_mod()-q));\n      _fact_inv.eb(_fact_inv[i-1]\
    \ * _inv[i]);\n    }\n  }\n\n  T fact(int n){\n    if(n >= _fact.size()) expand(n);\n\
    \    return _fact[n];\n  }\n\n  T fact_inv(int n){\n    if(n >= _fact.size())\
    \ expand(n);\n    return _fact_inv[n];\n  }\n  \n  T inv(int n){\n    if(n >=\
    \ _fact.size()) expand(n);\n    return _inv[n];\n  }\n  \n  T C(ll n, ll k, bool\
    \ large=false){\n    assert(n >= 0);\n    if (k < 0 || n < k) return 0;\n    if\
    \ (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);\n    k = min(k, n-k);\n\
    \    T x(1);\n    FOR(i, k){\n      x *= n - i;\n      x *= inv(i + 1);\n    }\n\
    \    return x;\n  }\n};\n\nusing modint107 = modint<1'000'000'007>;\nusing modint998\
    \ = modint<998'244'353>;\n#line 6 \"test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  using E = pair<mint,\
    \ mint>;\n  SegTree<E> seg(Monoid_affine<mint>());\n  seg.init(N);\n  vc<E> seg_raw(N);\n\
    \  FOR(i, N) {\n    LL(a, b);\n    seg_raw[i] = {a, b};\n  }\n  seg.build(seg_raw);\n\
    \n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(i, a, b);\n      seg.set(i,\
    \ E({a, b}));\n    } else {\n      LL(L, R, x);\n      auto [a, b] = seg.prod(L,\
    \ R);\n      print(a * mint(x) + b);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"my_template.hpp\"\n\n#include \"ds/segtree.hpp\"\n#include \"mod/modint.hpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  using E = pair<mint,\
    \ mint>;\n  SegTree<E> seg(Monoid_affine<mint>());\n  seg.init(N);\n  vc<E> seg_raw(N);\n\
    \  FOR(i, N) {\n    LL(a, b);\n    seg_raw[i] = {a, b};\n  }\n  seg.build(seg_raw);\n\
    \n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(i, a, b);\n      seg.set(i,\
    \ E({a, b}));\n    } else {\n      LL(L, R, x);\n      auto [a, b] = seg.prod(L,\
    \ R);\n      print(a * mint(x) + b);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/segtree.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 08:10:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
- /verify/test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp.html
title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
---