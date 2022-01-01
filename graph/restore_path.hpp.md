---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/shortest_path.test.cpp
    title: test/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/restore_path.hpp\"\nvector<int> restore_path(vector<int>\
    \ par, int t){\r\n  vector<int> pth = {t};\r\n  while (par[pth.back()] != -1)\
    \ pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\n  return pth;\r\n}\n"
  code: "vector<int> restore_path(vector<int> par, int t){\r\n  vector<int> pth =\
    \ {t};\r\n  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\
    \n  return pth;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/restore_path.hpp
  requiredBy: []
  timestamp: '2022-01-01 12:00:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/shortest_path.test.cpp
documentation_of: graph/restore_path.hpp
layout: document
redirect_from:
- /library/graph/restore_path.hpp
- /library/graph/restore_path.hpp.html
title: graph/restore_path.hpp
---
