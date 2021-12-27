---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: ds/swag.hpp
    title: ds/swag.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 3 \"test/library_checker/datastructure/queue_operate_all_composite.test.cpp\"\
    \n\r\n#line 2 \"algebra/monoid.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid\
    \ {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\
    \n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\n};\r\n\
    \r\ntemplate <typename E, typename OP>\r\nstruct Monoid_OP {\r\n  using F = function<E(E,\
    \ E)>;\r\n  using G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\
    \n  F f;\r\n  G g;\r\n  H h;\r\n  E unit;\r\n  OP OP_unit;\r\n  bool commute;\r\
    \n  bool OP_commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_reverse(Monoid<E>\
    \ Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return Mono.f(y, x); };\r\n \
    \ return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute, Mono.has_inverse,\
    \ Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_add()\
    \ {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto g = [](E x) ->\
    \ E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\n}\r\n\r\n\
    template <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E x, E\
    \ y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true, false});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto\
    \ f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF,\
    \ true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E, E>> Monoid_affine(bool\
    \ has_inverse = false) {\r\n  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E,\
    \ E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\n  };\r\n  auto inv\
    \ = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b iff x = (1/a) y - (b/a)\r\
    \n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n    return {a, a * (-b)};\r\n \
    \ };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)), false, has_inverse, inv});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid_OP<pair<E, E>, pair<E, E>> Monoid_cnt_sum_affine()\
    \ {\r\n  using P = pair<E, E>;\r\n  auto f = [](P x, P y) -> P { return P({x.fi\
    \ + y.fi, x.se + y.se}); };\r\n  auto g = [](P x, P y) -> P { return P({x.fi,\
    \ x.fi * y.se + x.se * y.fi}); };\r\n  auto h = [](P x, P y) -> P { return P({x.fi\
    \ * y.fi, x.se * y.fi + y.se}); };\r\n  return Monoid_OP<P, P>({f, g, h, P({0,\
    \ 0}), P({1, 0}), true, false});\r\n}\r\n#line 2 \"ds/swag.hpp\"\n\ntemplate <typename\
    \ E>\nstruct SWAG {\n  using F = function<E(E, E)>;\n  F f;\n  E e;\n  vc<E> dat;\n\
    \  vc<E> cum_l;\n  E cum_r;\n  SWAG(Monoid<E> M) : f(M.f), e(M.unit), cum_l({M.unit}),\
    \ cum_r(M.unit) {}\n\n  void push(E x) {\n    cum_r = f(cum_r, x);\n    dat.eb(x);\n\
    \  }\n\n  void pop() {\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n  \
    \    cum_l = {e};\n      cum_r = e;\n      while (len(dat) > 1) {\n        cum_l.eb(f(dat.back(),\
    \ cum_l.back()));\n        dat.pop_back();\n      }\n      dat.pop_back();\n \
    \   }\n  }\n\n  E prod() { return f(cum_l.back(), cum_r); }\n\n  void debug()\
    \ {\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"cum_r\"\
    , cum_r);\n  }\n};\n#line 1 \"mod/modint.hpp\"\ntemplate< int mod >\nstruct modint\
    \ {\n  int x;\n\n  modint() : x(0) {}\n\n  modint(int64_t y) : x(y >= 0 ? y %\
    \ mod : (mod - (-y) % mod) % mod) {}\n\n  modint &operator+=(const modint &p)\
    \ {\n    if((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  modint &operator-=(const\
    \ modint &p) {\n    if((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n\
    \  }\n\n  modint &operator*=(const modint &p) {\n    x = (int) (1LL * x * p.x\
    \ % mod);\n    return *this;\n  }\n\n  modint &operator/=(const modint &p) {\n\
    \    *this *= p.inverse();\n    return *this;\n  }\n\n  modint operator-() const\
    \ { return modint(-x); }\n\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n\n  modint operator-(const modint &p) const { return\
    \ modint(*this) -= p; }\n\n  modint operator*(const modint &p) const { return\
    \ modint(*this) *= p; }\n\n  modint operator/(const modint &p) const { return\
    \ modint(*this) /= p; }\n\n  bool operator==(const modint &p) const { return x\
    \ == p.x; }\n\n  bool operator!=(const modint &p) const { return x != p.x; }\n\
    \n  modint inverse() const {\n    int a = x, b = mod, u = 1, v = 0, t;\n    while(b\
    \ > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v,\
    \ v);\n    }\n    return modint(u);\n  }\n\n  modint pow(int64_t n) const {\n\
    \    modint ret(1), mul(x);\n    while(n > 0) {\n      if(n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const modint &p) {\n    return os << p.x;\n  }\n\n\
    \  friend istream &operator>>(istream &is, modint &a) {\n    int64_t t;\n    is\
    \ >> t;\n    a = modint< mod >(t);\n    return (is);\n  }\n\n  static int get_mod()\
    \ { return mod; }\n};\n\ntemplate< typename T >\nstruct ModCalc {\n  vector<T>\
    \ _fact = {1, 1};\n  vector<T> _fact_inv = {1, 1};\n  vector<T> _inv = {0, 1};\n\
    \  \n  T pow(T a, int n){\n    T x(1);\n    while(n) {\n      if(n & 1) x *= a;\n\
    \      a *= a;\n      n >>= 1;\n    }\n    return x;\n  }\n  void expand(int n){\n\
    \    while(_fact.size() <= n){\n      auto i = _fact.size();\n      _fact.eb(_fact[i-1]\
    \ * T(i));\n      auto q = T::get_mod() / i, r = T::get_mod() % i;\n      _inv.eb(_inv[r]\
    \ * T(T::get_mod()-q));\n      _fact_inv.eb(_fact_inv[i-1] * _inv[i]);\n    }\n\
    \  }\n\n  T fact(int n){\n    if(n >= _fact.size()) expand(n);\n    return _fact[n];\n\
    \  }\n\n  T fact_inv(int n){\n    if(n >= _fact.size()) expand(n);\n    return\
    \ _fact_inv[n];\n  }\n  \n  T inv(int n){\n    if(n >= _fact.size()) expand(n);\n\
    \    return _inv[n];\n  }\n  \n  T C(ll n, ll k, bool large=false){\n    assert(n\
    \ >= 0);\n    if (k < 0 || n < k) return 0;\n    if (!large) return fact(n) *\
    \ fact_inv(k) * fact_inv(n-k);\n    k = min(k, n-k);\n    T x(1);\n    FOR(i,\
    \ k){\n      x *= n - i;\n      x *= inv(i + 1);\n    }\n    return x;\n  }\n\
    };\n\nusing modint107 = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n\
    #line 6 \"test/library_checker/datastructure/queue_operate_all_composite.test.cpp\"\
    \n\r\nusing mint = modint998;\r\n\r\nvoid solve() {\r\n  LL(Q);\r\n  using E =\
    \ pair<mint, mint>;\r\n  SWAG<E> swag(Monoid_affine<mint>());\r\n\r\n  FOR(_,\
    \ Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(a, b);\r\n      swag.push(E({a,\
    \ b}));\r\n    }\r\n    elif (t == 1) { swag.pop(); }\r\n    elif (t == 2) {\r\
    \n      LL(x);\r\n      auto e = swag.prod();\r\n      print(e.fi * mint(x) +\
    \ e.se);\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"ds/swag.hpp\"\r\n#include \"\
    mod/modint.hpp\"\r\n\r\nusing mint = modint998;\r\n\r\nvoid solve() {\r\n  LL(Q);\r\
    \n  using E = pair<mint, mint>;\r\n  SWAG<E> swag(Monoid_affine<mint>());\r\n\r\
    \n  FOR(_, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(a, b);\r\n    \
    \  swag.push(E({a, b}));\r\n    }\r\n    elif (t == 1) { swag.pop(); }\r\n   \
    \ elif (t == 2) {\r\n      LL(x);\r\n      auto e = swag.prod();\r\n      print(e.fi\
    \ * mint(x) + e.se);\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - ds/swag.hpp
  - algebra/monoid.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2021-12-27 05:46:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/queue_operate_all_composite.test.cpp
- /verify/test/library_checker/datastructure/queue_operate_all_composite.test.cpp.html
title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
---
