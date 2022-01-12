---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/cycle_detection.hpp
    title: graph/cycle_detection.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/library_checker/graph/cycle_detection.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\r\n\r\n#line\
    \ 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
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
    \n    }\r\n  }\r\n};\r\n\r\nScanner scanner = Scanner(stdin);\r\nPrinter printer\
    \ = Printer(stdout);\r\n\r\nvoid flush() { printer.flush(); }\r\nvoid print()\
    \ { printer.write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head\
    \ &&head, Tail &&... tail) {\r\n  printer.write(head);\r\n  if (sizeof...(Tail))\
    \ printer.write(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  scanner.read(head);\r\n  read(tail...);\r\n}\r\n\r\n#define INT(...)\
    \   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\
    \r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHR(...)    \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)           \\\
    \r\n  long double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 6 \"my_template.hpp\"\n\n\nusing ll = long long;\nusing\
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
    \ }\n  return A;\n}\n\ntemplate <typename T>\nvector<T> cumsum(vector<T> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i +\
    \ 1] = B[i] + A[i]; }\n  if(off == 0) B.erase(B.begin());\n  return B;\n}\n\n\
    template<typename T>\nvc<int> bincount(vc<T> &A, int size) {\n  vc<int> C(size);\n\
    \  for (auto&& x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int>\
    \ argsort(vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j); });\n  return ids;\n}\n#line 4 \"test/library_checker/graph/cycle_detection.test.cpp\"\
    \n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() {}\n  Graph(int N) : N(N), M(0),\
    \ prepared(0) {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n  \
    \  assert(!prepared);\n    assert(0 <= frm && frm < N && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared = true;\n\
    \    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n\n  int size() { return N; }\n};\n#line 1 \"graph/cycle_detection.hpp\"\
    \ntemplate <typename Graph>\r\nvc<int> cycle_detection(Graph& G, bool is_edge)\
    \ {\r\n  assert(G.is_directed());\r\n  assert(G.is_prepared());\r\n  if (!is_edge)\
    \ {\r\n    auto C = cycle_detection(G, true);\r\n    if (len(C) == 0) return C;\r\
    \n    vc<int> ANS(len(C) + 1);\r\n    FOR(i, len(C)) {\r\n      auto e = G.edges[C[i]];\r\
    \n      ANS[i + 0] = e.frm;\r\n      ANS[i + 1] = e.to;\r\n    }\r\n    return\
    \ ANS;\r\n  }\r\n\r\n  int N = G.N;\r\n  vc<int> used(N);\r\n  vc<int> path; //\
    \ edge\r\n  vc<pair<int, int>> par(N);\r\n  vector<int> ANS;\r\n\r\n  auto dfs\
    \ = [&](auto self, int v) -> void {\r\n    used[v] = 1;\r\n    for (auto&& e:\
    \ G[v]) {\r\n      if (len(ANS)) return;\r\n      if (!used[e.to]) {\r\n     \
    \   par[e.to] = {v, e.id};\r\n        self(self, e.to);\r\n      }\r\n      elif\
    \ (used[e.to] == 1) {\r\n        ANS = {e.id};\r\n        int cur = v;\r\n   \
    \     while (cur != e.to) {\r\n          ANS.eb(par[cur].se);\r\n          cur\
    \ = par[cur].fi;\r\n        }\r\n        reverse(all(ANS));\r\n        return;\r\
    \n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N) if (!used[v]) dfs(dfs,\
    \ v);\r\n  return ANS;\r\n}\n#line 7 \"test/library_checker/graph/cycle_detection.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, M);\r\n  Graph<int, 1> G(N);\r\n  FOR(_, M) {\r\
    \n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n\r\n  auto C =\
    \ cycle_detection(G, true);\r\n  if (len(C) == 0) {\r\n    print(-1);\r\n  } else\
    \ {\r\n    print(len(C));\r\n    for (auto&& i: C) print(i);\r\n  }\r\n}\r\n\r\
    \nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n\
    \  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\r\n\r\
    \n#include \"my_template.hpp\"\r\n\r\n#include \"graph/base.hpp\"\r\n#include\
    \ \"graph/cycle_detection.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, M);\r\n  Graph<int,\
    \ 1> G(N);\r\n  FOR(_, M) {\r\n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\
    \n\r\n  auto C = cycle_detection(G, true);\r\n  if (len(C) == 0) {\r\n    print(-1);\r\
    \n  } else {\r\n    print(len(C));\r\n    for (auto&& i: C) print(i);\r\n  }\r\
    \n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/base.hpp
  - graph/cycle_detection.hpp
  isVerificationFile: true
  path: test/library_checker/graph/cycle_detection.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 03:05:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/cycle_detection.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/cycle_detection.test.cpp
- /verify/test/library_checker/graph/cycle_detection.test.cpp.html
title: test/library_checker/graph/cycle_detection.test.cpp
---
