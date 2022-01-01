---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group_add.hpp
    title: algebra/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_G_fenwick_raq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\n\ntemplate\
    \ <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n\
    \  FenwickTree(int n) : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n\
    \    dat.assign(n, AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)),\
    \ total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat = v;\n  \
    \  FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j -\
    \ 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n  E sum(int k) {\n\
    \    E ret = AbelGroup::unit;\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit;\n\
    \    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -=\
    \ R & -R;\n    }\n    E neg = AbelGroup::unit;\n    while (R < L) {\n      neg\
    \ = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\n  }\n\n  E sum_all() { return total; }\n\n  void\
    \ add(int k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <=\
    \ n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  template\
    \ <class F>\n  int max_right(F& check) {\n    assert(f(E(0)));\n    ll i = 0;\n\
    \    E s = AbelGroup::unit;\n    int k = 1;\n    int N = len(dat) + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E\
    \ k) {\n    auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/fenwickraq.hpp\"\
    \ntemplate <typename AbelGroup>\r\nstruct FenwickRAQ {\r\n  using E = typename\
    \ AbelGroup::value_type;\r\n  int n;\r\n  FenwickTree<AbelGroup> bit0;\r\n  FenwickTree<AbelGroup>\
    \ bit1;\r\n\r\n  FenwickRAQ() : FenwickRAQ(0) {}\r\n  FenwickRAQ(int n) : n(n),\
    \ bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E> v) : n(len(v)), bit0(v), bit1(len(v))\
    \ {}\r\n\r\n  void add(ll i, E val) { bit0.add(i, val); }\r\n\r\n  void add(ll\
    \ L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val, -L));\r\n    bit0.add(R,\
    \ AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\n    bit1.add(R, AbelGroup::inverse(val));\r\
    \n  }\r\n\r\n  E sum(ll L, ll R) {\r\n    E sum_R = AbelGroup::op(AbelGroup::power(bit1.sum(R),\
    \ R), bit0.sum(R));\r\n    E sum_L = AbelGroup::op(AbelGroup::power(bit1.sum(L),\
    \ L), bit0.sum(L));\r\n    return AbelGroup::op(AbelGroup::inverse(sum_L), sum_R);\r\
    \n  }\r\n};\r\n"
  code: "#include \"ds/fenwick.hpp\"\r\ntemplate <typename AbelGroup>\r\nstruct FenwickRAQ\
    \ {\r\n  using E = typename AbelGroup::value_type;\r\n  int n;\r\n  FenwickTree<AbelGroup>\
    \ bit0;\r\n  FenwickTree<AbelGroup> bit1;\r\n\r\n  FenwickRAQ() : FenwickRAQ(0)\
    \ {}\r\n  FenwickRAQ(int n) : n(n), bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E>\
    \ v) : n(len(v)), bit0(v), bit1(len(v)) {}\r\n\r\n  void add(ll i, E val) { bit0.add(i,\
    \ val); }\r\n\r\n  void add(ll L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val,\
    \ -L));\r\n    bit0.add(R, AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\
    \n    bit1.add(R, AbelGroup::inverse(val));\r\n  }\r\n\r\n  E sum(ll L, ll R)\
    \ {\r\n    E sum_R = AbelGroup::op(AbelGroup::power(bit1.sum(R), R), bit0.sum(R));\r\
    \n    E sum_L = AbelGroup::op(AbelGroup::power(bit1.sum(L), L), bit0.sum(L));\r\
    \n    return AbelGroup::op(AbelGroup::inverse(sum_L), sum_R);\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/fenwick.hpp
  - algebra/group_add.hpp
  isVerificationFile: false
  path: ds/fenwickraq.hpp
  requiredBy: []
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - test/aoj/DSL_2_G_fenwick_raq.test.cpp
documentation_of: ds/fenwickraq.hpp
layout: document
redirect_from:
- /library/ds/fenwickraq.hpp
- /library/ds/fenwickraq.hpp.html
title: ds/fenwickraq.hpp
---
