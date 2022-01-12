---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/tree/cartesian_tree.test.cpp
    title: test/library_checker/tree/cartesian_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/cartesian_tree.hpp\"\ntemplate <typename T>\r\nstruct\
    \ CartesianTree {\r\n  /*\r\n  \u8F9E\u66F8\u9806\u3067\u9AD8\u3055\u3092 unique\
    \ \u3057\u3066\u3001\u6728\u306B\u3057\u3066\u3044\u308B\u3002\r\n  \u6975\u5927\
    \u9577\u65B9\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3067\u7DDA\u5F62\u6642\
    \u9593\u69CB\u7BC9\u3002\r\n  */\r\n  int n;\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> range;\r\n  vc<int> lch, rch, par;\r\n\r\n  CartesianTree(vc<T> A) : n(len(A)),\
    \ A(A) {\r\n    range.assign(n, {-1, -1});\r\n    lch.assign(n, -1);\r\n    rch.assign(n,\
    \ -1);\r\n    par.assign(n, -1);\r\n    auto is_sm = [&](int i, int j) -> bool\
    \ {\r\n      return (A[i] < A[j]) || (A[i] == A[j] && i < j);\r\n    };\r\n  \
    \  vc<int> st;\r\n    FOR(i, n) {\r\n      while (!st.empty() && is_sm(i, st.back()))\
    \ {\r\n        lch[i] = st.back();\r\n        st.pop_back();\r\n      }\r\n  \
    \    range[i].fi = (st.empty() ? 0 : st.back() + 1);\r\n      st.eb(i);\r\n  \
    \  }\r\n    st.clear();\r\n    FOR_R(i, n) {\r\n      while (!st.empty() && is_sm(i,\
    \ st.back())) {\r\n        rch[i] = st.back();\r\n        st.pop_back();\r\n \
    \     }\r\n      range[i].se = (st.empty() ? n : st.back());\r\n      st.eb(i);\r\
    \n    }\r\n    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\r\n    FOR(i, n) if\
    \ (rch[i] != -1) par[rch[i]] = i;\r\n  }\r\n};\r\n"
  code: "template <typename T>\r\nstruct CartesianTree {\r\n  /*\r\n  \u8F9E\u66F8\
    \u9806\u3067\u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\u306B\u3057\u3066\
    \u3044\u308B\u3002\r\n  \u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\u3067\u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\r\n  */\r\n  int\
    \ n;\r\n  vc<T>& A;\r\n  vc<pair<int, int>> range;\r\n  vc<int> lch, rch, par;\r\
    \n\r\n  CartesianTree(vc<T> A) : n(len(A)), A(A) {\r\n    range.assign(n, {-1,\
    \ -1});\r\n    lch.assign(n, -1);\r\n    rch.assign(n, -1);\r\n    par.assign(n,\
    \ -1);\r\n    auto is_sm = [&](int i, int j) -> bool {\r\n      return (A[i] <\
    \ A[j]) || (A[i] == A[j] && i < j);\r\n    };\r\n    vc<int> st;\r\n    FOR(i,\
    \ n) {\r\n      while (!st.empty() && is_sm(i, st.back())) {\r\n        lch[i]\
    \ = st.back();\r\n        st.pop_back();\r\n      }\r\n      range[i].fi = (st.empty()\
    \ ? 0 : st.back() + 1);\r\n      st.eb(i);\r\n    }\r\n    st.clear();\r\n   \
    \ FOR_R(i, n) {\r\n      while (!st.empty() && is_sm(i, st.back())) {\r\n    \
    \    rch[i] = st.back();\r\n        st.pop_back();\r\n      }\r\n      range[i].se\
    \ = (st.empty() ? n : st.back());\r\n      st.eb(i);\r\n    }\r\n    FOR(i, n)\
    \ if (lch[i] != -1) par[lch[i]] = i;\r\n    FOR(i, n) if (rch[i] != -1) par[rch[i]]\
    \ = i;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/tree/cartesian_tree.test.cpp
documentation_of: ds/cartesian_tree.hpp
layout: document
redirect_from:
- /library/ds/cartesian_tree.hpp
- /library/ds/cartesian_tree.hpp.html
title: ds/cartesian_tree.hpp
---
