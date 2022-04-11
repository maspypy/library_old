---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint.hpp\"\ntemplate <uint mod>\nstruct modint {\n\
    \  static constexpr bool is_modint = true;\n  uint val;\n  constexpr modint(const\
    \ ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod)\
    \ % mod) {}\n  bool operator<(const modint &other) const {\n    return val < other.val;\n\
    \  } // To use std::map\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (uint)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(get_mod() - val); }\n  modint operator+(const modint &p) const\
    \ { return modint(*this) += p; }\n  modint operator-(const modint &p) const {\
    \ return modint(*this) -= p; }\n  modint operator*(const modint &p) const { return\
    \ modint(*this) *= p; }\n  modint operator/(const modint &p) const { return modint(*this)\
    \ /= p; }\n  bool operator==(const modint &p) const { return val == p.val; }\n\
    \  bool operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(int64_t n) const {\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr uint get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr bool is_modint\
    \ = true;\n  uint val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static uint &get_mod() {\n    static uint mod = 0;\n    return mod;\n\
    \  }\n  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ unsigned long long a = (unsigned long long)val * p.val;\n    unsigned xh = (unsigned)(a\
    \ >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"\
    =d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n\
    \  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-() const {\
    \ return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
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
    \  }\n    return ret;\n  }\n};\n\ntemplate <typename mint>\ntuple<mint, mint,\
    \ mint> get_factorial_data(int n) {\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> fact = {1, 1};\n  static\
    \ vector<mint> fact_inv = {1, 1};\n  static vector<mint> inv = {0, 1};\n  while\
    \ (len(fact) <= n) {\n    int k = len(fact);\n    fact.eb(fact[k - 1] * mint(k));\n\
    \    auto q = ceil(mod, k);\n    int r = k * q - mod;\n    inv.eb(inv[r] * mint(q));\n\
    \    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n  return {fact[n], fact_inv[n],\
    \ inv[n]};\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return 0;\n \
    \ return get<0>(get_factorial_data<mint>(n));\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static constexpr int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate\
    \ <typename mint>\nmint inv(int n) {\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate <typename mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n\
    \ >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n\
    \  FOR(i, k) { x *= mint(n - i); }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    using amint = ArbitraryModInt;\n#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator\
    \ {\n  mt19937 mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 3 \"mod/mod_sqrt.hpp\"\n\r\ntemplate\
    \ <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\n\
    \  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  RandomNumberGenerator RNG;\r\n  auto find\
    \ = [&]() -> pair<mint, mint> {\r\n    while (1) {\r\n      mint b = RNG(2, p);\r\
    \n      mint D = b * b - a;\r\n      if (D == 0) return {b, D};\r\n      if (D.pow(k)\
    \ != mint(1)) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n \
    \ if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1\
    \ = 1;\r\n  mint g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0,\
    \ g1) = mp(f0 * g0 + D * f1 * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0\
    \ * f0 + D * f1 * f1, mint(2) * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\
    \n}\r\n"
  code: "#include \"mod/modint.hpp\"\r\n#include \"other/random.hpp\"\r\n\r\ntemplate\
    \ <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\n\
    \  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  RandomNumberGenerator RNG;\r\n  auto find\
    \ = [&]() -> pair<mint, mint> {\r\n    while (1) {\r\n      mint b = RNG(2, p);\r\
    \n      mint D = b * b - a;\r\n      if (D == 0) return {b, D};\r\n      if (D.pow(k)\
    \ != mint(1)) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n \
    \ if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1\
    \ = 1;\r\n  mint g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0,\
    \ g1) = mp(f0 * g0 + D * f1 * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0\
    \ * f0 + D * f1 * f1, mint(2) * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\
    \n}\r\n"
  dependsOn:
  - mod/modint.hpp
  - other/random.hpp
  isVerificationFile: false
  path: mod/mod_sqrt.hpp
  requiredBy:
  - poly/fps_sqrt.hpp
  timestamp: '2022-04-11 22:58:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
documentation_of: mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/mod/mod_sqrt.hpp
- /library/mod/mod_sqrt.hpp.html
title: mod/mod_sqrt.hpp
---
