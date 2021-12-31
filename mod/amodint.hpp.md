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
  bundledCode: "#line 1 \"mod/amodint.hpp\"\nstruct ArbitraryModInt {\r\n  int x;\r\
    \n\r\n  ArbitraryModInt() : x(0) {}\r\n\r\n  ArbitraryModInt(int64_t y)\r\n  \
    \    : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod())\
    \ {\r\n  }\r\n\r\n  bool operator<(const ArbitraryModInt &other) const {\r\n \
    \   return x < other.x;\r\n  } // To use std::map<ArbitraryModInt, T>\r\n\r\n\
    \  static int &get_mod() {\r\n    static int mod = 0;\r\n    return mod;\r\n \
    \ }\r\n\r\n  static void set_mod(int md) { get_mod() = md; }\r\n\r\n  ArbitraryModInt\
    \ &operator+=(const ArbitraryModInt &p) {\r\n    if ((x += p.x) >= get_mod())\
    \ x -= get_mod();\r\n    return *this;\r\n  }\r\n\r\n  ArbitraryModInt &operator-=(const\
    \ ArbitraryModInt &p) {\r\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\r\
    \n    return *this;\r\n  }\r\n\r\n  ArbitraryModInt &operator*=(const ArbitraryModInt\
    \ &p) {\r\n    unsigned long long a = (unsigned long long)x * p.x;\r\n    unsigned\
    \ xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;\r\n    asm(\"divl %4; \\n\\\
    t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\r\n    x\
    \ = m;\r\n    return *this;\r\n  }\r\n\r\n  ArbitraryModInt &operator/=(const\
    \ ArbitraryModInt &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n\
    \  }\r\n\r\n  ArbitraryModInt operator-() const { return ArbitraryModInt(-x);\
    \ }\r\n\r\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\r\n \
    \   return ArbitraryModInt(*this) += p;\r\n  }\r\n\r\n  ArbitraryModInt operator-(const\
    \ ArbitraryModInt &p) const {\r\n    return ArbitraryModInt(*this) -= p;\r\n \
    \ }\r\n\r\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\r\n \
    \   return ArbitraryModInt(*this) *= p;\r\n  }\r\n\r\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\r\n    return ArbitraryModInt(*this) /= p;\r\n \
    \ }\r\n\r\n  bool operator==(const ArbitraryModInt &p) const { return x == p.x;\
    \ }\r\n\r\n  bool operator!=(const ArbitraryModInt &p) const { return x != p.x;\
    \ }\r\n\r\n  ArbitraryModInt inverse() const {\r\n    int a = x, b = get_mod(),\
    \ u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a\
    \ -= t * b, b);\r\n      swap(u -= t * v, v);\r\n    }\r\n    return ArbitraryModInt(u);\r\
    \n  }\r\n\r\n  ArbitraryModInt pow(int64_t n) const {\r\n    ArbitraryModInt ret(1),\
    \ mul(x);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  friend\
    \ ostream &operator<<(ostream &os, const ArbitraryModInt &p) {\r\n    return os\
    \ << p.x;\r\n  }\r\n\r\n  friend istream &operator>>(istream &is, ArbitraryModInt\
    \ &a) {\r\n    int64_t t;\r\n    is >> t;\r\n    a = ArbitraryModInt(t);\r\n \
    \   return (is);\r\n  }\r\n};\r\n\r\ntemplate <typename T>\r\nstruct ModCalc {\r\
    \n  vector<T> _fact = {1, 1};\r\n  vector<T> _fact_inv = {1, 1};\r\n  vector<T>\
    \ _inv = {0, 1};\r\n\r\n  T pow(T a, int n) {\r\n    T x(1);\r\n    while (n)\
    \ {\r\n      if (n & 1) x *= a;\r\n      a *= a;\r\n      n >>= 1;\r\n    }\r\n\
    \    return x;\r\n  }\r\n  void expand(int n) {\r\n    while (_fact.size() <=\
    \ n) {\r\n      auto i = _fact.size();\r\n      _fact.eb(_fact[i - 1] * T(i));\r\
    \n      auto q = T::get_mod() / i, r = T::get_mod() % i;\r\n      _inv.eb(_inv[r]\
    \ * T(T::get_mod() - q));\r\n      _fact_inv.eb(_fact_inv[i - 1] * _inv[i]);\r\
    \n    }\r\n  }\r\n\r\n  T fact(int n) {\r\n    if (n >= _fact.size()) expand(n);\r\
    \n    return _fact[n];\r\n  }\r\n\r\n  T fact_inv(int n) {\r\n    if (n >= _fact.size())\
    \ expand(n);\r\n    return _fact_inv[n];\r\n  }\r\n\r\n  T inv(int n) {\r\n  \
    \  if (n >= _fact.size()) expand(n);\r\n    return _inv[n];\r\n  }\r\n\r\n  T\
    \ C(ll n, ll k, bool large = false) {\r\n    assert(n >= 0);\r\n    if (k < 0\
    \ || n < k) return 0;\r\n    if (!large) return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n    k = min(k, n - k);\r\n    T x(1);\r\n    FOR(i, k) {\r\n      x\
    \ *= n - i;\r\n      x *= inv(i + 1);\r\n    }\r\n    return x;\r\n  }\r\n};\r\
    \n"
  code: "struct ArbitraryModInt {\r\n  int x;\r\n\r\n  ArbitraryModInt() : x(0) {}\r\
    \n\r\n  ArbitraryModInt(int64_t y)\r\n      : x(y >= 0 ? y % get_mod() : (get_mod()\
    \ - (-y) % get_mod()) % get_mod()) {\r\n  }\r\n\r\n  bool operator<(const ArbitraryModInt\
    \ &other) const {\r\n    return x < other.x;\r\n  } // To use std::map<ArbitraryModInt,\
    \ T>\r\n\r\n  static int &get_mod() {\r\n    static int mod = 0;\r\n    return\
    \ mod;\r\n  }\r\n\r\n  static void set_mod(int md) { get_mod() = md; }\r\n\r\n\
    \  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\r\n    if ((x += p.x)\
    \ >= get_mod()) x -= get_mod();\r\n    return *this;\r\n  }\r\n\r\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\r\n    if ((x += get_mod() - p.x) >=\
    \ get_mod()) x -= get_mod();\r\n    return *this;\r\n  }\r\n\r\n  ArbitraryModInt\
    \ &operator*=(const ArbitraryModInt &p) {\r\n    unsigned long long a = (unsigned\
    \ long long)x * p.x;\r\n    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a,\
    \ d, m;\r\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"\
    a\"(xl), \"r\"(get_mod()));\r\n    x = m;\r\n    return *this;\r\n  }\r\n\r\n\
    \  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\r\n    *this *= p.inverse();\r\
    \n    return *this;\r\n  }\r\n\r\n  ArbitraryModInt operator-() const { return\
    \ ArbitraryModInt(-x); }\r\n\r\n  ArbitraryModInt operator+(const ArbitraryModInt\
    \ &p) const {\r\n    return ArbitraryModInt(*this) += p;\r\n  }\r\n\r\n  ArbitraryModInt\
    \ operator-(const ArbitraryModInt &p) const {\r\n    return ArbitraryModInt(*this)\
    \ -= p;\r\n  }\r\n\r\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const\
    \ {\r\n    return ArbitraryModInt(*this) *= p;\r\n  }\r\n\r\n  ArbitraryModInt\
    \ operator/(const ArbitraryModInt &p) const {\r\n    return ArbitraryModInt(*this)\
    \ /= p;\r\n  }\r\n\r\n  bool operator==(const ArbitraryModInt &p) const { return\
    \ x == p.x; }\r\n\r\n  bool operator!=(const ArbitraryModInt &p) const { return\
    \ x != p.x; }\r\n\r\n  ArbitraryModInt inverse() const {\r\n    int a = x, b =\
    \ get_mod(), u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n \
    \     swap(a -= t * b, b);\r\n      swap(u -= t * v, v);\r\n    }\r\n    return\
    \ ArbitraryModInt(u);\r\n  }\r\n\r\n  ArbitraryModInt pow(int64_t n) const {\r\
    \n    ArbitraryModInt ret(1), mul(x);\r\n    while (n > 0) {\r\n      if (n &\
    \ 1) ret *= mul;\r\n      mul *= mul;\r\n      n >>= 1;\r\n    }\r\n    return\
    \ ret;\r\n  }\r\n\r\n  friend ostream &operator<<(ostream &os, const ArbitraryModInt\
    \ &p) {\r\n    return os << p.x;\r\n  }\r\n\r\n  friend istream &operator>>(istream\
    \ &is, ArbitraryModInt &a) {\r\n    int64_t t;\r\n    is >> t;\r\n    a = ArbitraryModInt(t);\r\
    \n    return (is);\r\n  }\r\n};\r\n\r\ntemplate <typename T>\r\nstruct ModCalc\
    \ {\r\n  vector<T> _fact = {1, 1};\r\n  vector<T> _fact_inv = {1, 1};\r\n  vector<T>\
    \ _inv = {0, 1};\r\n\r\n  T pow(T a, int n) {\r\n    T x(1);\r\n    while (n)\
    \ {\r\n      if (n & 1) x *= a;\r\n      a *= a;\r\n      n >>= 1;\r\n    }\r\n\
    \    return x;\r\n  }\r\n  void expand(int n) {\r\n    while (_fact.size() <=\
    \ n) {\r\n      auto i = _fact.size();\r\n      _fact.eb(_fact[i - 1] * T(i));\r\
    \n      auto q = T::get_mod() / i, r = T::get_mod() % i;\r\n      _inv.eb(_inv[r]\
    \ * T(T::get_mod() - q));\r\n      _fact_inv.eb(_fact_inv[i - 1] * _inv[i]);\r\
    \n    }\r\n  }\r\n\r\n  T fact(int n) {\r\n    if (n >= _fact.size()) expand(n);\r\
    \n    return _fact[n];\r\n  }\r\n\r\n  T fact_inv(int n) {\r\n    if (n >= _fact.size())\
    \ expand(n);\r\n    return _fact_inv[n];\r\n  }\r\n\r\n  T inv(int n) {\r\n  \
    \  if (n >= _fact.size()) expand(n);\r\n    return _inv[n];\r\n  }\r\n\r\n  T\
    \ C(ll n, ll k, bool large = false) {\r\n    assert(n >= 0);\r\n    if (k < 0\
    \ || n < k) return 0;\r\n    if (!large) return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n    k = min(k, n - k);\r\n    T x(1);\r\n    FOR(i, k) {\r\n      x\
    \ *= n - i;\r\n      x *= inv(i + 1);\r\n    }\r\n    return x;\r\n  }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: mod/amodint.hpp
  requiredBy: []
  timestamp: '2021-12-31 11:57:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/amodint.hpp
layout: document
redirect_from:
- /library/mod/amodint.hpp
- /library/mod/amodint.hpp.html
title: mod/amodint.hpp
---
