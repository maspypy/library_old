---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: polynomial/convolution.hpp
    title: polynomial/convolution.hpp
  - icon: ':x:'
    path: polynomial/multivar_convolution.hpp
    title: polynomial/multivar_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/library_checker/convolution/subset_convolution_multivar.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\r\n#line\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/convolution/subset_convolution_multivar.test.cpp\"\
    \n\r\n#line 2 \"mod/modint.hpp\"\ntemplate <int mod>\nstruct modint {\n  static\
    \ constexpr bool is_static = true;\n  int val;\n\n  constexpr modint(const ll\
    \ val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod) %\
    \ mod) {}\n\n  bool operator<(const modint &other) const {\n    return val < other.val;\n\
    \  } // To use std::map\n\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(-val); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n   \
    \ }\n    return modint(u);\n  }\n\n  modint pow(int64_t n) const {\n    modint\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const modint &p) {\n    return os << p.val;\n  }\n\
    \  friend istream &operator>>(istream &is, modint &a) {\n    int64_t t;\n    is\
    \ >> t;\n    a = modint(t);\n    return (is);\n  }\n  static constexpr int get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  int val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n\n  bool\
    \ operator<(const ArbitraryModInt &other) const {\n    return val < other.val;\n\
    \  } // To use std::map<ArbitraryModInt, T>\n\n  static int &get_mod() {\n   \
    \ static int mod = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod()\
    \ = md; }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val\
    \ += p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((val += get_mod() - p.val)\
    \ >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    unsigned long long a = (unsigned long long)val *\
    \ p.val;\n    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;\n   \
    \ asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"\
    (get_mod()));\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt &operator/=(const\
    \ ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n \
    \ ArbitraryModInt operator-() const { return ArbitraryModInt(-val); }\n  ArbitraryModInt\
    \ operator+(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ += p;\n  }\n  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) -= p;\n  }\n  ArbitraryModInt operator*(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) *= p;\n  }\n\n\
    \  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ /= p;\n  }\n\n  bool operator==(const ArbitraryModInt &p) const { return val\
    \ == p.val; }\n  bool operator!=(const ArbitraryModInt &p) const { return val\
    \ != p.val; }\n  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(),\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b);\n      swap(u -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n\
    \  }\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n  friend ostream &operator<<(ostream &os,\
    \ const ArbitraryModInt &p) {\n    return os << p.val;\n  }\n  friend istream\
    \ &operator>>(istream &is, ArbitraryModInt &a) {\n    int64_t t;\n    is >> t;\n\
    \    a = ArbitraryModInt(t);\n    return (is);\n  }\n};\n\ntemplate<typename mint>\n\
    tuple<mint, mint, mint> get_factorial_data(int n){\n  static constexpr int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n\n  static vector<mint> fact\
    \ = {1, 1};\n  static vector<mint> fact_inv = {1, 1};\n  static vector<mint> inv\
    \ = {0, 1};\n  while(len(fact) <= n){\n    int k = len(fact);\n    fact.eb(fact[k\
    \ - 1] * mint(k));\n    auto q = ceil(mod, k);\n    int r = k * q - mod;\n   \
    \ inv.eb(inv[r] * mint(q));\n    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n\
    \  return {fact[n], fact_inv[n], inv[n]};\n}\n\ntemplate<typename mint>\nmint\
    \ fact(int n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <= n);\n\
    \  if(n >= mod) return 0;\n  return get<0>(get_factorial_data<mint>(n));\n}\n\n\
    template<typename mint>\nmint fact_inv(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  return get<1>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate<typename mint>\nmint inv(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate<typename mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n\
    \ >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n\
    \  FOR(i, k) {\n    x *= mint(n - i);\n  }\n  x *= fact_inv<mint>(k);\n  return\
    \ x;\n}\n\nusing modint107 = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n\
    using amint = ArbitraryModInt;\n#line 2 \"polynomial/convolution.hpp\"\ntemplate\
    \ <class T>\r\nvector<T> convolution_naive(const vector<T>& a, const vector<T>&\
    \ b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  vector<T> ans(n + m\
    \ - 1);\r\n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\
    \n  } else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  }\r\n\
    \  return ans;\r\n}\r\n\r\ntemplate <class mint>\r\nstruct fft_info {\r\n  static\
    \ constexpr int bsf_constexpr(unsigned int n) {\r\n    int x = 0;\r\n    while\
    \ (!(n & (1 << x))) x++;\r\n    return x;\r\n  }\r\n\r\n  static constexpr int\
    \ rank2 = bsf_constexpr(mint::get_mod() - 1);\r\n  array<mint, rank2 + 1> root;\r\
    \n  array<mint, rank2 + 1> iroot;\r\n  array<mint, max(0, rank2 - 1)> rate2;\r\
    \n  array<mint, max(0, rank2 - 1)> irate2;\r\n  array<mint, max(0, rank2 - 2)>\
    \ rate3;\r\n  array<mint, max(0, rank2 - 2)> irate3;\r\n\r\n  fft_info() {\r\n\
    \    int g = primitive_root(mint::get_mod());\r\n    root[rank2] = mint(g).pow((mint::get_mod()\
    \ - 1) >> rank2);\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n\r\n    {\r\n      mint prod = 1, iprod = 1;\r\
    \n      for (int i = 0; i <= rank2 - 2; i++) {\r\n        rate2[i] = root[i +\
    \ 2] * prod;\r\n        irate2[i] = iroot[i + 2] * iprod;\r\n        prod *= iroot[i\
    \ + 2];\r\n        iprod *= root[i + 2];\r\n      }\r\n    }\r\n    {\r\n    \
    \  mint prod = 1, iprod = 1;\r\n      for (int i = 0; i <= rank2 - 3; i++) {\r\
    \n        rate3[i] = root[i + 3] * prod;\r\n        irate3[i] = iroot[i + 3] *\
    \ iprod;\r\n        prod *= iroot[i + 3];\r\n        iprod *= root[i + 3];\r\n\
    \      }\r\n    }\r\n  }\r\n\r\n  constexpr int primitive_root(int m) {\r\n  \
    \  if (m == 167772161) return 3;\r\n    if (m == 469762049) return 3;\r\n    if\
    \ (m == 754974721) return 11;\r\n    if (m == 880803841) return 26;\r\n    if\
    \ (m == 998244353) return 3;\r\n  }\r\n};\r\n\r\ntemplate <class mint>\r\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\r\n  int n = int(a.size());\r\n  int h\
    \ = topbit(n);\r\n  assert(n == 1 << h);\r\n  static const fft_info<mint> info;\r\
    \n  if (!inverse) {\r\n    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..]\
    \ is transformed\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n   \
    \     int p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1\
    \ << len) {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p]\
    \ * rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= info.rate2[topbit(~s & -~s)];\r\n\
    \        }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len\
    \ - 2);\r\n        mint rot = 1, imag = info.root[2];\r\n        for (int s =\
    \ 0; s < (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint\
    \ rot3 = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for\
    \ (int i = 0; i < p; i++) {\r\n            auto mod2 = 1ULL * mint::get_mod()\
    \ * mint::get_mod();\r\n            auto a0 = 1ULL * a[i + offset].val;\r\n  \
    \          auto a1 = 1ULL * a[i + offset + p].val * rot.val;\r\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val * rot2.val;\r\n            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].val * rot3.val;\r\n            auto a1na3imag = 1ULL\
    \ * mint(a1 + mod2 - a3).val * imag.val;\r\n            auto na2 = mod2 - a2;\r\
    \n            a[i + offset] = a0 + a2 + a1 + a3;\r\n            a[i + offset +\
    \ 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i + offset + 2 *\
    \ p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 * p] = a0 + na2 +\
    \ (mod2 - a1na3imag);\r\n          }\r\n          rot *= info.rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p];\r\
    \n            a[i + offset] = l + r;\r\n            a[i + offset + p]\r\n    \
    \            = (unsigned long long)(mint::get_mod() + l.val - r.val)\r\n     \
    \             * irot.val;\r\n            ;\r\n          }\r\n          irot *=\
    \ info.irate2[topbit(~s & -~s)];\r\n        }\r\n        len--;\r\n      } else\
    \ {\r\n        int p = 1 << (h - len);\r\n        mint irot = 1, iimag = info.iroot[2];\r\
    \n        FOR(s, (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n\
    \          mint irot3 = irot2 * irot;\r\n          int offset = s << (h - len\
    \ + 2);\r\n          for (int i = 0; i < p; i++) {\r\n            auto a0 = 1ULL\
    \ * a[i + offset + 0 * p].val;\r\n            auto a1 = 1ULL * a[i + offset +\
    \ 1 * p].val;\r\n            auto a2 = 1ULL * a[i + offset + 2 * p].val;\r\n \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val;\r\n\r\n            auto\
    \ a2na3iimag\r\n                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;\r\
    \n\r\n            a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset\
    \ + 1 * p]\r\n                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;\r\
    \n            a[i + offset + 2 * p]\r\n                = (a0 + a1 + (mint::get_mod()\
    \ - a2) + (mint::get_mod() - a3))\r\n                  * irot2.val;\r\n      \
    \      a[i + offset + 3 * p]\r\n                = (a0 + (mint::get_mod() - a1)\
    \ + (mint::get_mod() - a2na3iimag))\r\n                  * irot3.val;\r\n    \
    \      }\r\n          irot *= info.irate3[topbit(~s & -~s)];\r\n        }\r\n\
    \        len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  int n =\
    \ int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m -\
    \ 1) sz *= 2;\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a,\
    \ false);\r\n  if(same){\r\n    b = a;\r\n  } else {\r\n    ntt(b, false);\r\n\
    \  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, true);\r\n  a.resize(n + m - 1);\r\
    \n  mint iz = mint(1) / mint(sz);\r\n  FOR(i, len(a)) a[i] *= iz;\r\n  return\
    \ a;\r\n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  static const long long nttprimes[] = {754974721,\
    \ 167772161, 469762049};\r\n  using mint0 = modint<754974721>;\r\n  using mint1\
    \ = modint<167772161>;\r\n  using mint2 = modint<469762049>;\r\n  vc<mint0> a0(n),\
    \ b0(m);\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  static const\
    \ int mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2\
    \ x2) -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
    \ - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\r\n    return mint(r0\
    \ + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);\r\n  };\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);\r\n  return c;\r\n}\r\n\
    \r\nnamespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\
    \n\r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename R>\r\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\r\n  int need = (int)a.size() + (int)b.size() -\
    \ 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  fft(fa, sz);\r\n  C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1); i++)\
    \ {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i] *\
    \ fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\n  fft(fa,\
    \ sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0; i < need; i++)\
    \ {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n  }\r\n  return\
    \ ret;\r\n}\r\n} // namespace CFFT\r\n\r\nvector<ll> convolution(vector<ll>& a,\
    \ vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  FOR(i, n) abs_sum_a += abs(a[i]);\r\n  FOR(i, n) abs_sum_b\
    \ += abs(b[i]);\r\n  assert(abs_sum_a * abs_sum_b < 1e15);\r\n  vc<double> c =\
    \ CFFT::convolution_fft(a, b);\r\n  vc<ll> res(len(c));\r\n  FOR(i, len(c)) res[i]\
    \ = ll(floor(c[i] + .5));\r\n  return res;\r\n}\r\n\r\ntemplate<typename mint>\r\
    \nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(vc<mint>&\
    \ a, vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_ntt(a,\
    \ b);\r\n}\r\n\r\ntemplate<typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value,\
    \ vc<mint>> convolution(vc<mint>& a, vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a,\
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 2 \"polynomial/multivar_convolution.hpp\"\
    \ntemplate <typename mint>\r\nvc<mint> multivar_convolution(vi ns, vc<mint>& f,\
    \ vc<mint>& g) {\r\n  /*\r\n  (n0, n1, n2, ...) \u9032\u6CD5\u3067\u306E\u7E70\
    \u308A\u4E0A\u304C\u308A\u306E\u306A\u3044\u8DB3\u3057\u7B97\u306B\u95A2\u3059\
    \u308B\u7573\u307F\u8FBC\u307F\r\n\r\n  example : ns = (2, 3) \u2192 1 \u306E\u4F4D\
    \u304B\u3089\u9806\u306B 2, 3 \u9032\u6CD5\r\n  [a0, a1, a2, a3, a4, a5] = [a(0,0),\
    \ a(1,0), a(0,1), a(1,1), a(0,2), a(1,2)]\r\n  [b0, b1, b2, b3, b4, b5] = [b(0,0),\
    \ b(1,0), b(0,1), b(1,1), b(0,2), b(1,2)]\r\n  c(0,2) = a(0,0)b(0,2) + a(0,1)b(0,1)\
    \ + a(0,2)b(1,1)\r\n  c4 = a0b4 + a2b2 + a4b0\r\n\r\n  example : ns = (2, 2, ...,\
    \ 2, 2)\r\n  \u2192 subset convolution \u304C\u3053\u308C\u306E\u7279\u6B8A\u30B1\
    \u30FC\u30B9\r\n  */\r\n  int K = len(ns);\r\n  int N = 1;\r\n  FOR(k, K) N *=\
    \ ns[k];\r\n  assert(len(f) == N && len(g) == N);\r\n  if (N == 1) return {f[0]\
    \ * g[0]};\r\n\r\n  auto chi = [&](ll i) -> ll {\r\n    int x = 0;\r\n    for\
    \ (auto&& n : ns) {\r\n      i /= n;\r\n      x += i;\r\n    }\r\n    return x\
    \ % K;\r\n  };\r\n\r\n  int sz = 1;\r\n  while (sz < N + N) sz *= 2;\r\n  vv(mint,\
    \ ff, K, sz);\r\n  vv(mint, gg, K, sz);\r\n\r\n  FOR(i, N) {\r\n    auto k = chi(i);\r\
    \n    ff[k][i] = f[i];\r\n    gg[k][i] = g[i];\r\n  }\r\n\r\n  FOR(k, K) {\r\n\
    \    ntt(ff[k], false);\r\n    ntt(gg[k], false);\r\n  }\r\n\r\n  vv(mint, hh,\
    \ K, sz);\r\n  FOR(a, K) FOR(b, K) FOR(i, sz) { hh[(a + b) % K][i] += ff[a][i]\
    \ * gg[b][i]; }\r\n  FOR(k, K) ntt(hh[k], true);\r\n\r\n  vc<mint> h(N);\r\n \
    \ mint c = mint(1) / mint(sz);\r\n  FOR(i, N) h[i] = hh[chi(i)][i] * c;\r\n  return\
    \ h;\r\n}\r\n#line 6 \"test/library_checker/convolution/subset_convolution_multivar.test.cpp\"\
    \n\r\nusing mint = modint998;\r\n\r\nvoid solve() {\r\n  LL(N);\r\n  VEC(mint,\
    \ A, 1 << N);\r\n  VEC(mint, B, 1 << N);\r\n  vi ns(N, 2);\r\n  auto C = multivar_convolution(ns,\
    \ A, B);\r\n  print(C);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\r\n\
    #include \"my_template.hpp\"\r\n\r\n#include \"mod/modint.hpp\"\r\n#include \"\
    polynomial/multivar_convolution.hpp\"\r\n\r\nusing mint = modint998;\r\n\r\nvoid\
    \ solve() {\r\n  LL(N);\r\n  VEC(mint, A, 1 << N);\r\n  VEC(mint, B, 1 << N);\r\
    \n  vi ns(N, 2);\r\n  auto C = multivar_convolution(ns, A, B);\r\n  print(C);\r\
    \n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - mod/modint.hpp
  - polynomial/multivar_convolution.hpp
  - polynomial/convolution.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/subset_convolution_multivar.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 02:54:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/convolution/subset_convolution_multivar.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/subset_convolution_multivar.test.cpp
- /verify/test/library_checker/convolution/subset_convolution_multivar.test.cpp.html
title: test/library_checker/convolution/subset_convolution_multivar.test.cpp
---
