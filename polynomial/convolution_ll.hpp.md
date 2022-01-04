---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/tree_all_distances.hpp
    title: graph/tree_all_distances.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
    title: test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"polynomial/convolution_ll.hpp\"\nstruct CFFT {\r\n  struct\
    \ C {\r\n    double x, y;\r\n    C(double _x = 0, double _y = 0) : x(_x), y(_y)\
    \ {}\r\n    C operator~() const { return C(x, -y); }\r\n    C operator*(const\
    \ C& c) const {\r\n      return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n \
    \   }\r\n    C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n\
    \    C operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  };\r\n\
    \r\n  vector<vector<C>> w = vector<vector<C>>(1, vector<C>(1, 1));\r\n\r\n  void\
    \ init(int lg) {\r\n    for (int d = 1, m = 1; d <= lg; d++, m <<= 1)\r\n    \
    \  if (d >= (int)w.size()) {\r\n        w.emplace_back(m);\r\n        const double\
    \ th = M_PI / m;\r\n        for (int i = 0; i < m; i++)\r\n          w[d][i] =\
    \ (i & 1 ? C(cos(th * i), sin(th * i)) : w[d - 1][i >> 1]);\r\n      }\r\n  }\r\
    \n  void fft(vector<C>& f, bool inv) {\r\n    const int n = f.size();\r\n    const\
    \ int lg = __lg(n);\r\n    if (lg >= (int)w.size()) init(lg);\r\n    if (inv)\
    \ {\r\n      for (int k = 1; k <= lg; k++) {\r\n        const int d = 1 << (k\
    \ - 1);\r\n        for (int s = 0; s < n; s += 2 * d) {\r\n          for (int\
    \ i = s; i < s + d; i++) {\r\n            C x = f[i], y = ~w[k][i - s] * f[d +\
    \ i];\r\n            f[i] = x + y;\r\n            f[d + i] = x - y;\r\n      \
    \    }\r\n        }\r\n      }\r\n    } else {\r\n      for (int k = lg; k; k--)\
    \ {\r\n        const int d = 1 << (k - 1);\r\n        for (int s = 0; s < n; s\
    \ += 2 * d) {\r\n          for (int i = s; i < s + d; i++) {\r\n            C\
    \ x = f[i], y = f[d + i];\r\n            f[i] = x + y;\r\n            f[d + i]\
    \ = w[k][i - s] * (x - y);\r\n          }\r\n        }\r\n      }\r\n    }\r\n\
    \  }\r\n  vector<ll> conv(const vector<ll>& a, const vector<ll>& b) {\r\n    const\
    \ int as = a.size();\r\n    const int bs = b.size();\r\n    if (!as or !bs) return\
    \ {};\r\n    const int cs = as + bs - 1;\r\n    vector<ll> c(cs);\r\n    if (max(as,\
    \ bs) < 16) {\r\n      for (int i = 0; i < as; i++)\r\n        for (int j = 0;\
    \ j < bs; j++) { c[i + j] += (ll)a[i] * b[j]; }\r\n      return c;\r\n    }\r\n\
    \    const int n = 1 << __lg(2 * cs - 1);\r\n    vector<C> f(n);\r\n    for (int\
    \ i = 0; i < as; i++) f[i].x = a[i];\r\n    for (int i = 0; i < bs; i++) f[i].y\
    \ = b[i];\r\n    fft(f, 0);\r\n    static const C rad(0, -.25);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n      int j = i ? i ^ ((1 << __lg(i)) - 1) : 0;\r\n\
    \      if (i > j) continue;\r\n      C x = f[i] + ~f[j], y = f[i] - ~f[j];\r\n\
    \      f[i] = x * y * rad;\r\n      f[j] = ~f[i];\r\n    }\r\n    fft(f, 1);\r\
    \n    for (int i = 0; i < cs; i++) c[i] = f[i].x / n + .5;\r\n    return c;\r\n\
    \  }\r\n  vector<ll> square(const vector<ll>& a) {\r\n    const int as = a.size();\r\
    \n    if (!as) return {};\r\n    const int cs = as * 2 - 1;\r\n    vector<ll>\
    \ c(cs);\r\n    if (as < 16) {\r\n      for (int i = 0; i < as; i++)\r\n     \
    \   for (int j = 0; j < as; j++) { c[i + j] += (int)a[i] * a[j]; }\r\n      return\
    \ c;\r\n    }\r\n    const int n = 1 << __lg(cs * 2 - 1);\r\n    vector<C> f(n);\r\
    \n    for (int i = 0; i < as; i++) f[i].x = a[i];\r\n    fft(f, 0);\r\n    for\
    \ (int i = 0; i < n; i++) f[i] = f[i] * f[i];\r\n    fft(f, 1);\r\n    for (int\
    \ i = 0; i < cs; i++) c[i] = f[i].x / n + .5;\r\n    return c;\r\n  }\r\n};\r\n\
    \r\nCFFT cfft;\r\n\r\nvector<ll> convolution_ll(vector<ll>& A, vector<ll>& B)\
    \ {\r\n  if (min(len(A), len(B)) <= 60) {\r\n    vector<ll> C(len(A) + len(B)\
    \ - 1);\r\n    FOR(i, len(A)) FOR(j, len(B)) C[i + j] += A[i] * B[j];\r\n    return\
    \ C;\r\n  }\r\n  assert(SUM(A) * SUM(B) < 1e15);\r\n  return cfft.conv(A, B);\r\
    \n}\r\n\r\nvector<ll> conv_square_ll(vector<ll>& A) {\r\n  if (len(A) <= 60) {\r\
    \n    vector<ll> C(2 * len(A) - 1);\r\n    FOR(i, len(A)) FOR(j, len(A)) C[i +\
    \ j] += A[i] * A[j];\r\n    return C;\r\n  }\r\n  assert(SUM(A) * SUM(A) < 1e15);\r\
    \n  return cfft.square(A);\r\n}\r\n"
  code: "#pragma once\r\nstruct CFFT {\r\n  struct C {\r\n    double x, y;\r\n   \
    \ C(double _x = 0, double _y = 0) : x(_x), y(_y) {}\r\n    C operator~() const\
    \ { return C(x, -y); }\r\n    C operator*(const C& c) const {\r\n      return\
    \ C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n    }\r\n    C operator+(const C&\
    \ c) const { return C(x + c.x, y + c.y); }\r\n    C operator-(const C& c) const\
    \ { return C(x - c.x, y - c.y); }\r\n  };\r\n\r\n  vector<vector<C>> w = vector<vector<C>>(1,\
    \ vector<C>(1, 1));\r\n\r\n  void init(int lg) {\r\n    for (int d = 1, m = 1;\
    \ d <= lg; d++, m <<= 1)\r\n      if (d >= (int)w.size()) {\r\n        w.emplace_back(m);\r\
    \n        const double th = M_PI / m;\r\n        for (int i = 0; i < m; i++)\r\
    \n          w[d][i] = (i & 1 ? C(cos(th * i), sin(th * i)) : w[d - 1][i >> 1]);\r\
    \n      }\r\n  }\r\n  void fft(vector<C>& f, bool inv) {\r\n    const int n =\
    \ f.size();\r\n    const int lg = __lg(n);\r\n    if (lg >= (int)w.size()) init(lg);\r\
    \n    if (inv) {\r\n      for (int k = 1; k <= lg; k++) {\r\n        const int\
    \ d = 1 << (k - 1);\r\n        for (int s = 0; s < n; s += 2 * d) {\r\n      \
    \    for (int i = s; i < s + d; i++) {\r\n            C x = f[i], y = ~w[k][i\
    \ - s] * f[d + i];\r\n            f[i] = x + y;\r\n            f[d + i] = x -\
    \ y;\r\n          }\r\n        }\r\n      }\r\n    } else {\r\n      for (int\
    \ k = lg; k; k--) {\r\n        const int d = 1 << (k - 1);\r\n        for (int\
    \ s = 0; s < n; s += 2 * d) {\r\n          for (int i = s; i < s + d; i++) {\r\
    \n            C x = f[i], y = f[d + i];\r\n            f[i] = x + y;\r\n     \
    \       f[d + i] = w[k][i - s] * (x - y);\r\n          }\r\n        }\r\n    \
    \  }\r\n    }\r\n  }\r\n  vector<ll> conv(const vector<ll>& a, const vector<ll>&\
    \ b) {\r\n    const int as = a.size();\r\n    const int bs = b.size();\r\n   \
    \ if (!as or !bs) return {};\r\n    const int cs = as + bs - 1;\r\n    vector<ll>\
    \ c(cs);\r\n    if (max(as, bs) < 16) {\r\n      for (int i = 0; i < as; i++)\r\
    \n        for (int j = 0; j < bs; j++) { c[i + j] += (ll)a[i] * b[j]; }\r\n  \
    \    return c;\r\n    }\r\n    const int n = 1 << __lg(2 * cs - 1);\r\n    vector<C>\
    \ f(n);\r\n    for (int i = 0; i < as; i++) f[i].x = a[i];\r\n    for (int i =\
    \ 0; i < bs; i++) f[i].y = b[i];\r\n    fft(f, 0);\r\n    static const C rad(0,\
    \ -.25);\r\n    for (int i = 0; i < n; i++) {\r\n      int j = i ? i ^ ((1 <<\
    \ __lg(i)) - 1) : 0;\r\n      if (i > j) continue;\r\n      C x = f[i] + ~f[j],\
    \ y = f[i] - ~f[j];\r\n      f[i] = x * y * rad;\r\n      f[j] = ~f[i];\r\n  \
    \  }\r\n    fft(f, 1);\r\n    for (int i = 0; i < cs; i++) c[i] = f[i].x / n +\
    \ .5;\r\n    return c;\r\n  }\r\n  vector<ll> square(const vector<ll>& a) {\r\n\
    \    const int as = a.size();\r\n    if (!as) return {};\r\n    const int cs =\
    \ as * 2 - 1;\r\n    vector<ll> c(cs);\r\n    if (as < 16) {\r\n      for (int\
    \ i = 0; i < as; i++)\r\n        for (int j = 0; j < as; j++) { c[i + j] += (int)a[i]\
    \ * a[j]; }\r\n      return c;\r\n    }\r\n    const int n = 1 << __lg(cs * 2\
    \ - 1);\r\n    vector<C> f(n);\r\n    for (int i = 0; i < as; i++) f[i].x = a[i];\r\
    \n    fft(f, 0);\r\n    for (int i = 0; i < n; i++) f[i] = f[i] * f[i];\r\n  \
    \  fft(f, 1);\r\n    for (int i = 0; i < cs; i++) c[i] = f[i].x / n + .5;\r\n\
    \    return c;\r\n  }\r\n};\r\n\r\nCFFT cfft;\r\n\r\nvector<ll> convolution_ll(vector<ll>&\
    \ A, vector<ll>& B) {\r\n  if (min(len(A), len(B)) <= 60) {\r\n    vector<ll>\
    \ C(len(A) + len(B) - 1);\r\n    FOR(i, len(A)) FOR(j, len(B)) C[i + j] += A[i]\
    \ * B[j];\r\n    return C;\r\n  }\r\n  assert(SUM(A) * SUM(B) < 1e15);\r\n  return\
    \ cfft.conv(A, B);\r\n}\r\n\r\nvector<ll> conv_square_ll(vector<ll>& A) {\r\n\
    \  if (len(A) <= 60) {\r\n    vector<ll> C(2 * len(A) - 1);\r\n    FOR(i, len(A))\
    \ FOR(j, len(A)) C[i + j] += A[i] * A[j];\r\n    return C;\r\n  }\r\n  assert(SUM(A)\
    \ * SUM(A) < 1e15);\r\n  return cfft.square(A);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/convolution_ll.hpp
  requiredBy:
  - graph/tree_all_distances.hpp
  timestamp: '2022-01-03 11:29:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/frequency_table_of_tree_distance.test.cpp
documentation_of: polynomial/convolution_ll.hpp
layout: document
redirect_from:
- /library/polynomial/convolution_ll.hpp
- /library/polynomial/convolution_ll.hpp.html
title: polynomial/convolution_ll.hpp
---
