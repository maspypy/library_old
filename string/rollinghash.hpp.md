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
  bundledCode: "#line 2 \"string/rollinghash.hpp\"\n\nstruct RollingHash {\n  static\
    \ const uint64_t mod = (1ull << 61ull) - 1;\n  vector<uint64_t> power;\n  const\
    \ uint64_t base;\n\n  static inline uint64_t add(uint64_t a, uint64_t b) {\n \
    \   if ((a += b) >= mod) a -= mod;\n    return a;\n  }\n\n  static inline uint64_t\
    \ mul(uint64_t a, uint64_t b) {\n    const uint64_t MASK30 = (1LL<<30) - 1;\n\
    \    const uint64_t MASK31 = (1LL<<31) - 1;\n    const uint64_t MASK61 = (1LL<<61)\
    \ - 1;\n    uint64_t au = a >> 31, ad = a & MASK31;\n    uint64_t bu = b >> 31,\
    \ bd = b & MASK31;\n    uint64_t x = ad * bu + au * bd;\n    uint64_t xu = x >>\
    \ 30, xd = x & MASK30;\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\n   \
    \ xu = x >> 61, xd = x & MASK61;\n    x = xu + xd;\n    if(x >= MASK61) x -= MASK61;\n\
    \    return x;\n  }\n\n  static inline uint64_t generate_base() {\n    mt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n    uniform_int_distribution<uint64_t>\
    \ rand(1, RollingHash::mod - 1);\n    return rand(mt);\n  }\n\n  inline void expand(size_t\
    \ sz) {\n    if (power.size() < sz + 1) {\n      int pre_sz = (int)power.size();\n\
    \      power.resize(sz + 1);\n      for (int i = pre_sz - 1; i < sz; i++) {\n\
    \        power[i + 1] = mul(power[i], base);\n      }\n    }\n  }\n\n  explicit\
    \ RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}\n\n \
    \ vector<uint64_t> build(const string& s) const {\n    int sz = s.size();\n  \
    \  vector<uint64_t> hashed(sz + 1);\n    for (int i = 0; i < sz; i++) {\n    \
    \  hashed[i + 1] = add(mul(hashed[i], base), s[i]);\n    }\n    return hashed;\n\
    \  }\n\n  template <typename T>\n  vector<uint64_t> build(const vector<T>& s)\
    \ const {\n    int sz = s.size();\n    vector<uint64_t> hashed(sz + 1);\n    for\
    \ (int i = 0; i < sz; i++) {\n      hashed[i + 1] = add(mul(hashed[i], base),\
    \ s[i]);\n    }\n    return hashed;\n  }\n\n  uint64_t query(const vector<uint64_t>&\
    \ s, int l, int r) {\n    expand(r - l);\n    return add(s[r], mod - mul(s[l],\
    \ power[r - l]));\n  }\n\n  uint64_t combine(uint64_t h1, uint64_t h2, size_t\
    \ h2len) {\n    expand(h2len);\n    return add(mul(h1, power[h2len]), h2);\n \
    \ }\n\n  int lcp(const vector<uint64_t>& a, int l1, int r1, const vector<uint64_t>&\
    \ b, int l2, int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int low = 0,\
    \ high = len + 1;\n    while (high - low > 1) {\n      int mid = (low + high)\
    \ / 2;\n      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n        low\
    \ = mid;\n      else\n        high = mid;\n    }\n    return low;\n  }\n};\n"
  code: "#pragma once\n\nstruct RollingHash {\n  static const uint64_t mod = (1ull\
    \ << 61ull) - 1;\n  vector<uint64_t> power;\n  const uint64_t base;\n\n  static\
    \ inline uint64_t add(uint64_t a, uint64_t b) {\n    if ((a += b) >= mod) a -=\
    \ mod;\n    return a;\n  }\n\n  static inline uint64_t mul(uint64_t a, uint64_t\
    \ b) {\n    const uint64_t MASK30 = (1LL<<30) - 1;\n    const uint64_t MASK31\
    \ = (1LL<<31) - 1;\n    const uint64_t MASK61 = (1LL<<61) - 1;\n    uint64_t au\
    \ = a >> 31, ad = a & MASK31;\n    uint64_t bu = b >> 31, bd = b & MASK31;\n \
    \   uint64_t x = ad * bu + au * bd;\n    uint64_t xu = x >> 30, xd = x & MASK30;\n\
    \    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\n    xu = x >> 61, xd = x &\
    \ MASK61;\n    x = xu + xd;\n    if(x >= MASK61) x -= MASK61;\n    return x;\n\
    \  }\n\n  static inline uint64_t generate_base() {\n    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);\n    return\
    \ rand(mt);\n  }\n\n  inline void expand(size_t sz) {\n    if (power.size() <\
    \ sz + 1) {\n      int pre_sz = (int)power.size();\n      power.resize(sz + 1);\n\
    \      for (int i = pre_sz - 1; i < sz; i++) {\n        power[i + 1] = mul(power[i],\
    \ base);\n      }\n    }\n  }\n\n  explicit RollingHash(uint64_t base = generate_base())\
    \ : base(base), power{1} {}\n\n  vector<uint64_t> build(const string& s) const\
    \ {\n    int sz = s.size();\n    vector<uint64_t> hashed(sz + 1);\n    for (int\
    \ i = 0; i < sz; i++) {\n      hashed[i + 1] = add(mul(hashed[i], base), s[i]);\n\
    \    }\n    return hashed;\n  }\n\n  template <typename T>\n  vector<uint64_t>\
    \ build(const vector<T>& s) const {\n    int sz = s.size();\n    vector<uint64_t>\
    \ hashed(sz + 1);\n    for (int i = 0; i < sz; i++) {\n      hashed[i + 1] = add(mul(hashed[i],\
    \ base), s[i]);\n    }\n    return hashed;\n  }\n\n  uint64_t query(const vector<uint64_t>&\
    \ s, int l, int r) {\n    expand(r - l);\n    return add(s[r], mod - mul(s[l],\
    \ power[r - l]));\n  }\n\n  uint64_t combine(uint64_t h1, uint64_t h2, size_t\
    \ h2len) {\n    expand(h2len);\n    return add(mul(h1, power[h2len]), h2);\n \
    \ }\n\n  int lcp(const vector<uint64_t>& a, int l1, int r1, const vector<uint64_t>&\
    \ b, int l2, int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int low = 0,\
    \ high = len + 1;\n    while (high - low > 1) {\n      int mid = (low + high)\
    \ / 2;\n      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n        low\
    \ = mid;\n      else\n        high = mid;\n    }\n    return low;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
