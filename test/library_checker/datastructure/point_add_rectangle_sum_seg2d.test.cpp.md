---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algebra/addgroup.hpp
    title: algebra/addgroup.hpp
  - icon: ':x:'
    path: ds/segtree2d.hpp
    title: ds/segtree2d.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: point_add_rectangle_sum
    links: []
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp\"\
    \n#define PROBLEM \"point_add_rectangle_sum\"\r\n\r\n#line 2 \"my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ll8 = __int128;\nusing ld = long double;\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 4 \"test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp\"\
    \n\r\n#line 1 \"algebra/addgroup.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\n\
    struct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/segtree2d.hpp\"\ntemplate\
    \ <typename Monoid, typename XY, bool SMALL = false>\r\nstruct SegTree2D {\r\n\
    \  using S = typename Monoid::value_type;\r\n  int N;\r\n  int full_N;\r\n  vc<XY>\
    \ keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\n  vc<XY> keyY;\r\n  vc<S> dat;\r\
    \n\r\n  inline int xtoi(int x) {\r\n    return (SMALL ? clamp(x - min_X, 0, N)\
    \ : LB(keyX, x));\r\n  }\r\n\r\n  SegTree2D(vc<XY>& X, vc<XY>& Y, vc<S>& wt =\
    \ vc<S>()) {\r\n    if (len(wt) == 0) wt = vc<S>(len(X), S(0));\r\n    assert(Monoid::commute);\
    \ // \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u306E\u307F\r\n    assert(len(X) ==\
    \ len(Y) && len(X) == len(wt));\r\n\r\n    if (!SMALL) {\r\n      keyX = X;\r\n\
    \      UNIQUE(keyX);\r\n      N = len(keyX);\r\n    } else {\r\n      min_X =\
    \ (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X\
    \ + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\n  \
    \  }\r\n\r\n    vc<vc<XY>> keyY_raw(N + N);\r\n    vc<vc<S>> dat_raw(N + N);\r\
    \n\r\n    auto I = argsort(Y);\r\n    for (auto&& i: I) {\r\n      int ix = xtoi(X[i]),\
    \ y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\
    \n        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n    \
    \      dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = Monoid::op(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\
    \n      }\r\n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N)\
    \ indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\
    \n    keyY.resize(full_N);\r\n    dat.assign(2 * full_N, Monoid::unit);\r\n  \
    \  FOR(i, N + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n     \
    \   dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR3_R(j, 1, n)\r\n\
    \      dat[off + j] = Monoid::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\
    \n    }\r\n  }\r\n\r\n  void multiply_i(int i, XY y, S val) {\r\n    int LID =\
    \ indptr[i], n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\
    \n    int j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID + j] ==\
    \ y);\r\n    int off = 2 * LID;\r\n    j += n;\r\n\r\n    while (j) {\r\n    \
    \  dat[off + j] = Monoid::op(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n\
    \  }\r\n\r\n  void multiply(XY x, XY y, S val) {\r\n    int i = xtoi(x);\r\n \
    \   assert(keyX[i] == x);\r\n    i += N;\r\n    while (i) {\r\n      multiply_i(i,\
    \ y, val);\r\n      i >>= 1;\r\n    }\r\n  }\r\n\r\n  S prod_i(int i, XY ly, XY\
    \ ry) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    auto\
    \ it = keyY.begin() + LID;\r\n    int L = lower_bound(it, it + n, ly) - it;\r\n\
    \    int R = lower_bound(it, it + n, ry) - it;\r\n    int off = 2 * LID;\r\n \
    \   L += n;\r\n    R += n;\r\n    S val = Monoid::unit;\r\n    while (L < R) {\r\
    \n      if (L & 1) val = Monoid::op(val, dat[off + (L++)]);\r\n      if (R & 1)\
    \ val = Monoid::op(dat[off + (--R)], val);\r\n      L >>= 1;\r\n      R >>= 1;\r\
    \n    }\r\n    return val;\r\n  }\r\n\r\n  S prod(XY lx, XY rx, XY ly, XY ry)\
    \ {\r\n    int L = xtoi(lx);\r\n    int R = xtoi(rx);\r\n    L += N;\r\n    R\
    \ += N;\r\n    S val = Monoid::unit;\r\n    while (L < R) {\r\n      if (L & 1)\
    \ val = Monoid::op(val, prod_i(L++, ly, ry));\r\n      if (R & 1) val = Monoid::op(prod_i(--R,\
    \ ly, ry), val);\r\n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\"\
    , indptr);\r\n    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n\
    };\n#line 7 \"test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  vc<int> X(N), Y(N);\r\n  vi W(N);\r\n\
    \  FOR(i, N) {\r\n    LL(x, y, w);\r\n    X[i] = x, Y[i] = y, W[i] = w;\r\n  }\r\
    \n  using QQ = tuple<ll, ll, ll, ll>;\r\n  vc<QQ> query(Q);\r\n  FOR(q, Q) {\r\
    \n    LL(t);\r\n    if (t == 0) {\r\n      LL(x, y, w);\r\n      X.eb(x);\r\n\
    \      Y.eb(y);\r\n      W.eb(0);\r\n      query[q] = mt(-1, x, y, w);\r\n   \
    \ } else {\r\n      LL(a, b, c, d);\r\n      query[q] = mt(a, c, b, d);\r\n  \
    \  }\r\n  }\r\n\r\n  using Mono = AddGroup<ll>;\r\n\r\n  SegTree2D<Mono, int,\
    \ false> seg(X, Y, W);\r\n\r\n  FOR(q, Q) {\r\n    auto [a, b, c, d] = query[q];\r\
    \n    if (a == -1) {\r\n      seg.multiply(b, c, d);\r\n    } else {\r\n     \
    \ print(seg.prod(a, b, c, d));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n\
    \  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"point_add_rectangle_sum\"\r\n\r\n#include \"my_template.hpp\"\
    \r\n\r\n#include \"algebra/addgroup.hpp\"\r\n#include \"ds/segtree2d.hpp\"\r\n\
    \r\nvoid solve() {\r\n  LL(N, Q);\r\n  vc<int> X(N), Y(N);\r\n  vi W(N);\r\n \
    \ FOR(i, N) {\r\n    LL(x, y, w);\r\n    X[i] = x, Y[i] = y, W[i] = w;\r\n  }\r\
    \n  using QQ = tuple<ll, ll, ll, ll>;\r\n  vc<QQ> query(Q);\r\n  FOR(q, Q) {\r\
    \n    LL(t);\r\n    if (t == 0) {\r\n      LL(x, y, w);\r\n      X.eb(x);\r\n\
    \      Y.eb(y);\r\n      W.eb(0);\r\n      query[q] = mt(-1, x, y, w);\r\n   \
    \ } else {\r\n      LL(a, b, c, d);\r\n      query[q] = mt(a, c, b, d);\r\n  \
    \  }\r\n  }\r\n\r\n  using Mono = AddGroup<ll>;\r\n\r\n  SegTree2D<Mono, int,\
    \ false> seg(X, Y, W);\r\n\r\n  FOR(q, Q) {\r\n    auto [a, b, c, d] = query[q];\r\
    \n    if (a == -1) {\r\n      seg.multiply(b, c, d);\r\n    } else {\r\n     \
    \ print(seg.prod(a, b, c, d));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n\
    \  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - algebra/addgroup.hpp
  - ds/segtree2d.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 17:04:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
---
