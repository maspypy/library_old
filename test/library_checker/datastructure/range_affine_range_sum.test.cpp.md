---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group_affine.hpp
    title: algebra/group_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/group_cntsum.hpp
    title: algebra/group_cntsum.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_cntsum_affine.hpp
    title: algebra/lazy_cntsum_affine.hpp
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  - icon: ':question:'
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/range_affine_range_sum.test.cpp\"\
    \n\n#line 1 \"algebra/group_cntsum.hpp\"\ntemplate <typename E = long long>\r\n\
    struct Group_CntSum {\r\n  using value_type = pair<E,E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return {x.fi + y.fi, x.se\
    \ + y.se}; }\r\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se};\
    \ }\r\n  static constexpr X unit = {0, 0};\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 1 \"algebra/group_affine.hpp\"\ntemplate <typename K>\n\
    struct Group_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n  static\
    \ constexpr F op(const F &x, const F &y) noexcept {\n    return F({x.fi * y.fi,\
    \ x.se * y.fi + y.se});\n  }\n  static constexpr F inverse(const F &x) {\n   \
    \ auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static\
    \ constexpr K eval(const F &f, K x) noexcept { return f.fi * x + f.se; }\n  static\
    \ constexpr F unit = {K(1), K(0)};\n  static constexpr bool commute = false;\n\
    };\n#line 3 \"algebra/lazy_cntsum_affine.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Lazy_CntSum_Affine {\r\n  using X_structure = Group_CntSum<E>;\r\n  using\
    \ A_structure = Group_Affine<E>;\r\n  using X = typename X_structure::value_type;\r\
    \n  using A = typename A_structure::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) {\r\n    return {x.fi, x.fi * a.se + x.se * a.fi};\r\n  }\r\
    \n};\n#line 2 \"ds/lazysegtree.hpp\"\n\ntemplate <typename Lazy>\nstruct LazySegTree\
    \ {\n  using Monoid_X = typename Lazy::X_structure;\n  using Monoid_A = typename\
    \ Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n  using A =\
    \ typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A> laz;\n\
    \n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
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
    \n    return Monoid_X::op(xl, xr);\n  }\n\n  X all_prod() { return dat[1]; }\n\
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
    lazysegtree getall:\", get_all()); }\n};\n#line 1 \"mod/modint.hpp\"\ntemplate\
    \ <int mod>\nstruct modint {\n  int x;\n\n  constexpr modint(const ll x = 0) noexcept\n\
    \      : x(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\n\n  bool operator<(const\
    \ modint &other) const {\n    return x < other.x;\n  } // To use std::map\n\n\
    \  modint &operator+=(const modint &p) {\n    if ((x += p.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n\n  modint &operator-=(const modint &p) {\n    if ((x\
    \ += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  modint &operator*=(const\
    \ modint &p) {\n    x = (int)(1LL * x * p.x % mod);\n    return *this;\n  }\n\n\
    \  modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n\n  modint operator-() const { return modint(-x); }\n\n  modint\
    \ operator+(const modint &p) const { return modint(*this) += p; }\n\n  modint\
    \ operator-(const modint &p) const { return modint(*this) -= p; }\n\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n\n  modint\
    \ operator/(const modint &p) const { return modint(*this) /= p; }\n\n  bool operator==(const\
    \ modint &p) const { return x == p.x; }\n\n  bool operator!=(const modint &p)\
    \ const { return x != p.x; }\n\n  modint inverse() const {\n    int a = x, b =\
    \ mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -=\
    \ t * b, b);\n      swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n\n\
    \  modint pow(int64_t n) const {\n    modint ret(1), mul(x);\n    while (n > 0)\
    \ {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const modint\
    \ &p) { return os << p.x; }\n\n  friend istream &operator>>(istream &is, modint\
    \ &a) {\n    int64_t t;\n    is >> t;\n    a = modint<mod>(t);\n    return (is);\n\
    \  }\n\n  static int get_mod() { return mod; }\n};\n\ntemplate <typename T>\n\
    struct ModCalc {\n  vector<T> _fact = {1, 1};\n  vector<T> _fact_inv = {1, 1};\n\
    \  vector<T> _inv = {0, 1};\n\n  T pow(T a, int n) {\n    T x(1);\n    while (n)\
    \ {\n      if (n & 1) x *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return\
    \ x;\n  }\n  void expand(int n) {\n    while (_fact.size() <= n) {\n      auto\
    \ i = _fact.size();\n      _fact.eb(_fact[i - 1] * T(i));\n      auto q = T::get_mod()\
    \ / i, r = T::get_mod() % i;\n      _inv.eb(_inv[r] * T(T::get_mod() - q));\n\
    \      _fact_inv.eb(_fact_inv[i - 1] * _inv[i]);\n    }\n  }\n\n  T fact(int n)\
    \ {\n    if (n >= _fact.size()) expand(n);\n    return _fact[n];\n  }\n\n  T fact_inv(int\
    \ n) {\n    if (n >= _fact.size()) expand(n);\n    return _fact_inv[n];\n  }\n\
    \n  T inv(int n) {\n    if (n >= _fact.size()) expand(n);\n    return _inv[n];\n\
    \  }\n\n  T C(ll n, ll k, bool large = false) {\n    assert(n >= 0);\n    if (k\
    \ < 0 || n < k) return 0;\n    if (!large) return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\n    k = min(k, n - k);\n    T x(1);\n    FOR(i, k) {\n      x *= n -\
    \ i;\n      x *= inv(i + 1);\n    }\n    return x;\n  }\n};\n\nusing modint107\
    \ = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n#line 7 \"\
    test/library_checker/datastructure/range_affine_range_sum.test.cpp\"\n\nusing\
    \ mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  using S = Lazy_CntSum_Affine<mint>;\n\
    \  using E = pair<mint, mint>;\n  vc<E> seg_raw(N);\n  FOR(i, N) {\n    LL(x);\n\
    \    seg_raw[i] = E({mint(1), mint(x)});\n  }\n  LazySegTree<S> seg(seg_raw);\n\
    \n  FOR(_, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(l, r, a, b);\n      seg.apply(l,\
    \ r, E({a, b}));\n    }\n    elif (t == 1) {\n      LL(l, r);\n      auto cs =\
    \ seg.prod(l, r);\n      print(cs.se);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"my_template.hpp\"\n\n#include \"algebra/lazy_cntsum_affine.hpp\"\n\
    #include \"ds/lazysegtree.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\
    \nvoid solve() {\n  LL(N, Q);\n  using S = Lazy_CntSum_Affine<mint>;\n  using\
    \ E = pair<mint, mint>;\n  vc<E> seg_raw(N);\n  FOR(i, N) {\n    LL(x);\n    seg_raw[i]\
    \ = E({mint(1), mint(x)});\n  }\n  LazySegTree<S> seg(seg_raw);\n\n  FOR(_, Q)\
    \ {\n    LL(t);\n    if (t == 0) {\n      LL(l, r, a, b);\n      seg.apply(l,\
    \ r, E({a, b}));\n    }\n    elif (t == 1) {\n      LL(l, r);\n      auto cs =\
    \ seg.prod(l, r);\n      print(cs.se);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - algebra/lazy_cntsum_affine.hpp
  - algebra/group_cntsum.hpp
  - algebra/group_affine.hpp
  - ds/lazysegtree.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/range_affine_range_sum.test.cpp
- /verify/test/library_checker/datastructure/range_affine_range_sum.test.cpp.html
title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
---
