---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algebra/reversemonoid.hpp
    title: algebra/reversemonoid.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/lazytreemonoid.hpp
    title: graph/lazytreemonoid.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/reversemonoid.hpp\"\ntemplate <class Monoid>\r\n\
    struct ReverseMonoid {\r\n  using value_type = typename Monoid::value_type;\r\n\
    \  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit = Monoid::unit;\r\n\
    \  static const bool commute = Monoid::commute;\r\n};\r\n#line 2 \"algebra/reverselazy.hpp\"\
    \n\r\ntemplate <typename Lazy>\r\nstruct ReverseLazy {\r\n  using MX = typename\
    \ Lazy::X_structure;\r\n  using MA = typename Lazy::A_structure;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return Lazy::act(x, a); }\r\n};\r\n"
  code: "#include \"algebra/reversemonoid.hpp\"\r\n\r\ntemplate <typename Lazy>\r\n\
    struct ReverseLazy {\r\n  using MX = typename Lazy::X_structure;\r\n  using MA\
    \ = typename Lazy::A_structure;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return Lazy::act(x, a); }\r\
    \n};\r\n"
  dependsOn:
  - algebra/reversemonoid.hpp
  isVerificationFile: false
  path: algebra/reverselazy.hpp
  requiredBy:
  - graph/lazytreemonoid.hpp
  timestamp: '2021-12-31 00:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/reverselazy.hpp
layout: document
redirect_from:
- /library/algebra/reverselazy.hpp
- /library/algebra/reverselazy.hpp.html
title: algebra/reverselazy.hpp
---
