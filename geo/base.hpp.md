---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':heavy_check_mark:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/convex_layers.test.cpp
    title: test/library_checker/geometry/convex_layers.test.cpp
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
    \ }\n  Point operator-() const { return {-x, -y}; }\n};\n"
  code: "struct Point {\n  ll x, y;\n  Point operator-(Point p) const { return {x\
    \ - p.x, y - p.y}; }\n  ll det(Point p) const { return x * p.y - y * p.x; }\n\
    \  ll dot(Point p) const { return x * p.x + y * p.y; }\n  bool operator<(Point\
    \ p) const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  bool\
    \ operator==(Point p) const { return x == p.x && y == p.y; }\n  Point operator-()\
    \ const { return {-x, -y}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/base.hpp
  requiredBy:
  - geo/angle_sort.hpp
  - geo/dynamicupperhull.hpp
  timestamp: '2022-01-15 18:40:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/convex_layers.test.cpp
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
documentation_of: geo/base.hpp
layout: document
redirect_from:
- /library/geo/base.hpp
- /library/geo/base.hpp.html
title: geo/base.hpp
---
