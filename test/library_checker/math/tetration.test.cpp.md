---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  - icon: ':x:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
  - icon: ':x:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':x:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
    links:
    - https://judge.yosupo.jp/problem/tetration_mod
  bundledCode: "#line 1 \"test/library_checker/math/tetration.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\r\n#line 1 \"my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR_(n) for (ll _ = 0; (_) < (ll)(n);\
    \ ++(_))\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i,\
    \ m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i\
    \ = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1;\
    \ (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t =\
    \ (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x)\
    \ ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define stoi stoll\n\
    \ntemplate <typename T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x==0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x==0 ?\
    \ -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint\
    \ lowbit(int x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint lowbit(u32\
    \ x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint lowbit(ll x) { return\
    \ (x==0 ? -1 : 63 - __builtin_clzll(x)); }\nint lowbit(u64 x) { return (x==0 ?\
    \ -1 : 63 - __builtin_clzll(x)); }\n\ntemplate <typename T, typename U>\nT ceil(T\
    \ x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename\
    \ T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) /\
    \ y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T x, U y) {\n\
    \  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool\
    \ chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b,\
    \ 1 : 0);\n}\n\nvi s_to_vi(string S, char first_char = 'a') {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename T, typename CNT\
    \ = int>\nvc<CNT> bincount(vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(vector<T>\
    \ &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });\n\
    \  return ids;\n}\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include\
    \ <unistd.h>\r\n\r\nnamespace detail {\r\ntemplate <typename T, decltype(&T::is_modint)\
    \ = &T::is_modint>\r\nstd::true_type check_value(int);\r\ntemplate <typename T>\r\
    \nstd::false_type check_value(long);\r\n} // namespace detail\r\n\r\ntemplate\
    \ <typename T>\r\nstruct is_modint : decltype(detail::check_value<T>(0)) {};\r\
    \ntemplate <typename T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\
    \ntemplate <typename T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\
    \n\r\nstruct Scanner {\r\n  FILE *fp;\r\n  char line[(1 << 15) + 1];\r\n  size_t\
    \ st = 0, ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\
    \n    ed -= st;\r\n    st = 0;\r\n    ed += fread(line + ed, 1, (1 << 15) - ed,\
    \ fp);\r\n    line[ed] = '\\0';\r\n  }\r\n  bool succ() {\r\n    while (true)\
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
    \n  }\r\n  Scanner(FILE *fp) : fp(fp) {}\r\n};\r\n\r\nstruct Printer {\r\n  Printer(FILE\
    \ *_fp) : fp(_fp) {}\r\n  ~Printer() { flush(); }\r\n\r\n  static constexpr size_t\
    \ SIZE = 1 << 15;\r\n  FILE *fp;\r\n  char line[SIZE], small[50];\r\n  size_t\
    \ pos = 0;\r\n  void flush() {\r\n    fwrite(line, 1, pos, fp);\r\n    pos = 0;\r\
    \n  }\r\n  void write(const char &val) {\r\n    if (pos == SIZE) flush();\r\n\
    \    line[pos++] = val;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
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
    \n    }\r\n  }\r\n  template <class T, class U>\r\n  void write(const pair<T,\
    \ U> &val) {\r\n    write(val.first);\r\n    write(' ');\r\n    write(val.second);\r\
    \n  }\r\n  template <class A, class B, class C>\r\n  void write(const tuple<A,\
    \ B, C> &val) {\r\n    auto &[a, b, c] = val;\r\n    write(a);\r\n    write('\
    \ ');\r\n    write(b);\r\n    write(' ');\r\n    write(c);\r\n  }\r\n  template\
    \ <class A, class B, class C, class D>\r\n  void write(const tuple<A, B, C, D>\
    \ &val) {\r\n    auto &[a, b, c, d] = val;\r\n    write(a);\r\n    write(' ');\r\
    \n    write(b);\r\n    write(' ');\r\n    write(c);\r\n    write(' ');\r\n   \
    \ write(d);\r\n  }\r\n  template <class T, size_t S>\r\n  void write(const array<T,\
    \ S> &val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++)\
    \ {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\n    }\r\n  }\r\n  void\
    \ write(i128 val) {\r\n    string s;\r\n    while (val) {\r\n      s += '0' +\
    \ int(val % 10);\r\n      val /= 10;\r\n    }\r\n    reverse(all(s));\r\n    if\
    \ (len(s) == 0) s = \"0\";\r\n    write(s);\r\n  }\r\n};\r\n\r\nScanner scanner\
    \ = Scanner(stdin);\r\nPrinter printer = Printer(stdout);\r\n\r\nvoid flush()\
    \ { printer.flush(); }\r\nvoid print() { printer.write('\\n'); }\r\ntemplate <class\
    \ Head, class... Tail>\r\nvoid print(Head &&head, Tail &&... tail) {\r\n  printer.write(head);\r\
    \n  if (sizeof...(Tail)) printer.write(' ');\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\nvoid read() {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head\
    \ &head, Tail &... tail) {\r\n  scanner.read(head);\r\n  read(tail...);\r\n}\r\
    \n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n\
    #define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\r\n#line 1 \"mod/fast_div.hpp\"\nstruct fast_div {\r\n  // Min25\
    \ https://judge.yosupo.jp/submission/46090\r\n  // \u540C\u3058\u5B9A\u6570\u3067\
    \u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\u3068\u304D\u306E\u9AD8\u901F\u5316\
    \u306B\u4F7F\u3048\u308B\r\n  using i64 = long long;\r\n  using u64 = unsigned\
    \ long long;\r\n  using u128 = __uint128_t;\r\n  constexpr fast_div() : m(), s(),\
    \ x() {}\r\n  constexpr fast_div(int n)\r\n      : m(n), s(std::__lg(n - 1)),\
    \ x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\n  constexpr friend u64 operator/(u64\
    \ n, const fast_div& d) {\r\n    return (u128(n) * d.x >> d.s) >> 64;\r\n  }\r\
    \n  constexpr friend int operator%(u64 n, const fast_div& d) {\r\n    return n\
    \ - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64, int> divmod(u64 n) const\
    \ {\r\n    u64 q = n / *this;\r\n    return {q, n - q * m};\r\n  }\r\n\r\n  int\
    \ m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 2 \"nt/primetest.hpp\"\nstruct m64\
    \ {\r\n    using i64 = int64_t;\r\n    using u64 = uint64_t;\r\n    using u128\
    \ = __uint128_t;\r\n\r\n    inline static u64 m, r, n2; // r * m = -1 (mod 1<<64),\
    \ n2 = 1<<128 (mod m)\r\n    static void set_mod(u64 m) {\r\n        assert(m\
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
    \ false;\r\n        }\r\n    }\r\n    return true;\r\n}\n#line 3 \"nt/factor.hpp\"\
    \n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll n) { return uniform_int_distribution<ll>(0,\
    \ n - 1)(rng_mt); }\n\nll rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n >\
    \ 1);\n  const m64 cc(c);\n  auto f = [&](m64 x) { return x * x + cc; };\n  m64\
    \ x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\
    \ // ?\n  for (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n\
    \    for (ll k = 0; k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m,\
    \ r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if\
    \ (g == n)\n    do {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    }\
    \ while (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n\
    \ > 1);\n  if (primetest(n))\n    return n;\n  FOR(_, 100) {\n    ll m = rho(n,\
    \ rnd(n));\n    if (primetest(m))\n      return m;\n    n = m;\n  }\n  cerr <<\
    \ \"failed\" << endl;\n  assert(false);\n  return -1;\n}\n\nvc<pi> factor(ll n)\
    \ {\n  assert(n >= 1);\n  vc<pi> pf;\n  FOR3(p, 2, 100) {\n    if (p * p > n)\n\
    \      break;\n    if (n % p == 0) {\n      ll e = 0;\n      do {\n        n /=\
    \ p, e += 1;\n      } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while\
    \ (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\n     \
    \ n /= p, e += 1;\n    } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n#line 2 \"nt/euler_phi.hpp\"\nll euler_phi(ll n) {\r\n  auto\
    \ pf = factor(n);\r\n  for (auto&& [p, e]: pf) n -= n / p;\r\n  return n;\r\n\
    }\r\n#line 3 \"mod/tetration.hpp\"\n\r\nint tetration(vc<ll> a, int mod) {\r\n\
    \  for (auto&& x: a) assert(x > 0);\r\n\r\n  // a[0]^(a[1]^(a[2]^...))\r\n  vc<int>\
    \ mod_chain = {mod};\r\n  while (mod_chain.back() > 1) mod_chain.eb(euler_phi(mod_chain.back()));\r\
    \n  while (len(a) > len(mod_chain)) a.pop_back();\r\n  while (len(mod_chain) >\
    \ len(a)) mod_chain.pop_back();\r\n\r\n  auto pow = [&](ll x, int n, int mod)\
    \ -> int {\r\n    fast_div fd(mod);\r\n    if (x >= mod) x = x % fd + mod;\r\n\
    \    ll v = 1;\r\n    do {\r\n      if (n & 1) {\r\n        v *= x;\r\n      \
    \  if (v >= mod) v = v % fd + mod;\r\n      }\r\n      x *= x;\r\n      if (x\
    \ >= mod) x = x % fd + mod;\r\n      n /= 2;\r\n    } while (n);\r\n    return\
    \ v;\r\n  };\r\n\r\n  int v = 1;\r\n  FOR_R(i, len(a)) v = pow(a[i], v, mod_chain[i]);\r\
    \n  return v % mod;\r\n}\r\n#line 5 \"test/library_checker/math/tetration.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(a, b, m);\r\n  if (a == 0) {\r\n    ll ANS = (b %\
    \ 2 == 0 ? 1 : 0);\r\n    return print(ANS % m);\r\n  }\r\n  chmin(b, 64);\r\n\
    \  vi v(b, a);\r\n  print(tetration(v, m));\r\n}\r\n\r\nsigned main() {\r\n  LL(T);\r\
    \n  FOR_(T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"mod/tetration.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(a, b, m);\r\n  if (a == 0) {\r\n    ll ANS = (b\
    \ % 2 == 0 ? 1 : 0);\r\n    return print(ANS % m);\r\n  }\r\n  chmin(b, 64);\r\
    \n  vi v(b, a);\r\n  print(tetration(v, m));\r\n}\r\n\r\nsigned main() {\r\n \
    \ LL(T);\r\n  FOR_(T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/tetration.hpp
  - mod/fast_div.hpp
  - nt/euler_phi.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  isVerificationFile: true
  path: test/library_checker/math/tetration.test.cpp
  requiredBy: []
  timestamp: '2022-03-28 12:53:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/tetration.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/tetration.test.cpp
- /verify/test/library_checker/math/tetration.test.cpp.html
title: test/library_checker/math/tetration.test.cpp
---
