template <class X, X ONE = X(1)>
struct MulGroup {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x * y; }
  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }
  static constexpr X unit = ONE;
  static constexpr bool commute = true;
};
