---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/beats_sample.hpp\"\nconst ll INF = 1LL << 40;\r\n\r\n\
    struct CntSumMinMax {\r\n  struct X {\r\n    ll cnt, sum, min, max, minc, maxc,\
    \ min2, max2;\r\n    bool fail;\r\n  };\r\n  using value_type = X;\r\n  static\
    \ X op(const X& x, const X& y) {\r\n    if (x.min > x.max) return y;\r\n    if\
    \ (y.min > y.max) return x;\r\n    X z;\r\n    z.cnt = x.cnt + y.cnt, z.sum =\
    \ x.sum + y.sum;\r\n\r\n    z.min = min(x.min, y.min), z.max = max(x.max, y.max);\r\
    \n    z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\r\
    \n    z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\r\
    \n\r\n    z.min2 = z.max;\r\n    if (z.min < x.min && x.min < z.min2) z.min2 =\
    \ x.min;\r\n    if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\r\n  \
    \  if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\r\n    if (z.min < y.min2\
    \ && y.min2 < z.min2) z.min2 = y.min2;\r\n\r\n    z.max2 = z.min;\r\n    if (z.max\
    \ > x.max && x.max > z.max2) z.max2 = x.max;\r\n    if (z.max > x.max2 && x.max2\
    \ > z.max2) z.max2 = x.max2;\r\n    if (z.max > y.max && y.max > z.max2) z.max2\
    \ = y.max;\r\n    if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\r\n\r\
    \n    z.fail = 0;\r\n    return z;\r\n  }\r\n  static constexpr X unit = {0, 0,\
    \ INF, -INF, 0, 0, INF, -INF, 0};\r\n  bool commute = true;\r\n};\r\n\r\nstruct\
    \ AddChminChmax {\r\n  struct X {\r\n    ll add, min, max;\r\n  };\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X& x, const X& y) {\r\n   \
    \ auto [a, b, c] = x;\r\n    auto [d, e, f] = y;\r\n    a += d, b += d, c += d;\r\
    \n    b = min(b, e), c = min(c, e);\r\n    c = max(c, f);\r\n    return {a, b,\
    \ c};\r\n  }\r\n  static constexpr X unit = {0, INF, -INF};\r\n  bool commute\
    \ = false;\r\n};\r\n\r\nstruct Lazy {\r\n  using MX = CntSumMinMax;\r\n  using\
    \ MA = AddChminChmax;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\
    \n  using X = MX::value_type;\r\n  using A = MA::value_type;\r\n  static X act(X&\
    \ x, const A& a) {\r\n    assert(!x.fail);\r\n    if (x.cnt == 0) return x;\r\n\
    \    x.sum += x.cnt * a.add;\r\n    x.min += a.add, x.max += a.add;\r\n    x.min2\
    \ += a.add, x.max2 += a.add;\r\n\r\n    if (a.min == INF && a.max == -INF) return\
    \ x;\r\n\r\n    ll before_min = x.min, before_max = x.max;\r\n    chmin(x.min,\
    \ a.min), chmax(x.min, a.max);\r\n    chmin(x.max, a.min), chmax(x.max, a.max);\r\
    \n\r\n    if (x.min == x.max) {\r\n      x.sum = x.max * x.cnt;\r\n      x.max2\
    \ = x.min2 = x.max;\r\n      x.maxc = x.minc = x.cnt;\r\n    }\r\n    elif (x.max2\
    \ <= x.min) {\r\n      x.max2 = x.min, x.min2 = x.max;\r\n      x.minc = x.cnt\
    \ - x.maxc;\r\n      x.sum = x.max * x.maxc + x.min * x.minc;\r\n    }\r\n   \
    \ elif (x.min2 >= x.max) {\r\n      x.max2 = x.min, x.min2 = x.max;\r\n      x.maxc\
    \ = x.cnt - x.minc;\r\n      x.sum = x.max * x.maxc + x.min * x.minc;\r\n    }\r\
    \n    elif (x.min < x.min2 && x.max > x.max2) {\r\n      x.sum += (x.min - before_min)\
    \ * x.minc;\r\n      x.sum += (x.max - before_max) * x.maxc;\r\n    }\r\n    else\
    \ {\r\n      x.fail = 1;\r\n    }\r\n    return x;\r\n  }\r\n};\r\n"
  code: "const ll INF = 1LL << 40;\r\n\r\nstruct CntSumMinMax {\r\n  struct X {\r\n\
    \    ll cnt, sum, min, max, minc, maxc, min2, max2;\r\n    bool fail;\r\n  };\r\
    \n  using value_type = X;\r\n  static X op(const X& x, const X& y) {\r\n    if\
    \ (x.min > x.max) return y;\r\n    if (y.min > y.max) return x;\r\n    X z;\r\n\
    \    z.cnt = x.cnt + y.cnt, z.sum = x.sum + y.sum;\r\n\r\n    z.min = min(x.min,\
    \ y.min), z.max = max(x.max, y.max);\r\n    z.minc = (x.min == z.min ? x.minc\
    \ : 0) + (y.min == z.min ? y.minc : 0);\r\n    z.maxc = (x.max == z.max ? x.maxc\
    \ : 0) + (y.max == z.max ? y.maxc : 0);\r\n\r\n    z.min2 = z.max;\r\n    if (z.min\
    \ < x.min && x.min < z.min2) z.min2 = x.min;\r\n    if (z.min < x.min2 && x.min2\
    \ < z.min2) z.min2 = x.min2;\r\n    if (z.min < y.min && y.min < z.min2) z.min2\
    \ = y.min;\r\n    if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\r\n\r\
    \n    z.max2 = z.min;\r\n    if (z.max > x.max && x.max > z.max2) z.max2 = x.max;\r\
    \n    if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\r\n    if (z.max\
    \ > y.max && y.max > z.max2) z.max2 = y.max;\r\n    if (z.max > y.max2 && y.max2\
    \ > z.max2) z.max2 = y.max2;\r\n\r\n    z.fail = 0;\r\n    return z;\r\n  }\r\n\
    \  static constexpr X unit = {0, 0, INF, -INF, 0, 0, INF, -INF, 0};\r\n  bool\
    \ commute = true;\r\n};\r\n\r\nstruct AddChminChmax {\r\n  struct X {\r\n    ll\
    \ add, min, max;\r\n  };\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X& x, const X& y) {\r\n    auto [a, b, c] = x;\r\n    auto [d, e, f] = y;\r\n\
    \    a += d, b += d, c += d;\r\n    b = min(b, e), c = min(c, e);\r\n    c = max(c,\
    \ f);\r\n    return {a, b, c};\r\n  }\r\n  static constexpr X unit = {0, INF,\
    \ -INF};\r\n  bool commute = false;\r\n};\r\n\r\nstruct Lazy {\r\n  using MX =\
    \ CntSumMinMax;\r\n  using MA = AddChminChmax;\r\n  using X_structure = MX;\r\n\
    \  using A_structure = MA;\r\n  using X = MX::value_type;\r\n  using A = MA::value_type;\r\
    \n  static X act(X& x, const A& a) {\r\n    assert(!x.fail);\r\n    if (x.cnt\
    \ == 0) return x;\r\n    x.sum += x.cnt * a.add;\r\n    x.min += a.add, x.max\
    \ += a.add;\r\n    x.min2 += a.add, x.max2 += a.add;\r\n\r\n    if (a.min == INF\
    \ && a.max == -INF) return x;\r\n\r\n    ll before_min = x.min, before_max = x.max;\r\
    \n    chmin(x.min, a.min), chmax(x.min, a.max);\r\n    chmin(x.max, a.min), chmax(x.max,\
    \ a.max);\r\n\r\n    if (x.min == x.max) {\r\n      x.sum = x.max * x.cnt;\r\n\
    \      x.max2 = x.min2 = x.max;\r\n      x.maxc = x.minc = x.cnt;\r\n    }\r\n\
    \    elif (x.max2 <= x.min) {\r\n      x.max2 = x.min, x.min2 = x.max;\r\n   \
    \   x.minc = x.cnt - x.maxc;\r\n      x.sum = x.max * x.maxc + x.min * x.minc;\r\
    \n    }\r\n    elif (x.min2 >= x.max) {\r\n      x.max2 = x.min, x.min2 = x.max;\r\
    \n      x.maxc = x.cnt - x.minc;\r\n      x.sum = x.max * x.maxc + x.min * x.minc;\r\
    \n    }\r\n    elif (x.min < x.min2 && x.max > x.max2) {\r\n      x.sum += (x.min\
    \ - before_min) * x.minc;\r\n      x.sum += (x.max - before_max) * x.maxc;\r\n\
    \    }\r\n    else {\r\n      x.fail = 1;\r\n    }\r\n    return x;\r\n  }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/beats_sample.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: alg/beats_sample.hpp
layout: document
redirect_from:
- /library/alg/beats_sample.hpp
- /library/alg/beats_sample.hpp.html
title: alg/beats_sample.hpp
---
