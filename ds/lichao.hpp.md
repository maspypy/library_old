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
  bundledCode: "#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
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
    \  return ids;\n}\n#line 3 \"ds/lichao.hpp\"\n\r\ntemplate <typename T>\r\nstruct\
    \ LiChaoTree {\r\n  struct Line {\r\n    T a, b;\r\n\r\n    Line(T a, T b) : a(a),\
    \ b(b) {}\r\n\r\n    inline T get(T x) const { return a * x + b; }\r\n\r\n   \
    \ inline bool over(const Line& b, const T& x) const {\r\n      return get(x) <\
    \ b.get(x);\r\n    }\r\n  };\r\n\r\n  vector<T> xs;\r\n  vector<Line> seg;\r\n\
    \  int sz;\r\n\r\n  LiChaoTree(const vector<T>& x, T INF) : xs(x) {\r\n    sort(all(xs));\r\
    \n    sz = 1;\r\n    while (sz < xs.size()) sz <<= 1;\r\n    while (xs.size()\
    \ < sz) xs.push_back(xs.back() + 1);\r\n    seg.assign(2 * sz - 1, Line(0, INF));\r\
    \n  }\r\n\r\n  void update(Line& x, int k, int l, int r) {\r\n    int mid = (l\
    \ + r) >> 1;\r\n    auto latte = x.over(seg[k], xs[l]), malta = x.over(seg[k],\
    \ xs[mid]);\r\n    if (malta) swap(seg[k], x);\r\n    if (l + 1 >= r)\r\n    \
    \  return;\r\n    else if (latte != malta)\r\n      update(x, 2 * k + 1, l, mid);\r\
    \n    else\r\n      update(x, 2 * k + 2, mid, r);\r\n  }\r\n\r\n  void update(T\
    \ a, T b) {  // ax+b\r\n    Line l(a, b);\r\n    update(l, 0, 0, sz);\r\n  }\r\
    \n\r\n  T query(T x) {\r\n    ll k = LB(xs, x);\r\n    k += sz - 1;\r\n    T ret\
    \ = seg[k].get(x);\r\n    while (k > 0) {\r\n      k = (k - 1) >> 1;\r\n     \
    \ ret = min(ret, seg[k].get(x));\r\n    }\r\n    return ret;\r\n  }\r\n};\n"
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
  timestamp: '2022-03-14 04:45:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lichao.hpp
layout: document
redirect_from:
- /library/ds/lichao.hpp
- /library/ds/lichao.hpp.html
title: ds/lichao.hpp
---
