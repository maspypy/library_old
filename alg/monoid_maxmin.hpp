template <class X=long long, X INF=1LL<<60>
struct Monoid_MaxMin {
  using P = pair<X, X>;
  using value_type = P;
  static constexpr P op(const P x, const P y) noexcept { return {max(x.fi, y.fi), min(x.se, y.se)}; }
  static constexpr P unit = P({-INF, INF});
  static constexpr bool commute = true;
};
