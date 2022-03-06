template <typename Group>
struct WeightedUnionFind {
  using E = typename Group::value_type;
  int N;
  vc<E> vals;
  vc<int> par;
  vc<int> size;

  WeightedUnionFind(int N) : N(N), vals(N), size(N, 1) {
    par.resize(N);
    iota(all(par), 0);
  }

  pair<int, E> get(int v) {
    E res = Group::unit;
    while (v != par[v]) {
      res = Group::op(vals[v], res);
      res = Group::op(vals[par[v]], res);
      vals[v] = Group::op(vals[par[v]], vals[v]);
      v = par[v] = par[par[v]];
    }
    return {v, res};
  }

  bool merge(int frm, int to, E x) {
    auto [v1, x1] = get(frm);
    auto [v2, x2] = get(to);
    if (v1 == v2) return false;
    if(size[v1] < size[v2]) {
      swap(v1, v2);
      swap(x1, x2);
      x = Group::inverse(x);
    }
    x = Group::op(x1, x);
    x = Group::op(x, Group::inverse(x2));
    vals[v2] = x;
    par[v2] = v1;
    size[v1] += size[v2];
    return true;
  }

  void debug() {
    print("par", par);
    print("vals", vals);
    print("size", size);
  }
};