---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':warning:'
    path: geo/convexhull.hpp
    title: geo/convexhull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\n\ntemplate<typename X = long long>\nstruct\
    \ Point {\n  X x, y;\n  Point(X x=0, X y=0) : x(x), y(y) {}\n\n  template <typename\
    \ S, typename T>\n  Point(pair<S, T> p) : x(p.fi), y(p.se) {}\n\n  Point operator-(Point\
    \ p) const { return {x - p.x, y - p.y}; }\n  X det(Point p) const { return x *\
    \ p.y - y * p.x; }\n  X dot(Point p) const { return x * p.x + y * p.y; }\n  bool\
    \ operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n    return y\
    \ < p.y;\n  }\n  bool operator==(Point p) const { return x == p.x && y == p.y;\
    \ }\n  Point operator-() const { return {-x, -y}; }\n};\n#line 2 \"geo/convexhull.hpp\"\
    \n\r\ntemplate<typename T>\r\nvector<T> ConvexHull(vector<pair<T, T>>& XY, string\
    \ mode = \"full\",\r\n                      bool inclusive = false, bool sorted\
    \ = false) {\r\n  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\"\
    );\r\n  ll N = XY.size();\r\n  if (N == 1) return {0};\r\n  if (N == 2) return\
    \ {0, 1};\r\n  vc<int> I = argsort(XY);\r\n\r\n  auto check = [&](ll i, ll j,\
    \ ll k) -> bool {\r\n    auto xi = XY[i].fi, yi = XY[i].se;\r\n    auto xj = XY[j].fi,\
    \ yj = XY[j].se;\r\n    auto xk = XY[k].fi, yk = XY[k].se;\r\n    auto dx1 = xj\
    \ - xi, dy1 = yj - yi;\r\n    auto dx2 = xk - xj, dy2 = yk - yj;\r\n    ll det\
    \ = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive ? det >= 0 : det > 0);\r\n\
    \  };\r\n\r\n  auto calc = [&]() {\r\n    vector<int> P;\r\n    for (auto&& k:\
    \ I) {\r\n      while (P.size() > 1) {\r\n        auto i = P[P.size() - 2];\r\n\
    \        auto j = P[P.size() - 1];\r\n        if (check(i, j, k)) break;\r\n \
    \       P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\n    return P;\r\
    \n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode == \"lower\") {\r\
    \n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n  if (mode\
    \ == \"full\" || mode == \"upper\") {\r\n    if (!P.empty()) P.pop_back();\r\n\
    \    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P) >= 2 && P[0]\
    \ == P.back()) P.pop_back();\r\n  return P;\r\n}\r\n\r\ntemplate<typename X>\r\
    \nvc<int> ConvexHull(vector<Point<X>>& XY, string mode = \"full\",\r\n       \
    \               bool inclusive = false, bool sorted = false) {\r\n  assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\
    \n  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].x,\
    \ yi = XY[i].y;\r\n    auto xj = XY[j].x, yj = XY[j].y;\r\n    auto xk = XY[k].x,\
    \ yk = XY[k].y;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vc<int> P;\r\
    \n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i =\
    \ P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}\n#line 3 \"ds/cht_xy.hpp\"\
    \n\r\ntemplate <typename T = ll>\r\nstruct CHT_xy {\r\n  /*\r\n  \u3044\u308D\u3093\
    \u306A (a, b) \u3092\u5165\u308C\u308B \u2192 ax+by \u306E min, max \u3092\u691C\
    \u7D22\u3059\u308B\r\n  */\r\n  using P = Point<T>;\r\n  vc<P> points;\r\n  bool\
    \ is_prepared = 0;\r\n\r\n  void add(P p) {\r\n    assert(!is_prepared);\r\n \
    \   points.eb(p);\r\n  }\r\n\r\n  void add(T a, T b) { add(Point(a, b)); }\r\n\
    \r\n  template <typename A, typename B>\r\n  void add(pair<A, B> p) {\r\n    add(Point(p));\r\
    \n  }\r\n\r\n  int size() { return len(points); }\r\n\r\n  void build() {\r\n\
    \    assert(!is_prepared);\r\n    is_prepared = 1;\r\n    vc<P> tmp;\r\n    auto\
    \ I = ConvexHull(points);\r\n    for (auto&& i: I) tmp.eb(points[i]);\r\n    points\
    \ = tmp;\r\n  }\r\n\r\n  T eval_at(T x, T y, int n) {\r\n    n %= points.size();\r\
    \n    auto& p = points[n];\r\n    return p.x * x + p.y * y;\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  T minimize(int n, F f) {\r\n    // \u300C\u72ED\u7FA9\u5358\
    \u8ABF\u5897\u52A0 \u2192 \u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\u300D\u306A\u5468\
    \u671F n \u306E\u95A2\u6570\u306E\u6700\u5C0F\u5316\r\n    int a = 0, b = n, c\
    \ = 2 * n;\r\n    while (c - a > 2) {\r\n      int l = (a + b) / 2, r = (b + c\
    \ + 1) / 2;\r\n      if (f(l) < f(b)) tie(c, b) = mp(b, l);\r\n      elif (f(b)\
    \ > f(r)) tie(a, b) = mp(b, r);\r\n      else tie(a, c) = mp(l, r);\r\n    }\r\
    \n    return f(b);\r\n  }\r\n\r\n  T get_min(T x, T y) {\r\n    assert(is_prepared\
    \ && size());\r\n    auto f = [&](ll n) -> T { return eval_at(x, y, n); };\r\n\
    \    return minimize(size(), f);\r\n  }\r\n\r\n  T get_max(T x, T y) {\r\n   \
    \ assert(is_prepared && size());\r\n    auto f = [&](ll n) -> T { return -eval_at(x,\
    \ y, n); };\r\n    return -minimize(size(), f);\r\n  }\r\n};\r\n"
  code: "#include \"geo/base.hpp\"\r\n#include \"geo/convexhull.hpp\"\r\n\r\ntemplate\
    \ <typename T = ll>\r\nstruct CHT_xy {\r\n  /*\r\n  \u3044\u308D\u3093\u306A (a,\
    \ b) \u3092\u5165\u308C\u308B \u2192 ax+by \u306E min, max \u3092\u691C\u7D22\u3059\
    \u308B\r\n  */\r\n  using P = Point<T>;\r\n  vc<P> points;\r\n  bool is_prepared\
    \ = 0;\r\n\r\n  void add(P p) {\r\n    assert(!is_prepared);\r\n    points.eb(p);\r\
    \n  }\r\n\r\n  void add(T a, T b) { add(Point(a, b)); }\r\n\r\n  template <typename\
    \ A, typename B>\r\n  void add(pair<A, B> p) {\r\n    add(Point(p));\r\n  }\r\n\
    \r\n  int size() { return len(points); }\r\n\r\n  void build() {\r\n    assert(!is_prepared);\r\
    \n    is_prepared = 1;\r\n    vc<P> tmp;\r\n    auto I = ConvexHull(points);\r\
    \n    for (auto&& i: I) tmp.eb(points[i]);\r\n    points = tmp;\r\n  }\r\n\r\n\
    \  T eval_at(T x, T y, int n) {\r\n    n %= points.size();\r\n    auto& p = points[n];\r\
    \n    return p.x * x + p.y * y;\r\n  }\r\n\r\n  template <typename F>\r\n  T minimize(int\
    \ n, F f) {\r\n    // \u300C\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 \u2192 \u72ED\
    \u7FA9\u5358\u8ABF\u6E1B\u5C11\u300D\u306A\u5468\u671F n \u306E\u95A2\u6570\u306E\
    \u6700\u5C0F\u5316\r\n    int a = 0, b = n, c = 2 * n;\r\n    while (c - a > 2)\
    \ {\r\n      int l = (a + b) / 2, r = (b + c + 1) / 2;\r\n      if (f(l) < f(b))\
    \ tie(c, b) = mp(b, l);\r\n      elif (f(b) > f(r)) tie(a, b) = mp(b, r);\r\n\
    \      else tie(a, c) = mp(l, r);\r\n    }\r\n    return f(b);\r\n  }\r\n\r\n\
    \  T get_min(T x, T y) {\r\n    assert(is_prepared && size());\r\n    auto f =\
    \ [&](ll n) -> T { return eval_at(x, y, n); };\r\n    return minimize(size(),\
    \ f);\r\n  }\r\n\r\n  T get_max(T x, T y) {\r\n    assert(is_prepared && size());\r\
    \n    auto f = [&](ll n) -> T { return -eval_at(x, y, n); };\r\n    return -minimize(size(),\
    \ f);\r\n  }\r\n};\r\n"
  dependsOn:
  - geo/base.hpp
  - geo/convexhull.hpp
  isVerificationFile: false
  path: ds/cht_xy.hpp
  requiredBy: []
  timestamp: '2022-03-14 00:34:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/cht_xy.hpp
layout: document
redirect_from:
- /library/ds/cht_xy.hpp
- /library/ds/cht_xy.hpp.html
title: ds/cht_xy.hpp
---
