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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#include \"algebra/monoid.hpp\"\r\n#include \"ds/fenwick.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n\r\ntemplate <typename Graph, typename E, bool edge = false>\r\
    \nstruct TreeAbelGroup {\r\n  HLD<Graph> &hld;\r\n  int N;\r\n  FenwickTree<E>\
    \ bit_path, bit_subtree;\r\n  bool path_sum, subtree_sum;\r\n\r\n  TreeAbelGroup(HLD<Graph>\
    \ &hld, bool path_sum, bool subtree_sum)\r\n      : hld(hld), N(hld.N), path_sum(path_sum),\
    \ subtree_sum(subtree_sum) {\r\n    if (path_sum) bit_path.init(N + N);\r\n  \
    \  if (subtree_sum) bit_subtree.init(N);\r\n  }\r\n\r\n  void init_path(vc<E>\
    \ &dat) {\r\n    vc<E> fenwick_raw(N + N);\r\n    if (!edge) {\r\n      FOR(v,\
    \ N) {\r\n        fenwick_raw[hld.ELID[v]] = dat[v];\r\n        fenwick_raw[hld.ERID[v]]\
    \ = -dat[v];\r\n      }\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int\
    \ v = hld.e_to_v[i];\r\n        fenwick_raw[hld.ELID[v]] = dat[i];\r\n       \
    \ fenwick_raw[hld.ERID[v]] = -dat[i];\r\n      }\r\n    }\r\n    bit_path.build(fenwick_raw);\r\
    \n  }\r\n\r\n  void init_subtree(vc<E> &dat) {\r\n    vc<E> fenwick_raw(N);\r\n\
    \    if (!edge) {\r\n      FOR(v, N) { fenwick_raw[hld.LID[v]] = dat[v]; }\r\n\
    \    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n \
    \       fenwick_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    bit_subtree.build(fenwick_raw);\r\
    \n  }\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n\
    \    if (path_sum) init_path(dat);\r\n    if (subtree_sum) init_subtree(dat);\r\
    \n  }\r\n\r\n  void add(int i, E x) {\r\n    int v = (edge ? hld.e_to_v[i] : i);\r\
    \n    if (path_sum) {\r\n      bit_path.add(hld.ELID[v], x);\r\n      bit_path.add(hld.ERID[v],\
    \ -x);\r\n    }\r\n    if (subtree_sum) { bit_subtree.add(hld.LID[v], x); }\r\n\
    \  }\r\n\r\n  E sum_path(int frm, int to) {\r\n    int lca = hld.LCA(frm, to);\r\
    \n    E x1 = bit_path.sum(hld.ELID[lca] + 1, hld.ELID[frm] + 1);\r\n    E x2 =\
    \ bit_path.sum(hld.ELID[lca] + edge, hld.ELID[to] + 1);\r\n    return x1 + x2;\r\
    \n  }\r\n\r\n  E sum_subtree(int v) {\r\n    return bit_subtree.sum(hld.LID[v]\
    \ + edge, hld.RID[v]);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"bit_path\");\r\n    bit_path.debug();\r\n  \
    \  print(\"bit_subtree\");\r\n    bit_subtree.debug();\r\n  }\r\n\r\n  void doc()\
    \ {\r\n    print(\"EulerTour + FenwickTree\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(logN) \u6642\u9593\u3002\");\r\n    print(\"\u30A2\u30FC\u30D9\u30EB\u7FA4\
    \u3067\u3042\u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3092 O(logN) \u6642\u9593\u306B\u3059\u308B\u3002\");\r\n    print(\"\
    operator +- \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\u306A\
    \u3069\u304C\u3042\u308B\");\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/treeabel.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/treeabel.hpp
layout: document
redirect_from:
- /library/tree/treeabel.hpp
- /library/tree/treeabel.hpp.html
title: tree/treeabel.hpp
---
