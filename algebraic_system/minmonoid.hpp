template <class X, X INF>
struct MinMonoid {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }
  static constexpr X unit = INF;
};
