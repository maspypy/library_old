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
  bundledCode: "#line 1 \"graph/tree_dp.hpp\"\ntemplate <typename E, typename F1,\
    \ typename F2, typename F3, typename T>\r\npair<vc<T>, vc<T>> tree_dp(E& ET, F1\
    \ f_ee, F2 f_ev, F3 f_ve, T unit) {\r\n  auto& V = ET.V;\r\n  auto& G = ET.G;\r\
    \n  auto& par = ET.parent;\r\n  ll N = len(V);\r\n  vc<T> dp_v(N), dp_e(N);\r\n\
    \  FOR_R(i, N) {\r\n    auto v = V[i];\r\n    T dp = unit;\r\n    FORIN(e, G[v])\
    \ if (e.to != par[v]) {\r\n      dp_e[e.to] = f_ve(dp_v[e.to], e.id);\r\n    \
    \  dp = f_ee(dp, dp_e[e.to]);\r\n    }\r\n    dp_v[v] = f_ev(dp, v);\r\n  }\r\n\
    \  return {dp_v, dp_e};\r\n}\r\n"
  code: "template <typename E, typename F1, typename F2, typename F3, typename T>\r\
    \npair<vc<T>, vc<T>> tree_dp(E& ET, F1 f_ee, F2 f_ev, F3 f_ve, T unit) {\r\n \
    \ auto& V = ET.V;\r\n  auto& G = ET.G;\r\n  auto& par = ET.parent;\r\n  ll N =\
    \ len(V);\r\n  vc<T> dp_v(N), dp_e(N);\r\n  FOR_R(i, N) {\r\n    auto v = V[i];\r\
    \n    T dp = unit;\r\n    FORIN(e, G[v]) if (e.to != par[v]) {\r\n      dp_e[e.to]\
    \ = f_ve(dp_v[e.to], e.id);\r\n      dp = f_ee(dp, dp_e[e.to]);\r\n    }\r\n \
    \   dp_v[v] = f_ev(dp, v);\r\n  }\r\n  return {dp_v, dp_e};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_dp.hpp
  requiredBy: []
  timestamp: '2021-12-30 19:16:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_dp.hpp
layout: document
redirect_from:
- /library/graph/tree_dp.hpp
- /library/graph/tree_dp.hpp.html
title: graph/tree_dp.hpp
---
