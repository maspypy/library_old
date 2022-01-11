#include "pds/array.hpp"

struct PersistentUnionFind {
  using PA = PersistentArray<int>;
  int n;
  PA data; // root OR (-size)
  using np = PA::np;

  PersistentUnionFind(int n) : n(n) {}
  np init() {
    np t = data.get_root();
    FOR(i, n) data.destructive_set(i, -1, t);
    return t;
  }

  pair<bool, np> merge(int x, int y, np t) {
    x = root(x, t), y = root(y, t);
    if (x == y) return {0, t};
    if (data.get(x, t) > data.get(y, t)) swap(x, y);
    int new_sz = data.get(x, t) + data.get(y, t);
    np set_x_sz = data.set(x, new_sz, t);
    np set_y_par = data.set(y, x, set_x_sz);
    return {1, set_y_par};
  }

  int root(int x, np t) {
    int par_or_sz = data.get(x, t);
    if (par_or_sz < 0) return x;
    return root(par_or_sz, t);
  }

  bool same(int x, int y, np t) { return root(x, t) == root(y, t); }
  int size(int x, np t) { return -data.get(root(x, t), t); }
};