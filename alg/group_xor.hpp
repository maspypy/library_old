template <typename T=long long>
struct Group_Xor {
  using value_type = T;
  using X = value_type;
  static X op(X x, X y) { return x ^ y; }
  static constexpr X inverse(const X &x) noexcept { return x; }
  static constexpr X power(const X &x, ll n) noexcept { return (n & 1 ? x : 0);}
  static constexpr X unit = X(0);
  static constexpr bool commute = true;
};
