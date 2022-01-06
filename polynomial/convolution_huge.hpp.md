---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: polynomial/convolution.hpp
    title: polynomial/convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_huge.test.cpp
    title: test/library_checker/convolution/convolution_huge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint.hpp\"\ntemplate <int mod>\nstruct modint {\n\
    \  static constexpr bool is_static = true;\n  int val;\n\n  constexpr modint(const\
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
    \ &operator<<(ostream &os, const modint &p) {\n    return os << p.val;\n  }\n\
    \  friend istream &operator>>(istream &is, modint &a) {\n    int64_t t;\n    is\
    \ >> t;\n    a = modint(t);\n    return (is);\n  }\n  static constexpr int get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  int val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n\n  bool\
    \ operator<(const ArbitraryModInt &other) const {\n    return val < other.val;\n\
    \  } // To use std::map<ArbitraryModInt, T>\n\n  static int &get_mod() {\n   \
    \ static int mod = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod()\
    \ = md; }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val\
    \ += p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
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
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) *= p;\n  }\n\n\
    \  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ /= p;\n  }\n\n  bool operator==(const ArbitraryModInt &p) const { return val\
    \ == p.val; }\n  bool operator!=(const ArbitraryModInt &p) const { return val\
    \ != p.val; }\n  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(),\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b);\n      swap(u -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n\
    \  }\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n  friend ostream &operator<<(ostream &os,\
    \ const ArbitraryModInt &p) {\n    return os << p.val;\n  }\n  friend istream\
    \ &operator>>(istream &is, ArbitraryModInt &a) {\n    int64_t t;\n    is >> t;\n\
    \    a = ArbitraryModInt(t);\n    return (is);\n  }\n};\n\ntemplate<typename mint>\n\
    tuple<mint, mint, mint> get_factorial_data(int n){\n  static constexpr int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n\n  vector<mint> fact = {1,\
    \ 1};\n  vector<mint> fact_inv = {1, 1};\n  vector<mint> inv = {0, 1};\n  while(len(fact)\
    \ <= n){\n    int k = len(fact);\n    fact.eb(fact[k - 1] * mint(k));\n    auto\
    \ q = ceil(mod, k);\n    int r = k * q - mod;\n    inv.eb(inv[r] * mint(q));\n\
    \    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n  return {fact[n], fact_inv[n],\
    \ inv[n]};\n}\n\ntemplate<typename mint>\nmint fact(int n){\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n);\n  if(n >= mod) return 0;\n  return\
    \ get<0>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\nmint fact_inv(int\
    \ n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n\
    \  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename mint>\n\
    mint inv(int n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <=\
    \ n && n < mod);\n  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate<typename\
    \ mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n >= 0);\n  if (k\
    \ < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n) * fact_inv<mint>(k)\
    \ * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) {\n\
    \    x *= mint(n - i);\n  }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\nusing\
    \ modint107 = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\n\
    using amint = ArbitraryModInt;\n#line 2 \"polynomial/convolution.hpp\"\ntemplate\
    \ <class T>\r\nvector<T> convolution_naive(const vector<T>& a, const vector<T>&\
    \ b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  vector<T> ans(n + m\
    \ - 1);\r\n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\
    \n  } else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  }\r\n\
    \  return ans;\r\n}\r\n\r\ntemplate <class mint>\r\nstruct fft_info {\r\n  static\
    \ constexpr int bsf_constexpr(unsigned int n) {\r\n    int x = 0;\r\n    while\
    \ (!(n & (1 << x))) x++;\r\n    return x;\r\n  }\r\n\r\n  static constexpr int\
    \ rank2 = bsf_constexpr(mint::get_mod() - 1);\r\n  array<mint, rank2 + 1> root;\r\
    \n  array<mint, rank2 + 1> iroot;\r\n  array<mint, max(0, rank2 - 1)> rate2;\r\
    \n  array<mint, max(0, rank2 - 1)> irate2;\r\n  array<mint, max(0, rank2 - 2)>\
    \ rate3;\r\n  array<mint, max(0, rank2 - 2)> irate3;\r\n\r\n  fft_info() {\r\n\
    \    int g = primitive_root(mint::get_mod());\r\n    root[rank2] = mint(g).pow((mint::get_mod()\
    \ - 1) >> rank2);\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n\r\n    {\r\n      mint prod = 1, iprod = 1;\r\
    \n      for (int i = 0; i <= rank2 - 2; i++) {\r\n        rate2[i] = root[i +\
    \ 2] * prod;\r\n        irate2[i] = iroot[i + 2] * iprod;\r\n        prod *= iroot[i\
    \ + 2];\r\n        iprod *= root[i + 2];\r\n      }\r\n    }\r\n    {\r\n    \
    \  mint prod = 1, iprod = 1;\r\n      for (int i = 0; i <= rank2 - 3; i++) {\r\
    \n        rate3[i] = root[i + 3] * prod;\r\n        irate3[i] = iroot[i + 3] *\
    \ iprod;\r\n        prod *= iroot[i + 3];\r\n        iprod *= root[i + 3];\r\n\
    \      }\r\n    }\r\n  }\r\n\r\n  constexpr int primitive_root(int m) {\r\n  \
    \  if (m == 167772161) return 3;\r\n    if (m == 469762049) return 3;\r\n    if\
    \ (m == 754974721) return 11;\r\n    if (m == 880803841) return 26;\r\n    if\
    \ (m == 998244353) return 3;\r\n  }\r\n};\r\n\r\ntemplate <class mint>\r\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\r\n  int n = int(a.size());\r\n  int h\
    \ = topbit(n);\r\n  assert(n == 1 << h);\r\n  static const fft_info<mint> info;\r\
    \n  if (!inverse) {\r\n    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..]\
    \ is transformed\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n   \
    \     int p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1\
    \ << len) {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p]\
    \ * rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= info.rate2[topbit(~s & -~s)];\r\n\
    \        }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len\
    \ - 2);\r\n        mint rot = 1, imag = info.root[2];\r\n        for (int s =\
    \ 0; s < (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint\
    \ rot3 = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for\
    \ (int i = 0; i < p; i++) {\r\n            auto mod2 = 1ULL * mint::get_mod()\
    \ * mint::get_mod();\r\n            auto a0 = 1ULL * a[i + offset].val;\r\n  \
    \          auto a1 = 1ULL * a[i + offset + p].val * rot.val;\r\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val * rot2.val;\r\n            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].val * rot3.val;\r\n            auto a1na3imag = 1ULL\
    \ * mint(a1 + mod2 - a3).val * imag.val;\r\n            auto na2 = mod2 - a2;\r\
    \n            a[i + offset] = a0 + a2 + a1 + a3;\r\n            a[i + offset +\
    \ 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i + offset + 2 *\
    \ p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 * p] = a0 + na2 +\
    \ (mod2 - a1na3imag);\r\n          }\r\n          rot *= info.rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p];\r\
    \n            a[i + offset] = l + r;\r\n            a[i + offset + p]\r\n    \
    \            = (unsigned long long)(mint::get_mod() + l.val - r.val)\r\n     \
    \             * irot.val;\r\n            ;\r\n          }\r\n          irot *=\
    \ info.irate2[topbit(~s & -~s)];\r\n        }\r\n        len--;\r\n      } else\
    \ {\r\n        int p = 1 << (h - len);\r\n        mint irot = 1, iimag = info.iroot[2];\r\
    \n        FOR(s, (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n\
    \          mint irot3 = irot2 * irot;\r\n          int offset = s << (h - len\
    \ + 2);\r\n          for (int i = 0; i < p; i++) {\r\n            auto a0 = 1ULL\
    \ * a[i + offset + 0 * p].val;\r\n            auto a1 = 1ULL * a[i + offset +\
    \ 1 * p].val;\r\n            auto a2 = 1ULL * a[i + offset + 2 * p].val;\r\n \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val;\r\n\r\n            auto\
    \ a2na3iimag\r\n                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;\r\
    \n\r\n            a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset\
    \ + 1 * p]\r\n                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;\r\
    \n            a[i + offset + 2 * p]\r\n                = (a0 + a1 + (mint::get_mod()\
    \ - a2) + (mint::get_mod() - a3))\r\n                  * irot2.val;\r\n      \
    \      a[i + offset + 3 * p]\r\n                = (a0 + (mint::get_mod() - a1)\
    \ + (mint::get_mod() - a2na3iimag))\r\n                  * irot3.val;\r\n    \
    \      }\r\n          irot *= info.irate3[topbit(~s & -~s)];\r\n        }\r\n\
    \        len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  int n =\
    \ int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m -\
    \ 1) sz *= 2;\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a,\
    \ false);\r\n  if(same){\r\n    b = a;\r\n  } else {\r\n    ntt(b, false);\r\n\
    \  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, true);\r\n  a.resize(n + m - 1);\r\
    \n  mint iz = mint(1) / mint(sz);\r\n  FOR(i, len(a)) a[i] *= iz;\r\n  return\
    \ a;\r\n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  static const long long nttprimes[] = {754974721,\
    \ 167772161, 469762049};\r\n  using mint0 = modint<754974721>;\r\n  using mint1\
    \ = modint<167772161>;\r\n  using mint2 = modint<469762049>;\r\n  vc<mint0> a0(n),\
    \ b0(m);\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
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
    \ ret;\r\n}\r\n} // namespace CFFT\r\n\r\nvector<ll> convolution(vector<ll>& a,\
    \ vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  FOR(i, n) abs_sum_a += abs(a[i]);\r\n  FOR(i, n) abs_sum_b\
    \ += abs(b[i]);\r\n  assert(abs_sum_a * abs_sum_b < 1e15);\r\n  vc<double> c =\
    \ CFFT::convolution_fft(a, b);\r\n  vc<ll> res(len(c));\r\n  FOR(i, len(c)) res[i]\
    \ = ll(floor(c[i] + .5));\r\n  return res;\r\n}\r\n\r\ntemplate<typename mint>\r\
    \nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(vc<mint>&\
    \ a, vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_ntt(a,\
    \ b);\r\n}\r\n\r\ntemplate<typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value,\
    \ vc<mint>> convolution(vc<mint>& a, vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a,\
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 2 \"polynomial/convolution_huge.hpp\"\
    \ntemplate<typename mint>\r\nvc<mint> convolution_huge(vc<mint>& A, vc<mint>&\
    \ B) {\r\n  int N = len(A), M = len(B);\r\n  if (N + M - 1 <= (1 << 23)) return\
    \ convolution(A, B);\r\n  ll L = 22;\r\n  vv(mint, C, 4, 2 << L);\r\n  vv(mint,\
    \ D, 4, 2 << L);\r\n  int mask = (1 << L) - 1;\r\n  FOR(i, N) C[i >> L][i & mask]\
    \ = A[i];\r\n  FOR(i, M) D[i >> L][i & mask] = B[i];\r\n  FOR(i, 4) ntt(C[i],\
    \ false);\r\n  FOR(i, 4) ntt(D[i], false);\r\n  vv(mint, E, 7, 2 << L);\r\n  FOR(i,\
    \ 4) FOR(j, 4) FOR(k, 2 << L) E[i + j][k] += C[i][k] * D[j][k];\r\n  FOR(i, 7)\
    \ ntt(E[i], true);\r\n  vc<mint> ANS(8 << L);\r\n  FOR(i, 7) FOR(k, 2 << L) ANS[(i\
    \ << L) + k] += E[i][k];\r\n  ANS.resize(N + M - 1);\r\n  mint c = mint(1) / mint(2\
    \ << L);\r\n  FOR(i, len(ANS)) ANS[i] *= c;\r\n  return ANS;\r\n}\r\n"
  code: "#include \"polynomial/convolution.hpp\"\r\ntemplate<typename mint>\r\nvc<mint>\
    \ convolution_huge(vc<mint>& A, vc<mint>& B) {\r\n  int N = len(A), M = len(B);\r\
    \n  if (N + M - 1 <= (1 << 23)) return convolution(A, B);\r\n  ll L = 22;\r\n\
    \  vv(mint, C, 4, 2 << L);\r\n  vv(mint, D, 4, 2 << L);\r\n  int mask = (1 <<\
    \ L) - 1;\r\n  FOR(i, N) C[i >> L][i & mask] = A[i];\r\n  FOR(i, M) D[i >> L][i\
    \ & mask] = B[i];\r\n  FOR(i, 4) ntt(C[i], false);\r\n  FOR(i, 4) ntt(D[i], false);\r\
    \n  vv(mint, E, 7, 2 << L);\r\n  FOR(i, 4) FOR(j, 4) FOR(k, 2 << L) E[i + j][k]\
    \ += C[i][k] * D[j][k];\r\n  FOR(i, 7) ntt(E[i], true);\r\n  vc<mint> ANS(8 <<\
    \ L);\r\n  FOR(i, 7) FOR(k, 2 << L) ANS[(i << L) + k] += E[i][k];\r\n  ANS.resize(N\
    \ + M - 1);\r\n  mint c = mint(1) / mint(2 << L);\r\n  FOR(i, len(ANS)) ANS[i]\
    \ *= c;\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - polynomial/convolution.hpp
  - mod/modint.hpp
  isVerificationFile: false
  path: polynomial/convolution_huge.hpp
  requiredBy: []
  timestamp: '2022-01-07 01:39:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/convolution_huge.test.cpp
documentation_of: polynomial/convolution_huge.hpp
layout: document
redirect_from:
- /library/polynomial/convolution_huge.hpp
- /library/polynomial/convolution_huge.hpp.html
title: polynomial/convolution_huge.hpp
---
