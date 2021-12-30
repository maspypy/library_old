---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/addgroup.hpp
    title: algebra/addgroup.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/fenwick.hpp\"\ntemplate <typename AbelGroup>\nstruct\
    \ FenwickTree {\n  using E = typename AbelGroup::value_type;\n  int n;\n  vector<E>\
    \ dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n  FenwickTree(int n)\
    \ : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat.assign(n\
    \ + 1, AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit)\
    \ {\n    assert(AbelGroup::commute);\n    dat.assign(n + 1, AbelGroup::unit);\n\
    \    FOR(i, n) dat[i + 1] = v[i];\n    FOR3(i, 1, n + 1) {\n      int j = i +\
    \ (i & -i);\n      if (j <= n) dat[j] = AbelGroup::op(dat[i], dat[j]);\n    }\n\
    \  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit;\n    for (; k > 0; k -=\
    \ k & -k) ret = AbelGroup::op(ret, dat[k]);\n    return ret;\n  }\n\n  E sum(int\
    \ L, int R) {\n    E pos = AbelGroup::unit;\n    while (L < R) {\n      pos =\
    \ AbelGroup::op(pos, dat[R]);\n      R -= R & -R;\n    }\n    E neg = AbelGroup::unit;\n\
    \    while (R < L) {\n      neg = AbelGroup::op(neg, dat[L]);\n      L -= L &\
    \ -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n  }\n\n\
    \  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total = AbelGroup::op(total,\
    \ x);\n    for (++k; k < len(dat); k += k & -k) dat[k] = AbelGroup::op(dat[k],\
    \ x);\n  }\n\n  template <class F>\n  int max_right(F& check) {\n    assert(f(E(0)));\n\
    \    ll i = 0;\n    E s = AbelGroup::unit;\n    int k = 1;\n    int N = len(dat);\n\
    \    while (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i]);\n  \
    \    }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E\
    \ k) {\n    auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 1 \"algebra/addgroup.hpp\"\
    \ntemplate <class X, X ZERO = X(0)>\r\nstruct AddGroup {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return n * x; }\r\n\
    \  static constexpr X unit = ZERO;\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"other/rectanglesums.hpp\"\n\r\ntemplate <typename WT = ll, bool\
    \ SMALL = false>\r\nstruct RectangleSums {\r\n  int N;\r\n  int n, Q;\r\n  vi\
    \ X, Y;\r\n  vi keyX, keyY;\r\n  ll min_x, max_x, min_y, max_y;\r\n  vc<WT> wt;\r\
    \n  vc<vc<pair<int, WT>>> add;\r\n  vc<vc<tuple<int, int, int>>> query_l;\r\n\
    \  vc<vc<tuple<int, int, int>>> query_r;\r\n\r\n  RectangleSums(int N)\r\n   \
    \   : N(N), n(0), Q(0), X(N), Y(N), keyX(N), keyY(N), wt(N) {}\r\n\r\n  void add_pt(ll\
    \ x, ll y, WT w = 1) {\r\n    X[n] = x, Y[n] = y, wt[n] = w, keyX[n] = x, keyY[n]\
    \ = y;\r\n    ++n;\r\n    if (n == N) { compress(); }\r\n  }\r\n\r\n  void compress()\
    \ {\r\n    if (!SMALL) {\r\n      UNIQUE(keyX), UNIQUE(keyY);\r\n      add.resize(len(keyX)\
    \ + 1);\r\n      FOR(i, N) {\r\n        ll x = X[i], y = Y[i], w = wt[i];\r\n\
    \        x = LB(keyX, x), y = LB(keyY, y);\r\n        add[x].eb(y, w);\r\n   \
    \   }\r\n    } else {\r\n      min_x = (N == 0 ? 0 : MIN(X));\r\n      max_x =\
    \ (N == 0 ? 0 : MAX(X));\r\n      min_y = (N == 0 ? 0 : MIN(Y));\r\n      max_y\
    \ = (N == 0 ? 0 : MAX(Y));\r\n      add.resize(max_x - min_x + 2);\r\n      FOR(i,\
    \ N) {\r\n        ll x = X[i], y = Y[i], w = wt[i];\r\n        x -= min_x, y -=\
    \ min_y;\r\n        add[x].eb(y, w);\r\n      }\r\n    }\r\n    query_l.resize(len(add));\r\
    \n    query_r.resize(len(add));\r\n  }\r\n\r\n  void add_rect(ll xl, ll xr, ll\
    \ yl, ll yr) {\r\n    assert(n == N);\r\n    if (!SMALL) {\r\n      xl = LB(keyX,\
    \ xl), xr = LB(keyX, xr);\r\n      yl = LB(keyY, yl), yr = LB(keyY, yr);\r\n \
    \   } else {\r\n      xl -= min_x, xr -= min_x;\r\n      yl -= min_y, yr -= min_y;\r\
    \n      xl = clamp(xl, 0LL, max_x - min_x + 1);\r\n      xr = clamp(xr, 0LL, max_x\
    \ - min_x + 1);\r\n      yl = clamp(yl, 0LL, max_y - min_y + 1);\r\n      yr =\
    \ clamp(yr, 0LL, max_y - min_y + 1);\r\n    }\r\n    query_l[xl].eb(Q, yl, yr);\r\
    \n    query_r[xr].eb(Q, yl, yr);\r\n    ++Q;\r\n  }\r\n\r\n  vc<WT> calc() {\r\
    \n    assert(n == N);\r\n    vc<WT> ANS(Q);\r\n    int k = (SMALL ? max_y - min_y\
    \ + 2 : len(keyY) + 1);\r\n    FenwickTree<AddGroup<WT>> bit(k);\r\n    FOR(x,\
    \ len(add)) {\r\n      for (auto&& t: query_l[x]) {\r\n        auto [q, yl, yr]\
    \ = t;\r\n        ANS[q] -= bit.sum(yl, yr);\r\n      }\r\n      for (auto&& t:\
    \ query_r[x]) {\r\n        auto [q, yl, yr] = t;\r\n        ANS[q] += bit.sum(yl,\
    \ yr);\r\n      }\r\n      for (auto&& t: add[x]) {\r\n        auto [y, w] = t;\r\
    \n        bit.add(y, w);\r\n      }\r\n      query_l[x].clear();\r\n      query_r[x].clear();\r\
    \n    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    N \u500B\u306E\u70B9\u306F\u6700\u521D\u306B\u6C7A\u3081\u3066\u3057\u307E\u3046\
    \u3002\");\r\n    print(\"\u540C\u3058\u70B9\u7FA4\u306B\u5BFE\u3057\u3066\u30AF\
    \u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\u308B\u3002\"); // abc233-h\r\n   \
    \ print(\"SMALL=true \u306B\u3059\u308B\u3068\u3001\u5EA7\u5727\u3092\u3057\u306A\
    \u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\");\r\n  }\r\n};\r\n"
  code: "#include \"ds/fenwick.hpp\"\r\n#include \"algebra/addgroup.hpp\"\r\n\r\n\
    template <typename WT = ll, bool SMALL = false>\r\nstruct RectangleSums {\r\n\
    \  int N;\r\n  int n, Q;\r\n  vi X, Y;\r\n  vi keyX, keyY;\r\n  ll min_x, max_x,\
    \ min_y, max_y;\r\n  vc<WT> wt;\r\n  vc<vc<pair<int, WT>>> add;\r\n  vc<vc<tuple<int,\
    \ int, int>>> query_l;\r\n  vc<vc<tuple<int, int, int>>> query_r;\r\n\r\n  RectangleSums(int\
    \ N)\r\n      : N(N), n(0), Q(0), X(N), Y(N), keyX(N), keyY(N), wt(N) {}\r\n\r\
    \n  void add_pt(ll x, ll y, WT w = 1) {\r\n    X[n] = x, Y[n] = y, wt[n] = w,\
    \ keyX[n] = x, keyY[n] = y;\r\n    ++n;\r\n    if (n == N) { compress(); }\r\n\
    \  }\r\n\r\n  void compress() {\r\n    if (!SMALL) {\r\n      UNIQUE(keyX), UNIQUE(keyY);\r\
    \n      add.resize(len(keyX) + 1);\r\n      FOR(i, N) {\r\n        ll x = X[i],\
    \ y = Y[i], w = wt[i];\r\n        x = LB(keyX, x), y = LB(keyY, y);\r\n      \
    \  add[x].eb(y, w);\r\n      }\r\n    } else {\r\n      min_x = (N == 0 ? 0 :\
    \ MIN(X));\r\n      max_x = (N == 0 ? 0 : MAX(X));\r\n      min_y = (N == 0 ?\
    \ 0 : MIN(Y));\r\n      max_y = (N == 0 ? 0 : MAX(Y));\r\n      add.resize(max_x\
    \ - min_x + 2);\r\n      FOR(i, N) {\r\n        ll x = X[i], y = Y[i], w = wt[i];\r\
    \n        x -= min_x, y -= min_y;\r\n        add[x].eb(y, w);\r\n      }\r\n \
    \   }\r\n    query_l.resize(len(add));\r\n    query_r.resize(len(add));\r\n  }\r\
    \n\r\n  void add_rect(ll xl, ll xr, ll yl, ll yr) {\r\n    assert(n == N);\r\n\
    \    if (!SMALL) {\r\n      xl = LB(keyX, xl), xr = LB(keyX, xr);\r\n      yl\
    \ = LB(keyY, yl), yr = LB(keyY, yr);\r\n    } else {\r\n      xl -= min_x, xr\
    \ -= min_x;\r\n      yl -= min_y, yr -= min_y;\r\n      xl = clamp(xl, 0LL, max_x\
    \ - min_x + 1);\r\n      xr = clamp(xr, 0LL, max_x - min_x + 1);\r\n      yl =\
    \ clamp(yl, 0LL, max_y - min_y + 1);\r\n      yr = clamp(yr, 0LL, max_y - min_y\
    \ + 1);\r\n    }\r\n    query_l[xl].eb(Q, yl, yr);\r\n    query_r[xr].eb(Q, yl,\
    \ yr);\r\n    ++Q;\r\n  }\r\n\r\n  vc<WT> calc() {\r\n    assert(n == N);\r\n\
    \    vc<WT> ANS(Q);\r\n    int k = (SMALL ? max_y - min_y + 2 : len(keyY) + 1);\r\
    \n    FenwickTree<AddGroup<WT>> bit(k);\r\n    FOR(x, len(add)) {\r\n      for\
    \ (auto&& t: query_l[x]) {\r\n        auto [q, yl, yr] = t;\r\n        ANS[q]\
    \ -= bit.sum(yl, yr);\r\n      }\r\n      for (auto&& t: query_r[x]) {\r\n   \
    \     auto [q, yl, yr] = t;\r\n        ANS[q] += bit.sum(yl, yr);\r\n      }\r\
    \n      for (auto&& t: add[x]) {\r\n        auto [y, w] = t;\r\n        bit.add(y,\
    \ w);\r\n      }\r\n      query_l[x].clear();\r\n      query_r[x].clear();\r\n\
    \    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    N \u500B\u306E\u70B9\u306F\u6700\u521D\u306B\u6C7A\u3081\u3066\u3057\u307E\u3046\
    \u3002\");\r\n    print(\"\u540C\u3058\u70B9\u7FA4\u306B\u5BFE\u3057\u3066\u30AF\
    \u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\u308B\u3002\"); // abc233-h\r\n   \
    \ print(\"SMALL=true \u306B\u3059\u308B\u3068\u3001\u5EA7\u5727\u3092\u3057\u306A\
    \u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\");\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/fenwick.hpp
  - algebra/addgroup.hpp
  isVerificationFile: false
  path: other/rectanglesums.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:13:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
documentation_of: other/rectanglesums.hpp
layout: document
redirect_from:
- /library/other/rectanglesums.hpp
- /library/other/rectanglesums.hpp.html
title: other/rectanglesums.hpp
---
