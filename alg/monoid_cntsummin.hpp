struct Monoid_CntSumMin {
  static constexpr ll INF = 1LL << 60;
  using value_type = tuple<ll, ll, ll>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xc, xs, xm] = x;
    auto [yc, ys, ym] = y;
    return {xc + yc, xs + ys, min(xm, ym)};
  }
  static constexpr X unit = X({0, 0, INF});
  static constexpr bool commute = true;
};
