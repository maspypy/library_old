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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_reverse.hpp\"\ntemplate <class Group>\r\n\
    struct ReverseGroup {\r\n  using value_type = typename Group::value_type;\r\n\
    \  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Group::op(y, x); }\r\n  static constexpr X inverse(const X &x) { return\
    \ Group::inverse(x); }\r\n  static constexpr X unit = Group::unit;\r\n  static\
    \ const bool commute = Group::commute;\r\n};\r\n"
  code: "template <class Group>\r\nstruct ReverseGroup {\r\n  using value_type = typename\
    \ Group::value_type;\r\n  using X = value_type;\r\n  static constexpr X op(const\
    \ X &x, const X &y) { return Group::op(y, x); }\r\n  static constexpr X inverse(const\
    \ X &x) { return Group::inverse(x); }\r\n  static constexpr X unit = Group::unit;\r\
    \n  static const bool commute = Group::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_reverse.hpp
  requiredBy:
  - graph/treegroup.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
documentation_of: algebra/group_reverse.hpp
layout: document
redirect_from:
- /library/algebra/group_reverse.hpp
- /library/algebra/group_reverse.hpp.html
title: algebra/group_reverse.hpp
---
