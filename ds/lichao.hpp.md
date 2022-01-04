---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing ll8 = __int128;\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\nusing uint = unsigned int;\nusing ull = unsigned long\
    \ long;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing\
    \ vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate\
    \ <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc\
    \ = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\ntemplate\
    \ <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n#define\
    \ vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type, name,\
    \ size) \\\n  vector<type> name(size);    \\\n  IN(name)\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
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
    \ T1, typename T2, typename T3, typename T4>\nostream &operator<<(ostream &os,\
    \ const tuple<T1, T2, T3, T4> &t) {\n  os << get<0>(t) << \" \" << get<1>(t) <<\
    \ \" \" << get<2>(t) << \" \" << get<3>(t);\n  return os;\n}\ntemplate <typename\
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
    \  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j); });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check,\
    \ ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n      ng = x;\n\
    \  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a,\
    \ const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"ds/lichao.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct LiChaoTree {\r\n  struct Line {\r\n    T\
    \ a, b;\r\n\r\n    Line(T a, T b) : a(a), b(b) {}\r\n\r\n    inline T get(T x)\
    \ const { return a * x + b; }\r\n\r\n    inline bool over(const Line& b, const\
    \ T& x) const {\r\n      return get(x) < b.get(x);\r\n    }\r\n  };\r\n\r\n  vector<T>\
    \ xs;\r\n  vector<Line> seg;\r\n  int sz;\r\n\r\n  LiChaoTree(const vector<T>&\
    \ x, T INF) : xs(x) {\r\n    sort(all(xs));\r\n    sz = 1;\r\n    while (sz <\
    \ xs.size()) sz <<= 1;\r\n    while (xs.size() < sz) xs.push_back(xs.back() +\
    \ 1);\r\n    seg.assign(2 * sz - 1, Line(0, INF));\r\n  }\r\n\r\n  void update(Line&\
    \ x, int k, int l, int r) {\r\n    int mid = (l + r) >> 1;\r\n    auto latte =\
    \ x.over(seg[k], xs[l]), malta = x.over(seg[k], xs[mid]);\r\n    if (malta) swap(seg[k],\
    \ x);\r\n    if (l + 1 >= r)\r\n      return;\r\n    else if (latte != malta)\r\
    \n      update(x, 2 * k + 1, l, mid);\r\n    else\r\n      update(x, 2 * k + 2,\
    \ mid, r);\r\n  }\r\n\r\n  void update(T a, T b) {  // ax+b\r\n    Line l(a, b);\r\
    \n    update(l, 0, 0, sz);\r\n  }\r\n\r\n  T query(T x) {\r\n    ll k = LB(xs,\
    \ x);\r\n    k += sz - 1;\r\n    T ret = seg[k].get(x);\r\n    while (k > 0) {\r\
    \n      k = (k - 1) >> 1;\r\n      ret = min(ret, seg[k].get(x));\r\n    }\r\n\
    \    return ret;\r\n  }\r\n};\n"
  code: "#pragma once\r\n#include \"my_template.hpp\"\r\n\r\ntemplate <typename T>\r\
    \nstruct LiChaoTree {\r\n  struct Line {\r\n    T a, b;\r\n\r\n    Line(T a, T\
    \ b) : a(a), b(b) {}\r\n\r\n    inline T get(T x) const { return a * x + b; }\r\
    \n\r\n    inline bool over(const Line& b, const T& x) const {\r\n      return\
    \ get(x) < b.get(x);\r\n    }\r\n  };\r\n\r\n  vector<T> xs;\r\n  vector<Line>\
    \ seg;\r\n  int sz;\r\n\r\n  LiChaoTree(const vector<T>& x, T INF) : xs(x) {\r\
    \n    sort(all(xs));\r\n    sz = 1;\r\n    while (sz < xs.size()) sz <<= 1;\r\n\
    \    while (xs.size() < sz) xs.push_back(xs.back() + 1);\r\n    seg.assign(2 *\
    \ sz - 1, Line(0, INF));\r\n  }\r\n\r\n  void update(Line& x, int k, int l, int\
    \ r) {\r\n    int mid = (l + r) >> 1;\r\n    auto latte = x.over(seg[k], xs[l]),\
    \ malta = x.over(seg[k], xs[mid]);\r\n    if (malta) swap(seg[k], x);\r\n    if\
    \ (l + 1 >= r)\r\n      return;\r\n    else if (latte != malta)\r\n      update(x,\
    \ 2 * k + 1, l, mid);\r\n    else\r\n      update(x, 2 * k + 2, mid, r);\r\n \
    \ }\r\n\r\n  void update(T a, T b) {  // ax+b\r\n    Line l(a, b);\r\n    update(l,\
    \ 0, 0, sz);\r\n  }\r\n\r\n  T query(T x) {\r\n    ll k = LB(xs, x);\r\n    k\
    \ += sz - 1;\r\n    T ret = seg[k].get(x);\r\n    while (k > 0) {\r\n      k =\
    \ (k - 1) >> 1;\r\n      ret = min(ret, seg[k].get(x));\r\n    }\r\n    return\
    \ ret;\r\n  }\r\n};"
  dependsOn:
  - my_template.hpp
  isVerificationFile: false
  path: ds/lichao.hpp
  requiredBy: []
  timestamp: '2022-01-05 00:19:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lichao.hpp
layout: document
redirect_from:
- /library/ds/lichao.hpp
- /library/ds/lichao.hpp.html
title: ds/lichao.hpp
---
