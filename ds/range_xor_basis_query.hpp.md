---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc223/tasks/abc223_h
    - https://codeforces.com/contest/1100/problem/F
  bundledCode: "#line 2 \"ds/range_xor_basis_query.hpp\"\n\n/*\n\u5217\u3082\u30AF\
    \u30A8\u30EA\u3082 static \u306A\u5834\u5408\u3002\u8A08\u7B97\u91CF O((N+Q)LOG)\n\
    ----\nexample\nhttps://atcoder.jp/contests/abc223/tasks/abc223_h\nhttps://codeforces.com/contest/1100/problem/F\n\
    */\ntemplate <typename INT_TYPE, int LOG>\nstruct Range_Xor_Basis_Query {\n  int\
    \ n;\n  vc<INT_TYPE>& A;\n  vc<pair<int, int>> query;\n  vc<vi> QIDS;\n\n  Range_Xor_Basis_Query(vc<INT_TYPE>&\
    \ A) : n(len(A)), A(A) {\n    QIDS.resize(n + 1);\n  }\n\n  void add(int l, int\
    \ r) {\n    assert(0 <= l && l <= r && r <= n);\n    QIDS[r].eb(len(query));\n\
    \    query.eb(l, r);\n  }\n\n  // query_id, basis(vector) -> void \u3068\u3044\
    \u3046\u95A2\u6570 F \u3092\u6E21\u3059\n  template <typename CALC>\n  void calc(CALC\
    \ F) {\n    using P = pair<INT_TYPE, int>;\n    int Q = len(query);\n    FOR(q,\
    \ Q) { QIDS[query[q].se].eb(q); }\n    array<P, LOG> dat;\n    FOR(k, LOG) dat[k]\
    \ = {INT_TYPE(1) << k, -1};\n    vc<INT_TYPE> basis;\n\n    FOR(i, n + 1) {\n\
    \      for (auto&& q: QIDS[i]) {\n        auto& [l, r] = query[q];\n        basis.clear();\n\
    \        FOR_R(k, LOG) {\n          if (dat[k].se >= l) basis.eb(dat[k].fi);\n\
    \        }\n        F(q, basis);\n      }\n      if (i == n) break;\n      P p\
    \ = {A[i], i};\n      FOR_R(k, LOG) {\n        if (p.fi >> k & 1) {\n        \
    \  if (p.se > dat[k].se) swap(p, dat[k]);\n          p.fi ^= dat[k].fi;\n    \
    \    }\n      }\n    }\n  }\n};\n"
  code: "#pragma once\n\n/*\n\u5217\u3082\u30AF\u30A8\u30EA\u3082 static \u306A\u5834\
    \u5408\u3002\u8A08\u7B97\u91CF O((N+Q)LOG)\n----\nexample\nhttps://atcoder.jp/contests/abc223/tasks/abc223_h\n\
    https://codeforces.com/contest/1100/problem/F\n*/\ntemplate <typename INT_TYPE,\
    \ int LOG>\nstruct Range_Xor_Basis_Query {\n  int n;\n  vc<INT_TYPE>& A;\n  vc<pair<int,\
    \ int>> query;\n  vc<vi> QIDS;\n\n  Range_Xor_Basis_Query(vc<INT_TYPE>& A) : n(len(A)),\
    \ A(A) {\n    QIDS.resize(n + 1);\n  }\n\n  void add(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    QIDS[r].eb(len(query));\n    query.eb(l, r);\n\
    \  }\n\n  // query_id, basis(vector) -> void \u3068\u3044\u3046\u95A2\u6570 F\
    \ \u3092\u6E21\u3059\n  template <typename CALC>\n  void calc(CALC F) {\n    using\
    \ P = pair<INT_TYPE, int>;\n    int Q = len(query);\n    FOR(q, Q) { QIDS[query[q].se].eb(q);\
    \ }\n    array<P, LOG> dat;\n    FOR(k, LOG) dat[k] = {INT_TYPE(1) << k, -1};\n\
    \    vc<INT_TYPE> basis;\n\n    FOR(i, n + 1) {\n      for (auto&& q: QIDS[i])\
    \ {\n        auto& [l, r] = query[q];\n        basis.clear();\n        FOR_R(k,\
    \ LOG) {\n          if (dat[k].se >= l) basis.eb(dat[k].fi);\n        }\n    \
    \    F(q, basis);\n      }\n      if (i == n) break;\n      P p = {A[i], i};\n\
    \      FOR_R(k, LOG) {\n        if (p.fi >> k & 1) {\n          if (p.se > dat[k].se)\
    \ swap(p, dat[k]);\n          p.fi ^= dat[k].fi;\n        }\n      }\n    }\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/range_xor_basis_query.hpp
  requiredBy: []
  timestamp: '2022-04-12 00:36:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/range_xor_basis_query.hpp
layout: document
redirect_from:
- /library/ds/range_xor_basis_query.hpp
- /library/ds/range_xor_basis_query.hpp.html
title: ds/range_xor_basis_query.hpp
---
