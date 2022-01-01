---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/group_affine.hpp
    title: algebra/group_affine.hpp
  - icon: ':heavy_check_mark:'
    path: ds/swag.hpp
    title: ds/swag.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR(n) for (ll _ = 0; (_) < (ll)(n);\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/queue_operate_all_composite.test.cpp\"\
    \n\r\n#line 1 \"algebra/group_affine.hpp\"\ntemplate <typename K>\nstruct Group_Affine\
    \ {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.fi * y.fi, x.se * y.fi + y.se});\n\
    \  }\n  static constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a\
    \ = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr K eval(const\
    \ F &f, K x) noexcept { return f.fi * x + f.se; }\n  static constexpr F unit =\
    \ {K(1), K(0)};\n  static constexpr bool commute = false;\n};\n#line 1 \"ds/swag.hpp\"\
    \ntemplate <class Monoid>\nstruct SWAG {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\n  SWAG()\
    \ : cum_l({Monoid::unit}), cum_r(Monoid::unit) {}\n\n  void push(X x) {\n    cum_r\
    \ = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    cum_l.pop_back();\n\
    \    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit};\n      cum_r = Monoid::unit;\n\
    \      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n\
    \        dat.pop_back();\n      }\n      dat.pop_back();\n    }\n  }\n\n  X prod()\
    \ { return Monoid::op(cum_l.back(), cum_r); }\n\n  void debug() {\n    print(\"\
    swag\");\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"\
    cum_r\", cum_r);\n  }\n};\n#line 1 \"mod/modint.hpp\"\ntemplate <int mod>\nstruct\
    \ modint {\n  int val;\n\n  constexpr modint(const ll val = 0) noexcept\n    \
    \  : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \n  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val\
    \ -= mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n \
    \   if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n\n  modint inverse() const {\n    int a = val, b =\
    \ mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -=\
    \ t * b, b);\n      swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n\n\
    \  modint pow(int64_t n) const {\n    modint ret(1), mul(val);\n    while (n >\
    \ 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const modint\
    \ &p) { return os << p.val; }\n  static int get_mod() { return mod; }\n};\n\n\
    template <typename T>\nstruct ModCalc {\n  vector<T> _fact = {1, 1};\n  vector<T>\
    \ _fact_inv = {1, 1};\n  vector<T> _inv = {0, 1};\n\n  T pow(T a, int n) {\n \
    \   T x(1);\n    while (n) {\n      if (n & 1) x *= a;\n      a *= a;\n      n\
    \ >>= 1;\n    }\n    return x;\n  }\n  void expand(int n) {\n    while (_fact.size()\
    \ <= n) {\n      auto i = _fact.size();\n      _fact.eb(_fact[i - 1] * T(i));\n\
    \      auto q = T::get_mod() / i, r = T::get_mod() % i;\n      _inv.eb(_inv[r]\
    \ * T(T::get_mod() - q));\n      _fact_inv.eb(_fact_inv[i - 1] * _inv[i]);\n \
    \   }\n  }\n\n  T fact(int n) {\n    if (n >= _fact.size()) expand(n);\n    return\
    \ _fact[n];\n  }\n\n  T fact_inv(int n) {\n    if (n >= _fact.size()) expand(n);\n\
    \    return _fact_inv[n];\n  }\n\n  T inv(int n) {\n    if (n >= _fact.size())\
    \ expand(n);\n    return _inv[n];\n  }\n\n  T C(ll n, ll k, bool large = false)\
    \ {\n    assert(n >= 0);\n    if (k < 0 || n < k) return 0;\n    if (!large) return\
    \ fact(n) * fact_inv(k) * fact_inv(n - k);\n    k = min(k, n - k);\n    T x(1);\n\
    \    FOR(i, k) {\n      x *= n - i;\n      x *= inv(i + 1);\n    }\n    return\
    \ x;\n  }\n};\n\nusing modint107 = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n\
    #line 7 \"test/library_checker/datastructure/queue_operate_all_composite.test.cpp\"\
    \n\r\nusing mint = modint998;\r\n\r\nvoid solve() {\r\n  LL(Q);\r\n  using Mono\
    \ = Group_Affine<mint>;\r\n  using F = Mono::value_type;\r\n\r\n  SWAG<Mono> swag;\r\
    \n\r\n  FOR(_, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(a, b);\r\n\
    \      swag.push(F({a, b}));\r\n    }\r\n    elif (t == 1) { swag.pop(); }\r\n\
    \    elif (t == 2) {\r\n      LL(x);\r\n      F f = swag.prod();\r\n      print(Mono::eval(f,\
    \ x));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"algebra/group_affine.hpp\"\r\
    \n#include \"ds/swag.hpp\"\r\n#include \"mod/modint.hpp\"\r\n\r\nusing mint =\
    \ modint998;\r\n\r\nvoid solve() {\r\n  LL(Q);\r\n  using Mono = Group_Affine<mint>;\r\
    \n  using F = Mono::value_type;\r\n\r\n  SWAG<Mono> swag;\r\n\r\n  FOR(_, Q) {\r\
    \n    LL(t);\r\n    if (t == 0) {\r\n      LL(a, b);\r\n      swag.push(F({a,\
    \ b}));\r\n    }\r\n    elif (t == 1) { swag.pop(); }\r\n    elif (t == 2) {\r\
    \n      LL(x);\r\n      F f = swag.prod();\r\n      print(Mono::eval(f, x));\r\
    \n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - algebra/group_affine.hpp
  - ds/swag.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 02:35:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/queue_operate_all_composite.test.cpp
- /verify/test/library_checker/datastructure/queue_operate_all_composite.test.cpp.html
title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
---
