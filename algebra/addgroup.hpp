template <class X, X ZERO = X(0)>
struct AddGroup {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X unit = ZERO;
  static constexpr bool commute = true;
};
