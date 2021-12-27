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
  bundledCode: "#line 2 \"matrix/matrix.hpp\"\n\r\ntemplate <typename T>\r\nstruct\
    \ Matrix {\r\n  int H, W;\r\n  vector<vector<T>> data;\r\n\r\n  Matrix(int H,\
    \ int W) : H(H), W(W), data(H, vector<T>(W, 0)){};\r\n  vector<T>& operator[](int\
    \ i) { return data[i]; }\r\n  Matrix<T> operator*(Matrix<T>& other) {\r\n    assert(W\
    \ == other.H);\r\n    int a = H, b = W, c = other.W;\r\n    Matrix<T> C(a, c);\r\
    \n    FOR(i, a) {\r\n      FOR(j, b) {\r\n        FOR(k, c) { C[i][k] += data[i][j]\
    \ * other[j][k]; }\r\n      }\r\n    }\r\n    return C;\r\n  }\r\n  void eye()\
    \ { FOR(i, H) FOR(j, W) data[i][j] = (i == j ? 1 : 0); }\r\n  Matrix<T> pow(ll\
    \ K) {\r\n    Matrix<T> P(H, H);\r\n    P.eye();\r\n    Matrix<T> Q(H, H);\r\n\
    \    FOR(i, H) FOR(j, H) Q[i][j] = data[i][j];\r\n    while (K) {\r\n      if\
    \ (K & 1) P = P * Q;\r\n      Q = Q * Q;\r\n      K >>= 1;\r\n    }\r\n    return\
    \ P;\r\n  }\r\n};\r\n\r\n\r\ntemplate <class T>\r\nbool is_zero(const T& a) {\r\
    \n  return a == T(0);\r\n}\r\n\r\ntemplate <class T>\r\nint row_reduce(std::vector<std::vector<T>>&\
    \ a, int limit = -1) {\r\n  int h = std::size(a);\r\n  if (h == 0) return 0;\r\
    \n  int w = std::size(a[0]), rank = 0;\r\n  if (limit < 0 or w < limit) limit\
    \ = w;\r\n  for (int p = 0; p < limit; ++p) {\r\n    for (int i = rank + 1; i\
    \ < h; ++i)\r\n      if constexpr (std::is_floating_point_v<T>) {\r\n        if\
    \ (std::abs(a[rank][p]) < std::abs(a[i][p])) std::swap(a[rank], a[i]);\r\n   \
    \   } else if (not is_zero(a[i][p])) {\r\n        std::swap(a[rank], a[i]);\r\n\
    \        break;\r\n      }\r\n    if (is_zero(a[rank][p])) continue;\r\n    T\
    \ inv = T(1) / a[rank][p];\r\n    for (auto&& e : a[rank]) e *= inv;\r\n    for\
    \ (int i = 0; i < h; ++i)\r\n      if (i != rank and not is_zero(a[i][p])) {\r\
    \n        for (int j = p + 1; j < w; ++j) a[i][j] -= a[rank][j] * a[i][p];\r\n\
    \        a[i][p] = 0;\r\n      }\r\n    if (++rank == h) break;\r\n  }\r\n  return\
    \ rank;\r\n}\r\n\r\ntemplate <class T>\r\nstd::pair<std::vector<T>, std::vector<std::vector<T>>>\
    \ solve_linear(\r\n  std::vector<std::vector<T>> a, const std::vector<T>& b) {\r\
    \n  assert(std::size(a) == std::size(b));\r\n  assert(not std::empty(a));\r\n\
    \  int h = std::size(a), w = std::size(a[0]);\r\n  for (int i = 0; i < h; ++i)\
    \ a[i].push_back(b[i]);\r\n  int rank = row_reduce(a, w);\r\n  for (int i = rank;\
    \ i < h; ++i)\r\n    if (not is_zero(a[i][w])) return {};\r\n  std::vector<T>\
    \ x(w);\r\n  std::vector pivot(w, -1);\r\n  for (int i = 0, j = 0; i < rank; ++i)\
    \ {\r\n    while (is_zero(a[i][j])) ++j;\r\n    x[j] = a[i][w];\r\n    pivot[j]\
    \ = i;\r\n  }\r\n  std::vector<std::vector<T>> basis;\r\n  for (int p = 0; p <\
    \ w; ++p)\r\n    if (pivot[p] == -1) {\r\n      basis.emplace_back(w);\r\n   \
    \   basis.back()[p] = -1;\r\n      for (int j = 0; j < p; ++j)\r\n        if (pivot[j]\
    \ != -1) basis.back()[j] = a[pivot[j]][p];\r\n    }\r\n  return {x, basis};\r\n\
    }\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nstruct Matrix {\r\n  int H,\
    \ W;\r\n  vector<vector<T>> data;\r\n\r\n  Matrix(int H, int W) : H(H), W(W),\
    \ data(H, vector<T>(W, 0)){};\r\n  vector<T>& operator[](int i) { return data[i];\
    \ }\r\n  Matrix<T> operator*(Matrix<T>& other) {\r\n    assert(W == other.H);\r\
    \n    int a = H, b = W, c = other.W;\r\n    Matrix<T> C(a, c);\r\n    FOR(i, a)\
    \ {\r\n      FOR(j, b) {\r\n        FOR(k, c) { C[i][k] += data[i][j] * other[j][k];\
    \ }\r\n      }\r\n    }\r\n    return C;\r\n  }\r\n  void eye() { FOR(i, H) FOR(j,\
    \ W) data[i][j] = (i == j ? 1 : 0); }\r\n  Matrix<T> pow(ll K) {\r\n    Matrix<T>\
    \ P(H, H);\r\n    P.eye();\r\n    Matrix<T> Q(H, H);\r\n    FOR(i, H) FOR(j, H)\
    \ Q[i][j] = data[i][j];\r\n    while (K) {\r\n      if (K & 1) P = P * Q;\r\n\
    \      Q = Q * Q;\r\n      K >>= 1;\r\n    }\r\n    return P;\r\n  }\r\n};\r\n\
    \r\n\r\ntemplate <class T>\r\nbool is_zero(const T& a) {\r\n  return a == T(0);\r\
    \n}\r\n\r\ntemplate <class T>\r\nint row_reduce(std::vector<std::vector<T>>& a,\
    \ int limit = -1) {\r\n  int h = std::size(a);\r\n  if (h == 0) return 0;\r\n\
    \  int w = std::size(a[0]), rank = 0;\r\n  if (limit < 0 or w < limit) limit =\
    \ w;\r\n  for (int p = 0; p < limit; ++p) {\r\n    for (int i = rank + 1; i <\
    \ h; ++i)\r\n      if constexpr (std::is_floating_point_v<T>) {\r\n        if\
    \ (std::abs(a[rank][p]) < std::abs(a[i][p])) std::swap(a[rank], a[i]);\r\n   \
    \   } else if (not is_zero(a[i][p])) {\r\n        std::swap(a[rank], a[i]);\r\n\
    \        break;\r\n      }\r\n    if (is_zero(a[rank][p])) continue;\r\n    T\
    \ inv = T(1) / a[rank][p];\r\n    for (auto&& e : a[rank]) e *= inv;\r\n    for\
    \ (int i = 0; i < h; ++i)\r\n      if (i != rank and not is_zero(a[i][p])) {\r\
    \n        for (int j = p + 1; j < w; ++j) a[i][j] -= a[rank][j] * a[i][p];\r\n\
    \        a[i][p] = 0;\r\n      }\r\n    if (++rank == h) break;\r\n  }\r\n  return\
    \ rank;\r\n}\r\n\r\ntemplate <class T>\r\nstd::pair<std::vector<T>, std::vector<std::vector<T>>>\
    \ solve_linear(\r\n  std::vector<std::vector<T>> a, const std::vector<T>& b) {\r\
    \n  assert(std::size(a) == std::size(b));\r\n  assert(not std::empty(a));\r\n\
    \  int h = std::size(a), w = std::size(a[0]);\r\n  for (int i = 0; i < h; ++i)\
    \ a[i].push_back(b[i]);\r\n  int rank = row_reduce(a, w);\r\n  for (int i = rank;\
    \ i < h; ++i)\r\n    if (not is_zero(a[i][w])) return {};\r\n  std::vector<T>\
    \ x(w);\r\n  std::vector pivot(w, -1);\r\n  for (int i = 0, j = 0; i < rank; ++i)\
    \ {\r\n    while (is_zero(a[i][j])) ++j;\r\n    x[j] = a[i][w];\r\n    pivot[j]\
    \ = i;\r\n  }\r\n  std::vector<std::vector<T>> basis;\r\n  for (int p = 0; p <\
    \ w; ++p)\r\n    if (pivot[p] == -1) {\r\n      basis.emplace_back(w);\r\n   \
    \   basis.back()[p] = -1;\r\n      for (int j = 0; j < p; ++j)\r\n        if (pivot[j]\
    \ != -1) basis.back()[j] = a[pivot[j]][p];\r\n    }\r\n  return {x, basis};\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy: []
  timestamp: '2021-12-28 03:01:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: matrix/matrix.hpp
---
