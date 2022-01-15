---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/group_affine.hpp
    title: alg/group_affine.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
    \n\r\nnamespace detail {\r\ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\r\
    \nstd::true_type check_value(int);\r\ntemplate <typename T>\r\nstd::false_type\
    \ check_value(long);\r\n} // namespace detail\r\n\r\ntemplate <typename T>\r\n\
    struct is_modint : decltype(detail::check_value<T>(0)) {};\r\ntemplate <typename\
    \ T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\ntemplate <typename\
    \ T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\n\r\nstruct\
    \ Scanner {\r\n  int fd = -1;\r\n  char line[(1 << 15) + 1];\r\n  size_t st =\
    \ 0, ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\n\
    \    ed -= st;\r\n    st = 0;\r\n    ed += ::read(fd, line + ed, (1 << 15) - ed);\r\
    \n    line[ed] = '\\0';\r\n  }\r\n  bool succ() {\r\n    while (true) {\r\n  \
    \    if (st == ed) {\r\n        reread();\r\n        if (st == ed) return false;\r\
    \n      }\r\n      while (st != ed && isspace(line[st])) st++;\r\n      if (st\
    \ != ed) break;\r\n    }\r\n    if (ed - st <= 50) {\r\n      bool sep = false;\r\
    \n      for (size_t i = st; i < ed; i++) {\r\n        if (isspace(line[i])) {\r\
    \n          sep = true;\r\n          break;\r\n        }\r\n      }\r\n      if\
    \ (!sep) reread();\r\n    }\r\n    return true;\r\n  }\r\n  template <class T,\
    \ enable_if_t<is_same<T, string>::value, int> = 0>\r\n  bool read_single(T &ref)\
    \ {\r\n    if (!succ()) return false;\r\n    while (true) {\r\n      size_t sz\
    \ = 0;\r\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\r\n    \
    \  ref.append(line + st, sz);\r\n      st += sz;\r\n      if (!sz || st != ed)\
    \ break;\r\n      reread();\r\n    }\r\n    return true;\r\n  }\r\n  template\
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
    \ __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHR(...)    \\\r\n  char __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)           \\\r\n  long double\
    \ __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name, size)\
    \ \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type, name,\
    \ h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n#line\
    \ 6 \"my_template.hpp\"\n\n\nusing ll = long long;\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using i128 = __int128;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define vv(type,\
    \ name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
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
    \ return __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - __builtin_clz(x);\
    \ }\nint topbit(uint x) { return 31 - __builtin_clz(x); }\nint topbit(ll x) {\
    \ return 63 - __builtin_clzll(x); }\nint topbit(u64 x) { return 63 - __builtin_clzll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return\
    \ 31 - __builtin_clz(x); }\nint lowbit(uint x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(ll x) { return 63 - __builtin_clzll(x); }\nint lowbit(u64 x) {\
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
    \ }\n  return A;\n}\n\ntemplate <typename T>\nvector<T> cumsum(vector<T> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i +\
    \ 1] = B[i] + A[i]; }\n  if(off == 0) B.erase(B.begin());\n  return B;\n}\n\n\
    template<typename T>\nvc<int> bincount(vc<T> &A, int size) {\n  vc<int> C(size);\n\
    \  for (auto&& x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int>\
    \ argsort(vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j); });\n  return ids;\n}\n#line 3 \"test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp\"\
    \n\n#line 2 \"ds/segtree.hpp\"\ntemplate <class Monoid>\nstruct SegTree {\n  using\
    \ X = typename Monoid::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int\
    \ n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) : SegTree(vc<X>(n,\
    \ Monoid::unit)) {}\n  SegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n    while\
    \ ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit);\n\
    \    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\
    \n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n\
    \  void set(int i, X x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while\
    \ (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n\
    \    assert(R <= n);\n    X vl = Monoid::unit, vr = Monoid::unit;\n    L += size,\
    \ R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n\
    \      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n  \
    \  }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return dat[1];}\n\
    \n  template <class F>\n  int max_right(F &check, int L) {\n    assert(0 <= L\
    \ && L <= n && check(Monoid::unit));\n    if (L == n) return n;\n    L += size;\n\
    \    X sm = Monoid::unit;\n    do {\n      while (L % 2 == 0) L >>= 1;\n     \
    \ if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n        \
    \  L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n            sm\
    \ = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n      \
    \  return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n      L++;\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F &check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit;\n    do {\n\
    \      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < n) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(\"\
    segtree\", dat); }\n};\n#line 2 \"mod/modint.hpp\"\ntemplate <int mod>\nstruct\
    \ modint {\n  static constexpr bool is_modint = true;\n  int val;\n  constexpr\
    \ modint(const ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod -\
    \ (-val) % mod) % mod) {}\n  bool operator<(const modint &other) const {\n   \
    \ return val < other.val;\n  } // To use std::map\n  modint &operator+=(const\
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
    \ >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"\
    =d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n\
    \  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-() const {\
    \ return ArbitraryModInt(-val); }\n  ArbitraryModInt operator+(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt\
    \ operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n};\n\ntemplate<typename mint>\ntuple<mint, mint, mint>\
    \ get_factorial_data(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> fact = {1, 1};\n  static\
    \ vector<mint> fact_inv = {1, 1};\n  static vector<mint> inv = {0, 1};\n  while(len(fact)\
    \ <= n){\n    int k = len(fact);\n    fact.eb(fact[k - 1] * mint(k));\n    auto\
    \ q = ceil(mod, k);\n    int r = k * q - mod;\n    inv.eb(inv[r] * mint(q));\n\
    \    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n  return {fact[n], fact_inv[n],\
    \ inv[n]};\n}\n\ntemplate<typename mint>\nmint fact(int n){\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n);\n  if(n >= mod) return 0;\n  return\
    \ get<0>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\nmint fact_inv(int\
    \ n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n\
    \  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\n\
    mint inv(int n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <=\
    \ n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename\
    \ mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n >= 0);\n  if (k\
    \ < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n) * fact_inv<mint>(k)\
    \ * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) {\n\
    \    x *= mint(n - i);\n  }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\nusing\
    \ modint107 = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n\
    using amint = ArbitraryModInt;\n#line 1 \"alg/group_affine.hpp\"\ntemplate <typename\
    \ K>\nstruct Group_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n\
    \  static constexpr F op(const F &x, const F &y) noexcept {\n    return F({x.fi\
    \ * y.fi, x.se * y.fi + y.se});\n  }\n  static constexpr F inverse(const F &x)\
    \ {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n\
    \  static constexpr K eval(const F &f, K x) noexcept { return f.fi * x + f.se;\
    \ }\n  static constexpr F unit = {K(1), K(0)};\n  static constexpr bool commute\
    \ = false;\n};\n#line 7 \"test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  using Mono = Group_Affine<mint>;\n\
    \  using F = Mono::value_type;\n\n  vc<F> seg_raw(N);\n  FOR(i, N) {\n    LL(a,\
    \ b);\n    seg_raw[i] = {a, b};\n  }\n\n  SegTree<Mono> seg(seg_raw);\n\n  FOR(q,\
    \ Q) {\n    LL(t);\n    if (t == 0) {\n      LL(i, a, b);\n      seg.set(i, F({a,\
    \ b}));\n    } else {\n      LL(L, R, x);\n      auto f = seg.prod(L, R);\n  \
    \    print(Mono::eval(f, x));\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"my_template.hpp\"\n\n#include \"ds/segtree.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"alg/group_affine.hpp\"\n\nusing mint = modint998;\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  using Mono = Group_Affine<mint>;\n  using F = Mono::value_type;\n\
    \n  vc<F> seg_raw(N);\n  FOR(i, N) {\n    LL(a, b);\n    seg_raw[i] = {a, b};\n\
    \  }\n\n  SegTree<Mono> seg(seg_raw);\n\n  FOR(q, Q) {\n    LL(t);\n    if (t\
    \ == 0) {\n      LL(i, a, b);\n      seg.set(i, F({a, b}));\n    } else {\n  \
    \    LL(L, R, x);\n      auto f = seg.prod(L, R);\n      print(Mono::eval(f, x));\n\
    \    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree.hpp
  - mod/modint.hpp
  - alg/group_affine.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  requiredBy: []
  timestamp: '2022-01-15 18:21:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
- /verify/test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp.html
title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
---
