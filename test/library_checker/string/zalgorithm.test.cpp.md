---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: string/zalgorithm.hpp
    title: string/zalgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library_checker/string/zalgorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n#line 1 \"my_template.hpp\"\
    \n#include <bits/stdc++.h>\n#include <unistd.h>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing ll8 = __int128;\nusing pi = pair<ll, ll>;\nusing vi =\
    \ vector<ll>;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\n\
    template <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
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
    \ {\n  ll q = floor(x, y);\n  return {q, x - q * y};\n}\n\nnamespace yosupo_IO\
    \ {\n\ntemplate <class T>\nusing is_signed_int128 =\n    typename std::conditional<is_same<T,\
    \ __int128_t>::value\n                                  || is_same<T, __int128>::value,\n\
    \                              true_type, false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int128 =\n    typename std::conditional<is_same<T, __uint128_t>::value\n\
    \                                  || is_same<T, unsigned __int128>::value,\n\
    \                              true_type, false_type>::type;\n\ntemplate <class\
    \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<is_same<T, __int128_t>::value,\
    \ __uint128_t,\n                              unsigned __int128>;\n\ntemplate\
    \ <class T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\n\
    \                                  || is_signed_int128<T>::value\n           \
    \                       || is_unsigned_int128<T>::value,\n                   \
    \           true_type, false_type>::type;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<(is_integral<T>::value\n                  \
    \             && std::is_signed<T>::value)\n                                 \
    \ || is_signed_int128<T>::value,\n                              true_type, false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\n\
    \                               && std::is_unsigned<T>::value)\n             \
    \                     || is_unsigned_int128<T>::value,\n                     \
    \         true_type, false_type>::type;\n\ntemplate <class T>\nusing to_unsigned\
    \ = typename std::conditional<\n    is_signed_int128<T>::value, make_unsigned_int128<T>,\n\
    \    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,\n\
    \                              std::common_type<T>>::type>::type;\n\ntemplate\
    \ <class T>\nusing is_integral_t = enable_if_t<is_integral<T>::value>;\n\ntemplate\
    \ <class T>\nusing is_signed_int_t = enable_if_t<is_signed_int<T>::value>;\n\n\
    template <class T>\nusing is_unsigned_int_t = enable_if_t<is_unsigned_int<T>::value>;\n\
    \nnamespace detail {\ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\n\
    std::true_type check_value(int);\ntemplate <typename T>\nstd::false_type check_value(long);\n\
    } // namespace detail\n\ntemplate <typename T>\nstruct is_modint : decltype(detail::check_value<T>(0))\
    \ {};\n\ntemplate <typename T>\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\n\
    template <typename T>\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\n\
    \ntemplate <class T>\nusing to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    struct Scanner {\npublic:\n  Scanner(const Scanner &) = delete;\n  Scanner &operator=(const\
    \ Scanner &) = delete;\n\n  Scanner(FILE *fp) : fd(fileno(fp)) { line[0] = 127;\
    \ }\n\n  void read() {}\n  template <class H, class... T>\n  void read(H &h, T\
    \ &... t) {\n    bool f = read_single(h);\n    assert(f);\n    read(t...);\n \
    \ }\n\n  int read_unsafe() { return 0; }\n  template <class H, class... T>\n \
    \ int read_unsafe(H &h, T &... t) {\n    bool f = read_single(h);\n    if (!f)\
    \ return 0;\n    return 1 + read_unsafe(t...);\n  }\n\n  int close() { return\
    \ ::close(fd); }\n\nprivate:\n  static constexpr int SIZE = 1 << 15;\n\n  int\
    \ fd = -1;\n  array<char, SIZE + 1> line;\n  int st = 0, ed = 0;\n  bool eof =\
    \ false;\n\n  bool read_single(string &ref) {\n    if (!skip_space()) return false;\n\
    \    ref = \"\";\n    while (true) {\n      char c = top();\n      if (c <= '\
    \ ') break;\n      ref += c;\n      st++;\n    }\n    return true;\n  }\n  bool\
    \ read_single(double &ref) {\n    string s;\n    if (!read_single(s)) return false;\n\
    \    ref = std::stod(s);\n    return true;\n  }\n\n  template <class T, enable_if_t<is_same<T,\
    \ char>::value> * = nullptr>\n  bool read_single(T &ref) {\n    if (!skip_space<50>())\
    \ return false;\n    ref = top();\n    st++;\n    return true;\n  }\n\n  template\
    \ <class T, is_signed_int_t<T> * = nullptr,\n            enable_if_t<!is_same<T,\
    \ char>::value> * = nullptr>\n  bool read_single(T &sref) {\n    using U = to_unsigned_t<T>;\n\
    \    if (!skip_space<50>()) return false;\n    bool neg = false;\n    if (line[st]\
    \ == '-') {\n      neg = true;\n      st++;\n    }\n    U ref = 0;\n    do { ref\
    \ = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');\n    sref = neg\
    \ ? -ref : ref;\n    return true;\n  }\n  template <class U, is_unsigned_int_t<U>\
    \ * = nullptr,\n            enable_if_t<!is_same<U, char>::value> * = nullptr>\n\
    \  bool read_single(U &ref) {\n    if (!skip_space<50>()) return false;\n    ref\
    \ = 0;\n    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');\n\
    \    return true;\n  }\n\n  bool reread() {\n    if (ed - st >= 50) return true;\n\
    \    if (st > SIZE / 2) {\n      std::memmove(line.data(), line.data() + st, ed\
    \ - st);\n      ed -= st;\n      st = 0;\n    }\n    if (eof) return false;\n\
    \    auto u = ::read(fd, line.data() + ed, SIZE - ed);\n    if (u == 0) {\n  \
    \    eof = true;\n      line[ed] = '\\0';\n      u = 1;\n    }\n    ed += int(u);\n\
    \    line[ed] = char(127);\n    return true;\n  }\n\n  char top() {\n    if (st\
    \ == ed) {\n      bool f = reread();\n      assert(f);\n    }\n    return line[st];\n\
    \  }\n\n  template <int TOKEN_LEN = 0>\n  bool skip_space() {\n    while (true)\
    \ {\n      while (line[st] <= ' ') st++;\n      if (ed - st > TOKEN_LEN) return\
    \ true;\n      if (st > ed) st = ed;\n      for (auto i = st; i < ed; i++) {\n\
    \        if (line[i] <= ' ') return true;\n      }\n      if (!reread()) return\
    \ false;\n    }\n  }\n};\n\nstruct Printer {\npublic:\n  template <char sep =\
    \ ' ', bool F = false>\n  void write() {}\n  template <char sep = ' ', bool F\
    \ = false, class H, class... T>\n  void write(const H &h, const T &... t) {\n\
    \    if (F) write_single(sep);\n    write_single(h);\n    write<true>(t...);\n\
    \  }\n  template <char sep = ' ', class... T>\n  void writeln(const T &... t)\
    \ {\n    write<sep>(t...);\n    write_single('\\n');\n  }\n\n  Printer(FILE *_fp)\
    \ : fd(fileno(_fp)) {}\n  ~Printer() { flush(); }\n\n  int close() {\n    flush();\n\
    \    return ::close(fd);\n  }\n\n  void flush() {\n    if (pos) {\n      auto\
    \ res = ::write(fd, line.data(), pos);\n      assert(res != -1);\n      pos =\
    \ 0;\n    }\n  }\n\nprivate:\n  static array<array<char, 2>, 100> small;\n  static\
    \ array<unsigned long long, 20> tens;\n\n  static constexpr size_t SIZE = 1 <<\
    \ 15;\n  int fd;\n  array<char, SIZE> line;\n  size_t pos = 0;\n  std::stringstream\
    \ ss;\n\n  template <class T, enable_if_t<is_same<char, T>::value> * = nullptr>\n\
    \  void write_single(const T &val) {\n    if (pos == SIZE) flush();\n    line[pos++]\
    \ = val;\n  }\n\n  template <class T, is_signed_int_t<T> * = nullptr,\n      \
    \      enable_if_t<!is_same<char, T>::value> * = nullptr>\n  void write_single(const\
    \ T &val) {\n    using U = to_unsigned_t<T>;\n    if (val == 0) {\n      write_single('0');\n\
    \      return;\n    }\n    if (pos > SIZE - 50) flush();\n    U uval = val;\n\
    \    if (val < 0) {\n      write_single('-');\n      uval = -uval;\n    }\n  \
    \  write_unsigned(uval);\n  }\n\n  template <class T, is_modint_t<T> * = nullptr>\n\
    \  void write_single(const T &val) {\n    write_single(val.val);\n  }\n\n  static\
    \ int bsr(unsigned int n) {\n    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);\n\
    \  }\n  static int bsr(unsigned long n) {\n    return 8 * (int)sizeof(unsigned\
    \ long) - 1 - __builtin_clzl(n);\n  }\n  static int bsr(unsigned long long n)\
    \ {\n    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);\n\
    \  }\n\n  template <class U, is_unsigned_int_t<U> * = nullptr>\n  void write_single(U\
    \ uval) {\n    if (uval == 0) {\n      write_single('0');\n      return;\n   \
    \ }\n    if (pos > SIZE - 50) flush();\n\n    write_unsigned(uval);\n  }\n\n \
    \ template <class U, is_unsigned_int_t<U> * = nullptr>\n  static int calc_len(U\
    \ x) {\n    int i = (bsr(1ULL * x) * 3 + 3) / 10;\n    if (x < tens[i])\n    \
    \  return i;\n    else\n      return i + 1;\n  }\n\n  template <class U, is_unsigned_int_t<U>\
    \ * = nullptr,\n            enable_if_t<2 >= sizeof(U)> * = nullptr>\n  void write_unsigned(U\
    \ uval) {\n    size_t len = calc_len(uval);\n    pos += len;\n\n    char *ptr\
    \ = line.data() + pos;\n    while (uval >= 100) {\n      ptr -= 2;\n      memcpy(ptr,\
    \ small[uval % 100].data(), 2);\n      uval /= 100;\n    }\n    if (uval >= 10)\
    \ {\n      memcpy(ptr - 2, small[uval].data(), 2);\n    } else {\n      *(ptr\
    \ - 1) = char('0' + uval);\n    }\n  }\n\n  template <class U, is_unsigned_int_t<U>\
    \ * = nullptr,\n            enable_if_t<4 == sizeof(U)> * = nullptr>\n  void write_unsigned(U\
    \ uval) {\n    array<char, 8> buf;\n    memcpy(buf.data() + 6, small[uval % 100].data(),\
    \ 2);\n    memcpy(buf.data() + 4, small[uval / 100 % 100].data(), 2);\n    memcpy(buf.data()\
    \ + 2, small[uval / 10000 % 100].data(), 2);\n    memcpy(buf.data() + 0, small[uval\
    \ / 1000000 % 100].data(), 2);\n\n    if (uval >= 100000000) {\n      if (uval\
    \ >= 1000000000) {\n        memcpy(line.data() + pos, small[uval / 100000000 %\
    \ 100].data(), 2);\n        pos += 2;\n      } else {\n        line[pos] = char('0'\
    \ + uval / 100000000);\n        pos++;\n      }\n      memcpy(line.data() + pos,\
    \ buf.data(), 8);\n      pos += 8;\n    } else {\n      size_t len = calc_len(uval);\n\
    \      memcpy(line.data() + pos, buf.data() + (8 - len), len);\n      pos += len;\n\
    \    }\n  }\n\n  template <class U, is_unsigned_int_t<U> * = nullptr,\n      \
    \      enable_if_t<8 == sizeof(U)> * = nullptr>\n  void write_unsigned(U uval)\
    \ {\n    size_t len = calc_len(uval);\n    pos += len;\n\n    char *ptr = line.data()\
    \ + pos;\n    while (uval >= 100) {\n      ptr -= 2;\n      memcpy(ptr, small[uval\
    \ % 100].data(), 2);\n      uval /= 100;\n    }\n    if (uval >= 10) {\n     \
    \ memcpy(ptr - 2, small[uval].data(), 2);\n    } else {\n      *(ptr - 1) = char('0'\
    \ + uval);\n    }\n  }\n\n  template <class U, enable_if_t<is_unsigned_int128<U>::value>\
    \ * = nullptr>\n  void write_unsigned(U uval) {\n    static array<char, 50> buf;\n\
    \    size_t len = 0;\n    while (uval > 0) {\n      buf[len++] = char((uval %\
    \ 10) + '0');\n      uval /= 10;\n    }\n    std::reverse(buf.begin(), buf.begin()\
    \ + len);\n    memcpy(line.data() + pos, buf.data(), len);\n    pos += len;\n\
    \  }\n\n  void write_single(const std::string &s) {\n    for (char c: s) write_single(c);\n\
    \  }\n  void write_single(const char *s) {\n    size_t len = strlen(s);\n    for\
    \ (size_t i = 0; i < len; i++) write_single(s[i]);\n  }\n  template <class T>\n\
    \  void write_single(const std::vector<T> &val) {\n    auto n = val.size();\n\
    \    for (size_t i = 0; i < n; i++) {\n      if (i) write_single(' ');\n     \
    \ write_single(val[i]);\n    }\n  }\n};\n\narray<array<char, 2>, 100> Printer::small\
    \ = [] {\n  array<array<char, 2>, 100> table;\n  for (int i = 0; i <= 99; i++)\
    \ {\n    table[i][1] = char('0' + (i % 10));\n    table[i][0] = char('0' + (i\
    \ / 10 % 10));\n  }\n  return table;\n}();\narray<ull, 20> Printer::tens = []\
    \ {\n  array<ull, 20> table;\n  for (int i = 0; i < 20; i++) {\n    table[i] =\
    \ 1;\n    for (int j = 0; j < i; j++) { table[i] *= 10; }\n  }\n  return table;\n\
    }();\n\n} // namespace yosupo_IO\n\nusing namespace yosupo_IO;\nScanner scanner\
    \ = Scanner(stdin);\nPrinter printer = Printer(stdout);\n\n#define INT(...)  \
    \ \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__; \\\n\
    \  IN(__VA_ARGS__)\n#define CHR(...)    \\\n  char __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define DBL(...)           \\\n  long double __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    void scan(int &a) { scanner.read(a); }\nvoid scan(ll &a) { scanner.read(a); }\n\
    void scan(ull &a) { scanner.read(a); }\nvoid scan(char &a) { scanner.read(a);\
    \ }\nvoid scan(double &a) { scanner.read(a); }\n// void scan(long double &a) {\
    \ scanner.read(a); }\nvoid scan(string &a) { scanner.read(a); }\ntemplate <class\
    \ T, class U>\nvoid scan(pair<T, U> &p) {\n  scan(p.first), scan(p.second);\n\
    }\ntemplate <class A, class B, class C>\nvoid scan(tuple<A, B, C> &p) {\n  scan(get<0>(p)),\
    \ scan(get<1>(p)), scan(get<2>(p));\n}\ntemplate <class A, class B, class C, class\
    \ D>\nvoid scan(tuple<A, B, C, D> &p) {\n  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p)),\
    \ scan(get<3>(p));\n}\ntemplate <class T>\nvoid scan(vector<T> &a) {\n  for (auto\
    \ &&i: a) scan(i);\n}\ntemplate <class T> // modint\nvoid scan(T &a) {\n  ll x;\n\
    \  scanner.read(x);\n  a = x;\n}\nvoid IN() {}\ntemplate <class Head, class...\
    \ Tail>\nvoid IN(Head &head, Tail &... tail) {\n  scan(head);\n  IN(tail...);\n\
    }\n\nvi s_to_vi(string S, char first_char = 'a') {\n  vi A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\nvoid print() { printer.writeln();\
    \ }\ntemplate <class Head, class... Tail>\nvoid print(Head &&head, Tail &&...\
    \ tail) {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write(' ');\n\
    \  print(forward<Tail>(tail)...);\n}\n\nvoid YES(bool t = 1) { print(t ? \"YES\"\
    \ : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t\
    \ ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t =\
    \ 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A) {\n  int N = A.size();\n  vector<T>\
    \ B(N + 1);\n  B[0] = T(0);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  return\
    \ B;\n}\n\nvc<int> bin_count(vi &A, int size) {\n  vc<int> C(size);\n  for (auto\
    \ &x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(vector<T>\
    \ &A) {\n  vector<int> ids(A.size());\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });\n\
    \  return ids;\n}\n\nll binary_search(function<bool(ll)> check, ll ok, ll ng)\
    \ {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok)\
    \ / 2;\n    if (check(x))\n      ok = x;\n    else\n      ng = x;\n  }\n  return\
    \ ok;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n\
    \  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool\
    \ chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n#define SUM(v)\
    \ accumulate(all(v), 0LL)\n#define MIN(v) *min_element(all(v))\n#define MAX(v)\
    \ *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/string/zalgorithm.test.cpp\"\
    \n\r\n#line 1 \"string/zalgorithm.hpp\"\ntemplate <typename STRING>  // string,\
    \ vector \u3069\u3061\u3089\u3067\u3082\nvector<int> z_algorithm(const STRING&\
    \ s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int> z(n);\n\
    \  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n   \
    \ k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k < n\
    \ && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n#line 5 \"test/library_checker/string/zalgorithm.test.cpp\"\
    \n\r\nvoid solve() {\r\n  STR(S);\r\n  auto Z = z_algorithm(S);\r\n  print(Z);\r\
    \n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n#include\
    \ \"my_template.hpp\"\r\n\r\n#include \"string/zalgorithm.hpp\"\r\n\r\nvoid solve()\
    \ {\r\n  STR(S);\r\n  auto Z = z_algorithm(S);\r\n  print(Z);\r\n}\r\n\r\nsigned\
    \ main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout\
    \ << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - string/zalgorithm.hpp
  isVerificationFile: true
  path: test/library_checker/string/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 07:43:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/zalgorithm.test.cpp
- /verify/test/library_checker/string/zalgorithm.test.cpp.html
title: test/library_checker/string/zalgorithm.test.cpp
---
