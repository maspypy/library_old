---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':x:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator {\n  mt19937\
    \ mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 2 \"nt/primetest.hpp\"\nstruct\
    \ m64 {\r\n    using i64 = int64_t;\r\n    using u64 = uint64_t;\r\n    using\
    \ u128 = __uint128_t;\r\n\r\n    inline static u64 m, r, n2; // r * m = -1 (mod\
    \ 1<<64), n2 = 1<<128 (mod m)\r\n    static void set_mod(u64 m) {\r\n        assert(m\
    \ < (1ull << 62));\r\n        assert((m & 1) == 1);\r\n        m64::m = m;\r\n\
    \        n2 = -u128(m) % m;\r\n        r = m;\r\n        FOR (_, 5) r *= 2 - m*r;\r\
    \n        r = -r;\r\n        assert(r * m == -1ull);\r\n    }\r\n    static u64\
    \ reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n    u64 x;\r\
    \n    m64() : x(0) {}\r\n    m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n    u64\
    \ val() const { u64 y = reduce(x); return y >= m ? y-m : y; }\r\n    m64 &operator+=(m64\
    \ y) {\r\n        x += y.x - (m << 1);\r\n        x = (i64(x) < 0 ? x + (m <<\
    \ 1) : x);\r\n        return *this;\r\n    }\r\n    m64 &operator-=(m64 y) {\r\
    \n        x -= y.x;\r\n        x = (i64(x) < 0 ? x + (m << 1) : x);\r\n      \
    \  return *this;\r\n    }\r\n    m64 &operator*=(m64 y) { x = reduce(u128(x) *\
    \ y.x); return *this; }\r\n    m64 operator+(m64 y) const { return m64(*this)\
    \ += y; }\r\n    m64 operator-(m64 y) const { return m64(*this) -= y; }\r\n  \
    \  m64 operator*(m64 y) const { return m64(*this) *= y; }\r\n    bool operator==(m64\
    \ y) const { return (x >= m ? x-m : x) == (y.x >= m ? y.x-m : y.x); }\r\n    bool\
    \ operator!=(m64 y) const { return not operator==(y); }\r\n    m64 pow(u64 n)\
    \ const {\r\n        m64 y = 1, z = *this;\r\n        for ( ; n; n >>= 1, z *=\
    \ z) if (n & 1) y *= z;\r\n        return y;\r\n    }\r\n};\r\n\r\nbool primetest(const\
    \ uint64_t x) {\r\n    using u64 = uint64_t;\r\n    if (x == 2 or x == 3 or x\
    \ == 5 or x == 7) return true;\r\n    if (x % 2 == 0 or x % 3 == 0 or x % 5 ==\
    \ 0 or x % 7 == 0) return false;\r\n    if (x < 121) return x > 1;\r\n    const\
    \ u64 d = (x-1) >> __builtin_ctzll(x-1);\r\n    m64::set_mod(x);\r\n    const\
    \ m64 one(1), minus_one(x-1);\r\n    auto ok = [&](u64 a) {\r\n        auto y\
    \ = m64(a).pow(d);\r\n        u64 t = d;\r\n        while (y != one and y != minus_one\
    \ and t != x-1) y *= y, t <<= 1;\r\n        if (y != minus_one and t % 2 == 0)\
    \ return false;\r\n        return true;\r\n    };\r\n    if (x < (1ull << 32))\
    \ {\r\n        for (u64 a : { 2, 7, 61 }) if (not ok(a)) return false;\r\n   \
    \ } else {\r\n        for (u64 a : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022\
    \ }) {\r\n            if (x <= a) return true;\r\n            if (not ok(a)) return\
    \ false;\r\n        }\r\n    }\r\n    return true;\r\n}\n#line 3 \"graph/chromatic.hpp\"\
    \n\r\ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph&\
    \ G) {\r\n  assert(G.is_prepared());\r\n  // O(N2^N)\r\n\r\n  int N = G.N;\r\n\
    \  vc<int> nbd(N);\r\n  FOR(v, N) for (auto&& e : G[v]) nbd[v] |= 1 << e.to;\r\
    \n\r\n  // s \u306E subset \u3067\u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\
    \u5408\u306E\u6570\u3048\u4E0A\u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\
    \n  FOR(v, N) FOR(s, 1 << v) { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\
    \n\r\n  vi pow(1 << N);\r\n  auto solve_p = [&](int p) -> int {\r\n    FOR(s,\
    \ 1 << N) pow[s] = ((N - popcnt(s)) & 1 ? 1 : -1);\r\n    FOR3(k, 1, N) {\r\n\
    \      ll sum = 0;\r\n      FOR(s, 1 << N) {\r\n        pow[s] = pow[s] * dp[s];\r\
    \n        if (p) pow[s] %= p;\r\n        sum += pow[s];\r\n      }\r\n      if\
    \ (p) sum %= p;\r\n      if (sum != 0) { return k; }\r\n    }\r\n    return N;\r\
    \n  };\r\n\r\n  int ANS = 0;\r\n  chmax(ANS, solve_p(0));\r\n\r\n  FOR_(TRIAL)\
    \ {\r\n    RandomNumberGenerator RNG;\r\n    int p;\r\n    while (1) {\r\n   \
    \   p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p)) break;\r\n    }\r\
    \n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\n"
  code: "#include \"other/random.hpp\"\r\n#include \"nt/primetest.hpp\"\r\n\r\ntemplate\
    \ <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph& G) {\r\n  assert(G.is_prepared());\r\
    \n  // O(N2^N)\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\n  FOR(v, N) for (auto&&\
    \ e : G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset \u3067\u3042\u308B\
    \u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\u3052\r\n \
    \ vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1 << v) { dp[s | 1\
    \ << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\n  auto solve_p\
    \ = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s)) & 1 ?\
    \ 1 : -1);\r\n    FOR3(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1 << N)\
    \ {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\n   \
    \     sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum !=\
    \ 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\n\
    \  chmax(ANS, solve_p(0));\r\n\r\n  FOR_(TRIAL) {\r\n    RandomNumberGenerator\
    \ RNG;\r\n    int p;\r\n    while (1) {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\
    \n      if (primetest(p)) break;\r\n    }\r\n    chmax(ANS, solve_p(p));\r\n \
    \ }\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - other/random.hpp
  - nt/primetest.hpp
  isVerificationFile: false
  path: graph/chromatic.hpp
  requiredBy: []
  timestamp: '2022-01-05 04:59:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: graph/chromatic.hpp
layout: document
redirect_from:
- /library/graph/chromatic.hpp
- /library/graph/chromatic.hpp.html
title: graph/chromatic.hpp
---
