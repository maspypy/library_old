---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/beats_summaxmin_chminchmax.hpp
    title: ds/beats_summaxmin_chminchmax.hpp
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree_beats.hpp
    title: ds/lazysegtree_beats.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
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
    \ DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n\
    #define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\r\n#line 2 \"ds/lazysegtree_beats.hpp\"\n\ntemplate <typename Lazy>\n\
    struct LazySegTreeBeats {\n  using Monoid_X = typename Lazy::X_structure;\n  using\
    \ Monoid_A = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTreeBeats() : LazySegTreeBeats(0) {}\n  LazySegTreeBeats(int\
    \ n) : LazySegTreeBeats(vc<X>(n, Monoid_X::unit)) {}\n  LazySegTreeBeats(vc<X>\
    \ v) : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit);\n    laz.assign(size,\
    \ Monoid_A::unit);\n    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size)\
    \ update(i);\n  }\n\n  void update(int k) { dat[k] = Monoid_X::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n\n  void all_apply(int k, A a) {\n    dat[k] = Lazy::act(dat[k],\
    \ a);\n    if (k < size) {\n      laz[k] = Monoid_A::op(laz[k], a);\n      if\
    \ (dat[k].fail) push(k), update(k);\n    }\n  }\n\n  void push(int k) {\n    all_apply(2\
    \ * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit;\n\
    \  }\n\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(i, size) push(i);\n\
    \    return {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return\
    \ Monoid_X::unit;\n\n    l += size;\n    r += size;\n\n    for (int i = log; i\
    \ >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >>\
    \ i) << i) != r) push((r - 1) >> i);\n    }\n\n    X xl = Monoid_X::unit, xr =\
    \ Monoid_X::unit;\n    while (l < r) {\n      if (l & 1) xl = Monoid_X::op(xl,\
    \ dat[l++]);\n      if (r & 1) xr = Monoid_X::op(dat[--r], xr);\n      l >>= 1;\n\
    \      r >>= 1;\n    }\n\n    return Monoid_X::op(xl, xr);\n  }\n\n  X prod_all()\
    \ { return dat[1]; }\n\n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    if (!Monoid_A::commute)\n      for (int i = log; i >= 1;\
    \ i--) push(p >> i);\n    dat[p] = Lazy::act(dat[p], a);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r, A a) {\n \
    \   assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if\
    \ (l & 1) all_apply(l++, a);\n        if (r & 1) all_apply(--r, a);\n        l\
    \ >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n \
    \   for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l\
    \ >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n\
    \  template <typename C>\n  int max_right(C& check, int l) {\n    assert(0 <=\
    \ l && l <= n);\n    assert(check(Monoid_X::unit));\n    if (l == n) return n;\n\
    \    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n    X sm =\
    \ Monoid_X::unit;\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(Monoid_X::op(sm,\
    \ dat[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (check(Monoid_X::op(sm, dat[l]))) {\n            sm = Monoid_X::op(sm,\
    \ dat[l]);\n            l++;\n          }\n        }\n        return l - size;\n\
    \      }\n      sm = Monoid_X::op(sm, dat[l]);\n      l++;\n    } while ((l &\
    \ -l) != l);\n    return n;\n  }\n\n  template <typename C>\n  int min_left(C&\
    \ check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(Monoid_X::unit));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = Monoid_X::unit;\n    do {\n      r--;\n    \
    \  while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(Monoid_X::op(dat[r], sm)))\
    \ {\n        while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n\
    \          if (check(Monoid_X::op(dat[r], sm))) {\n            sm = Monoid_X::op(dat[r],\
    \ sm);\n            r--;\n          }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = Monoid_X::op(dat[r], sm);\n    } while ((r & -r) != r);\n\
    \    return 0;\n  }\n\n  void debug() { print(\"lazysegtree getall:\", get_all());\
    \ }\n};\n#line 2 \"ds/beats_summaxmin_chminchmax.hpp\"\n\r\nconst ll INF = 1LL\
    \ << 40;\r\n\r\nstruct Beats_SumMaxMin_ChminChmax {\r\n  struct CntSumMinMax {\r\
    \n    struct X {\r\n      ll cnt, sum, min, max, minc, maxc, min2, max2;\r\n \
    \     bool fail;\r\n    };\r\n    using value_type = X;\r\n    static X op(const\
    \ X& x, const X& y) {\r\n      if (x.min > x.max) return y;\r\n      if (y.min\
    \ > y.max) return x;\r\n      X z;\r\n      z.cnt = x.cnt + y.cnt, z.sum = x.sum\
    \ + y.sum;\r\n\r\n      z.min = min(x.min, y.min), z.max = max(x.max, y.max);\r\
    \n      z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\r\
    \n      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\r\
    \n\r\n      z.min2 = z.max;\r\n      if (z.min < x.min && x.min < z.min2) z.min2\
    \ = x.min;\r\n      if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\r\n\
    \      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\r\n      if (z.min\
    \ < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\r\n\r\n      z.max2 = z.min;\r\
    \n      if (z.max > x.max && x.max > z.max2) z.max2 = x.max;\r\n      if (z.max\
    \ > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\r\n      if (z.max > y.max &&\
    \ y.max > z.max2) z.max2 = y.max;\r\n      if (z.max > y.max2 && y.max2 > z.max2)\
    \ z.max2 = y.max2;\r\n\r\n      z.fail = 0;\r\n      return z;\r\n    }\r\n  \
    \  static constexpr X unit = {0, 0, INF, -INF, 0, 0, INF, -INF, 0};\r\n    bool\
    \ commute = true;\r\n  };\r\n\r\n  struct AddChminChmax {\r\n    struct X {\r\n\
    \      ll add, min, max;\r\n    };\r\n    using value_type = X;\r\n    static\
    \ constexpr X op(const X& x, const X& y) {\r\n      auto [a, b, c] = x;\r\n  \
    \    auto [d, e, f] = y;\r\n      a += d, b += d, c += d;\r\n      b = min(b,\
    \ e), c = min(c, e);\r\n      c = max(c, f);\r\n      return {a, b, c};\r\n  \
    \  }\r\n    static constexpr X unit = {0, INF, -INF};\r\n    bool commute = false;\r\
    \n  };\r\n  struct Lazy {\r\n    using MX = CntSumMinMax;\r\n    using MA = AddChminChmax;\r\
    \n    using X_structure = MX;\r\n    using A_structure = MA;\r\n    using X =\
    \ MX::value_type;\r\n    using A = MA::value_type;\r\n    static X act(X& x, const\
    \ A& a) {\r\n      assert(!x.fail);\r\n      if (x.cnt == 0) return x;\r\n   \
    \   x.sum += x.cnt * a.add;\r\n      x.min += a.add, x.max += a.add;\r\n     \
    \ x.min2 += a.add, x.max2 += a.add;\r\n\r\n      if (a.min == INF && a.max ==\
    \ -INF) return x;\r\n\r\n      ll before_min = x.min, before_max = x.max;\r\n\
    \      x.min = min(x.min, a.min);\r\n      x.min = max(x.min, a.max);\r\n    \
    \  x.max = min(x.max, a.min);\r\n      x.max = max(x.max, a.max);\r\n\r\n    \
    \  if (x.min == x.max) {\r\n        x.sum = x.max * x.cnt;\r\n        x.max2 =\
    \ x.min2 = x.max;\r\n        x.maxc = x.minc = x.cnt;\r\n      }\r\n      elif\
    \ (x.max2 <= x.min) {\r\n        x.max2 = x.min, x.min2 = x.max;\r\n        x.minc\
    \ = x.cnt - x.maxc;\r\n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n  \
    \    }\r\n      elif (x.min2 >= x.max) {\r\n        x.max2 = x.min, x.min2 = x.max;\r\
    \n        x.maxc = x.cnt - x.minc;\r\n        x.sum = x.max * x.maxc + x.min *\
    \ x.minc;\r\n      }\r\n      elif (x.min < x.min2 && x.max > x.max2) {\r\n  \
    \      x.sum += (x.min - before_min) * x.minc;\r\n        x.sum += (x.max - before_max)\
    \ * x.maxc;\r\n      }\r\n      else {\r\n        x.fail = 1;\r\n      }\r\n \
    \     return x;\r\n    }\r\n  };\r\n\r\n  LazySegTreeBeats<Lazy> seg;\r\n\r\n\
    \  Beats_SumMaxMin_ChminChmax(vc<ll>& A) {\r\n    using X = Lazy::MX::value_type;\r\
    \n    vc<X> seg_raw(len(A));\r\n    FOR(i, len(A)) {\r\n      ll x = A[i];\r\n\
    \      seg_raw[i] = {1, x, x, x, 1, 1, x, x, 0};\r\n    }\r\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\r\
    \n  }\r\n\r\n  void set(int i, ll x) { seg.set(i, {1, x, x, x, 1, 1, x, x, 0});\
    \ }\r\n\r\n  Lazy::MX::value_type prod(int l, int r) {\r\n    auto e = seg.prod(l,\
    \ r);\r\n    return e;\r\n  }\r\n\r\n  void chmin(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, x, -INF}); }\r\n\r\n  void chmax(int l, int r, ll x) { seg.apply(l, r,\
    \ {0, INF, x}); }\r\n\r\n  void add(int l, int r, ll x) { seg.apply(l, r, {x,\
    \ INF, -INF}); }\r\n};\r\n#line 7 \"test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Beats_SumMaxMin_ChminChmax\
    \ seg(A);\r\n  FOR(_, Q) {\r\n    LL(t, L, R);\r\n    if (t == 0) {\r\n      LL(x);\r\
    \n      seg.chmin(L, R, x);\r\n    }\r\n    elif (t == 1) {\r\n      LL(x);\r\n\
    \      seg.chmax(L, R, x);\r\n    }\r\n    elif (t == 2) {\r\n      LL(x);\r\n\
    \      seg.add(L, R, x);\r\n    }\r\n    elif (t == 3) {\r\n      auto x = seg.prod(L,\
    \ R);\r\n      print(x.sum);\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n \
    \ cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include\
    \ \"ds/beats_summaxmin_chminchmax.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\
    \n  VEC(ll, A, N);\r\n  Beats_SumMaxMin_ChminChmax seg(A);\r\n  FOR(_, Q) {\r\n\
    \    LL(t, L, R);\r\n    if (t == 0) {\r\n      LL(x);\r\n      seg.chmin(L, R,\
    \ x);\r\n    }\r\n    elif (t == 1) {\r\n      LL(x);\r\n      seg.chmax(L, R,\
    \ x);\r\n    }\r\n    elif (t == 2) {\r\n      LL(x);\r\n      seg.add(L, R, x);\r\
    \n    }\r\n    elif (t == 3) {\r\n      auto x = seg.prod(L, R);\r\n      print(x.sum);\r\
    \n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/beats_summaxmin_chminchmax.hpp
  - ds/lazysegtree_beats.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 20:39:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
---
