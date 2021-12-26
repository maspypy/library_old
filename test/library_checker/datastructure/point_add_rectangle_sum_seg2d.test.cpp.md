---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree2d.hpp
    title: ds/segtree2d.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\r\
    \n\r\n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
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
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 1 \"ds/segtree2d.hpp\"\
    \ntemplate <typename E, bool SMALL = false>\r\nstruct SegTree2D {\r\n  using F\
    \ = function<E(E, E)>;\r\n  E E_unit;\r\n  F seg_f;\r\n  int N;\r\n  int full_N;\r\
    \n  vi keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\n  vi keyY;\r\n  vc<E> dat;\r\
    \n\r\n  SegTree2D(F f, E E_unit, vi& X, vi& Y, vc<E>& wt) : seg_f(f), E_unit(E_unit)\
    \ {\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  SegTree2D(vi& X, vi& Y) {\r\n    vc<E>\
    \ wt(len(X), E_unit);\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  inline int xtoi(int\
    \ x) {\r\n    return (SMALL ? clamp(x - min_X, 0, N) : LB(keyX, x));\r\n  }\r\n\
    \r\n  void build(vi& X, vi& Y, vc<E>& wt) {\r\n    if (!SMALL) {\r\n      keyX\
    \ = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\n    } else {\r\n    \
    \  min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\
    \n    }\r\n\r\n    vc<vi> keyY_raw(N + N);\r\n    vc<vc<E>> dat_raw(N + N);\r\n\
    \r\n    auto I = argsort(Y);\r\n    FORIN(i, I) {\r\n      int ix = xtoi(X[i]),\
    \ y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\
    \n        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n    \
    \      dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = seg_f(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\n  \
    \    }\r\n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N) indptr[i\
    \ + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\n\
    \    keyY.resize(full_N);\r\n    dat.assign(2 * full_N, E_unit);\r\n    FOR(i,\
    \ N + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      \
    \  dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR3_R(j, 1, n)\r\n \
    \     dat[off + j] = seg_f(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\n  \
    \  }\r\n  }\r\n\r\n  void multiply_i(int i, ll y, E val) {\r\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int\
    \ j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID + j] == y);\r\n\
    \    int off = 2 * LID;\r\n    j += n;\r\n\r\n    while (j) {\r\n      dat[off\
    \ + j] = seg_f(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n \
    \ void multiply(ll x, ll y, E val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i]\
    \ == x);\r\n    i += N;\r\n    while (i) {\r\n      multiply_i(i, y, val);\r\n\
    \      i >>= 1;\r\n    }\r\n  }\r\n\r\n  E prod_i(int i, ll ly, ll ry) {\r\n \
    \   E ret = 0;\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it, it + n, ly)\
    \ - it;\r\n    int R = lower_bound(it, it + n, ry) - it;\r\n    int off = 2 *\
    \ LID;\r\n    L += n;\r\n    R += n;\r\n    E val = E_unit;\r\n    while (L <\
    \ R) {\r\n      if (L & 1) val = seg_f(val, dat[off + (L++)]);\r\n      if (R\
    \ & 1) val = seg_f(dat[off + (--R)], val);\r\n      L >>= 1;\r\n      R >>= 1;\r\
    \n    }\r\n    return val;\r\n  }\r\n\r\n  E prod(ll lx, ll rx, ll ly, ll ry)\
    \ {\r\n    int L = xtoi(lx);\r\n    int R = xtoi(rx);\r\n    L += N;\r\n    R\
    \ += N;\r\n    E val = E_unit;\r\n    while (L < R) {\r\n      if (L & 1) val\
    \ = seg_f(val, prod_i(L++, ly, ry));\r\n      if (R & 1) val = seg_f(prod_i(--R,\
    \ ly, ry), val);\r\n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\"\
    , indptr);\r\n    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n\
    };\n#line 5 \"test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp\"\
    \n\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  vi X(N), Y(N), W(N);\r\n  FOR(i,\
    \ N) {\r\n    LL(x, y, w);\r\n    X[i] = x, Y[i] = y, W[i] = w;\r\n  }\r\n  using\
    \ QQ = tuple<ll, ll, ll, ll>;\r\n  vc<QQ> query(Q);\r\n  FOR(q, Q) {\r\n    LL(t);\r\
    \n    if (t == 0) {\r\n      LL(x, y, w);\r\n      X.eb(x);\r\n      Y.eb(y);\r\
    \n      W.eb(0);\r\n      query[q] = mt(-1, x, y, w);\r\n    } else {\r\n    \
    \  LL(a, b, c, d);\r\n      query[q] = mt(a, c, b, d);\r\n    }\r\n  }\r\n\r\n\
    \  SegTree2D<ll, false> seg([&](ll x, ll y) -> ll { return x + y; }, 0, X, Y,\
    \ W);\r\n\r\n  FOR(q, Q) {\r\n    auto [a, b, c, d] = query[q];\r\n    if (a ==\
    \ -1) {\r\n      seg.multiply(b, c, d);\r\n    } else {\r\n      print(seg.prod(a,\
    \ b, c, d));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"ds/segtree2d.hpp\"\r\n\r\n\r\
    \nvoid solve() {\r\n  LL(N, Q);\r\n  vi X(N), Y(N), W(N);\r\n  FOR(i, N) {\r\n\
    \    LL(x, y, w);\r\n    X[i] = x, Y[i] = y, W[i] = w;\r\n  }\r\n  using QQ =\
    \ tuple<ll, ll, ll, ll>;\r\n  vc<QQ> query(Q);\r\n  FOR(q, Q) {\r\n    LL(t);\r\
    \n    if (t == 0) {\r\n      LL(x, y, w);\r\n      X.eb(x);\r\n      Y.eb(y);\r\
    \n      W.eb(0);\r\n      query[q] = mt(-1, x, y, w);\r\n    } else {\r\n    \
    \  LL(a, b, c, d);\r\n      query[q] = mt(a, c, b, d);\r\n    }\r\n  }\r\n\r\n\
    \  SegTree2D<ll, false> seg([&](ll x, ll y) -> ll { return x + y; }, 0, X, Y,\
    \ W);\r\n\r\n  FOR(q, Q) {\r\n    auto [a, b, c, d] = query[q];\r\n    if (a ==\
    \ -1) {\r\n      seg.multiply(b, c, d);\r\n    } else {\r\n      print(seg.prod(a,\
    \ b, c, d));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - ds/segtree2d.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 17:51:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
---
