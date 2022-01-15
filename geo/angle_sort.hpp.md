---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/base.hpp\"\nstruct Point {\n  ll x, y;\n  Point operator-(Point\
    \ p) const { return {x - p.x, y - p.y}; }\n  ll det(Point p) const { return x\
    \ * p.y - y * p.x; }\n  ll dot(Point p) const { return x * p.x + y * p.y; }\n\
    \  bool operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n    return\
    \ y < p.y;\n  }\n  bool operator==(Point p) const { return x == p.x && y == p.y;\
    \ }\n  Point operator-() const { return {-x, -y}; }\n};\n#line 2 \"geo/angle_sort.hpp\"\
    \n\r\nvector<int> angle_argsort(vector<Point>& P) {\r\n  auto is_lower = [](Point\
    \ P) { return (P.y < 0) || (P.y == 0 && P.x > 0); };\r\n  vector<int> lower, origin,\
    \ upper;\r\n  Point O = {0, 0};\r\n  FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\
    \n    elif (is_lower(P[i])) lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n \
    \ sort(all(lower), [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });\r\n\
    \  sort(all(upper), [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });\r\n\
    \  auto& I = lower;\r\n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(),\
    \ all(upper));\r\n  return I;\r\n}\r\n\r\nvoid angle_sort(vector<Point>& P) {\r\
    \n  auto I = angle_argsort(P);\r\n  vc<Point> Q(len(P));\r\n  FOR(i, len(P)) Q[i]\
    \ = P[I[i]];\r\n  P = Q;\r\n}\r\n"
  code: "#include \"geo/base.hpp\"\r\n\r\nvector<int> angle_argsort(vector<Point>&\
    \ P) {\r\n  auto is_lower = [](Point P) { return (P.y < 0) || (P.y == 0 && P.x\
    \ > 0); };\r\n  vector<int> lower, origin, upper;\r\n  Point O = {0, 0};\r\n \
    \ FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\n    elif (is_lower(P[i]))\
    \ lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(),\
    \ all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return I;\r\n}\r\n\r\n\
    void angle_sort(vector<Point>& P) {\r\n  auto I = angle_argsort(P);\r\n  vc<Point>\
    \ Q(len(P));\r\n  FOR(i, len(P)) Q[i] = P[I[i]];\r\n  P = Q;\r\n}\r\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/angle_sort.hpp
  requiredBy: []
  timestamp: '2022-01-15 18:40:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
documentation_of: geo/angle_sort.hpp
layout: document
redirect_from:
- /library/geo/angle_sort.hpp
- /library/geo/angle_sort.hpp.html
title: geo/angle_sort.hpp
---
