template <typename E>
struct Monoid_Or {
  using value_type = ll;
  using X = value_type;
  static X op(X x, X y) { return x | y; }
  static constexpr X unit = X(0);
  static constexpr bool commute = true;
};
