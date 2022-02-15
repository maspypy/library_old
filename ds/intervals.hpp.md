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
    - https://codeforces.com/contest/1638/problem/E
  bundledCode: "#line 1 \"ds/intervals.hpp\"\n// https://codeforces.com/contest/1638/problem/E\n\
    template <typename T = ll, typename X = ll>\nstruct Intervals {\n  static constexpr\
    \ X INF = numeric_limits<X>::max();\n  const T none_val;\n  // none_val \u3067\
    \u306A\u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int\
    \ total_num;\n  X total_len;\n  map<X, T> dat;\n\n  // \u300C\u533A\u9593 [l,\
    \ r) \u3092\u5024 x in T \u3067\u4E0A\u66F8\u304D\u3059\u308B\u300D\u3092\u884C\
    \u3046\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[-INF] = none_val;\n    dat[INF] = none_val;\n  }\n\n  tuple<X, X,\
    \ T> get(X x) {\n    auto it = dat.upper_bound(x);\n    X r = (*it).fi;\n    auto\
    \ [l, t] = *prev(it);\n    return {l, r, t};\n  }\n\n  template <typename ADD,\
    \ typename RM>\n  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L ==\
    \ R) return;\n    assert(L < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\
    \u66F4\u3059\u308B\n    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\
    \u308A\u5408\u3046\u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>>\
    \ tmp;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l,\
    \ t] = *it;\n      if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n\
    \      tmp.eb(l, r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__,\
    \ rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\
    \u9664\n    for (auto&& [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t ==\
    \ none_val) continue;\n      total_num--;\n      total_len -= r - l;\n      rm_f(l,\
    \ r, t);\n    }\n    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n\
    \    if (lx < L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val)\
    \ {\n        total_num++;\n        total_len += L - lx;\n        add_f(lx, L,\
    \ lt);\n      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n\
    \      if (rt != none_val) {\n        total_num++;\n        total_len += rx -\
    \ R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n\
    \    if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n   \
    \   add_f(L, R, t);\n    }\n  }\n\n  void insert(X L, X R, T t = 1) {\n    auto\
    \ f = [&](X L, X R, T t) -> void {};\n    set(L, R, t);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val);\n\
    \  }\n\n  void debug() {\n    auto it = dat.begin();\n    print(\"Intervals\"\
    );\n    print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n\
    \    while (1) {\n      auto [l, t] = *it;\n      ++it;\n      if (it == dat.end())\
    \ break;\n      X r = (*it).fi;\n      print(\"l, r, t\", l, r, t);\n    }\n \
    \ }\n};\n"
  code: "// https://codeforces.com/contest/1638/problem/E\ntemplate <typename T =\
    \ ll, typename X = ll>\nstruct Intervals {\n  static constexpr X INF = numeric_limits<X>::max();\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  // \u300C\u533A\u9593 [l, r) \u3092\u5024 x in T \u3067\u4E0A\u66F8\
    \u304D\u3059\u308B\u300D\u3092\u884C\u3046\n  Intervals(T none_val) : none_val(none_val),\
    \ total_num(0), total_len(0) {\n    dat[-INF] = none_val;\n    dat[INF] = none_val;\n\
    \  }\n\n  tuple<X, X, T> get(X x) {\n    auto it = dat.upper_bound(x);\n    X\
    \ r = (*it).fi;\n    auto [l, t] = *prev(it);\n    return {l, r, t};\n  }\n\n\
    \  template <typename ADD, typename RM>\n  void set(X L, X R, T t, ADD& add_f,\
    \ RM& rm_f) {\n    if (L == R) return;\n    assert(L < R);\n    // \u533A\u9593\
    \ [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n    // \u307E\u305A\u306F\u3001\
    \u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\u533A\u9593\u3092\u5168\u5217\
    \u6319\n    vc<tuple<X, X, T>> tmp;\n    auto it = prev(dat.lower_bound(L));\n\
    \    while (1) {\n      auto [l, t] = *it;\n      if (R < l) break;\n      it\
    \ = next(it);\n      X r = (*it).fi;\n      tmp.eb(l, r, t);\n    }\n    auto\
    \ [lx, _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n    // \u3068\u308A\
    \u3042\u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&& [l, r, t]: tmp) {\n\
    \      dat.erase(l);\n      if (t == none_val) continue;\n      total_num--;\n\
    \      total_len -= r - l;\n      rm_f(l, r, t);\n    }\n    if (lt == t) chmin(L,\
    \ lx);\n    if (rt == t) chmax(R, rx);\n    if (lx < L) {\n      // [lx, L)\n\
    \      dat[lx] = lt;\n      if (lt != none_val) {\n        total_num++;\n    \
    \    total_len += L - lx;\n        add_f(lx, L, lt);\n      }\n    }\n    if (R\
    \ < rx) {\n      // [R, rx)\n      dat[R] = rt;\n      if (rt != none_val) {\n\
    \        total_num++;\n        total_len += rx - R;\n        add_f(R, rx, rt);\n\
    \      }\n    }\n    // [L, R)\n    dat[L] = t;\n    if (t != none_val) {\n  \
    \    total_num++;\n      total_len += R - L;\n      add_f(L, R, t);\n    }\n \
    \ }\n\n  void insert(X L, X R, T t = 1) {\n    auto f = [&](X L, X R, T t) ->\
    \ void {};\n    set(L, R, t);\n  }\n\n  void erase(X L, X R) {\n    auto f = [&](X\
    \ L, X R, T t) -> void {};\n    set(L, R, none_val);\n  }\n\n  void debug() {\n\
    \    auto it = dat.begin();\n    print(\"Intervals\");\n    print(\"total_num\"\
    , total_num);\n    print(\"total_len\", total_len);\n    while (1) {\n      auto\
    \ [l, t] = *it;\n      ++it;\n      if (it == dat.end()) break;\n      X r = (*it).fi;\n\
    \      print(\"l, r, t\", l, r, t);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/intervals.hpp
  requiredBy: []
  timestamp: '2022-02-15 17:43:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/intervals.hpp
layout: document
redirect_from:
- /library/ds/intervals.hpp
- /library/ds/intervals.hpp.html
title: ds/intervals.hpp
---
