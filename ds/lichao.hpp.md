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
    \ std;\n\nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T> using vc\
    \ = vector<T>;\ntemplate <class T> using vvc = vector<vc<T>>;\ntemplate <class\
    \ T> using vvvc = vector<vvc<T>>;\ntemplate <class T> using vvvvc = vector<vvvc<T>>;\n\
    template <class T> using vvvvvc = vector<vvvvc<T>>;\ntemplate <class T> using\
    \ pq = priority_queue<T>;\ntemplate <class T> using pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define VEC(type, name, size)                                                \
    \                                                                            \
    \      \\\n    vector<type> name(size);                                      \
    \                                                                            \
    \                 \\\n    IN(name)\n#define vv(type, name, h, ...) vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define VV(type, name, h, w)           \
    \                                                                            \
    \                                            \\\n    vector<vector<type>> name(h,\
    \ vector<type>(w));                                                          \
    \                                                   \\\n    IN(name)\n#define\
    \ vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...)        \
    \                                                                            \
    \                                     \\\n    vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i, m, n)\
    \ for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i = (ll)(n)-1;\
    \ (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m);\
    \ --(i))\n#define FORIN(x, A) for (auto&& x : A)\n#define FOR_nCk(s, n, k) \\\n\
    \  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \\\n  tmp_var = s | (s\
    \ - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s)\
    \ + 1))) \n#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1)\
    \ & s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n\n#define\
    \ elif else if\n\nusing ull = unsigned long long;\nusing uint = unsigned int;\n\
    int popcnt(uint x) {\n  return __builtin_popcount(x);\n}\nint popcnt(int x) {\n\
    \  return __builtin_popcount(x);\n}\nint popcnt(ull x) {\n  return __builtin_popcountll(x);\n\
    }\nint popcnt(ll x) {\n  return __builtin_popcountll(x);\n}\nint bsr(uint x) {\n\
    \  return 31 - __builtin_clz(x);\n}\nint bsr(ull x) {\n  return 63 - __builtin_clzll(x);\n\
    }\nint ctz(int x) {\n  return __builtin_ctz(x);\n}\nint ctz(ll x) {\n  return\
    \ __builtin_ctzll(x);\n}\nint ctz(ull x) {\n  return __builtin_ctzll(x);\n}\n\n\
    #define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define\
    \ MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\n#define\
    \ LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\nll ceil(ll x, ll y) {\n    assert(y >= 1);\n    return (x > 0 ?\
    \ (x + y - 1) / y : x / y);\n}\n\nll floor(ll x, ll y) {\n    assert(y >= 1);\n\
    \    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\nll mod(ll x, ll y) {\n  return\
    \ x - y * floor(x, y);\n}\n\n#define INT(...) \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define LL(...) \\\n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)\
    \ \\\n  string __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...) \\\n  char\
    \ __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define DBL(...) \\\n  long double __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\nvoid scan(int &a) { cin >> a; }\nvoid scan(long long\
    \ &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double &a) {\
    \ cin >> a; }\nvoid scan(long double &a) { cin >> a; }\nvoid scan(string &a) {\
    \ cin >> a; }\ntemplate <class T, class S> void scan(pair<T, S> &p) { scan(p.first),\
    \ scan(p.second); }\ntemplate <class T> void scan(vector<T> &a) {for(auto &i :\
    \ a) scan(i);}\ntemplate <class T> void scan(T &a) { cin >> a; }\nvoid IN() {}\n\
    template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {\n  scan(head);\n\
    \  IN(tail...);\n}\n\nll isqrt(ll n) {\n  ll x = n, y = (n + 1) / 2;\n  while\
    \ (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }\n  return x;\n}\n\nvi s_to_vi(string\
    \ S, char first_char='a'){\n  vi A(S.size());\n  FOR(i, S.size()){\n    A[i] =\
    \ S[i] - first_char;\n  }\n  return A;\n}\n\ntemplate <typename T, typename U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& A) {\n  os << A.fi << \" \"\
    \ << A.se;\n  return os;\n}\n\ntemplate <typename T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& A) {\n  for (size_t i = 0; i < A.size(); i++) {\n    if(i)\
    \ os << \" \";\n    os << A[i];\n  }\n  return os;\n}\n\nvoid print() {\n  cout\
    \ << \"\\n\";\n}\n\ntemplate <class Head, class... Tail>\nvoid print(Head&& head,\
    \ Tail&&... tail) {\n  cout << head;\n  if (sizeof...(Tail)) cout << \" \";\n\
    \  print(forward<Tail>(tail)...);\n}\n\nconst string YESNO[2] = {\"NO\", \"YES\"\
    };\nconst string YesNo[2] = {\"No\", \"Yes\"};\nconst string yesno[2] = {\"no\"\
    , \"yes\"};\nvoid YES(bool t = 1) { cout << YESNO[t] << endl; }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { cout << YesNo[t] << endl; }\nvoid\
    \ No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { cout << yesno[t] << endl;\
    \ }\nvoid no(bool t = 1) { yes(!t); }\n\ntemplate <typename T>\nvector<T> cumsum(vector<T>\
    \ A) {\n  ll N = A.size();\n  vector<T> B(N + 1);\n  B[0] = T(0);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  return B;\n}\n\nvi bin_count(vi& A, ll size)\
    \ {\n  vi C(size);\n  for (auto&& x : A) {\n    ++C[x];\n  }\n  return C;\n}\n\
    \ntemplate <typename T>\nvi argsort(vector<T>& A){\n  vi ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](ll i, ll j){\n    return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j);\n  });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check,\
    \ ll ok, ll ng) {\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    if (check(x))\n      ok = x;\n    else\n      ng = x;\n  }\n  return ok;\n\
    }\n\ntemplate <class T, class S> inline bool chmax(T &a, const S &b) { return\
    \ (a < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
    \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\ntemplate <typename T>\nvc<T>\
    \ merge_sort(vc<T>& A, vc<T>& B) {\n  vc<T> C;\n  C.reserve(A.size() + B.size());\n\
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 3 \"ds/lichao.hpp\"\
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
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lichao.hpp
layout: document
redirect_from:
- /library/ds/lichao.hpp
- /library/ds/lichao.hpp.html
title: ds/lichao.hpp
---
