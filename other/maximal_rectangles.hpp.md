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
  bundledCode: "#line 1 \"other/maximal_rectangles.hpp\"\nvc<pi> maximal_rectangles(vector<ll>\
    \ H) {\n  /*\n  \u9AD8\u3055 H[i] \u306E\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u304C\
    \u4E0E\u3048\u3089\u308C\u308B\u3002\u5404 i \u306B\u5BFE\u3057\u3066\u3001\n\
    \  i \u756A\u76EE\u306E bar \u3092\u542B\u3080\u6975\u5927\u9577\u65B9\u5F62\u3092\
    \u8FD4\u3059\u3002\u6975\u5927\u9577\u65B9\u5F62\u304C [l,r) x [0,H[i]]\n  \u306E\
    \u3068\u304D\u306B\u3001pair (l, r) \u3092\u5165\u308C\u308B\u3002\n  */\n  ll\
    \ N = len(H);\n  vc<pi> LR(N);\n  vi st;\n  FOR(i, N) {\n    while (!st.empty()\
    \ && H[st.back()] >= H[i]) st.pop_back();\n    LR[i].fi = (st.empty() ? 0 : st.back()\
    \ + 1);\n    st.eb(i);\n  }\n  st.clear();\n  FOR_R(i, N) {\n    while (!st.empty()\
    \ && H[st.back()] >= H[i]) st.pop_back();\n    LR[i].se = (st.empty() ? N : st.back());\n\
    \    st.eb(i);\n  }\n  return LR;\n}\n"
  code: "vc<pi> maximal_rectangles(vector<ll> H) {\n  /*\n  \u9AD8\u3055 H[i] \u306E\
    \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u304C\u4E0E\u3048\u3089\u308C\u308B\u3002\
    \u5404 i \u306B\u5BFE\u3057\u3066\u3001\n  i \u756A\u76EE\u306E bar \u3092\u542B\
    \u3080\u6975\u5927\u9577\u65B9\u5F62\u3092\u8FD4\u3059\u3002\u6975\u5927\u9577\
    \u65B9\u5F62\u304C [l,r) x [0,H[i]]\n  \u306E\u3068\u304D\u306B\u3001pair (l,\
    \ r) \u3092\u5165\u308C\u308B\u3002\n  */\n  ll N = len(H);\n  vc<pi> LR(N);\n\
    \  vi st;\n  FOR(i, N) {\n    while (!st.empty() && H[st.back()] >= H[i]) st.pop_back();\n\
    \    LR[i].fi = (st.empty() ? 0 : st.back() + 1);\n    st.eb(i);\n  }\n  st.clear();\n\
    \  FOR_R(i, N) {\n    while (!st.empty() && H[st.back()] >= H[i]) st.pop_back();\n\
    \    LR[i].se = (st.empty() ? N : st.back());\n    st.eb(i);\n  }\n  return LR;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: other/maximal_rectangles.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/maximal_rectangles.hpp
layout: document
redirect_from:
- /library/other/maximal_rectangles.hpp
- /library/other/maximal_rectangles.hpp.html
title: other/maximal_rectangles.hpp
---
