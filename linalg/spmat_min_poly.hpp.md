---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/random.hpp
    title: other/random.hpp
  - icon: ':heavy_check_mark:'
    path: sequence/find_linear_recurrence.hpp
    title: sequence/find_linear_recurrence.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"sequence/find_linear_recurrence.hpp\"\ntemplate <typename\
    \ mint>\r\nvector<mint> find_linear_recurrence(vector<mint>& A) {\r\n  int N =\
    \ len(A);\r\n  vc<mint> B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p =\
    \ 1;\r\n  FOR(i, N) {\r\n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j]\
    \ * A[i - j]; }\r\n    if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\
    \n    auto tmp = C;\r\n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(),\
    \ len(B) + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n   \
    \ if (l + l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n     \
    \ p = d;\r\n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\
    #line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator {\n  mt19937 mt;\n\n\
    \  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n#line 3 \"linalg/spmat_min_poly.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> spmat_min_poly(int N, vc<tuple<int,\
    \ int, mint>> dat) {\r\n  RandomNumberGenerator RNG;\r\n  vc<mint> S(N + N + 10);\r\
    \n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\n  FOR(k, N + N + 10) {\r\n  \
    \  FOR(i, N) S[k] += c[i] * v[i];\r\n    vc<mint> w(N);\r\n    for (auto&& [i,\
    \ j, x]: dat) w[j] += x * v[i];\r\n    swap(v, w);\r\n  }\r\n  return find_linear_recurrence(S);\r\
    \n}\r\n"
  code: "#include \"sequence/find_linear_recurrence.hpp\"\r\n#include \"other/random.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nvc<mint> spmat_min_poly(int N, vc<tuple<int,\
    \ int, mint>> dat) {\r\n  RandomNumberGenerator RNG;\r\n  vc<mint> S(N + N + 10);\r\
    \n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\n  FOR(k, N + N + 10) {\r\n  \
    \  FOR(i, N) S[k] += c[i] * v[i];\r\n    vc<mint> w(N);\r\n    for (auto&& [i,\
    \ j, x]: dat) w[j] += x * v[i];\r\n    swap(v, w);\r\n  }\r\n  return find_linear_recurrence(S);\r\
    \n}\r\n"
  dependsOn:
  - sequence/find_linear_recurrence.hpp
  - other/random.hpp
  isVerificationFile: false
  path: linalg/spmat_min_poly.hpp
  requiredBy:
  - linalg/spmat_det.hpp
  timestamp: '2022-01-10 08:17:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
documentation_of: linalg/spmat_min_poly.hpp
layout: document
redirect_from:
- /library/linalg/spmat_min_poly.hpp
- /library/linalg/spmat_min_poly.hpp.html
title: linalg/spmat_min_poly.hpp
---