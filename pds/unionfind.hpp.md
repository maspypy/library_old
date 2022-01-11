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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: persistent_ds/array.hpp:\
    \ line -1: no such header\n"
  code: "#include \"persistent_ds/array.hpp\"\r\n\r\nstruct PersistentUnionFind {\r\
    \n  using PA = PersistentArray<int>;\r\n  int n;\r\n  PA data; // root OR (-size)\r\
    \n  using np = PA::np;\r\n\r\n  PersistentUnionFind(int n) : n(n) {}\r\n  np init()\
    \ {\r\n    np t = data.get_root();\r\n    FOR(i, n) data.destructive_set(i, -1,\
    \ t);\r\n    return t;\r\n  }\r\n\r\n  pair<bool, np> merge(int x, int y, np t)\
    \ {\r\n    x = root(x, t), y = root(y, t);\r\n    if (x == y) return {0, t};\r\
    \n    if (data.get(x, t) > data.get(y, t)) swap(x, y);\r\n    int new_sz = data.get(x,\
    \ t) + data.get(y, t);\r\n    np set_x_sz = data.set(x, new_sz, t);\r\n    np\
    \ set_y_par = data.set(y, x, set_x_sz);\r\n    return {1, set_y_par};\r\n  }\r\
    \n\r\n  int root(int x, np t) {\r\n    int par_or_sz = data.get(x, t);\r\n   \
    \ if (par_or_sz < 0) return x;\r\n    return root(par_or_sz, t);\r\n  }\r\n\r\n\
    \  bool same(int x, int y, np t) { return root(x, t) == root(y, t); }\r\n  int\
    \ size(int x, np t) { return -data.get(root(x, t), t); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: pds/unionfind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pds/unionfind.hpp
layout: document
redirect_from:
- /library/pds/unionfind.hpp
- /library/pds/unionfind.hpp.html
title: pds/unionfind.hpp
---
