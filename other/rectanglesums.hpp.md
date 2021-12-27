---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"ds/fenwick.hpp\"\ntemplate <typename T>\nstruct FenwickTree\
    \ {\n  vector<T> data;\n  T total;\n\n  FenwickTree() : total(0) {}\n  FenwickTree(int\
    \ sz) : total(0) { data.assign(++sz, 0); }\n\n  void init(int n) { data.assign(++n,\
    \ 0); }\n\n  void build(vector<T>& raw_data) {\n    assert(len(data) == len(raw_data)\
    \ + 1);\n    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];\n    FOR(i, len(data))\
    \ {\n      int j = i + (i & -i);\n      if (j < len(data)) data[j] += data[i];\n\
    \    }\n  }\n\n  T sum(int k) {\n    T ret = 0;\n    for (; k > 0; k -= k & -k)\
    \ ret += data[k];\n    return (ret);\n  }\n\n  T sum(int L, int R) {\n    T ret\
    \ = 0;\n    while (L < R) {\n      ret += data[R];\n      R -= R & -R;\n    }\n\
    \    while (R < L) {\n      ret -= data[L];\n      L -= L & -L;\n    }\n    return\
    \ ret;\n  }\n\n  T sum_all() { return total; }\n\n  void add(int k, T x) {\n \
    \   total += x;\n    for (++k; k < data.size(); k += k & -k) data[k] += x;\n \
    \ }\n\n  template <class F>\n  int max_right(F& check) {\n    assert(f(T(0)));\n\
    \    ll i = 0;\n    T s = 0;\n    int k = 1;\n    int N = len(data);\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(s + data[i\
    \ + k])) {\n        i += k;\n        s += data[i];\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(T k) {\n    auto check =\
    \ [&](T x) -> bool { return x < k; };\n    return max_right(check);\n  }\n\n \
    \ void debug() { print(data); }\n};\n\ntemplate <typename T>\nstruct Fenwick_RAQ\
    \ {\n  int N;\n  FenwickTree<T> bit0;\n  FenwickTree<T> bit1;\n\n  Fenwick_RAQ(int\
    \ N) : N(N), bit0(N), bit1(N) {}\n  Fenwick_RAQ() {}\n\n  void init(int n) {\n\
    \    N = n;\n    bit0.init(n);\n    bit1.init(n);\n  }\n\n  void build(vc<T>&\
    \ v) { bit0.build(v); }\n\n  void add_at(ll i, T val) { bit0.add(i, val); }\n\n\
    \  void add_range(ll L, ll R, T val) {\n    bit0.add(L, -val * L);\n    bit1.add(L,\
    \ +val);\n    bit0.add(R, +val * R);\n    bit1.add(R, -val);\n  }\n\n  T sum(ll\
    \ L, ll R) {\n    T sum_R = R * bit1.sum(R) + bit0.sum(R);\n    T sum_L = L *\
    \ bit1.sum(L) + bit0.sum(L);\n    return sum_R - sum_L;\n  }\n};\n#line 2 \"other/rectanglesums.hpp\"\
    \n\r\ntemplate <typename WT = ll, bool SMALL = false>\r\nstruct RectangleSums\
    \ {\r\n  int N;\r\n  int n, Q;\r\n  vi X, Y;\r\n  vi keyX, keyY;\r\n  ll min_x,\
    \ max_x, min_y, max_y;\r\n  vc<WT> wt;\r\n  vc<vc<pair<int, WT>>> add;\r\n  vc<vc<tuple<int,\
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
    \n    FenwickTree<WT> bit(k);\r\n    FOR(x, len(add)) {\r\n      FORIN(t, query_l[x])\
    \ {\r\n        auto [q, yl, yr] = t;\r\n        ANS[q] -= bit.sum(yl, yr);\r\n\
    \      }\r\n      FORIN(t, query_r[x]) {\r\n        auto [q, yl, yr] = t;\r\n\
    \        ANS[q] += bit.sum(yl, yr);\r\n      }\r\n      FORIN(t, add[x]) {\r\n\
    \        auto [y, w] = t;\r\n        bit.add(y, w);\r\n      }\r\n      query_l[x].clear();\r\
    \n      query_r[x].clear();\r\n    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\
    \n\r\n  void doc() {\r\n    print(\"N \u500B\u306E\u70B9\u306F\u6700\u521D\u306B\
    \u6C7A\u3081\u3066\u3057\u307E\u3046\u3002\");\r\n    print(\"\u540C\u3058\u70B9\
    \u7FA4\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\
    \u308B\u3002\"); // abc233-h\r\n    print(\"SMALL=true \u306B\u3059\u308B\u3068\
    \u3001\u5EA7\u5727\u3092\u3057\u306A\u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\
    \");\r\n  }\r\n};\r\n"
  code: "#include \"ds/fenwick.hpp\"\r\n\r\ntemplate <typename WT = ll, bool SMALL\
    \ = false>\r\nstruct RectangleSums {\r\n  int N;\r\n  int n, Q;\r\n  vi X, Y;\r\
    \n  vi keyX, keyY;\r\n  ll min_x, max_x, min_y, max_y;\r\n  vc<WT> wt;\r\n  vc<vc<pair<int,\
    \ WT>>> add;\r\n  vc<vc<tuple<int, int, int>>> query_l;\r\n  vc<vc<tuple<int,\
    \ int, int>>> query_r;\r\n\r\n  RectangleSums(int N)\r\n      : N(N), n(0), Q(0),\
    \ X(N), Y(N), keyX(N), keyY(N), wt(N) {}\r\n\r\n  void add_pt(ll x, ll y, WT w\
    \ = 1) {\r\n    X[n] = x, Y[n] = y, wt[n] = w, keyX[n] = x, keyY[n] = y;\r\n \
    \   ++n;\r\n    if (n == N) { compress(); }\r\n  }\r\n\r\n  void compress() {\r\
    \n    if (!SMALL) {\r\n      UNIQUE(keyX), UNIQUE(keyY);\r\n      add.resize(len(keyX)\
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
    \ + 2 : len(keyY) + 1);\r\n    FenwickTree<WT> bit(k);\r\n    FOR(x, len(add))\
    \ {\r\n      FORIN(t, query_l[x]) {\r\n        auto [q, yl, yr] = t;\r\n     \
    \   ANS[q] -= bit.sum(yl, yr);\r\n      }\r\n      FORIN(t, query_r[x]) {\r\n\
    \        auto [q, yl, yr] = t;\r\n        ANS[q] += bit.sum(yl, yr);\r\n     \
    \ }\r\n      FORIN(t, add[x]) {\r\n        auto [y, w] = t;\r\n        bit.add(y,\
    \ w);\r\n      }\r\n      query_l[x].clear();\r\n      query_r[x].clear();\r\n\
    \    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    N \u500B\u306E\u70B9\u306F\u6700\u521D\u306B\u6C7A\u3081\u3066\u3057\u307E\u3046\
    \u3002\");\r\n    print(\"\u540C\u3058\u70B9\u7FA4\u306B\u5BFE\u3057\u3066\u30AF\
    \u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\u308B\u3002\"); // abc233-h\r\n   \
    \ print(\"SMALL=true \u306B\u3059\u308B\u3068\u3001\u5EA7\u5727\u3092\u3057\u306A\
    \u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\");\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/fenwick.hpp
  isVerificationFile: false
  path: other/rectanglesums.hpp
  requiredBy: []
  timestamp: '2021-12-27 09:12:02+09:00'
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
