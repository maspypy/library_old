---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid_rollinghash.hpp
    title: alg/monoid_rollinghash.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_rollinghash.hpp\"\nstruct Monoid_Rolling_Hash\
    \ {\r\n  using value_type = pi; // pow of base, val\r\n  using X = value_type;\r\
    \n  static constexpr ll M61 = (1LL << 61) - 1;\r\n  static ll add(ll a, ll b)\
    \ {\r\n    if ((a += b) >= M61) a -= M61;\r\n    return a;\r\n  }\r\n  static\
    \ ll mul(ll a, ll b) {\r\n    const ll MASK30 = (1LL << 30) - 1;\r\n    const\
    \ ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 = (1LL << 61) - 1;\r\n \
    \   ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >> 31, bd = b & MASK31;\r\
    \n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30, xd = x & MASK30;\r\n \
    \   x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n    xu = x >> 61, xd = x &\
    \ MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x -= MASK61;\r\n    return\
    \ x;\r\n  }\r\n  static X op(X x, X y) {\r\n    return {mul(x.fi, y.fi), add(mul(x.se,\
    \ y.fi), y.se)};\r\n  }\r\n  static constexpr X unit = X(1, 0);\r\n  static constexpr\
    \ bool commute = false;\r\n};\n#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator\
    \ {\n  mt19937 mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 2 \"ds/segtree.hpp\"\ntemplate\
    \ <class Monoid>\nstruct SegTree {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0)\
    \ {}\n  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit)) {}\n  SegTree(vc<X> v)\
    \ : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, Monoid::unit);\n    FOR(i, n) dat[size +\
    \ i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  X operator[](int i)\
    \ { return dat[size + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n\n  void set(int i, X x) {\n    assert(i < n);\n \
    \   dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L,\
    \ int R) {\n    assert(L <= R);\n    assert(R <= n);\n    X vl = Monoid::unit,\
    \ vr = Monoid::unit;\n    L += size, R += size;\n    while (L < R) {\n      if\
    \ (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R],\
    \ vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n\
    \  X prod_all() { return dat[1];}\n\n  template <class F>\n  int max_right(F &check,\
    \ int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit));\n    if (L ==\
    \ n) return n;\n    L += size;\n    X sm = Monoid::unit;\n    do {\n      while\
    \ (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n       \
    \ while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F &check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit;\n    do {\n      --R;\n      while (R > 1 && (R % 2))\
    \ R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R < size)\
    \ {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R], sm))) {\n\
    \            sm = Monoid::op(dat[R], sm);\n            R--;\n          }\n   \
    \     }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  void debug() { print(\"\
    segtree\", dat); }\n};\n#line 4 \"mod/modular_subset_sum.hpp\"\n\r\nvc<bool> modular_subset_sum(int\
    \ mod, vc<int> vals) {\r\n  /*\r\n  (|vals| + mod) * log^2(mod)\r\n  */\r\n  using\
    \ Mono = Monoid_Rolling_Hash;\r\n  RandomNumberGenerator RNG;\r\n  const ll base\
    \ = RNG(0, Mono::M61);\r\n  vc<bool> A(mod + mod);\r\n  ll cnt = 0;\r\n  vc<pi>\
    \ seg_raw(mod + mod);\r\n  FOR(i, mod + mod) seg_raw[i] = {base, 0};\r\n  SegTree<Mono>\
    \ seg(seg_raw);\r\n\r\n  auto add = [&](ll x) -> void {\r\n    ++cnt;\r\n    A[x]\
    \ = A[x + mod] = 1;\r\n    seg.set(x, {base, 1});\r\n    seg.set(x + mod, {base,\
    \ 1});\r\n  };\r\n\r\n  add(0);\r\n\r\n  for (auto&& val: vals) {\r\n    val %=\
    \ mod;\r\n    if (cnt == mod) break;\r\n    vc<pi> LR;\r\n    LR.eb(0, mod);\r\
    \n    vi ADD;\r\n    while (len(LR)) {\r\n      auto [L, R] = LR.back();\r\n \
    \     LR.pop_back();\r\n      if (L == R) continue;\r\n      ll x1 = seg.prod(L,\
    \ R).se;\r\n      ll x2 = seg.prod(mod + L - val, mod + R - val).se;\r\n     \
    \ if (x1 == x2) continue;\r\n      if (R == L + 1) {\r\n        // \u5BFE\u79F0\
    \u5DEE L \u304C\u898B\u3064\u304B\u3063\u305F\r\n        if (!A[L]) ADD.eb(L);\r\
    \n        continue;\r\n      }\r\n      ll M = (L + R) / 2;\r\n      LR.eb(L,\
    \ M);\r\n      LR.eb(M, R);\r\n    }\r\n    for (auto&& a: ADD) add(a);\r\n  }\r\
    \n\r\n  A.resize(mod);\r\n  return A;\r\n}\n"
  code: "#include \"alg/monoid_rollinghash.hpp\"\r\n#include \"other/random.hpp\"\r\
    \n#include \"ds/segtree.hpp\"\r\n\r\nvc<bool> modular_subset_sum(int mod, vc<int>\
    \ vals) {\r\n  /*\r\n  (|vals| + mod) * log^2(mod)\r\n  */\r\n  using Mono = Monoid_Rolling_Hash;\r\
    \n  RandomNumberGenerator RNG;\r\n  const ll base = RNG(0, Mono::M61);\r\n  vc<bool>\
    \ A(mod + mod);\r\n  ll cnt = 0;\r\n  vc<pi> seg_raw(mod + mod);\r\n  FOR(i, mod\
    \ + mod) seg_raw[i] = {base, 0};\r\n  SegTree<Mono> seg(seg_raw);\r\n\r\n  auto\
    \ add = [&](ll x) -> void {\r\n    ++cnt;\r\n    A[x] = A[x + mod] = 1;\r\n  \
    \  seg.set(x, {base, 1});\r\n    seg.set(x + mod, {base, 1});\r\n  };\r\n\r\n\
    \  add(0);\r\n\r\n  for (auto&& val: vals) {\r\n    val %= mod;\r\n    if (cnt\
    \ == mod) break;\r\n    vc<pi> LR;\r\n    LR.eb(0, mod);\r\n    vi ADD;\r\n  \
    \  while (len(LR)) {\r\n      auto [L, R] = LR.back();\r\n      LR.pop_back();\r\
    \n      if (L == R) continue;\r\n      ll x1 = seg.prod(L, R).se;\r\n      ll\
    \ x2 = seg.prod(mod + L - val, mod + R - val).se;\r\n      if (x1 == x2) continue;\r\
    \n      if (R == L + 1) {\r\n        // \u5BFE\u79F0\u5DEE L \u304C\u898B\u3064\
    \u304B\u3063\u305F\r\n        if (!A[L]) ADD.eb(L);\r\n        continue;\r\n \
    \     }\r\n      ll M = (L + R) / 2;\r\n      LR.eb(L, M);\r\n      LR.eb(M, R);\r\
    \n    }\r\n    for (auto&& a: ADD) add(a);\r\n  }\r\n\r\n  A.resize(mod);\r\n\
    \  return A;\r\n}"
  dependsOn:
  - alg/monoid_rollinghash.hpp
  - other/random.hpp
  - ds/segtree.hpp
  isVerificationFile: false
  path: mod/modular_subset_sum.hpp
  requiredBy: []
  timestamp: '2022-03-11 22:59:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modular_subset_sum.hpp
layout: document
redirect_from:
- /library/mod/modular_subset_sum.hpp
- /library/mod/modular_subset_sum.hpp.html
title: mod/modular_subset_sum.hpp
---
