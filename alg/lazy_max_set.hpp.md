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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid_min.hpp:\
    \ line -1: no such header\n"
  code: "#include \"algebra/monoid_min.hpp\"\r\n#include \"algebra/monoid_set.hpp\"\
    \r\n\r\ntemplate <typename E, E INF, E none_val>\r\nstruct Lazy_Max_Set {\r\n\
    \  using MX = Monoid_Max<E, INF>;\r\n  using MA = Monoid_Set<E, none_val>;\r\n\
    \  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) { return (a==none_val ? x : a) ;}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/lazy_max_set.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_max_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_max_set.hpp
- /library/alg/lazy_max_set.hpp.html
title: alg/lazy_max_set.hpp
---
