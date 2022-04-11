---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_mul.hpp
    title: alg/group_mul.hpp
  - icon: ':question:'
    path: ds/swag.hpp
    title: ds/swag.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':x:'
    path: seq/interpolate_poly_exp.hpp
    title: seq/interpolate_poly_exp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/group_mul.hpp\"\ntemplate <class X>\r\nstruct Group_Mul\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return X(1) / x; }\r\n  static constexpr X unit() { return X(1); }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/swag.hpp\"\ntemplate <class\
    \ Monoid>\nstruct SWAG {\n  using X = typename Monoid::value_type;\n  using value_type\
    \ = X;\n  int sz = 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\n  SWAG() :\
    \ cum_l({Monoid::unit()}), cum_r(Monoid::unit()) {}\n\n  int size() { return sz;\
    \ }\n\n  void push(X x) {\n    ++sz;\n    cum_r = Monoid::op(cum_r, x);\n    dat.eb(x);\n\
    \  }\n\n  void pop() {\n    --sz;\n    cum_l.pop_back();\n    if (len(cum_l) ==\
    \ 0) {\n      cum_l = {Monoid::unit()};\n      cum_r = Monoid::unit();\n     \
    \ while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n\
    \        dat.pop_back();\n      }\n      dat.pop_back();\n    }\n  }\n\n  X prod()\
    \ { return Monoid::op(cum_l.back(), cum_r); }\n\n  void debug() {\n    print(\"\
    swag\");\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"\
    cum_r\", cum_r);\n  }\n};\n#line 2 \"mod/modint.hpp\"\ntemplate <uint mod>\nstruct\
    \ modint {\n  static constexpr bool is_modint = true;\n  uint val;\n  constexpr\
    \ modint(const ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod -\
    \ (-val) % mod) % mod) {}\n  bool operator<(const modint &other) const {\n   \
    \ return val < other.val;\n  } // To use std::map\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += mod - p.val) >=\
    \ mod) val -= mod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = (uint)(1LL * val * p.val % mod);\n    return *this;\n  }\n\
    \  modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint(get_mod() - val); }\n\
    \  modint operator+(const modint &p) const { return modint(*this) += p; }\n  modint\
    \ operator-(const modint &p) const { return modint(*this) -= p; }\n  modint operator*(const\
    \ modint &p) const { return modint(*this) *= p; }\n  modint operator/(const modint\
    \ &p) const { return modint(*this) /= p; }\n  bool operator==(const modint &p)\
    \ const { return val == p.val; }\n  bool operator!=(const modint &p) const { return\
    \ val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod, u = 1,\
    \ v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t\
    \ n) const {\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n &\
    \ 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr uint get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt\
    \ {\n  static constexpr bool is_modint = true;\n  uint val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ ArbitraryModInt &other) const {\n    return val < other.val;\n  } // To use\
    \ std::map<ArbitraryModInt, T>\n  static uint &get_mod() {\n    static uint mod\
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
    \ ArbitraryModInt operator-() const { return ArbitraryModInt(get_mod() - val);\
    \ }\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\n    return\
    \ ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt operator-(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) -= p;\n  }\n  ArbitraryModInt\
    \ operator*(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ *= p;\n  }\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) /= p;\n  }\n  bool operator==(const ArbitraryModInt\
    \ &p) const { return val == p.val; }\n  bool operator!=(const ArbitraryModInt\
    \ &p) const { return val != p.val; }\n  ArbitraryModInt inverse() const {\n  \
    \  int a = val, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ ArbitraryModInt(u);\n  }\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n};\n\ntemplate <typename\
    \ mint>\ntuple<mint, mint, mint> get_factorial_data(int n) {\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ fact = {1, 1};\n  static vector<mint> fact_inv = {1, 1};\n  static vector<mint>\
    \ inv = {0, 1};\n  while (len(fact) <= n) {\n    int k = len(fact);\n    fact.eb(fact[k\
    \ - 1] * mint(k));\n    auto q = ceil(mod, k);\n    int r = k * q - mod;\n   \
    \ inv.eb(inv[r] * mint(q));\n    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n\
    \  return {fact[n], fact_inv[n], inv[n]};\n}\n\ntemplate <typename mint>\nmint\
    \ fact(int n) {\n  static constexpr int mod = mint::get_mod();\n  assert(0 <=\
    \ n);\n  if (n >= mod) return 0;\n  return get<0>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static constexpr int\
    \ mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  return get<1>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static constexpr int mod =\
    \ mint::get_mod();\n  assert(0 <= n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate <typename mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n\
    \ >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n\
    \  FOR(i, k) { x *= mint(n - i); }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    using amint = ArbitraryModInt;\n#line 3 \"poly/convolution.hpp\"\ntemplate <class\
    \ T>\r\nvector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {\r\
    \n  int n = int(a.size()), m = int(b.size());\r\n  vector<T> ans(n + m - 1);\r\
    \n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\n  }\
    \ else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  }\r\n  return\
    \ ans;\r\n}\r\n\r\ntemplate <class mint>\r\nstruct fft_info {\r\n  static constexpr\
    \ int bsf_constexpr(unsigned int n) {\r\n    int x = 0;\r\n    while (!(n & (1\
    \ << x))) x++;\r\n    return x;\r\n  }\r\n\r\n  static constexpr int rank2 = bsf_constexpr(mint::get_mod()\
    \ - 1);\r\n  array<mint, rank2 + 1> root;\r\n  array<mint, rank2 + 1> iroot;\r\
    \n  array<mint, max(0, rank2 - 1)> rate2;\r\n  array<mint, max(0, rank2 - 1)>\
    \ irate2;\r\n  array<mint, max(0, rank2 - 2)> rate3;\r\n  array<mint, max(0, rank2\
    \ - 2)> irate3;\r\n\r\n  fft_info() {\r\n    int g = primitive_root(mint::get_mod());\r\
    \n    root[rank2] = mint(g).pow((mint::get_mod() - 1) >> rank2);\r\n    iroot[rank2]\
    \ = mint(1) / root[rank2];\r\n    FOR_R(i, rank2) {\r\n      root[i] = root[i\
    \ + 1] * root[i + 1];\r\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n   \
    \ }\r\n\r\n    {\r\n      mint prod = 1, iprod = 1;\r\n      for (int i = 0; i\
    \ <= rank2 - 2; i++) {\r\n        rate2[i] = root[i + 2] * prod;\r\n        irate2[i]\
    \ = iroot[i + 2] * iprod;\r\n        prod *= iroot[i + 2];\r\n        iprod *=\
    \ root[i + 2];\r\n      }\r\n    }\r\n    {\r\n      mint prod = 1, iprod = 1;\r\
    \n      for (int i = 0; i <= rank2 - 3; i++) {\r\n        rate3[i] = root[i +\
    \ 3] * prod;\r\n        irate3[i] = iroot[i + 3] * iprod;\r\n        prod *= iroot[i\
    \ + 3];\r\n        iprod *= root[i + 3];\r\n      }\r\n    }\r\n  }\r\n\r\n  constexpr\
    \ int primitive_root(int m) {\r\n    if (m == 167772161) return 3;\r\n    if (m\
    \ == 469762049) return 3;\r\n    if (m == 754974721) return 11;\r\n    if (m ==\
    \ 880803841) return 26;\r\n    if (m == 998244353) return 3;\r\n    return -1;\r\
    \n  }\r\n};\r\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool inverse)\
    \ {\r\n  int n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n == 1 <<\
    \ h);\r\n  static const fft_info<mint> info;\r\n  if (!inverse) {\r\n    int len\
    \ = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n    while (len\
    \ < h) {\r\n      if (h - len == 1) {\r\n        int p = 1 << (h - len - 1);\r\
    \n        mint rot = 1;\r\n        FOR(s, 1 << len) {\r\n          int offset\
    \ = s << (h - len);\r\n          FOR(i, p) {\r\n            auto l = a[i + offset];\r\
    \n            auto r = a[i + offset + p] * rot;\r\n            a[i + offset] =\
    \ l + r;\r\n            a[i + offset + p] = l - r;\r\n          }\r\n        \
    \  rot *= info.rate2[topbit(~s & -~s)];\r\n        }\r\n        len++;\r\n   \
    \   } else {\r\n        int p = 1 << (h - len - 2);\r\n        mint rot = 1, imag\
    \ = info.root[2];\r\n        for (int s = 0; s < (1 << len); s++) {\r\n      \
    \    mint rot2 = rot * rot;\r\n          mint rot3 = rot2 * rot;\r\n         \
    \ int offset = s << (h - len);\r\n          for (int i = 0; i < p; i++) {\r\n\
    \            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();\r\n       \
    \     auto a0 = 1ULL * a[i + offset].val;\r\n            auto a1 = 1ULL * a[i\
    \ + offset + p].val * rot.val;\r\n            auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].val * rot2.val;\r\n            auto a3 = 1ULL * a[i + offset + 3 * p].val\
    \ * rot3.val;\r\n            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val\
    \ * imag.val;\r\n            auto na2 = mod2 - a2;\r\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\r\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\r\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\r\n     \
    \     }\r\n          rot *= info.rate3[topbit(~s & -~s)];\r\n        }\r\n   \
    \     len += 2;\r\n      }\r\n    }\r\n  } else {\r\n    mint coef = mint(1) /\
    \ mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\n    int len = h;\r\n  \
    \  while (len) {\r\n      if (len == 1) {\r\n        int p = 1 << (h - len);\r\
    \n        mint irot = 1;\r\n        FOR(s, 1 << (len - 1)) {\r\n          int\
    \ offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\n            auto l\
    \ = a[i + offset];\r\n            auto r = a[i + offset + p];\r\n            a[i\
    \ + offset] = l + r;\r\n            a[i + offset + p]\r\n                = (unsigned\
    \ long long)(mint::get_mod() + l.val - r.val)\r\n                  * irot.val;\r\
    \n            ;\r\n          }\r\n          irot *= info.irate2[topbit(~s & -~s)];\r\
    \n        }\r\n        len--;\r\n      } else {\r\n        int p = 1 << (h - len);\r\
    \n        mint irot = 1, iimag = info.iroot[2];\r\n        FOR(s, (1 << (len -\
    \ 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint irot3 = irot2\
    \ * irot;\r\n          int offset = s << (h - len + 2);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            auto a0 = 1ULL * a[i + offset + 0 * p].val;\r\
    \n            auto a1 = 1ULL * a[i + offset + 1 * p].val;\r\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val;\r\n            auto a3 = 1ULL * a[i +\
    \ offset + 3 * p].val;\r\n\r\n            auto a2na3iimag\r\n                =\
    \ 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;\r\n\r\n          \
    \  a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 * p]\r\n\
    \                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;\r\n\
    \            a[i + offset + 2 * p]\r\n                = (a0 + a1 + (mint::get_mod()\
    \ - a2) + (mint::get_mod() - a3))\r\n                  * irot2.val;\r\n      \
    \      a[i + offset + 3 * p]\r\n                = (a0 + (mint::get_mod() - a1)\
    \ + (mint::get_mod() - a2na3iimag))\r\n                  * irot3.val;\r\n    \
    \      }\r\n          irot *= info.irate3[topbit(~s & -~s)];\r\n        }\r\n\
    \        len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  int n =\
    \ int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m -\
    \ 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\
    \u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\
    \u308B\u306E\u3067\u3002\r\n  if((n+m-3) <= sz / 2){\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.eb(0);\r\n    c.eb(0);\r\n    c.back() = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n\r\n  a.resize(sz),\
    \ b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if(same){\r\n  \
    \  b = a;\r\n  } else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\
    \n  ntt(a, 1);\r\n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ const long long nttprimes[] = {754974721, 167772161, 469762049};\r\n  using\
    \ mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\n  using\
    \ mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n),\
    \ b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] =\
    \ a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val,\
    \ b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1\
    \ = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  static const\
    \ int mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2\
    \ x2) -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
    \ - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\r\n    return mint(r0\
    \ + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);\r\n  };\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);\r\n  return c;\r\n}\r\n\
    \r\nnamespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\
    \n\r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename R>\r\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\r\n  int need = (int)a.size() + (int)b.size() -\
    \ 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  fft(fa, sz);\r\n  C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1); i++)\
    \ {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i] *\
    \ fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\n  fft(fa,\
    \ sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0; i < need; i++)\
    \ {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n  }\r\n  return\
    \ ret;\r\n}\r\n} // namespace CFFT\r\n\r\nvector<ll> convolution(const vector<ll>&\
    \ a, const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m)\
    \ return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll\
    \ abs_sum_a = 0, abs_sum_b = 0;\r\n  FOR(i, n) abs_sum_a += abs(a[i]);\r\n  FOR(i,\
    \ m) abs_sum_b += abs(b[i]);\r\n  assert(abs_sum_a * abs_sum_b < 1e15);\r\n  vc<double>\
    \ c = CFFT::convolution_fft(a, b);\r\n  vc<ll> res(len(c));\r\n  FOR(i, len(c))\
    \ res[i] = ll(floor(c[i] + .5));\r\n  return res;\r\n}\r\n\r\ntemplate<typename\
    \ mint>\r\nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\
    \n  return convolution_ntt(a, b);\r\n}\r\n\r\ntemplate<typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_garner(a,\
    \ b);\r\n}\r\n#line 5 \"poly/lagrange_interpolate_iota.hpp\"\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n\
    \  /*\r\n  Input: f(0), ..., f(n-1) and c, m (1 default)\r\n  Return: f(c), f(c+1),\
    \ ..., f(c+m-1)\r\n  Complexity: M(n, n + m)\r\n  \u2192 m \u304C\u3068\u3066\u3082\
    \u5C0F\u3055\u3044\u306A\u3089\u3070 O(n) \u3092 m \u56DE\u3084\u308B\u65B9\u304C\
    \u901F\u3044\u306E\u304B\r\n  */\r\n  if(m <= 60){\r\n    vc<mint> ANS(m);\r\n\
    \    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f, c + mint(i));\r\n    return\
    \ ANS;\r\n  }\r\n  ll n = len(f);\r\n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i]\
    \ = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1 - i);\r\n    if ((n - 1 -\
    \ i) & 1) a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ... \u306B\u5BFE\u3057\u3066\
    \ a0/x + a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\u304F\r\n  vc<mint> b(n\
    \ + m - 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c + mint(i - n + 1));\r\n\
    \  a = convolution(a, b);\r\n\r\n  SWAG<Group_Mul<mint>> swag;\r\n  vc<mint> ANS(m);\r\
    \n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while (L < i) { swag.pop(), ++L;\
    \ }\r\n    while (R - L < n) { swag.push(c + mint((R++) - n + 1)); }\r\n    auto\
    \ coef = swag.prod();\r\n    if (coef == 0) {\r\n      ANS[i] = f[(c + i).val];\r\
    \n    } else {\r\n      ANS[i] = a[i + n - 1] * coef;\r\n    }\r\n  }\r\n  return\
    \ ANS;\r\n}\r\n\r\ntemplate <typename mint>\r\nmint lagrange_interpolate_iota(vc<mint>\
    \ &f, mint c) {\r\n  /*\r\n  Input: f(0), ..., f(n-1) and c\r\n  Return: f(c)\r\
    \n  Complexity: O(n)\r\n  */\r\n  int n = len(f);\r\n  if(c.val < n) return f[c.val];\r\
    \n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n\
    \ - 1 - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n  }\r\n  vc<mint> lp(n+1),\
    \ rp(n+1);\r\n  lp[0] = rp[n] = 1;\r\n  FOR(i, n) lp[i+1] = lp[i] * (c - i);\r\
    \n  FOR_R(i, n) rp[i] = rp[i+1] * (c - i);\r\n  mint ANS = 0;\r\n  FOR(i, n) ANS\
    \ += a[i] * lp[i] * rp[i + 1];\r\n  return ANS;\r\n}\r\n#line 1 \"seq/interpolate_poly_exp.hpp\"\
    \ntemplate <typename mint>\r\nmint interpolate_poly_exp(vc<mint> a, mint r, ll\
    \ n) {\r\n  // a[i] = r^i * (polynomial of i) \u3068\u306A\u3063\u3066\u3044\u308B\
    \u5834\u5408\u306E\u88DC\u9593\r\n  if (r == 0) return (n == 0 ? a[0] : 0);\r\n\
    \  mint inv_r = mint(1) / r;\r\n  mint p = 1;\r\n  for (auto&& x: a) {\r\n   \
    \ x *= p;\r\n    p *= inv_r;\r\n  }\r\n  return lagrange_interpolate_iota(a, mint(n))\
    \ * r.pow(n);\r\n}\r\n#line 3 \"seq/interpolate_poly_exp_sum.hpp\"\n\r\ntemplate\
    \ <typename mint>\r\nmint interpolate_poly_exp_sum(vc<mint> a, mint r, ll n) {\r\
    \n  /*\r\n  a[i] = (prefix sum of r^i * (polynomial of i)) \u3068\u306A\u3063\u3066\
    \u3044\u308B\u5834\u5408\u306E\u88DC\u9593\r\n  fps \u3067\u306F (1-rx)^d(1-x)\
    \ \u306E\u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\u5408\u3068\u3044\u3046\
    \u3053\u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d + c / (1-x) \u3068\u3057\
    \u3066\u3001c \u304C\u77E5\u308A\u305F\u3044\r\n  (1-rx)^d \u3092\u304B\u3051\u3066\
    \u3001d \u6B21\u306E\u4FC2\u6570\u3092\u3068\u308C\u3070\u3001c \u304C\u624B\u306B\
    \u5165\u308B\r\n  */\r\n  if (r == mint(1)) return lagrange_interpolate_iota(a,\
    \ mint(n));\r\n  mint c = 0;\r\n  int d = len(a) - 1;\r\n  mint p = 1;\r\n  FOR(i,\
    \ d + 1) {\r\n    c += a[d - i] * p * C<mint>(d, i);\r\n    p *= -r;\r\n  }\r\n\
    \  c /= (mint(1) - r).pow(d);\r\n  for (auto&& x: a) x -= c;\r\n  return interpolate_poly_exp(a,\
    \ r, n) + c;\r\n}\r\n"
  code: "#include \"poly/lagrange_interpolate_iota.hpp\"\r\n#include \"seq/interpolate_poly_exp.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nmint interpolate_poly_exp_sum(vc<mint> a,\
    \ mint r, ll n) {\r\n  /*\r\n  a[i] = (prefix sum of r^i * (polynomial of i))\
    \ \u3068\u306A\u3063\u3066\u3044\u308B\u5834\u5408\u306E\u88DC\u9593\r\n  fps\
    \ \u3067\u306F (1-rx)^d(1-x) \u306E\u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\
    \u5408\u3068\u3044\u3046\u3053\u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d\
    \ + c / (1-x) \u3068\u3057\u3066\u3001c \u304C\u77E5\u308A\u305F\u3044\r\n  (1-rx)^d\
    \ \u3092\u304B\u3051\u3066\u3001d \u6B21\u306E\u4FC2\u6570\u3092\u3068\u308C\u3070\
    \u3001c \u304C\u624B\u306B\u5165\u308B\r\n  */\r\n  if (r == mint(1)) return lagrange_interpolate_iota(a,\
    \ mint(n));\r\n  mint c = 0;\r\n  int d = len(a) - 1;\r\n  mint p = 1;\r\n  FOR(i,\
    \ d + 1) {\r\n    c += a[d - i] * p * C<mint>(d, i);\r\n    p *= -r;\r\n  }\r\n\
    \  c /= (mint(1) - r).pow(d);\r\n  for (auto&& x: a) x -= c;\r\n  return interpolate_poly_exp(a,\
    \ r, n) + c;\r\n}\r\n"
  dependsOn:
  - poly/lagrange_interpolate_iota.hpp
  - alg/group_mul.hpp
  - ds/swag.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - seq/interpolate_poly_exp.hpp
  isVerificationFile: false
  path: seq/interpolate_poly_exp_sum.hpp
  requiredBy: []
  timestamp: '2022-04-11 22:58:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
documentation_of: seq/interpolate_poly_exp_sum.hpp
layout: document
redirect_from:
- /library/seq/interpolate_poly_exp_sum.hpp
- /library/seq/interpolate_poly_exp_sum.hpp.html
title: seq/interpolate_poly_exp_sum.hpp
---
