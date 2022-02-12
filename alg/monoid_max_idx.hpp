template <typename T, T INF = 1LL << 60>
struct Monoid_Max_Idx {
  using value_type = pair<T, ll>;
  using X = value_type;
  static X op(X x, X y) { return max(x, y); }
  static constexpr X unit = X(-INF, -1);
  static constexpr bool commute = true;
};