template <typename T=long long>
struct Monoid_Xor {
  using value_type = T;
  using X = value_type;
  static X op(X x, X y) { return x ^ y; }
  static constexpr X unit = X(0);
  static constexpr bool commute = true;
};
