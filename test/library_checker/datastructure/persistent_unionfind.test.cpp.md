---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: pds/array.hpp
    title: pds/array.hpp
  - icon: ':x:'
    path: pds/unionfind.hpp
    title: pds/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library_checker/datastructure/persistent_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\
    #line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \ { yes(!t); }\r\n#line 4 \"test/library_checker/datastructure/persistent_unionfind.test.cpp\"\
    \n\r\n#line 2 \"pds/array.hpp\"\n\r\ntemplate <typename T, int shift = 4>\r\n\
    struct PersistentArray {\r\n  struct node;\r\n  using np = node*;\r\n  struct\
    \ node {\r\n    T data;\r\n    np ch[1 << shift] = {};\r\n  };\r\n\r\n  static\
    \ constexpr int mask = (1 << shift) - 1;\r\n  np root = nullptr;\r\n  PersistentArray()\
    \ {}\r\n  np get_root() { return root; }\r\n  T get(np t, int idx) {\r\n    if\
    \ (!t) return 0;\r\n    if (idx == 0) {\r\n      return t->data;\r\n    } else\
    \ {\r\n      return get(t->ch[idx & mask], idx >> shift);\r\n    }\r\n  }\r\n\r\
    \n  void destructive_set(np& t, int idx, T val) {\r\n    // \u7834\u58CA\u7684\
    \u306A\u5024\u306E\u5909\u66F4\u3002\u4E3B\u306B\u521D\u671F\u5316\u306B\u4F7F\
    \u3046\u3002\r\n    if (!t) t = new node();\r\n    if (idx == 0)\r\n      t->data\
    \ = val;\r\n    else {\r\n      destructive_set(t->ch[idx & mask], idx >> shift,\
    \ val);\r\n    }\r\n  }\r\n\r\n  np set(const np& t, int idx, T val) {\r\n   \
    \ // set \u3057\u305F\u3042\u3068\u306E\u6C38\u7D9A\u914D\u5217\u306E root node\
    \ pointer \u3092\u8FD4\u3059\r\n    np res = new node();\r\n    if (t) {\r\n \
    \     memcpy(res->ch, t->ch, sizeof(t->ch));\r\n      res->data = t->data;\r\n\
    \    }\r\n    if (idx == 0) {\r\n      res->data = val;\r\n    } else {\r\n  \
    \    res->ch[idx & mask] = set(res->ch[idx & mask], idx >> shift, val);\r\n  \
    \  }\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"pds/unionfind.hpp\"\n\r\nstruct\
    \ PersistentUnionFind {\r\n  using PA = PersistentArray<int>;\r\n  int n;\r\n\
    \  PA data; // root OR (-size)\r\n  using np = PA::np;\r\n\r\n  PersistentUnionFind(int\
    \ n) : n(n) {}\r\n  np init() {\r\n    np t = data.get_root();\r\n    FOR(i, n)\
    \ data.destructive_set(t, i, -1);\r\n    return t;\r\n  }\r\n\r\n  pair<bool,\
    \ np> merge(np t, int x, int y) {\r\n    x = root(t, x), y = root(t, y);\r\n \
    \   if (x == y) return {0, t};\r\n    if (data.get(t, x) > data.get(t, y)) swap(x,\
    \ y);\r\n    int new_sz = data.get(t, x) + data.get(t, y);\r\n    np set_x_sz\
    \ = data.set(t, x, new_sz);\r\n    np set_y_par = data.set(set_x_sz, y, x);\r\n\
    \    return {1, set_y_par};\r\n  }\r\n\r\n  int root(np t, int x) {\r\n    int\
    \ par_or_sz = data.get(t, x);\r\n    if (par_or_sz < 0) return x;\r\n    return\
    \ root(t, par_or_sz);\r\n  }\r\n\r\n  bool same(np t, int x, int y) { return root(t,\
    \ x) == root(t, y); }\r\n  int size(np t, int x) { return -data.get(t, root(t,\
    \ x)); }\r\n};\n#line 6 \"test/library_checker/datastructure/persistent_unionfind.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n\r\n  PersistentUnionFind uf(N);\r\n  using\
    \ np = PersistentUnionFind::np;\r\n  vc<np> UFS;\r\n\r\n  UFS.reserve(Q + 1);\r\
    \n  UFS.eb(uf.init());\r\n\r\n  FOR3(q, 1, Q + 1) {\r\n    LL(t, k, u, v);\r\n\
    \    ++k;\r\n    if (t == 0) {\r\n      UFS.eb(uf.merge(UFS[k], u, v).se);\r\n\
    \    } else {\r\n      print(uf.same(UFS[k], u, v));\r\n      UFS.eb(UFS[q - 1]);\r\
    \n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include \"\
    pds/unionfind.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n\r\n  PersistentUnionFind\
    \ uf(N);\r\n  using np = PersistentUnionFind::np;\r\n  vc<np> UFS;\r\n\r\n  UFS.reserve(Q\
    \ + 1);\r\n  UFS.eb(uf.init());\r\n\r\n  FOR3(q, 1, Q + 1) {\r\n    LL(t, k, u,\
    \ v);\r\n    ++k;\r\n    if (t == 0) {\r\n      UFS.eb(uf.merge(UFS[k], u, v).se);\r\
    \n    } else {\r\n      print(uf.same(UFS[k], u, v));\r\n      UFS.eb(UFS[q -\
    \ 1]);\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - pds/unionfind.hpp
  - pds/array.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-04-14 18:25:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/persistent_unionfind.test.cpp
- /verify/test/library_checker/datastructure/persistent_unionfind.test.cpp.html
title: test/library_checker/datastructure/persistent_unionfind.test.cpp
---
