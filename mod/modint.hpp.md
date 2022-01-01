---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/modint.hpp\"\ntemplate <int mod>\nstruct modint {\n\
    \  int val;\n\n  constexpr modint(const ll val = 0) noexcept\n      : val(val\
    \ >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \n  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val\
    \ -= mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n \
    \   if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n\n  modint inverse() const {\n    int a = val, b =\
    \ mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -=\
    \ t * b, b);\n      swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n\n\
    \  modint pow(int64_t n) const {\n    modint ret(1), mul(val);\n    while (n >\
    \ 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const modint\
    \ &p) { return os << p.val; }\n  static int get_mod() { return mod; }\n};\n\n\
    template <typename T>\nstruct ModCalc {\n  vector<T> _fact = {1, 1};\n  vector<T>\
    \ _fact_inv = {1, 1};\n  vector<T> _inv = {0, 1};\n\n  T pow(T a, int n) {\n \
    \   T x(1);\n    while (n) {\n      if (n & 1) x *= a;\n      a *= a;\n      n\
    \ >>= 1;\n    }\n    return x;\n  }\n  void expand(int n) {\n    while (_fact.size()\
    \ <= n) {\n      auto i = _fact.size();\n      _fact.eb(_fact[i - 1] * T(i));\n\
    \      auto q = T::get_mod() / i, r = T::get_mod() % i;\n      _inv.eb(_inv[r]\
    \ * T(T::get_mod() - q));\n      _fact_inv.eb(_fact_inv[i - 1] * _inv[i]);\n \
    \   }\n  }\n\n  T fact(int n) {\n    if (n >= _fact.size()) expand(n);\n    return\
    \ _fact[n];\n  }\n\n  T fact_inv(int n) {\n    if (n >= _fact.size()) expand(n);\n\
    \    return _fact_inv[n];\n  }\n\n  T inv(int n) {\n    if (n >= _fact.size())\
    \ expand(n);\n    return _inv[n];\n  }\n\n  T C(ll n, ll k, bool large = false)\
    \ {\n    assert(n >= 0);\n    if (k < 0 || n < k) return 0;\n    if (!large) return\
    \ fact(n) * fact_inv(k) * fact_inv(n - k);\n    k = min(k, n - k);\n    T x(1);\n\
    \    FOR(i, k) {\n      x *= n - i;\n      x *= inv(i + 1);\n    }\n    return\
    \ x;\n  }\n};\n\nusing modint107 = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n"
  code: "template <int mod>\nstruct modint {\n  int val;\n\n  constexpr modint(const\
    \ ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod)\
    \ % mod) {}\n\n  bool operator<(const modint &other) const {\n    return val <\
    \ other.val;\n  } // To use std::map\n\n  modint &operator+=(const modint &p)\
    \ {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += mod - p.val) >= mod) val -=\
    \ mod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n    val\
    \ = (int)(1LL * val * p.val % mod);\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint(-val); }\n  modint operator+(const modint &p) const {\
    \ return modint(*this) += p; }\n  modint operator-(const modint &p) const { return\
    \ modint(*this) -= p; }\n  modint operator*(const modint &p) const { return modint(*this)\
    \ *= p; }\n  modint operator/(const modint &p) const { return modint(*this) /=\
    \ p; }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n   \
    \ }\n    return modint(u);\n  }\n\n  modint pow(int64_t n) const {\n    modint\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const modint &p) { return os << p.val; }\n  static\
    \ int get_mod() { return mod; }\n};\n\ntemplate <typename T>\nstruct ModCalc {\n\
    \  vector<T> _fact = {1, 1};\n  vector<T> _fact_inv = {1, 1};\n  vector<T> _inv\
    \ = {0, 1};\n\n  T pow(T a, int n) {\n    T x(1);\n    while (n) {\n      if (n\
    \ & 1) x *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return x;\n  }\n  void\
    \ expand(int n) {\n    while (_fact.size() <= n) {\n      auto i = _fact.size();\n\
    \      _fact.eb(_fact[i - 1] * T(i));\n      auto q = T::get_mod() / i, r = T::get_mod()\
    \ % i;\n      _inv.eb(_inv[r] * T(T::get_mod() - q));\n      _fact_inv.eb(_fact_inv[i\
    \ - 1] * _inv[i]);\n    }\n  }\n\n  T fact(int n) {\n    if (n >= _fact.size())\
    \ expand(n);\n    return _fact[n];\n  }\n\n  T fact_inv(int n) {\n    if (n >=\
    \ _fact.size()) expand(n);\n    return _fact_inv[n];\n  }\n\n  T inv(int n) {\n\
    \    if (n >= _fact.size()) expand(n);\n    return _inv[n];\n  }\n\n  T C(ll n,\
    \ ll k, bool large = false) {\n    assert(n >= 0);\n    if (k < 0 || n < k) return\
    \ 0;\n    if (!large) return fact(n) * fact_inv(k) * fact_inv(n - k);\n    k =\
    \ min(k, n - k);\n    T x(1);\n    FOR(i, k) {\n      x *= n - i;\n      x *=\
    \ inv(i + 1);\n    }\n    return x;\n  }\n};\n\nusing modint107 = modint<1'000'000'007>;\n\
    using modint998 = modint<998'244'353>;\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.hpp
  requiredBy: []
  timestamp: '2022-01-02 02:35:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: mod/modint.hpp
layout: document
redirect_from:
- /library/mod/modint.hpp
- /library/mod/modint.hpp.html
title: mod/modint.hpp
---
