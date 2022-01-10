---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: polynomial/convolution.hpp
    title: polynomial/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/fps_inv.hpp
    title: polynomial/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/poly_divmod.hpp
    title: polynomial/poly_divmod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_polynomials.test.cpp
    title: test/library_checker/polynomial/inv_of_polynomials.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf
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
    \ >> 32), xl = (unsigned)a, d, m;\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator/=(const ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  ArbitraryModInt operator-() const { return ArbitraryModInt(-val);\
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
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n};\n\ntemplate<typename\
    \ mint>\ntuple<mint, mint, mint> get_factorial_data(int n){\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ fact = {1, 1};\n  static vector<mint> fact_inv = {1, 1};\n  static vector<mint>\
    \ inv = {0, 1};\n  while(len(fact) <= n){\n    int k = len(fact);\n    fact.eb(fact[k\
    \ - 1] * mint(k));\n    auto q = ceil(mod, k);\n    int r = k * q - mod;\n   \
    \ inv.eb(inv[r] * mint(q));\n    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n\
    \  return {fact[n], fact_inv[n], inv[n]};\n}\n\ntemplate<typename mint>\nmint\
    \ fact(int n){\n  static constexpr int mod = mint::get_mod();\n  assert(0 <= n);\n\
    \  if(n >= mod) return 0;\n  return get<0>(get_factorial_data<mint>(n));\n}\n\n\
    template<typename mint>\nmint fact_inv(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  return get<1>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate<typename mint>\nmint inv(int n){\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate<typename mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n\
    \ >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n\
    \  FOR(i, k) {\n    x *= mint(n - i);\n  }\n  x *= fact_inv<mint>(k);\n  return\
    \ x;\n}\n\ntemplate<typename mint>\nvc<mint> power_table(mint a, ll N) {\n  vc<mint>\
    \ f(N, 1);\n  FOR(i, N - 1) f[i + 1] = a * f[i];\n  return f;\n}\n\nusing modint107\
    \ = modint<1'000'000'007>;\nusing modint998 = modint<998'244'353>;\nusing amint\
    \ = ArbitraryModInt;\n#line 3 \"polynomial/convolution.hpp\"\ntemplate <class\
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
    \ 880803841) return 26;\r\n    if (m == 998244353) return 3;\r\n  }\r\n};\r\n\r\
    \ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool inverse) {\r\n  int\
    \ n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  static\
    \ const fft_info<mint> info;\r\n  if (!inverse) {\r\n    int len = 0; // a[i,\
    \ i+(n>>len), i+2*(n>>len), ..] is transformed\r\n    while (len < h) {\r\n  \
    \    if (h - len == 1) {\r\n        int p = 1 << (h - len - 1);\r\n        mint\
    \ rot = 1;\r\n        FOR(s, 1 << len) {\r\n          int offset = s << (h - len);\r\
    \n          FOR(i, p) {\r\n            auto l = a[i + offset];\r\n           \
    \ auto r = a[i + offset + p] * rot;\r\n            a[i + offset] = l + r;\r\n\
    \            a[i + offset + p] = l - r;\r\n          }\r\n          rot *= info.rate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len++;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len - 2);\r\n        mint rot = 1, imag = info.root[2];\r\n      \
    \  for (int s = 0; s < (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\
    \n          mint rot3 = rot2 * rot;\r\n          int offset = s << (h - len);\r\
    \n          for (int i = 0; i < p; i++) {\r\n            auto mod2 = 1ULL * mint::get_mod()\
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
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
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
    \ n) abs_sum_b += abs(b[i]);\r\n  assert(abs_sum_a * abs_sum_b < 1e15);\r\n  vc<double>\
    \ c = CFFT::convolution_fft(a, b);\r\n  vc<ll> res(len(c));\r\n  FOR(i, len(c))\
    \ res[i] = ll(floor(c[i] + .5));\r\n  return res;\r\n}\r\n\r\ntemplate<typename\
    \ mint>\r\nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\
    \n  return convolution_ntt(a, b);\r\n}\r\n\r\ntemplate<typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_garner(a,\
    \ b);\r\n}\r\n#line 2 \"polynomial/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_inv(vc<mint>& F) {\r\n  vc<mint> G = {mint(1) / F[0]};\r\n  G.reserve(len(F));\r\
    \n  ll N = len(F), n = 1;\r\n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 *\
    \ n);\r\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\
    \n    ntt(f, false);\r\n    ntt(g, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\
    \n    ntt(f, true);\r\n    FOR(i, n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i,\
    \ 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR3(i, n, 2 * n) G.eb(f[i]\
    \ * mint(-1));\r\n    n *= 2;\r\n  }\r\n  G.resize(N);\r\n  return G;\r\n}\r\n\
    #line 2 \"polynomial/poly_divmod.hpp\"\ntemplate <typename mint>\r\npair<vc<mint>,\
    \ vc<mint>> poly_divmod(vc<mint> f, vc<mint> g) {\r\n  assert(g.back() != 0);\r\
    \n  if (len(f) < len(g)) { return {{}, f}; }\r\n  auto rf = f, rg = g;\r\n  reverse(all(rf)),\
    \ reverse(all(rg));\r\n  ll deg = len(rf) - len(rg) + 1;\r\n  rf.resize(deg),\
    \ rg.resize(deg);\r\n  rg = fps_inv(rg);\r\n  auto q = convolution(rf, rg);\r\n\
    \  q.resize(deg);\r\n  reverse(all(q));\r\n  auto h = convolution(q, g);\r\n \
    \ FOR(i, len(f)) f[i] -= h[i];\r\n  while (len(f) > 0 && f.back() == 0) f.pop_back();\r\
    \n  return {q, f};\r\n}\r\n#line 2 \"polynomial/poly_gcd.hpp\"\n\r\nnamespace\
    \ half_gcd {\r\n// https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf\r\
    \ntemplate <typename T>\r\nusing arr = array<vc<T>, 2>;\r\n\r\ntemplate <typename\
    \ T>\r\nusing mat = array<vc<T>, 4>;\r\n\r\ntemplate <typename T>\r\nvoid shrink(vc<T>&\
    \ a) {\r\n  while (len(a) && a.back() == 0) a.pop_back();\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvc<T> operator+(const vc<T>& a, const vc<T>& b) {\r\n  vc<T>\
    \ c(max(len(a), len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n  FOR(i, len(b))\
    \ c[i] += b[i];\r\n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvc<T> operator-(const vc<T>& a, const vc<T>& b) {\r\n  vc<T> c(max(len(a),\
    \ len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n  FOR(i, len(b)) c[i] -= b[i];\r\
    \n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate <typename T>\r\nvc<T> operator*(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  return convolution(a, b);\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nmat<T> operator*(const mat<T>& A, const mat<T>& B) {\r\n  return\
    \ {A[0] * B[0] + A[1] * B[2], A[0] * B[1] + A[1] * B[3],\r\n          A[2] * B[0]\
    \ + A[3] * B[2], A[2] * B[1] + A[3] * B[3]};\r\n}\r\n\r\ntemplate <typename T>\r\
    \nmat<T> step(const vc<T> q) {\r\n  mat<T> Q;\r\n  Q[1] = {1}, Q[2] = {1};\r\n\
    \  Q[3] = Q[3] - q;\r\n  return Q;\r\n}\r\n\r\ntemplate <typename T>\r\narr<T>\
    \ operator*(const mat<T>& A, const arr<T>& b) {\r\n  return {A[0] * b[0] + A[1]\
    \ * b[1], A[2] * b[0] + A[3] * b[1]};\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T>\
    \ hgcd(arr<T> a) {\r\n  assert(len(a[0]) > len(a[1]) && len(a[1]) > 0);\r\n  int\
    \ m = len(a[0]) / 2;\r\n  if (a[1].size() <= m) {\r\n    mat<T> M;\r\n    M[0]\
    \ = {1}, M[3] = {1};\r\n    return M;\r\n  }\r\n  auto R = hgcd(arr<T>({vc<T>(a[0].begin()\
    \ + m, a[0].end()),\r\n                        vc<T>(a[1].begin() + m, a[1].end())}));\r\
    \n  a = R * a;\r\n  if (a[1].size() <= m) return R;\r\n  mat<T> Q = step(poly_divmod(a[0],\
    \ a[1]).fi);\r\n  R = Q * R, a = Q * a;\r\n  if (a[1].size() <= m) return R;\r\
    \n  int k = 2 * m + 1 - len(a[0]);\r\n  auto H = hgcd(arr<T>({vc<T>(a[0].begin()\
    \ + k, a[0].end()),\r\n                        vc<T>(a[1].begin() + k, a[1].end())}));\r\
    \n  return H * R;\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T> cgcd(arr<T> a) {\r\
    \n  assert(a[0].size() > a[1].size() && !a[1].empty());\r\n  auto m0 = hgcd(a);\r\
    \n  a = m0 * a;\r\n  if (a[1].empty()) return m0;\r\n  mat<T> Q = step(poly_divmod(a[0],\
    \ a[1]).fi);\r\n  m0 = Q * m0, a = Q * a;\r\n  if (a[1].empty()) return m0;\r\n\
    \  return cgcd(a) * m0;\r\n}\r\n\r\ntemplate <typename T>\r\ntuple<vc<T>, vc<T>,\
    \ vc<T>> poly_extgcd(const vc<T>& a, const vc<T>& b) {\r\n  mat<T> Q = step(poly_divmod(a,\
    \ b).fi);\r\n  auto m = Q;\r\n  auto ap = Q * arr<T>{a, b};\r\n  if (!ap[1].empty())\
    \ m = cgcd(ap) * m;\r\n  return {a * m[0] + b * m[1], m[0], m[1]};\r\n}\r\n} //\
    \ namespace half_gcd\r\nusing half_gcd::poly_extgcd;\n"
  code: "#include \"polynomial/poly_divmod.hpp\"\r\n\r\nnamespace half_gcd {\r\n//\
    \ https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf\r\ntemplate\
    \ <typename T>\r\nusing arr = array<vc<T>, 2>;\r\n\r\ntemplate <typename T>\r\n\
    using mat = array<vc<T>, 4>;\r\n\r\ntemplate <typename T>\r\nvoid shrink(vc<T>&\
    \ a) {\r\n  while (len(a) && a.back() == 0) a.pop_back();\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvc<T> operator+(const vc<T>& a, const vc<T>& b) {\r\n  vc<T>\
    \ c(max(len(a), len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n  FOR(i, len(b))\
    \ c[i] += b[i];\r\n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvc<T> operator-(const vc<T>& a, const vc<T>& b) {\r\n  vc<T> c(max(len(a),\
    \ len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n  FOR(i, len(b)) c[i] -= b[i];\r\
    \n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate <typename T>\r\nvc<T> operator*(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  return convolution(a, b);\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nmat<T> operator*(const mat<T>& A, const mat<T>& B) {\r\n  return\
    \ {A[0] * B[0] + A[1] * B[2], A[0] * B[1] + A[1] * B[3],\r\n          A[2] * B[0]\
    \ + A[3] * B[2], A[2] * B[1] + A[3] * B[3]};\r\n}\r\n\r\ntemplate <typename T>\r\
    \nmat<T> step(const vc<T> q) {\r\n  mat<T> Q;\r\n  Q[1] = {1}, Q[2] = {1};\r\n\
    \  Q[3] = Q[3] - q;\r\n  return Q;\r\n}\r\n\r\ntemplate <typename T>\r\narr<T>\
    \ operator*(const mat<T>& A, const arr<T>& b) {\r\n  return {A[0] * b[0] + A[1]\
    \ * b[1], A[2] * b[0] + A[3] * b[1]};\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T>\
    \ hgcd(arr<T> a) {\r\n  assert(len(a[0]) > len(a[1]) && len(a[1]) > 0);\r\n  int\
    \ m = len(a[0]) / 2;\r\n  if (a[1].size() <= m) {\r\n    mat<T> M;\r\n    M[0]\
    \ = {1}, M[3] = {1};\r\n    return M;\r\n  }\r\n  auto R = hgcd(arr<T>({vc<T>(a[0].begin()\
    \ + m, a[0].end()),\r\n                        vc<T>(a[1].begin() + m, a[1].end())}));\r\
    \n  a = R * a;\r\n  if (a[1].size() <= m) return R;\r\n  mat<T> Q = step(poly_divmod(a[0],\
    \ a[1]).fi);\r\n  R = Q * R, a = Q * a;\r\n  if (a[1].size() <= m) return R;\r\
    \n  int k = 2 * m + 1 - len(a[0]);\r\n  auto H = hgcd(arr<T>({vc<T>(a[0].begin()\
    \ + k, a[0].end()),\r\n                        vc<T>(a[1].begin() + k, a[1].end())}));\r\
    \n  return H * R;\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T> cgcd(arr<T> a) {\r\
    \n  assert(a[0].size() > a[1].size() && !a[1].empty());\r\n  auto m0 = hgcd(a);\r\
    \n  a = m0 * a;\r\n  if (a[1].empty()) return m0;\r\n  mat<T> Q = step(poly_divmod(a[0],\
    \ a[1]).fi);\r\n  m0 = Q * m0, a = Q * a;\r\n  if (a[1].empty()) return m0;\r\n\
    \  return cgcd(a) * m0;\r\n}\r\n\r\ntemplate <typename T>\r\ntuple<vc<T>, vc<T>,\
    \ vc<T>> poly_extgcd(const vc<T>& a, const vc<T>& b) {\r\n  mat<T> Q = step(poly_divmod(a,\
    \ b).fi);\r\n  auto m = Q;\r\n  auto ap = Q * arr<T>{a, b};\r\n  if (!ap[1].empty())\
    \ m = cgcd(ap) * m;\r\n  return {a * m[0] + b * m[1], m[0], m[1]};\r\n}\r\n} //\
    \ namespace half_gcd\r\nusing half_gcd::poly_extgcd;"
  dependsOn:
  - polynomial/poly_divmod.hpp
  - polynomial/fps_inv.hpp
  - polynomial/convolution.hpp
  - mod/modint.hpp
  isVerificationFile: false
  path: polynomial/poly_gcd.hpp
  requiredBy: []
  timestamp: '2022-01-10 16:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/polynomial/inv_of_polynomials.test.cpp
documentation_of: polynomial/poly_gcd.hpp
layout: document
redirect_from:
- /library/polynomial/poly_gcd.hpp
- /library/polynomial/poly_gcd.hpp.html
title: polynomial/poly_gcd.hpp
---