---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a),\
    \ to(b), cost(c), id(d) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n  int\
    \ N, M;\n  using edge_t = Edge<T>;\n  vector<edge_t> edges;\n  vector<vector<edge_t>>\
    \ G;\n  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false) : N(N),\
    \ M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    if (i == -1) i = M;\n    auto e = edge_t(frm, to, cost, i);\n \
    \   edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n      auto e_rev =\
    \ edge_t(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n    ++M;\n  }\n\n\
    \  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v << \" :\"\
    ;\n      for (auto e: G[v]) {\n        if (detail)\n          cout << \" (\" <<\
    \ e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id << \")\";\n     \
    \   else\n          cout << \" \" << e.to;\n      }\n      cout << \"\\n\";\n\
    \    }\n  }\n\n  vector<int> degrees() {\n    vector<int> deg(N);\n    for (auto&&\
    \ e: edges) {\n      deg[e.frm]++;\n      deg[e.to]++;\n    }\n    return deg;\n\
    \  }\n\n  int size() { return N; }\n\n  vector<edge_t>& operator[](int v) { return\
    \ G[v]; }\n};\n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long\
    \ double;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint = unsigned\
    \ int;\nusing ull = unsigned long long;\n\ntemplate <class T>\nusing vc = vector<T>;\n\
    template <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc\
    \ = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate\
    \ <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq =\
    \ priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define VEC(type, name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  IN(name)\n#define vvv(type, name, h, w, ...) \\\n  vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i, m, n)\
    \ for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i = (ll)(n)-1;\
    \ (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m);\
    \ --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t\
    \ - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n\
    #define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define\
    \ mt make_tuple\n#define fi first\n#define se second\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(uint x) { return __builtin_popcount(x);\
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
    \ {\n  ll q = floor(x, y);\n  return {q, x - q * y};\n}\n\n#define INT(...)  \
    \ \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__; \\\n\
    \  IN(__VA_ARGS__)\n#define CHR(...)    \\\n  char __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define DBL(...)           \\\n  long double __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    void scan(int &a) { cin >> a; }\nvoid scan(long long &a) { cin >> a; }\nvoid scan(char\
    \ &a) { cin >> a; }\nvoid scan(double &a) { cin >> a; }\nvoid scan(long double\
    \ &a) { cin >> a; }\nvoid scan(string &a) { cin >> a; }\ntemplate <class T>\n\
    void scan(pair<T, T> &p) {\n  scan(p.first), scan(p.second);\n}\ntemplate <class\
    \ T>\nvoid scan(tuple<T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));\n\
    }\ntemplate <class T>\nvoid scan(tuple<T, T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)),\
    \ scan(get<2>(p)), scan(get<3>(p));\n}\ntemplate <class T>\nvoid scan(vector<T>\
    \ &a) {\n  for (auto &i: a) scan(i);\n}\ntemplate <class T>\nvoid scan(T &a) {\n\
    \  cin >> a;\n}\nvoid IN() {}\ntemplate <class Head, class... Tail>\nvoid IN(Head\
    \ &head, Tail &... tail) {\n  scan(head);\n  IN(tail...);\n}\n\nvi s_to_vi(string\
    \ S, char first_char = 'a') {\n  vi A(S.size());\n  FOR(i, S.size()) { A[i] =\
    \ S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &A) {\n  os << A.fi << \" \"\
    \ << A.se;\n  return os;\n}\ntemplate <typename T1, typename T2, typename T3>\n\
    ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &t) {\n  os << get<0>(t)\
    \ << \" \" << get<1>(t) << \" \" << get<2>(t);\n  return os;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &A) {\n  for (size_t i\
    \ = 0; i < A.size(); i++) {\n    if (i) os << \" \";\n    os << A[i];\n  }\n \
    \ return os;\n}\n\nvoid print() { cout << \"\\n\"; }\ntemplate <class Head, class...\
    \ Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  cout << head;\n  if (sizeof...(Tail))\
    \ cout << \" \";\n  print(forward<Tail>(tail)...);\n}\n\nvoid YES(bool t = 1)\
    \ { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t);\
    \ }\n\ntemplate <typename T>\nvector<T> cumsum(vector<T> &A) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  B[0] = T(0);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  return B;\n}\n\nvc<int> bin_count(vi &A, int size) {\n  vc<int> C(size);\n\
    \  for (auto &x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int>\
    \ argsort(vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids), 0);\n\
    \  sort(all(ids), [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i\
    \ < j); });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check, ll\
    \ ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x\
    \ = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n      ng = x;\n\
    \  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a,\
    \ const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 4 \"graph/bipartite_coloring.hpp\"\
    \n\npair<int, vi> bipartite_edge_coloring(Graph<ll>& G) {\n  auto N = G.N;\n \
    \ vi deg(N);\n  vi ANS(G.M, -1);\n  FORIN(e, G.edges) {\n    ++deg[e.frm];\n \
    \   ++deg[e.to];\n  }\n  ll C = MAX(deg);\n  // \u9802\u70B9, \u8272 -> \u8FBA\
    \u756A\u53F7\n  vv(int, TO, N, C, -1);\n\n  FOR(id, G.M) {\n    auto const a =\
    \ G.edges[id].frm, b = G.edges[id].to;\n    [&] {\n      // a \u3067\u5B9F\u73FE\
    \u3057\u3066\u3044\u306A\u3044\u8272 ca \u3068 b \u3067\u5B9F\u73FE\u3057\u3066\
    \u3044\u306A\u3044\u8272 cb \u3092\u3072\u3068\u3064\u3068\u308B\u3002\n     \
    \ int ca = -1, cb = -1;\n      FOR(c, C) if (TO[a][c] == -1) {\n        ca = c;\n\
    \        break;\n      }\n      FOR(c, C) if (TO[b][c] == -1) {\n        cb =\
    \ c;\n        break;\n      }\n      int v = a, w = b, eid = id, cv = ca, cw =\
    \ cb;\n      while (1) {\n        ANS[eid] = cv;\n        TO[v][cv] = eid;\n \
    \       TO[w][cw] = -1;\n        if (TO[w][cv] == -1) {\n          TO[w][cv] =\
    \ eid;\n          break;\n        }\n        swap(eid, TO[w][cv]);\n        auto\
    \ const& e = G.edges[eid];\n        v = w;\n        w ^= e.frm ^ e.to;\n     \
    \   swap(cv, cw);\n      }\n    }();\n  }\n  return {C, ANS};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n#include \"my_template.hpp\"\n\
    \npair<int, vi> bipartite_edge_coloring(Graph<ll>& G) {\n  auto N = G.N;\n  vi\
    \ deg(N);\n  vi ANS(G.M, -1);\n  FORIN(e, G.edges) {\n    ++deg[e.frm];\n    ++deg[e.to];\n\
    \  }\n  ll C = MAX(deg);\n  // \u9802\u70B9, \u8272 -> \u8FBA\u756A\u53F7\n  vv(int,\
    \ TO, N, C, -1);\n\n  FOR(id, G.M) {\n    auto const a = G.edges[id].frm, b =\
    \ G.edges[id].to;\n    [&] {\n      // a \u3067\u5B9F\u73FE\u3057\u3066\u3044\u306A\
    \u3044\u8272 ca \u3068 b \u3067\u5B9F\u73FE\u3057\u3066\u3044\u306A\u3044\u8272\
    \ cb \u3092\u3072\u3068\u3064\u3068\u308B\u3002\n      int ca = -1, cb = -1;\n\
    \      FOR(c, C) if (TO[a][c] == -1) {\n        ca = c;\n        break;\n    \
    \  }\n      FOR(c, C) if (TO[b][c] == -1) {\n        cb = c;\n        break;\n\
    \      }\n      int v = a, w = b, eid = id, cv = ca, cw = cb;\n      while (1)\
    \ {\n        ANS[eid] = cv;\n        TO[v][cv] = eid;\n        TO[w][cw] = -1;\n\
    \        if (TO[w][cv] == -1) {\n          TO[w][cv] = eid;\n          break;\n\
    \        }\n        swap(eid, TO[w][cv]);\n        auto const& e = G.edges[eid];\n\
    \        v = w;\n        w ^= e.frm ^ e.to;\n        swap(cv, cw);\n      }\n\
    \    }();\n  }\n  return {C, ANS};\n}"
  dependsOn:
  - graph/base.hpp
  - my_template.hpp
  isVerificationFile: false
  path: graph/bipartite_coloring.hpp
  requiredBy: []
  timestamp: '2021-12-27 18:35:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_coloring.hpp
layout: document
redirect_from:
- /library/graph/bipartite_coloring.hpp
- /library/graph/bipartite_coloring.hpp.html
title: graph/bipartite_coloring.hpp
---