---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/convexhull.hpp\"\nvector<ll> ConvexHull(vector<pair<ll,\
    \ ll>>& XY, string mode = \"full\",\r\n                      bool inclusive =\
    \ false) {\r\n  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\"\
    );\r\n  ll N = XY.size();\r\n  if (N == 1) return {0};\r\n  if (N == 2) return\
    \ {0, 1};\r\n  auto I = argsort(XY);\r\n\r\n  auto check = [&](ll i, ll j, ll\
    \ k) -> bool {\r\n    auto xi = XY[i].fi, yi = XY[i].se;\r\n    auto xj = XY[j].fi,\
    \ yj = XY[j].se;\r\n    auto xk = XY[k].fi, yk = XY[k].se;\r\n    auto dx1 = xj\
    \ - xi, dy1 = yj - yi;\r\n    auto dx2 = xk - xj, dy2 = yk - yj;\r\n    ll det\
    \ = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive ? det >= 0 : det > 0);\r\n\
    \  };\r\n\r\n  auto calc = [&]() {\r\n    vector<ll> P;\r\n    FORIN(k, I) {\r\
    \n      while (P.size() > 1) {\r\n        auto i = P[P.size() - 2];\r\n      \
    \  auto j = P[P.size() - 1];\r\n        if (check(i, j, k)) break;\r\n       \
    \ P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\n    return P;\r\n  };\r\
    \n\r\n  vi P;\r\n  if (mode == \"full\" || mode == \"lower\") {\r\n    vi Q =\
    \ calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n  if (mode == \"full\" ||\
    \ mode == \"upper\") {\r\n    if (!P.empty()) P.pop_back();\r\n    reverse(all(I));\r\
    \n    vi Q = calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n  if (mode ==\
    \ \"upper\") reverse(all(P));\r\n  return P;\r\n}\n"
  code: "vector<ll> ConvexHull(vector<pair<ll, ll>>& XY, string mode = \"full\",\r\
    \n                      bool inclusive = false) {\r\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\n  if (N\
    \ == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  auto I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].fi,\
    \ yi = XY[i].se;\r\n    auto xj = XY[j].fi, yj = XY[j].se;\r\n    auto xk = XY[k].fi,\
    \ yk = XY[k].se;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vector<ll>\
    \ P;\r\n    FORIN(k, I) {\r\n      while (P.size() > 1) {\r\n        auto i =\
    \ P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vi P;\r\n  if (mode == \"full\" || mode == \"\
    lower\") {\r\n    vi Q = calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n\
    \  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty()) P.pop_back();\r\
    \n    reverse(all(I));\r\n    vi Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  return P;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo/convexhull.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/convexhull.hpp
layout: document
redirect_from:
- /library/geo/convexhull.hpp
- /library/geo/convexhull.hpp.html
title: geo/convexhull.hpp
---
