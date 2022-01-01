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
  requiredBy: []
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group_reverse.hpp
layout: document
redirect_from:
- /library/algebra/group_reverse.hpp
- /library/algebra/group_reverse.hpp.html
title: algebra/group_reverse.hpp
---
