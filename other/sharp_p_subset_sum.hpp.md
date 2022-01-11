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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/fps_exp.hpp:\
    \ line -1: no such header\n"
  code: "#include \"polynomial/fps_exp.hpp\"\r\ntemplate<typename mint>\r\nvc<mint>\
    \ sharp_p_subset_sum(vc<int> S, int LIM) {\r\n  auto CNT = bincount(S, LIM);\r\
    \n  vc<mint> logf(LIM);\r\n  FOR3(x, 1, LIM) {\r\n    FOR3(d, 1, (LIM-1) / x +\
    \ 1) {\r\n      if (d & 1)\r\n        logf[d * x] += mint(CNT[x]) * inv<mint>(d);\r\
    \n      else\r\n        logf[d * x] -= mint(CNT[x]) * inv<mint>(d);\r\n    }\r\
    \n  }\r\n  return fps_exp(logf);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/sharp_p_subset_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/sharp_p_subset_sum.hpp
layout: document
redirect_from:
- /library/other/sharp_p_subset_sum.hpp
- /library/other/sharp_p_subset_sum.hpp.html
title: other/sharp_p_subset_sum.hpp
---
