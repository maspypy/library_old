---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: persistent_ds/array.hpp
    title: persistent_ds/array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/persistent_unionfind.test.cpp
    title: test/library_checker/datastructure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"persistent_ds/array.hpp\"\n\r\ntemplate <typename T, int\
    \ shift = 4>\r\nstruct PersistentArray {\r\n  struct node;\r\n  using np = node*;\r\
    \n  struct node {\r\n    T data;\r\n    np ch[1 << shift] = {};\r\n  };\r\n\r\n\
    \  static constexpr int mask = (1 << shift) - 1;\r\n  np root = nullptr;\r\n \
    \ PersistentArray() {}\r\n  np get_root() { return root; }\r\n  T get(int idx,\
    \ np t) {\r\n    if (!t) return 0;\r\n    if (idx == 0) {\r\n      return t->data;\r\
    \n    } else {\r\n      return get(idx >> shift, t->ch[idx & mask]);\r\n    }\r\
    \n  }\r\n\r\n  void destructive_set(int idx, T val, np& t) {\r\n    // \u7834\u58CA\
    \u7684\u306A\u5024\u306E\u5909\u66F4\u3002\u4E3B\u306B\u521D\u671F\u5316\u306B\
    \u4F7F\u3046\u3002\r\n    if (!t) t = new node();\r\n    if (idx == 0)\r\n   \
    \   t->data = val;\r\n    else {\r\n      destructive_set(idx >> shift, val, t->ch[idx\
    \ & mask]);\r\n    }\r\n  }\r\n\r\n  np set(int idx, T val, const np& t) {\r\n\
    \    // set \u3057\u305F\u3042\u3068\u306E\u6C38\u7D9A\u914D\u5217\u306E root\
    \ node pointer \u3092\u8FD4\u3059\r\n    np res = new node();\r\n    if (t) {\r\
    \n      memcpy(res->ch, t->ch, sizeof(t->ch));\r\n      res->data = t->data;\r\
    \n    }\r\n    if (idx == 0) {\r\n      res->data = val;\r\n    } else {\r\n \
    \     res->ch[idx & mask] = set(idx >> shift, val, res->ch[idx & mask]);\r\n \
    \   }\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"persistent_ds/unionfind.hpp\"\
    \n\r\nstruct PersistentUnionFind {\r\n  using PA = PersistentArray<int>;\r\n \
    \ int n;\r\n  PA data; // root OR (-size)\r\n  using np = PA::np;\r\n\r\n  PersistentUnionFind(int\
    \ n) : n(n) {}\r\n  np init() {\r\n    np t = data.get_root();\r\n    FOR(i, n)\
    \ data.destructive_set(i, -1, t);\r\n    return t;\r\n  }\r\n\r\n  pair<bool,\
    \ np> merge(int x, int y, np t) {\r\n    x = root(x, t), y = root(y, t);\r\n \
    \   if (x == y) return {0, t};\r\n    if (data.get(x, t) > data.get(y, t)) swap(x,\
    \ y);\r\n    int new_sz = data.get(x, t) + data.get(y, t);\r\n    np set_x_sz\
    \ = data.set(x, new_sz, t);\r\n    np set_y_par = data.set(y, x, set_x_sz);\r\n\
    \    return {1, set_y_par};\r\n  }\r\n\r\n  int root(int x, np t) {\r\n    int\
    \ par_or_sz = data.get(x, t);\r\n    if (par_or_sz < 0) return x;\r\n    return\
    \ root(par_or_sz, t);\r\n  }\r\n\r\n  bool same(int x, int y, np t) { return root(x,\
    \ t) == root(y, t); }\r\n  int size(int x, np t) { return -data.get(root(x, t),\
    \ t); }\r\n};\n"
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
  dependsOn:
  - persistent_ds/array.hpp
  isVerificationFile: false
  path: persistent_ds/unionfind.hpp
  requiredBy: []
  timestamp: '2021-12-28 19:36:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/persistent_unionfind.test.cpp
documentation_of: persistent_ds/unionfind.hpp
layout: document
redirect_from:
- /library/persistent_ds/unionfind.hpp
- /library/persistent_ds/unionfind.hpp.html
title: persistent_ds/unionfind.hpp
---
