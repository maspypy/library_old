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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/group_cntsum.hpp:\
    \ line -1: no such header\n"
  code: "#include \"algebra/group_cntsum.hpp\"\r\n#include \"algebra/monoid_set.hpp\"\
    \r\n\r\ntemplate <typename E, E none_val>\r\nstruct Lazy_CntSum_Set {\r\n  using\
    \ X_structure = Group_CntSum<E>;\r\n  using A_structure = Monoid_Set<E, none_val>;\r\
    \n  using X = typename X_structure::value_type;\r\n  using A = typename A_structure::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    if(a == A_structure::unit)\
    \ return x;\r\n    return {x.fi, x.fi * a};\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/lazy_cntsum_set.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_cntsum_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntsum_set.hpp
- /library/alg/lazy_cntsum_set.hpp.html
title: alg/lazy_cntsum_set.hpp
---
