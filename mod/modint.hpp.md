---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':warning:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_or_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/subset_convolution.test.cpp
    title: test/library_checker/convolution/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/hafnian_of_matrix.test.cpp
    title: test/library_checker/matrix/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/inverse_matrix.test.cpp
    title: test/library_checker/matrix/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/solve_linear.test.cpp
    title: test/library_checker/matrix/solve_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint.hpp\"\ntemplate <int mod>\nstruct modint {\n\
    \  static constexpr bool is_modint = true;\n  int val;\n  constexpr modint(const\
    \ ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod)\
    \ % mod) {}\n  bool operator<(const modint &other) const {\n    return val < other.val;\n\
    \  } // To use std::map\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(-val); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(int64_t n) const {\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr int get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr bool is_modint\
    \ = true;\n  int val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ unsigned long long a = (unsigned long long)val * p.val;\n    unsigned xh = (unsigned)(a\
    \ >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"\
    =d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n\
    \  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-() const {\
    \ return ArbitraryModInt(-val); }\n  ArbitraryModInt operator+(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt\
    \ operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n};\n\ntemplate<typename mint>\ntuple<mint, mint, mint>\
    \ get_factorial_data(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> fact = {1, 1};\n  static\
    \ vector<mint> fact_inv = {1, 1};\n  static vector<mint> inv = {0, 1};\n  while(len(fact)\
    \ <= n){\n    int k = len(fact);\n    fact.eb(fact[k - 1] * mint(k));\n    auto\
    \ q = ceil(mod, k);\n    int r = k * q - mod;\n    inv.eb(inv[r] * mint(q));\n\
    \    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n  return {fact[n], fact_inv[n],\
    \ inv[n]};\n}\n\ntemplate<typename mint>\nmint fact(int n){\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n);\n  if(n >= mod) return 0;\n  return\
    \ get<0>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\nmint fact_inv(int\
    \ n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n\
    \  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\n\
    mint inv(int n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <=\
    \ n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename\
    \ mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n >= 0);\n  if (k\
    \ < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n) * fact_inv<mint>(k)\
    \ * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) {\n\
    \    x *= mint(n - i);\n  }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\ntemplate<typename\
    \ mint>\nvc<mint> power_table(mint a, ll N) {\n  vc<mint> f(N, 1);\n  FOR(i, N\
    \ - 1) f[i + 1] = a * f[i];\n  return f;\n}\n\nusing modint107 = modint<1'000'000'007>;\n\
    using modint998 = modint<998'244'353>;\nusing amint = ArbitraryModInt;\n"
  code: "#pragma once\ntemplate <int mod>\nstruct modint {\n  static constexpr bool\
    \ is_modint = true;\n  int val;\n  constexpr modint(const ll val = 0) noexcept\n\
    \      : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -=\
    \ mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if\
    \ ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t\
    \ n) const {\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n &\
    \ 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt\
    \ {\n  static constexpr bool is_modint = true;\n  int val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ ArbitraryModInt &other) const {\n    return val < other.val;\n  } // To use\
    \ std::map<ArbitraryModInt, T>\n  static int &get_mod() {\n    static int mod\
    \ = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod() = md;\
    \ }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val +=\
    \ p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((val += get_mod() - p.val)\
    \ >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    unsigned long long a = (unsigned long long)val *\
    \ p.val;\n    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;\n   \
    \ asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"\
    (get_mod()));\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt &operator/=(const\
    \ ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n \
    \ ArbitraryModInt operator-() const { return ArbitraryModInt(-val); }\n  ArbitraryModInt\
    \ operator+(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ += p;\n  }\n  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) -= p;\n  }\n  ArbitraryModInt operator*(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) *= p;\n  }\n\
    \  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ /= p;\n  }\n  bool operator==(const ArbitraryModInt &p) const { return val ==\
    \ p.val; }\n  bool operator!=(const ArbitraryModInt &p) const { return val !=\
    \ p.val; }\n  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(),\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n};\n\ntemplate<typename mint>\ntuple<mint, mint, mint>\
    \ get_factorial_data(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> fact = {1, 1};\n  static\
    \ vector<mint> fact_inv = {1, 1};\n  static vector<mint> inv = {0, 1};\n  while(len(fact)\
    \ <= n){\n    int k = len(fact);\n    fact.eb(fact[k - 1] * mint(k));\n    auto\
    \ q = ceil(mod, k);\n    int r = k * q - mod;\n    inv.eb(inv[r] * mint(q));\n\
    \    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n  return {fact[n], fact_inv[n],\
    \ inv[n]};\n}\n\ntemplate<typename mint>\nmint fact(int n){\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n);\n  if(n >= mod) return 0;\n  return\
    \ get<0>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\nmint fact_inv(int\
    \ n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n\
    \  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\n\
    mint inv(int n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <=\
    \ n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename\
    \ mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n >= 0);\n  if (k\
    \ < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n) * fact_inv<mint>(k)\
    \ * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) {\n\
    \    x *= mint(n - i);\n  }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\ntemplate<typename\
    \ mint>\nvc<mint> power_table(mint a, ll N) {\n  vc<mint> f(N, 1);\n  FOR(i, N\
    \ - 1) f[i + 1] = a * f[i];\n  return f;\n}\n\nusing modint107 = modint<1'000'000'007>;\n\
    using modint998 = modint<998'244'353>;\nusing amint = ArbitraryModInt;"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.hpp
  requiredBy:
  - mod/mod_sqrt.hpp
  - poly/convolution.hpp
  timestamp: '2022-01-10 17:44:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  - test/library_checker/convolution/subset_convolution.test.cpp
  - test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - test/library_checker/convolution/bitwise_or_convolution.test.cpp
  - test/library_checker/matrix/matrix_product.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
  - test/library_checker/matrix/hafnian_of_matrix.test.cpp
  - test/library_checker/matrix/inverse_matrix.test.cpp
  - test/library_checker/matrix/solve_linear.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
documentation_of: mod/modint.hpp
layout: document
redirect_from:
- /library/mod/modint.hpp
- /library/mod/modint.hpp.html
title: mod/modint.hpp
---
