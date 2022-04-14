---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/centroid.hpp
    title: graph/centroid.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1038
    links:
    - https://yukicoder.me/problems/no/1038
  bundledCode: "#line 1 \"test/yukicoder/1038_centroid.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1038\"\r\n#line 1 \"my_template.hpp\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing pi =\
    \ pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\nusing vc\
    \ = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
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
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint lowbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint lowbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n\ntemplate <typename T, typename U>\n\
    T ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
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
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  int n = len(A);\n  assert(len(I) == n);\n \
    \ vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n}\n#line 1 \"other/io.hpp\"\
    \n// based on yosupo's fastio\r\n#include <unistd.h>\r\n\r\nnamespace detail {\r\
    \ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\r\nstd::true_type\
    \ check_value(int);\r\ntemplate <typename T>\r\nstd::false_type check_value(long);\r\
    \n} // namespace detail\r\n\r\ntemplate <typename T>\r\nstruct is_modint : decltype(detail::check_value<T>(0))\
    \ {};\r\ntemplate <typename T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\
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
    \ return false;\r\n    ref = std::stod(s);\r\n    return true;\r\n  }\r\n  bool\
    \ read_single(char &ref) {\r\n    string s;\r\n    if (!read_single(s) || s.size()\
    \ != 1) return false;\r\n    ref = s[0];\r\n    return true;\r\n  }\r\n  template\
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
    \    ostringstream oss;\r\n    oss << setprecision(15) << x;\r\n    string s =\
    \ oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double &x) {\r\
    \n    ostringstream oss;\r\n    oss << setprecision(15) << x;\r\n    string s\
    \ = oss.str();\r\n    write(s);\r\n  }\r\n  template <class T, is_modint_t<T>\
    \ * = nullptr>\r\n  void write(T &ref) {\r\n    write(ref.val);\r\n  }\r\n  template\
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
    \ write(i128 val) {\r\n    string s;\r\n    bool negative = 0;\r\n    if(val <\
    \ 0){\r\n      negative = 1;\r\n      val = -val;\r\n    }\r\n    while (val)\
    \ {\r\n      s += '0' + int(val % 10);\r\n      val /= 10;\r\n    }\r\n    if(negative)\
    \ s += \"-\";\r\n    reverse(all(s));\r\n    if (len(s) == 0) s = \"0\";\r\n \
    \   write(s);\r\n  }\r\n};\r\n\r\nScanner scanner = Scanner(stdin);\r\nPrinter\
    \ printer = Printer(stdout);\r\n\r\nvoid flush() { printer.flush(); }\r\nvoid\
    \ print() { printer.write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\n\
    void print(Head &&head, Tail &&... tail) {\r\n  printer.write(head);\r\n  if (sizeof...(Tail))\
    \ printer.write(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  scanner.read(head);\r\n  read(tail...);\r\n}\r\n\r\n#define INT(...)\
    \   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\
    \r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)      \\\r\
    \n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n#line\
    \ 4 \"test/yukicoder/1038_centroid.test.cpp\"\n\r\n#line 2 \"alg/group_add.hpp\"\
    \ntemplate <class X>\r\nstruct Group_Add {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr\
    \ X power(const X &x, ll n) noexcept { return n * x; }\r\n  static constexpr X\
    \ unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n\
    #line 3 \"ds/fenwick.hpp\"\n\ntemplate <typename AbelGroup>\nstruct FenwickTree\
    \ {\n  using E = typename AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n  FenwickTree(int n) : n(n),\
    \ total(AbelGroup::unit()) {\n    assert(AbelGroup::commute);\n    dat.assign(n,\
    \ AbelGroup::unit());\n  }\n  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit())\
    \ {\n    assert(AbelGroup::commute);\n    FOR(i, n) total = AbelGroup::op(total,\
    \ v[i]);\n    dat = v;\n    FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n\
    \      if (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n\
    \  }\n\n  void reset(){\n    total = AbelGroup::unit();\n    dat.assign(n, AbelGroup::unit());\n\
    \  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit();\n    for (; k > 0; k\
    \ -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return ret;\n  }\n\n \
    \ E sum(int L, int R) {\n    E pos = AbelGroup::unit();\n    while (L < R) {\n\
    \      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n    }\n    E\
    \ neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total\
    \ = AbelGroup::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] =\
    \ AbelGroup::op(dat[k - 1], x);\n  }\n\n  template <class F>\n  int max_right(F&\
    \ check) {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n\
    \    int k = 1;\n    int N = len(dat) + 1;\n    while (2 * k < N) k *= 2;\n  \
    \  while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"graph/base.hpp\"\n\
    \ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int\
    \ N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\
    \n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l,\
    \ int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n     \
    \ if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const\
    \ edge_type* end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared\
    \ && 0 <= frm && 0 <= to);\n    chmax(N, frm + 1);\n    chmax(N, to + 1);\n  \
    \  if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    FOR_(M) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int\
    \ off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p,\
    \ v);\n    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n\
    \    csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n     \
    \ csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n        csr_edges[counter[e.to]++]\
    \ = edge_type({e.to, e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int\
    \ v) const {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n\
    \  }\n\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 2 \"graph/centroid.hpp\"\ntemplate <typename Graph>\r\n\
    vc<int> find_centroids(Graph& G) {\r\n  int N = G.N;\r\n  vc<int> par(N, -1);\r\
    \n  vc<int> V(N);\r\n  vc<int> sz(N);\r\n  int l = 0, r = 0;\r\n  V[r++] = 0;\r\
    \n  while (l < r) {\r\n    int v = V[l++];\r\n    for (auto&& e: G[v])\r\n   \
    \   if (e.to != par[v]) {\r\n        par[e.to] = v;\r\n        V[r++] = e.to;\r\
    \n      }\r\n  }\r\n  FOR_R(i, N) {\r\n    int v = V[i];\r\n    sz[v] += 1;\r\n\
    \    int p = par[v];\r\n    if (p != -1) sz[p] += sz[v];\r\n  }\r\n\r\n  int M\
    \ = N / 2;\r\n  auto check = [&](int v) -> bool {\r\n    if (N - sz[v] > M) return\
    \ false;\r\n    for (auto&& e: G[v]) {\r\n      if (e.to != par[v] && sz[e.to]\
    \ > M) return false;\r\n    }\r\n    return true;\r\n  };\r\n  vc<int> ANS;\r\n\
    \  FOR(v, N) if (check(v)) ANS.eb(v);\r\n  return ANS;\r\n}\r\n\r\ntemplate <typename\
    \ Graph, typename E = int>\r\nstruct CentroidDecomposition {\r\n  using edge_type\
    \ = typename Graph::edge_type;\r\n  using F = function<E(E, edge_type)>;\r\n \
    \ Graph& G;\r\n  int N;\r\n  F f; // (E path value, edge e) -> E new_path_value\r\
    \n  vc<int> sz;\r\n  vc<int> par;\r\n  vector<int> cdep; // depth in centroid\
    \ tree\r\n  bool calculated;\r\n\r\n  CentroidDecomposition(\r\n      Graph& G,\
    \ F f = [](int x, edge_type e) { return x + e.cost; })\r\n      : G(G), N(G.N),\
    \ f(f), sz(G.N), par(G.N), cdep(G.N, -1) {\r\n    calculated = 0;\r\n    build();\r\
    \n  }\r\nprivate:\r\n  int find(int v) {\r\n    vc<int> V = {v};\r\n    par[v]\
    \ = -1;\r\n    int p = 0;\r\n    while (p < len(V)) {\r\n      int v = V[p++];\r\
    \n      sz[v] = 0;\r\n      for (auto&& e: G[v]) {\r\n        if (e.to == par[v]\
    \ || cdep[e.to] != -1) continue;\r\n        par[e.to] = v;\r\n        V.eb(e.to);\r\
    \n      }\r\n    }\r\n    while (len(V)) {\r\n      int v = V.back();\r\n    \
    \  V.pop_back();\r\n      sz[v] += 1;\r\n      if (p - sz[v] <= p / 2) return\
    \ v;\r\n      sz[par[v]] += sz[v];\r\n    }\r\n    return -1;\r\n  }\r\n  void\
    \ build() {\r\n    assert(G.is_prepared());\r\n    assert(!G.is_directed());\r\
    \n    assert(!calculated);\r\n    calculated = 1;\r\n\r\n    vc<pair<int, int>>\
    \ st;\r\n    st.eb(0, 0);\r\n    while (!st.empty()) {\r\n      auto [lv, v] =\
    \ st.back();\r\n      st.pop_back();\r\n      auto c = find(v);\r\n      cdep[c]\
    \ = lv;\r\n      for (auto&& e: G[c]) {\r\n        if (cdep[e.to] == -1) { st.eb(lv\
    \ + 1, e.to); }\r\n      }\r\n    }\r\n  }\r\n\r\npublic:\r\n  vc<vc<pair<int,\
    \ E>>> collect(int root, E root_val) {\r\n    /*\r\n    root \u3092\u91CD\u5FC3\
    \u3068\u3059\u308B\u6728\u306B\u304A\u3044\u3066\u3001(v, path data v) \u306E\
    \ vector\r\n    \u3092\u3001\u65B9\u5411\u3054\u3068\u306B\u96C6\u3081\u3066\u8FD4\
    \u3059 \u30FB0 \u756A\u76EE\uFF1Aroot \u304B\u3089\u306E\u30D1\u30B9\u3059\u3079\
    \u3066\uFF08root \u3092\u542B\u3080\uFF09 \u30FBi\r\n    \u756A\u76EE\uFF1Ai \u756A\
    \u76EE\u306E\u65B9\u5411\r\n    */\r\n    vc<vc<pair<int, E>>> res = {{{root,\
    \ root_val}}};\r\n    for (auto&& e: G[root]) {\r\n      int nxt = e.to;\r\n \
    \     if (cdep[nxt] < cdep[root]) continue;\r\n      vc<pair<int, E>> dat;\r\n\
    \      int p = 0;\r\n      dat.eb(nxt, f(root_val, e));\r\n      par[nxt] = root;\r\
    \n      while (p < len(dat)) {\r\n        auto [v, val] = dat[p++];\r\n      \
    \  for (auto&& e: G[v]) {\r\n          if (e.to == par[v]) continue;\r\n     \
    \     if (cdep[e.to] < cdep[root]) continue;\r\n          par[e.to] = v;\r\n \
    \         dat.eb(e.to, f(val, e));\r\n        }\r\n      }\r\n      res.eb(dat);\r\
    \n      res[0].insert(res[0].end(), all(dat));\r\n    }\r\n    return res;\r\n\
    \  }\r\n};\r\n#line 7 \"test/yukicoder/1038_centroid.test.cpp\"\n\r\nvoid solve()\
    \ {\r\n  LL(N, Q);\r\n  Graph<int> G(N);\r\n  G.read_tree();\r\n\r\n  using T\
    \ = tuple<ll, ll, ll>;\r\n  VEC(T, query, Q);\r\n  for (auto&& [a, b, c]: query)\
    \ --a;\r\n\r\n  // \u9802\u70B9 -> \u30AF\u30A8\u30EA\r\n  vc<vi> query_at(N);\r\
    \n  FOR(q, Q) query_at[get<0>(query[q])].eb(q);\r\n\r\n  CentroidDecomposition\
    \ CD(G);\r\n  vi ANS(Q);\r\n  FenwickTree<Group_Add<ll>> bit(N + 10);\r\n\r\n\
    \  FOR(root, N) {\r\n    auto dats = CD.collect(root, 0);\r\n    FOR(i, len(dats))\
    \ {\r\n      auto dat = dats[i];\r\n      // qid, v, dv\r\n      vc<T> event;\r\
    \n      for (auto&& [v, dv]: dat) {\r\n        for (auto&& q: query_at[v]) { event.eb(q,\
    \ v, dv); }\r\n      }\r\n      sort(all(event));\r\n      for (auto&& [qid, v,\
    \ dv]: event) {\r\n        auto [_, y, z] = query[qid];\r\n        ll add = bit.sum(0,\
    \ dv + 1);\r\n        ANS[qid] += (i == 0 ? add : -add);\r\n        if (dv <=\
    \ y) {\r\n          bit.add(0, z);\r\n          bit.add(y - dv + 1, -z);\r\n \
    \       }\r\n      }\r\n      for (auto&& [qid, v, dv]: event) {\r\n        auto\
    \ [_, y, z] = query[qid];\r\n        if (dv <= y) {\r\n          bit.add(0, -z);\r\
    \n          bit.add(y - dv + 1, +z);\r\n        }\r\n      }\r\n    }\r\n  }\r\
    \n  for (auto&& x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  ll T\
    \ = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1038\"\r\n#include \"\
    my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include \"ds/fenwick.hpp\"\
    \r\n#include \"graph/centroid.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n \
    \ Graph<int> G(N);\r\n  G.read_tree();\r\n\r\n  using T = tuple<ll, ll, ll>;\r\
    \n  VEC(T, query, Q);\r\n  for (auto&& [a, b, c]: query) --a;\r\n\r\n  // \u9802\
    \u70B9 -> \u30AF\u30A8\u30EA\r\n  vc<vi> query_at(N);\r\n  FOR(q, Q) query_at[get<0>(query[q])].eb(q);\r\
    \n\r\n  CentroidDecomposition CD(G);\r\n  vi ANS(Q);\r\n  FenwickTree<Group_Add<ll>>\
    \ bit(N + 10);\r\n\r\n  FOR(root, N) {\r\n    auto dats = CD.collect(root, 0);\r\
    \n    FOR(i, len(dats)) {\r\n      auto dat = dats[i];\r\n      // qid, v, dv\r\
    \n      vc<T> event;\r\n      for (auto&& [v, dv]: dat) {\r\n        for (auto&&\
    \ q: query_at[v]) { event.eb(q, v, dv); }\r\n      }\r\n      sort(all(event));\r\
    \n      for (auto&& [qid, v, dv]: event) {\r\n        auto [_, y, z] = query[qid];\r\
    \n        ll add = bit.sum(0, dv + 1);\r\n        ANS[qid] += (i == 0 ? add :\
    \ -add);\r\n        if (dv <= y) {\r\n          bit.add(0, z);\r\n          bit.add(y\
    \ - dv + 1, -z);\r\n        }\r\n      }\r\n      for (auto&& [qid, v, dv]: event)\
    \ {\r\n        auto [_, y, z] = query[qid];\r\n        if (dv <= y) {\r\n    \
    \      bit.add(0, -z);\r\n          bit.add(y - dv + 1, +z);\r\n        }\r\n\
    \      }\r\n    }\r\n  }\r\n  for (auto&& x: ANS) print(x);\r\n}\r\n\r\nsigned\
    \ main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout\
    \ << setprecision(15);\r\n\r\n  ll T = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/fenwick.hpp
  - alg/group_add.hpp
  - graph/centroid.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test/yukicoder/1038_centroid.test.cpp
  requiredBy: []
  timestamp: '2022-04-14 19:49:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/1038_centroid.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1038_centroid.test.cpp
- /verify/test/yukicoder/1038_centroid.test.cpp.html
title: test/yukicoder/1038_centroid.test.cpp
---
