template <class X=long long, X INF=1LL<<60>
struct Monoid_Max {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }
  static constexpr X unit = -INF;
  static constexpr bool commute = true;
};
