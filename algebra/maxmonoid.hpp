template <class X, X INF>
struct MaxMonoid {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }
  static constexpr X unit = -INF;
  static constexpr bool commute = true;
};
