---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/convexhull.hpp
    title: geo/convexhull.hpp
  - icon: ':x:'
    path: geo/points_diameter.hpp
    title: geo/points_diameter.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/96
    links:
    - https://yukicoder.me/problems/no/96
  bundledCode: "#line 1 \"test/yukicoder/96_points_diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/96\"\n#line 1 \"my_template.hpp\"\n#include\
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
    \ CHAR(...)      \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n\
    #define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\r\n#line 1 \"ds/hashmap.hpp\"\ntemplate <typename Val, int LOG\
    \ = 20>\r\nstruct HashMapLL {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n \
    \ vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const int shift;\r\n  const uint64_t\
    \ r = 11995408973635179863ULL;\r\n  HashMapLL()\r\n      : N(1 << LOG), keys(new\
    \ ll[N]), vals(new Val[N]), shift(64 - __lg(N)) {}\r\n  int hash(ll x) {\r\n \
    \   static const uint64_t FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset(){\r\n    for(auto&& i : IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n};\r\n#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n  int\
    \ comp;\n  vc<int> size, par;\n  UnionFind(int n) : num(n), comp(n), size(n, 1),\
    \ par(n) {\n    iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n \
    \   while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n  \
    \  }\n    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n  bool\
    \ merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x == y) { return\
    \ false; }\n    comp--;\n    if (size[x] < size[y]) swap(x, y);\n    size[x] +=\
    \ size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n  }\n\n  vc<int>\
    \ find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i] = find(i);\n    return\
    \ A;\n  }\n};\n#line 2 \"geo/base.hpp\"\n\ntemplate<typename X = long long>\n\
    struct Point {\n  X x, y;\n  Point(X x=0, X y=0) : x(x), y(y) {}\n\n  template\
    \ <typename S, typename T>\n  Point(pair<S, T> p) : x(p.fi), y(p.se) {}\n\n  Point\
    \ operator+(Point p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point\
    \ p) const { return {x - p.x, y - p.y}; }\n  X det(Point p) const { return x *\
    \ p.y - y * p.x; }\n  X dot(Point p) const { return x * p.x + y * p.y; }\n  pair<double,double>\
    \ polar(){\n    double r = sqrt(x * x + y * y);\n    double theta = atan2(y, x);\n\
    \    return {r, theta};\n  }\n  bool operator<(Point p) const {\n    if (x !=\
    \ p.x) return x < p.x;\n    return y < p.y;\n  }\n  bool operator==(Point p) const\
    \ { return x == p.x && y == p.y; }\n  Point operator-() const { return {-x, -y};\
    \ }\n};\n#line 2 \"geo/convexhull.hpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ ConvexHull(vector<pair<T, T>>& XY, string mode = \"full\",\r\n             \
    \         bool inclusive = false, bool sorted = false) {\r\n  assert(mode == \"\
    full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\n\
    \  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].fi,\
    \ yi = XY[i].se;\r\n    auto xj = XY[j].fi, yj = XY[j].se;\r\n    auto xk = XY[k].fi,\
    \ yk = XY[k].se;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vector<int>\
    \ P;\r\n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto\
    \ i = P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}\r\n\r\ntemplate<typename\
    \ X>\r\nvc<int> ConvexHull(vector<Point<X>>& XY, string mode = \"full\",\r\n \
    \                     bool inclusive = false, bool sorted = false) {\r\n  assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\
    \n  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].x,\
    \ yi = XY[i].y;\r\n    auto xj = XY[j].x, yj = XY[j].y;\r\n    auto xk = XY[k].x,\
    \ yk = XY[k].y;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vc<int> P;\r\
    \n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i =\
    \ P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}\n#line 3 \"geo/points_diameter.hpp\"\
    \n\n// \u6700\u9060\u70B9\u5BFE\u3068\u306A\u308B 2 \u70B9\u306E index \u3092\u304B\
    \u3048\u3059\u3002\u7A7A\u96C6\u5408\u306F\u30A8\u30E9\u30FC\u3002\ntemplate <typename\
    \ T>\npair<int, int> points_diameter(vc<Point<T>>& XY) {\n  ll N = len(XY);\n\
    \  assert(N >= 1);\n  if (N == 1) return {0, 0};\n  auto I = ConvexHull(XY, \"\
    full\");\n  pi res = {0, 0};\n  ll best = 0;\n  ll s = 0;\n  FOR(k, len(I)) {\n\
    \    ll i = (k == 0 ? I.back() : I[k - 1]), j = I[k];\n    Point<T> A = XY[i],\
    \ B = XY[j];\n    ll dx = B.x - A.x, dy = B.y - A.y;\n    Point<T> vec = {-dy,\
    \ dx};\n    while (1) {\n      Point<T> p = XY[I[s]], q = XY[I[(s + 1) % len(I)]];\n\
    \      if (vec.dot(p - q) < 0)\n        s = (s + 1) % len(I);\n      else\n  \
    \      break;\n    }\n    Point<T> C = XY[I[s]];\n    if (chmax(best, (A - C).dot(A\
    \ - C))) res = {i, I[s]};\n    if (chmax(best, (B - C).dot(B - C))) res = {j,\
    \ I[s]};\n  }\n  return res;\n}\n#line 7 \"test/yukicoder/96_points_diameter.test.cpp\"\
    \n\nusing P = Point<ll>;\n\nvoid solve() {\n  LL(N);\n  if (N == 0) return print(1);\n\
    \  vc<P> XY(N);\n  FOR(i, N) {\n    LL(x, y);\n    XY[i] = {x, y};\n  }\n\n  HashMapLL<int>\
    \ MP;\n  auto to_key = [&](P p) -> ll { return p.x * 1e6 + p.y; };\n  FOR(i, N)\
    \ { MP[to_key(XY[i])] = i; }\n\n  UnionFind uf(N);\n  FOR(i, N) {\n    P p = XY[i];\n\
    \    FOR3(dx, 0, 11) FOR3(dy, -10, 11) {\n      if (dx * dx + dy * dy > 100) continue;\n\
    \      if (dx == 0 && dy == 0) continue;\n      P q = p;\n      q.x += dx, q.y\
    \ += dy;\n      ll key = to_key(q);\n      if (!MP.count(key)) continue;\n   \
    \   ll j = MP[key];\n      uf.merge(i, j);\n    }\n  }\n\n  vc<vi> IDS(N);\n \
    \ FOR(v, N) IDS[uf[v]].eb(v);\n\n  using Re = double;\n  Re ANS = 2.0;\n\n  for\
    \ (auto&& I: IDS) {\n    if (len(I) == 0) continue;\n    vc<P> xy;\n    for (auto&&\
    \ i: I) xy.eb(XY[i]);\n    auto [a, b] = points_diameter(xy);\n    P vec = xy[b]\
    \ - xy[a];\n    chmax(ANS, sqrt(Re(vec.dot(vec))) + 2.0);\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/96\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"ds/hashmap.hpp\"\n#include \"ds/unionfind.hpp\"\
    \n#include \"geo/points_diameter.hpp\"\n\nusing P = Point<ll>;\n\nvoid solve()\
    \ {\n  LL(N);\n  if (N == 0) return print(1);\n  vc<P> XY(N);\n  FOR(i, N) {\n\
    \    LL(x, y);\n    XY[i] = {x, y};\n  }\n\n  HashMapLL<int> MP;\n  auto to_key\
    \ = [&](P p) -> ll { return p.x * 1e6 + p.y; };\n  FOR(i, N) { MP[to_key(XY[i])]\
    \ = i; }\n\n  UnionFind uf(N);\n  FOR(i, N) {\n    P p = XY[i];\n    FOR3(dx,\
    \ 0, 11) FOR3(dy, -10, 11) {\n      if (dx * dx + dy * dy > 100) continue;\n \
    \     if (dx == 0 && dy == 0) continue;\n      P q = p;\n      q.x += dx, q.y\
    \ += dy;\n      ll key = to_key(q);\n      if (!MP.count(key)) continue;\n   \
    \   ll j = MP[key];\n      uf.merge(i, j);\n    }\n  }\n\n  vc<vi> IDS(N);\n \
    \ FOR(v, N) IDS[uf[v]].eb(v);\n\n  using Re = double;\n  Re ANS = 2.0;\n\n  for\
    \ (auto&& I: IDS) {\n    if (len(I) == 0) continue;\n    vc<P> xy;\n    for (auto&&\
    \ i: I) xy.eb(XY[i]);\n    auto [a, b] = points_diameter(xy);\n    P vec = xy[b]\
    \ - xy[a];\n    chmax(ANS, sqrt(Re(vec.dot(vec))) + 2.0);\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/hashmap.hpp
  - ds/unionfind.hpp
  - geo/points_diameter.hpp
  - geo/convexhull.hpp
  - geo/base.hpp
  isVerificationFile: true
  path: test/yukicoder/96_points_diameter.test.cpp
  requiredBy: []
  timestamp: '2022-04-11 04:12:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/96_points_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/96_points_diameter.test.cpp
- /verify/test/yukicoder/96_points_diameter.test.cpp.html
title: test/yukicoder/96_points_diameter.test.cpp
---
