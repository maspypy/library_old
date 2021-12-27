---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fenwick2d.hpp
    title: ds/fenwick2d.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 2\
    \ \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing pi =\
    \ pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint = unsigned int;\nusing ull\
    \ = unsigned long long;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type,\
    \ name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n#define vv(type,\
    \ name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 4 \"test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp\"\
    \n\n#line 1 \"ds/fenwick2d.hpp\"\ntemplate <typename T, bool SMALL = false>\r\n\
    struct Fenwick2D {\r\n  int N;\r\n  vi keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\
    \n  vi keyY;\r\n  vc<T> dat;\r\n\r\n  Fenwick2D(vi& X, vi& Y, vc<T>& wt) { build(X,\
    \ Y, wt); }\r\n\r\n  Fenwick2D(vi& X, vi& Y) {\r\n    vc<T> wt(len(X), 0);\r\n\
    \    build(X, Y, wt);\r\n  }\r\n\r\n  inline int xtoi(int x) { return (SMALL ?\
    \ clamp(x - min_X, 0, N) : LB(keyX, x)); }\r\n\r\n  inline int nxt(int i) {\r\n\
    \    i += 1;\r\n    return i + (i & -i) - 1;\r\n  }\r\n\r\n  inline int prev(int\
    \ i) {\r\n    i += 1;\r\n    return i - (i & -i) - 1;\r\n  }\r\n\r\n  void build(vi&\
    \ X, vi& Y, vc<T>& wt) {\r\n    if (!SMALL) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\
    \n      N = len(keyX);\r\n    } else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\
    \n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\
    \n      FOR(i, N) keyX[i] = min_X + i;\r\n    }\r\n\r\n    vc<vi> keyY_raw(N);\r\
    \n    vc<vc<T>> dat_raw(N);\r\n\r\n    auto I = argsort(Y);\r\n    for (auto&&\
    \ i: I) {\r\n      int ix = xtoi(X[i]), y = Y[i];\r\n      while (ix < N) {\r\n\
    \        auto& KY = keyY_raw[ix];\r\n        if (len(KY) == 0 || KY.back() < y)\
    \ {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\n        } else\
    \ {\r\n          dat_raw[ix].back() += wt[i];\r\n        }\r\n        ix = nxt(ix);\r\
    \n      }\r\n    }\r\n\r\n    indptr.assign(N + 1, 0);\r\n    FOR(i, N) indptr[i\
    \ + 1] = indptr[i] + len(keyY_raw[i]);\r\n    keyY.resize(indptr.back());\r\n\
    \    dat.resize(indptr.back());\r\n    FOR(i, N) FOR(j, indptr[i + 1] - indptr[i])\
    \ {\r\n      keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      dat[indptr[i] + j]\
    \ = dat_raw[i][j];\r\n    }\r\n    FOR(i, N) {\r\n      int n = indptr[i + 1]\
    \ - indptr[i];\r\n      FOR(j, n - 1) {\r\n        int k = nxt(j);\r\n       \
    \ if (k < n) dat[indptr[i] + k] += dat[indptr[i] + j];\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  void add_i(int i, ll y, T val) {\r\n    int LID = indptr[i], n =\
    \ indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int j\
    \ = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID + j] == y);\r\n  \
    \  while (j < n) {\r\n      dat[LID + j] += val;\r\n      j = nxt(j);\r\n    }\r\
    \n  }\r\n\r\n  void add(ll x, ll y, T val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i]\
    \ == x);\r\n    while (i < N) {\r\n      add_i(i, y, val);\r\n      i = nxt(i);\r\
    \n    }\r\n  }\r\n\r\n  T sum_i(int i, ll ly, ll ry) {\r\n    T ret = 0;\r\n \
    \   int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin()\
    \ + LID;\r\n    int L = lower_bound(it, it + n, ly) - it - 1;\r\n    int R = lower_bound(it,\
    \ it + n, ry) - it - 1;\r\n    while (L < R) {\r\n      ret += dat[LID + R];\r\
    \n      R = prev(R);\r\n    }\r\n    while (R < L) {\r\n      ret -= dat[LID +\
    \ L];\r\n      L = prev(L);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  T sum(ll\
    \ lx, ll rx, ll ly, ll ry) {\r\n    T ret = 0;\r\n    int L = xtoi(lx) - 1;\r\n\
    \    int R = xtoi(rx) - 1;\r\n    while (L < R) {\r\n      ret += sum_i(R, ly,\
    \ ry);\r\n      R = prev(R);\r\n    }\r\n    while (R < L) {\r\n      ret -= sum_i(L,\
    \ ly, ry);\r\n      L = prev(L);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  void\
    \ debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n\
    \    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n};\n#line 6\
    \ \"test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp\"\n\nvoid\
    \ solve() {\n  LL(N, Q);\n  vi X(N), Y(N), W(N);\n  FOR(i, N) {\n    LL(x, y,\
    \ w);\n    X[i] = x, Y[i] = y, W[i] = w;\n  }\n  Fenwick2D<ll, false> bit(X, Y,\
    \ W);\n  FOR(_, Q) {\n    LL(l, d, r, u);\n    print(bit.sum(l, r, d, u));\n \
    \ }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"my_template.hpp\"\n\n#include \"ds/fenwick2d.hpp\"\n\nvoid solve() {\n  LL(N,\
    \ Q);\n  vi X(N), Y(N), W(N);\n  FOR(i, N) {\n    LL(x, y, w);\n    X[i] = x,\
    \ Y[i] = y, W[i] = w;\n  }\n  Fenwick2D<ll, false> bit(X, Y, W);\n  FOR(_, Q)\
    \ {\n    LL(l, d, r, u);\n    print(bit.sum(l, r, d, u));\n  }\n}\n\nsigned main()\
    \ {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/fenwick2d.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  requiredBy: []
  timestamp: '2021-12-27 17:43:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
- /verify/test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp.html
title: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
---
