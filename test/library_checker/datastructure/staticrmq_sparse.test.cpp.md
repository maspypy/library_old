---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/disjointsparse.hpp
    title: ds/disjointsparse.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/datastructure/staticrmq_sparse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"my_template.hpp\"\
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
    #define mt make_tuple\n#define fi first\n#define se second\n\ntemplate <typename\
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - __builtin_clz(x);\
    \ }\nint topbit(u32 x) { return 31 - __builtin_clz(x); }\nint topbit(ll x) { return\
    \ 63 - __builtin_clzll(x); }\nint topbit(u64 x) { return 63 - __builtin_clzll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return\
    \ 31 - __builtin_clz(x); }\nint lowbit(u32 x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(ll x) { return 63 - __builtin_clzll(x); }\nint lowbit(u64 x) {\
    \ return 63 - __builtin_clzll(x); }\n\ntemplate <typename T, typename U>\nT ceil(T\
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
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename T>\nvc<int> bincount(vc<T>\
    \ &A, int size) {\n  vc<int> C(size);\n  for (auto &&x: A) { ++C[x]; }\n  return\
    \ C;\n}\n\ntemplate <typename T>\nvector<int> argsort(vector<T> &A) {\n  // stable\n\
    \  vector<int> ids(A.size());\n  iota(all(ids), 0);\n  sort(all(ids),\n      \
    \ [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });\n  return\
    \ ids;\n}\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
    \n\r\nnamespace detail {\r\ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\r\
    \nstd::true_type check_value(int);\r\ntemplate <typename T>\r\nstd::false_type\
    \ check_value(long);\r\n} // namespace detail\r\n\r\ntemplate <typename T>\r\n\
    struct is_modint : decltype(detail::check_value<T>(0)) {};\r\ntemplate <typename\
    \ T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\ntemplate <typename\
    \ T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\n\r\nstruct\
    \ Scanner {\r\n  FILE* fp;\r\n  char line[(1 << 15) + 1];\r\n  size_t st = 0,\
    \ ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\n \
    \   ed -= st;\r\n    st = 0;\r\n    ed += fread(line + ed, 1, (1 << 15) - ed,\
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
    \n  }\r\n};\r\n\r\nScanner scanner = Scanner(stdin);\r\nPrinter printer = Printer(stdout);\r\
    \n\r\nvoid flush() { printer.flush(); }\r\nvoid print() { printer.write('\\n');\
    \ }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&...\
    \ tail) {\r\n  printer.write(head);\r\n  if (sizeof...(Tail)) printer.write('\
    \ ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read() {}\r\ntemplate\
    \ <class Head, class... Tail>\r\nvoid read(Head &head, Tail &... tail) {\r\n \
    \ scanner.read(head);\r\n  read(tail...);\r\n}\r\n\r\n#define INT(...)   \\\r\n\
    \  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll\
    \ __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n  string\
    \ __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)           \\\r\n\
    \  long double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 4 \"test/library_checker/datastructure/staticrmq_sparse.test.cpp\"\
    \n\n#line 1 \"alg/monoid_min.hpp\"\ntemplate <class X=long long, X INF=1LL<<60>\r\
    \nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit\
    \ = INF;\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/disjointsparse.hpp\"\
    \ntemplate <class Monoid>\r\nstruct DisjointSparse {\r\n  using X = typename Monoid::value_type;\r\
    \n  using value_type = X;\r\n  int n, log;\r\n  vc<vc<X>> dat;\r\n\r\n  DisjointSparse(vc<X>&\
    \ A) : n(len(A)) {\r\n    log = 1;\r\n    while ((1 << log) < n) ++log;\r\n  \
    \  dat.assign(log, A);\r\n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\n\
    \      int b = 1 << i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n    \
    \    int L = m - b, R = min(n, m + b);\r\n        FOR3_R(j, L + 1, m) v[j - 1]\
    \ = Monoid::op(v[j - 1], v[j]);\r\n        FOR3(j, m, R - 1) v[j + 1] = Monoid::op(v[j],\
    \ v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n  \
    \  if (L == R) return Monoid::unit;\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\
    \n    int k = 31 - __builtin_clz(L ^ R);\r\n    return Monoid::op(dat[k][L], dat[k][R]);\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"disjoint sparse table\");\r\n   \
    \ FOR(i, log) print(dat[i]);\r\n  }\r\n};\r\n#line 7 \"test/library_checker/datastructure/staticrmq_sparse.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(int, A, N);\n  using Mono = Monoid_Min<int,\
    \ 1 << 30>;\n  DisjointSparse<Mono> DS(A);\n\n  FOR(_, Q) {\n    LL(L, R);\n \
    \   print(DS.prod(L, R));\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/monoid_min.hpp\"\
    \n#include \"ds/disjointsparse.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(int,\
    \ A, N);\n  using Mono = Monoid_Min<int, 1 << 30>;\n  DisjointSparse<Mono> DS(A);\n\
    \n  FOR(_, Q) {\n    LL(L, R);\n    print(DS.prod(L, R));\n  }\n}\n\nsigned main()\
    \ {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid_min.hpp
  - ds/disjointsparse.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  requiredBy: []
  timestamp: '2022-02-11 06:59:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/staticrmq_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/staticrmq_sparse.test.cpp
- /verify/test/library_checker/datastructure/staticrmq_sparse.test.cpp.html
title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
---
