---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/centroid.hpp
    title: graph/centroid.hpp
  - icon: ':x:'
    path: graph/tree_all_distances.hpp
    title: graph/tree_all_distances.hpp
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
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/library_checker/tree/frequency_table_of_tree_distance.test.cpp\"\
    \n#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \ yes(!t); }\r\n#line 5 \"test/library_checker/tree/frequency_table_of_tree_distance.test.cpp\"\
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
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared && 0 <= frm && 0 <= to);\n   \
    \ chmax(N, frm + 1);\n    chmax(N, to + 1);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void\
    \ read_tree(bool wt=false, int off=1){\n    read_graph(N - 1, wt, off);\n  }\n\
    \n  void read_graph(int M, bool wt=false, int off=1){\n    FOR_(M){\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if(!wt){\n        add(a, b);\n      }\
    \ else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n   \
    \ }\n    prepare();\n  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
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
    \    }\n  }\n};\n#line 2 \"graph/centroid.hpp\"\ntemplate <typename Graph, typename\
    \ E = int>\r\nstruct CentroidDecomposition {\r\n  using edge_type = typename Graph::edge_type;\r\
    \n  using F = function<E(E, edge_type)>;\r\n  Graph& G;\r\n  F f; // (E path value,\
    \ edge e) -> E new_path_value\r\n  int N;\r\n  vector<int> cdep; // depth in centroid\
    \ tree\r\n  vc<int> sz;\r\n  vc<int> par;\r\n\r\n  CentroidDecomposition(\r\n\
    \      Graph& G, F f = [](int x, edge_type e) { return x + e.cost; })\r\n    \
    \  : G(G), N(G.N), f(f), sz(G.N), par(G.N), cdep(G.N, -1) {\r\n    build();\r\n\
    \  }\r\n\r\n  int find(int v) {\r\n    vc<int> V = {v};\r\n    par[v] = -1;\r\n\
    \    int p = 0;\r\n    while (p < len(V)) {\r\n      int v = V[p++];\r\n     \
    \ sz[v] = 0;\r\n      for (auto&& e: G[v]) {\r\n        if (e.to == par[v] ||\
    \ cdep[e.to] != -1) continue;\r\n        par[e.to] = v;\r\n        V.eb(e.to);\r\
    \n      }\r\n    }\r\n    while (len(V)) {\r\n      int v = V.back();\r\n    \
    \  V.pop_back();\r\n      sz[v] += 1;\r\n      if (p - sz[v] <= p / 2) return\
    \ v;\r\n      sz[par[v]] += sz[v];\r\n    }\r\n    return -1;\r\n  }\r\n\r\n \
    \ void build() {\r\n    assert(G.is_prepared());\r\n    assert(!G.is_directed());\r\
    \n    int N = G.N;\r\n\r\n    vc<pair<int, int>> st = {{0, 0}};\r\n    while (len(st))\
    \ {\r\n      auto [lv, v] = st.back();\r\n      st.pop_back();\r\n      auto c\
    \ = find(v);\r\n      cdep[c] = lv;\r\n      for (auto&& [frm, to, cost, id]:\
    \ G[c]) {\r\n        if (cdep[to] == -1) st.eb(lv + 1, to);\r\n      }\r\n   \
    \ }\r\n  }\r\n\r\n  vc<vc<pair<int, E>>> collect(int root, E root_val) {\r\n \
    \   /*\r\n    root \u3092\u91CD\u5FC3\u3068\u3059\u308B\u6728\u306B\u304A\u3044\
    \u3066\u3001(v, path data v) \u306E vector \u3092\u3001\u65B9\u5411\u3054\u3068\
    \u306B\u96C6\u3081\u3066\u8FD4\u3059\r\n    \u30FB0 \u756A\u76EE\uFF1Aroot \u304B\
    \u3089\u306E\u30D1\u30B9\u3059\u3079\u3066\uFF08root \u3092\u542B\u3080\uFF09\r\
    \n    \u30FBi \u756A\u76EE\uFF1Ai \u756A\u76EE\u306E\u65B9\u5411\r\n    */\r\n\
    \    vc<vc<pair<int, E>>> res = {{{root, root_val}}};\r\n    for (auto&& e: G[root])\
    \ {\r\n      int nxt = e.to;\r\n      if (cdep[nxt] < cdep[root]) continue;\r\n\
    \      vc<pair<int, E>> dat;\r\n      int p = 0;\r\n      dat.eb(nxt, f(root_val,\
    \ e));\r\n      par[nxt] = root;\r\n      while (p < len(dat)) {\r\n        auto\
    \ [v, val] = dat[p++];\r\n        for (auto&& e: G[v]) {\r\n          if (e.to\
    \ == par[v]) continue;\r\n          if (cdep[e.to] < cdep[root]) continue;\r\n\
    \          par[e.to] = v;\r\n          dat.eb(e.to, f(val, e));\r\n        }\r\
    \n      }\r\n      res.eb(dat);\r\n      res[0].insert(res[0].end(), all(dat));\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"mod/modint.hpp\"\ntemplate\
    \ <int mod>\nstruct modint {\n  static constexpr bool is_modint = true;\n  int\
    \ val;\n  constexpr modint(const ll val = 0) noexcept\n      : val(val >= 0 ?\
    \ val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const modint &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map\n  modint &operator+=(const\
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
    using amint = ArbitraryModInt;\n#line 3 \"poly/convolution.hpp\"\ntemplate <class\
    \ T>\r\nvector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {\r\
    \n  int n = int(a.size()), m = int(b.size());\r\n  vector<T> ans(n + m - 1);\r\
    \n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\n  }\
    \ else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  }\r\n  return\
    \ ans;\r\n}\r\n\r\ntemplate <class mint>\r\nstruct fft_info {\r\n  static constexpr\
    \ int bsf_constexpr(unsigned int n) {\r\n    int x = 0;\r\n    while (!(n & (1\
    \ << x))) x++;\r\n    return x;\r\n  }\r\n\r\n  static constexpr int rank2 = bsf_constexpr(mint::get_mod()\
    \ - 1);\r\n  array<mint, rank2 + 1> root;\r\n  array<mint, rank2 + 1> iroot;\r\
    \n  array<mint, max(0, rank2 - 1)> rate2;\r\n  array<mint, max(0, rank2 - 1)>\
    \ irate2;\r\n  array<mint, max(0, rank2 - 2)> rate3;\r\n  array<mint, max(0, rank2\
    \ - 2)> irate3;\r\n\r\n  fft_info() {\r\n    int g = primitive_root(mint::get_mod());\r\
    \n    root[rank2] = mint(g).pow((mint::get_mod() - 1) >> rank2);\r\n    iroot[rank2]\
    \ = mint(1) / root[rank2];\r\n    FOR_R(i, rank2) {\r\n      root[i] = root[i\
    \ + 1] * root[i + 1];\r\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n   \
    \ }\r\n\r\n    {\r\n      mint prod = 1, iprod = 1;\r\n      for (int i = 0; i\
    \ <= rank2 - 2; i++) {\r\n        rate2[i] = root[i + 2] * prod;\r\n        irate2[i]\
    \ = iroot[i + 2] * iprod;\r\n        prod *= iroot[i + 2];\r\n        iprod *=\
    \ root[i + 2];\r\n      }\r\n    }\r\n    {\r\n      mint prod = 1, iprod = 1;\r\
    \n      for (int i = 0; i <= rank2 - 3; i++) {\r\n        rate3[i] = root[i +\
    \ 3] * prod;\r\n        irate3[i] = iroot[i + 3] * iprod;\r\n        prod *= iroot[i\
    \ + 3];\r\n        iprod *= root[i + 3];\r\n      }\r\n    }\r\n  }\r\n\r\n  constexpr\
    \ int primitive_root(int m) {\r\n    if (m == 167772161) return 3;\r\n    if (m\
    \ == 469762049) return 3;\r\n    if (m == 754974721) return 11;\r\n    if (m ==\
    \ 880803841) return 26;\r\n    if (m == 998244353) return 3;\r\n  }\r\n};\r\n\r\
    \ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool inverse) {\r\n  int\
    \ n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  static\
    \ const fft_info<mint> info;\r\n  if (!inverse) {\r\n    int len = 0; // a[i,\
    \ i+(n>>len), i+2*(n>>len), ..] is transformed\r\n    while (len < h) {\r\n  \
    \    if (h - len == 1) {\r\n        int p = 1 << (h - len - 1);\r\n        mint\
    \ rot = 1;\r\n        FOR(s, 1 << len) {\r\n          int offset = s << (h - len);\r\
    \n          FOR(i, p) {\r\n            auto l = a[i + offset];\r\n           \
    \ auto r = a[i + offset + p] * rot;\r\n            a[i + offset] = l + r;\r\n\
    \            a[i + offset + p] = l - r;\r\n          }\r\n          rot *= info.rate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len++;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len - 2);\r\n        mint rot = 1, imag = info.root[2];\r\n      \
    \  for (int s = 0; s < (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\
    \n          mint rot3 = rot2 * rot;\r\n          int offset = s << (h - len);\r\
    \n          for (int i = 0; i < p; i++) {\r\n            auto mod2 = 1ULL * mint::get_mod()\
    \ * mint::get_mod();\r\n            auto a0 = 1ULL * a[i + offset].val;\r\n  \
    \          auto a1 = 1ULL * a[i + offset + p].val * rot.val;\r\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val * rot2.val;\r\n            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].val * rot3.val;\r\n            auto a1na3imag = 1ULL\
    \ * mint(a1 + mod2 - a3).val * imag.val;\r\n            auto na2 = mod2 - a2;\r\
    \n            a[i + offset] = a0 + a2 + a1 + a3;\r\n            a[i + offset +\
    \ 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i + offset + 2 *\
    \ p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 * p] = a0 + na2 +\
    \ (mod2 - a1na3imag);\r\n          }\r\n          rot *= info.rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p];\r\
    \n            a[i + offset] = l + r;\r\n            a[i + offset + p]\r\n    \
    \            = (unsigned long long)(mint::get_mod() + l.val - r.val)\r\n     \
    \             * irot.val;\r\n            ;\r\n          }\r\n          irot *=\
    \ info.irate2[topbit(~s & -~s)];\r\n        }\r\n        len--;\r\n      } else\
    \ {\r\n        int p = 1 << (h - len);\r\n        mint irot = 1, iimag = info.iroot[2];\r\
    \n        FOR(s, (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n\
    \          mint irot3 = irot2 * irot;\r\n          int offset = s << (h - len\
    \ + 2);\r\n          for (int i = 0; i < p; i++) {\r\n            auto a0 = 1ULL\
    \ * a[i + offset + 0 * p].val;\r\n            auto a1 = 1ULL * a[i + offset +\
    \ 1 * p].val;\r\n            auto a2 = 1ULL * a[i + offset + 2 * p].val;\r\n \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val;\r\n\r\n            auto\
    \ a2na3iimag\r\n                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;\r\
    \n\r\n            a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset\
    \ + 1 * p]\r\n                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;\r\
    \n            a[i + offset + 2 * p]\r\n                = (a0 + a1 + (mint::get_mod()\
    \ - a2) + (mint::get_mod() - a3))\r\n                  * irot2.val;\r\n      \
    \      a[i + offset + 3 * p]\r\n                = (a0 + (mint::get_mod() - a1)\
    \ + (mint::get_mod() - a2na3iimag))\r\n                  * irot3.val;\r\n    \
    \      }\r\n          irot *= info.irate3[topbit(~s & -~s)];\r\n        }\r\n\
    \        len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  int n =\
    \ int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m -\
    \ 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\
    \u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\
    \u308B\u306E\u3067\u3002\r\n  if((n+m-3) <= sz / 2){\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.eb(0);\r\n    c.eb(0);\r\n    c.back() = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n\r\n  a.resize(sz),\
    \ b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if(same){\r\n  \
    \  b = a;\r\n  } else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\
    \n  ntt(a, 1);\r\n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ const long long nttprimes[] = {754974721, 167772161, 469762049};\r\n  using\
    \ mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\n  using\
    \ mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n),\
    \ b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] =\
    \ a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val,\
    \ b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1\
    \ = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  static const\
    \ int mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2\
    \ x2) -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
    \ - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\r\n    return mint(r0\
    \ + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);\r\n  };\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);\r\n  return c;\r\n}\r\n\
    \r\nnamespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\
    \n\r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename R>\r\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\r\n  int need = (int)a.size() + (int)b.size() -\
    \ 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  fft(fa, sz);\r\n  C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1); i++)\
    \ {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i] *\
    \ fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\n  fft(fa,\
    \ sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0; i < need; i++)\
    \ {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n  }\r\n  return\
    \ ret;\r\n}\r\n} // namespace CFFT\r\n\r\nvector<ll> convolution(const vector<ll>&\
    \ a, const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m)\
    \ return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll\
    \ abs_sum_a = 0, abs_sum_b = 0;\r\n  FOR(i, n) abs_sum_a += abs(a[i]);\r\n  FOR(i,\
    \ m) abs_sum_b += abs(b[i]);\r\n  assert(abs_sum_a * abs_sum_b < 1e15);\r\n  vc<double>\
    \ c = CFFT::convolution_fft(a, b);\r\n  vc<ll> res(len(c));\r\n  FOR(i, len(c))\
    \ res[i] = ll(floor(c[i] + .5));\r\n  return res;\r\n}\r\n\r\ntemplate<typename\
    \ mint>\r\nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\
    \n  return convolution_ntt(a, b);\r\n}\r\n\r\ntemplate<typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_garner(a,\
    \ b);\r\n}\r\n#line 3 \"graph/tree_all_distances.hpp\"\n\r\ntemplate<typename\
    \ Graph>\r\nvi tree_all_distances(Graph& G){\r\n  // frequency table of distance\
    \ of all directed pairs. \r\n  // sum of result array = N^2\r\n  \r\n  assert(G.is_prepared());\r\
    \n  assert(!G.is_directed());\r\n\r\n  CentroidDecomposition CD(G);\r\n\r\n  ll\
    \ N = G.N;\r\n  vi ANS(N);\r\n  FOR(root, N) {\r\n    auto data = CD.collect(root,\
    \ 0);\r\n    FOR(i, len(data)) {\r\n      int n = 0;\r\n      FOR(j, len(data[i]))\
    \ chmax(n, data[i][j].se + 1);\r\n      vi A(n);\r\n      FOR(j, len(data[i]))\
    \ A[data[i][j].se]++;\r\n      auto B = convolution(A, A);\r\n      FOR(j, min(N,\
    \ len(B))) ANS[j] += (i == 0 ? B[j] : -B[j]);\r\n    }\r\n  }\r\n  return ANS;\r\
    \n}\n#line 7 \"test/library_checker/tree/frequency_table_of_tree_distance.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\n\
    \    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n\r\n  vi ANS =\
    \ tree_all_distances(G);\r\n  ANS.erase(ANS.begin());\r\n  for (auto&& x: ANS)\
    \ x /= 2;\r\n  print(ANS);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"graph/tree_all_distances.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int>\
    \ G(N);\r\n  FOR(_, N - 1) {\r\n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n \
    \ G.prepare();\r\n\r\n  vi ANS = tree_all_distances(G);\r\n  ANS.erase(ANS.begin());\r\
    \n  for (auto&& x: ANS) x /= 2;\r\n  print(ANS);\r\n}\r\n\r\nsigned main() {\r\
    \n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/tree_all_distances.hpp
  - graph/centroid.hpp
  - graph/base.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2022-02-11 06:59:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
- /verify/test/library_checker/tree/frequency_table_of_tree_distance.test.cpp.html
title: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
---