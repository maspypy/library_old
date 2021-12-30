---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/treegroup.hpp
    title: graph/treegroup.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/reversegroup.hpp\"\ntemplate <class Group>\r\nstruct\
    \ ReverseGroup {\r\n  using value_type = typename Group::value_type;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ Group::op(y, x); }\r\n  static constexpr X inverse(const X &x) { return Group::inverse(x);\
    \ }\r\n  static constexpr X unit = Group::unit;\r\n  static const bool commute\
    \ = Group::commute;\r\n};\r\n"
  code: "template <class Group>\r\nstruct ReverseGroup {\r\n  using value_type = typename\
    \ Group::value_type;\r\n  using X = value_type;\r\n  static constexpr X op(const\
    \ X &x, const X &y) { return Group::op(y, x); }\r\n  static constexpr X inverse(const\
    \ X &x) { return Group::inverse(x); }\r\n  static constexpr X unit = Group::unit;\r\
    \n  static const bool commute = Group::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/reversegroup.hpp
  requiredBy:
  - graph/treegroup.hpp
  timestamp: '2021-12-30 21:20:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
documentation_of: algebra/reversegroup.hpp
layout: document
redirect_from:
- /library/algebra/reversegroup.hpp
- /library/algebra/reversegroup.hpp.html
title: algebra/reversegroup.hpp
---
