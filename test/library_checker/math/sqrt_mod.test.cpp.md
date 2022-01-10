---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/library_checker/math/sqrt_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\r\n#line 1 \"my_template.hpp\"\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"other/io.hpp\"\n\
    // based on yosupo's fastio\r\n#include <unistd.h>\r\n\r\nnamespace detail {\r\
    \ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\r\nstd::true_type\
    \ check_value(int);\r\ntemplate <typename T>\r\nstd::false_type check_value(long);\r\
    \n} // namespace detail\r\n\r\ntemplate <typename T>\r\nstruct is_modint : decltype(detail::check_value<T>(0))\
    \ {};\r\ntemplate <typename T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\
    \ntemplate <typename T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\
    \n\r\nstruct Scanner {\r\n  int fd = -1;\r\n  char line[(1 << 15) + 1];\r\n  size_t\
    \ st = 0, ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\
    \n    ed -= st;\r\n    st = 0;\r\n    ed += ::read(fd, line + ed, (1 << 15) -\
    \ ed);\r\n    line[ed] = '\\0';\r\n  }\r\n  bool succ() {\r\n    while (true)\
    \ {\r\n      if (st == ed) {\r\n        reread();\r\n        if (st == ed) return\
    \ false;\r\n      }\r\n      while (st != ed && isspace(line[st])) st++;\r\n \
    \     if (st != ed) break;\r\n    }\r\n    if (ed - st <= 50) {\r\n      bool\
    \ sep = false;\r\n      for (size_t i = st; i < ed; i++) {\r\n        if (isspace(line[i]))\
    \ {\r\n          sep = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!sep) reread();\r\n    }\r\n    return true;\r\n  }\r\n  template <class\
    \ T, enable_if_t<is_same<T, string>::value, int> = 0>\r\n  bool read_single(T\
    \ &ref) {\r\n    if (!succ()) return false;\r\n    while (true) {\r\n      size_t\
    \ sz = 0;\r\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\r\n \
    \     ref.append(line + st, sz);\r\n      st += sz;\r\n      if (!sz || st !=\
    \ ed) break;\r\n      reread();\r\n    }\r\n    return true;\r\n  }\r\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\r\n  bool read_single(T\
    \ &ref) {\r\n    if (!succ()) return false;\r\n    bool neg = false;\r\n    if\
    \ (line[st] == '-') {\r\n      neg = true;\r\n      st++;\r\n    }\r\n    ref\
    \ = T(0);\r\n    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf);\
    \ }\r\n    if (neg) ref = -ref;\r\n    return true;\r\n  }\r\n  template <class\
    \ T, is_modint_t<T> * = nullptr>\r\n  bool read_single(T &ref) {\r\n    long long\
    \ val = 0;\r\n    bool f = read_single(val);\r\n    ref = T(val);\r\n    return\
    \ f;\r\n  }\r\n  bool read_single(double &ref) {\r\n    string s;\r\n    if (!read_single(s))\
    \ return false;\r\n    ref = std::stod(s);\r\n    return true;\r\n  }\r\n  template\
    \ <class T>\r\n  bool read_single(vector<T> &ref) {\r\n    for (auto &d: ref)\
    \ {\r\n      if (!read_single(d)) return false;\r\n    }\r\n    return true;\r\
    \n  }\r\n  template <class T, class U>\r\n  bool read_single(pair<T, U> &p) {\r\
    \n    return (read_single(p.first) && read_single(p.second));\r\n  }\r\n  template\
    \ <class A, class B, class C>\r\n  bool read_single(tuple<A, B, C> &p) {\r\n \
    \   return (read_single(get<0>(p)) && read_single(get<1>(p))\r\n            &&\
    \ read_single(get<2>(p)));\r\n  }\r\n  template <class A, class B, class C, class\
    \ D>\r\n  bool read_single(tuple<A, B, C, D> &p) {\r\n    return (read_single(get<0>(p))\
    \ && read_single(get<1>(p))\r\n            && read_single(get<2>(p)) && read_single(get<3>(p)));\r\
    \n  }\r\n  void read() {}\r\n  template <class H, class... T>\r\n  void read(H\
    \ &h, T &... t) {\r\n    bool f = read_single(h);\r\n    assert(f);\r\n    read(t...);\r\
    \n  }\r\n  Scanner(FILE *fp) : fd(fileno(fp)) {}\r\n};\r\n\r\nstruct Printer {\r\
    \n  Printer(FILE *_fp) : fp(_fp) {}\r\n  ~Printer() { flush(); }\r\n\r\n  static\
    \ constexpr size_t SIZE = 1 << 15;\r\n  FILE *fp;\r\n  char line[SIZE], small[50];\r\
    \n  size_t pos = 0;\r\n  void flush() {\r\n    fwrite(line, 1, pos, fp);\r\n \
    \   pos = 0;\r\n  }\r\n  void write(const char &val) {\r\n    if (pos == SIZE)\
    \ flush();\r\n    line[pos++] = val;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n  void write(T val) {\r\n    if (pos > (1 << 15) - 50) flush();\r\
    \n    if (val == 0) {\r\n      write('0');\r\n      return;\r\n    }\r\n    if\
    \ (val < 0) {\r\n      write('-');\r\n      val = -val; // todo min\r\n    }\r\
    \n    size_t len = 0;\r\n    while (val) {\r\n      small[len++] = char(0x30 |\
    \ (val % 10));\r\n      val /= 10;\r\n    }\r\n    for (size_t i = 0; i < len;\
    \ i++) { line[pos + i] = small[len - 1 - i]; }\r\n    pos += len;\r\n  }\r\n \
    \ void write(const string &s) {\r\n    for (char c: s) write(c);\r\n  }\r\n  void\
    \ write(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t i =\
    \ 0; i < len; i++) write(s[i]);\r\n  }\r\n  void write(const double &x) {\r\n\
    \    ostringstream oss;\r\n    oss << setprecision(12) << x;\r\n    string s =\
    \ oss.str();\r\n    write(s);\r\n  }\r\n  template <class T, is_modint_t<T> *\
    \ = nullptr>\r\n  void write(T &ref) {\r\n    write(ref.val);\r\n  }\r\n  template\
    \ <class T>\r\n  void write(const vector<T> &val) {\r\n    auto n = val.size();\r\
    \n    for (size_t i = 0; i < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\
    \n    }\r\n  }\r\n};\r\n\r\nScanner scanner = Scanner(stdin);\r\nPrinter printer\
    \ = Printer(stdout);\r\n\r\nvoid print() { printer.write('\\n'); }\r\ntemplate\
    \ <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&... tail) {\r\n\
    \  printer.write(head);\r\n  if (sizeof...(Tail)) printer.write(' ');\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\nvoid read() {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head\
    \ &head, Tail &... tail) {\r\n  scanner.read(head);\r\n  read(tail...);\r\n}\r\
    \n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ CHR(...)    \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)\
    \           \\\r\n  long double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n\
    #define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\r\n#line 6 \"my_template.hpp\"\n\n\nusing ll = long long;\nusing\
    \ ll8 = __int128;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint\
    \ = unsigned int;\nusing ull = unsigned long long;\n\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n            b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR_(n) for (ll _ = 0; (_) < (ll)(n);\
    \ ++(_))\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i,\
    \ m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i\
    \ = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1;\
    \ (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t =\
    \ (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x)\
    \ ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define SUM(v) accumulate(all(v),\
    \ 0LL)\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(uint x) { return __builtin_popcount(x); }\nint popcnt(ll x) {\
    \ return __builtin_popcountll(x); }\nint popcnt(ull x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - __builtin_clz(x);\
    \ }\nint topbit(uint x) { return 31 - __builtin_clz(x); }\nint topbit(ll x) {\
    \ return 63 - __builtin_clzll(x); }\nint topbit(ull x) { return 63 - __builtin_clzll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return\
    \ 31 - __builtin_clz(x); }\nint lowbit(uint x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(ll x) { return 63 - __builtin_clzll(x); }\nint lowbit(ull x) {\
    \ return 63 - __builtin_clzll(x); }\n\nll ceil(ll x, ll y) { return (x > 0 ? (x\
    \ + y - 1) / y : x / y); }\nll floor(ll x, ll y) { return (x > 0 ? x / y : (x\
    \ - y + 1) / y); }\npi divmod(ll x, ll y) {\n  ll q = floor(x, y);\n  return {q,\
    \ x - q * y};\n}\n\nll binary_search(function<bool(ll)> check, ll ok, ll ng) {\n\
    \  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) /\
    \ 2;\n    if (check(x)) ok = x;\n    else ng = x;\n  }\n  return ok;\n}\n\ntemplate\
    \ <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ?\
    \ a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const\
    \ S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\nvi s_to_vi(string S, char first_char\
    \ = 'a') {\n  vi A(S.size());\n  FOR(i, S.size()) { A[i] = S[i] - first_char;\
    \ }\n  return A;\n}\n\ntemplate <typename T>\nvector<T> cumsum(vector<T> &A) {\n\
    \  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  return B;\n}\n\nvc<int> bincount(vi &A, int size) {\n  vc<int> C(size);\n\
    \  for (auto&& x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int>\
    \ argsort(vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j); });\n  return ids;\n}\n#line 2 \"mod/modint.hpp\"\ntemplate <int\
    \ mod>\nstruct modint {\n  static constexpr bool is_modint = true;\n  int val;\n\
    \  constexpr modint(const ll val = 0) noexcept\n      : val(val >= 0 ? val % mod\
    \ : (mod - (-val) % mod) % mod) {}\n  bool operator<(const modint &other) const\
    \ {\n    return val < other.val;\n  } // To use std::map\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += mod - p.val) >=\
    \ mod) val -= mod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = (int)(1LL * val * p.val % mod);\n    return *this;\n  }\n \
    \ modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint(-val); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t n) const {\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr\
    \ bool is_modint = true;\n  int val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ unsigned long long a = (unsigned long long)val * p.val;\n    unsigned xh = (unsigned)(a\
    \ >> 32), xl = (unsigned)a, d, m;\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator/=(const ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  ArbitraryModInt operator-() const { return ArbitraryModInt(-val);\
    \ }\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\n    return\
    \ ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt operator-(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) -= p;\n  }\n  ArbitraryModInt\
    \ operator*(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ *= p;\n  }\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) /= p;\n  }\n  bool operator==(const ArbitraryModInt\
    \ &p) const { return val == p.val; }\n  bool operator!=(const ArbitraryModInt\
    \ &p) const { return val != p.val; }\n  ArbitraryModInt inverse() const {\n  \
    \  int a = val, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ ArbitraryModInt(u);\n  }\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n};\n\ntemplate<typename\
    \ mint>\ntuple<mint, mint, mint> get_factorial_data(int n){\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ fact = {1, 1};\n  static vector<mint> fact_inv = {1, 1};\n  static vector<mint>\
    \ inv = {0, 1};\n  while(len(fact) <= n){\n    int k = len(fact);\n    fact.eb(fact[k\
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
    \ x;\n}\n\ntemplate<typename mint>\nvc<mint> power_table(mint a, ll N) {\n  vc<mint>\
    \ f(N, 1);\n  FOR(i, N - 1) f[i + 1] = a * f[i];\n  return f;\n}\n\nusing modint107\
    \ = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\nusing amint\
    \ = ArbitraryModInt;\n#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator\
    \ {\n  mt19937 mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 3 \"mod/mod_sqrt.hpp\"\n\r\ntemplate\
    \ <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\n\
    \  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  RandomNumberGenerator RNG;\r\n  auto find\
    \ = [&]() -> pair<mint, mint> {\r\n    while (1) {\r\n      mint b = RNG(2, p);\r\
    \n      mint D = b * b - a;\r\n      if (D == 0) return {b, D};\r\n      if (D.pow(k)\
    \ != mint(1)) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n \
    \ if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1\
    \ = 1;\r\n  mint g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0,\
    \ g1) = mp(f0 * g0 + D * f1 * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0\
    \ * f0 + D * f1 * f1, mint(2) * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\
    \n}\r\n#line 4 \"test/library_checker/math/sqrt_mod.test.cpp\"\n\r\nusing mint\
    \ = amint;\r\n\r\nvoid solve() {\r\n  LL(T);\r\n  FOR_(T) {\r\n    LL(y0, p);\r\
    \n    mint::set_mod(p);\r\n    mint y = y0;\r\n    mint r = mod_sqrt(y);\r\n \
    \   if (r * r == y)\r\n      print(r);\r\n    else\r\n      print(-1);\r\n  }\r\
    \n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"mod/mod_sqrt.hpp\"\r\n\r\nusing mint = amint;\r\
    \n\r\nvoid solve() {\r\n  LL(T);\r\n  FOR_(T) {\r\n    LL(y0, p);\r\n    mint::set_mod(p);\r\
    \n    mint y = y0;\r\n    mint r = mod_sqrt(y);\r\n    if (r * r == y)\r\n   \
    \   print(r);\r\n    else\r\n      print(-1);\r\n  }\r\n}\r\n\r\nsigned main()\
    \ {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/mod_sqrt.hpp
  - mod/modint.hpp
  - other/random.hpp
  isVerificationFile: true
  path: test/library_checker/math/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 16:25:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/sqrt_mod.test.cpp
- /verify/test/library_checker/math/sqrt_mod.test.cpp.html
title: test/library_checker/math/sqrt_mod.test.cpp
---
