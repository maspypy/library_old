template <class X=long long, X INF=1LL<<60>
struct Monoid_Min {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }
  static constexpr X unit = INF;
  static constexpr bool commute = true;
};
