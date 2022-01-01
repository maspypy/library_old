template<typename E, E none_val = E(-1)>
struct SetMonoid {
  using value_type = E;
  using X = value_type;
  static X op(X x, X y) {
    return (y==none_val ? x : y);
  }
  static constexpr X unit = none_val;
  bool commute = false;
};