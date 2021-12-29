template <typename K>
struct AffineGroup {
  using F = pair<K, K>;
  using value_type = F;
  static constexpr F op(const F &x, const F &y) noexcept {
    return F({x.fi * y.fi, x.se * y.fi + y.se});
  }
  static constexpr F inverse(const F &x) {
    auto [a, b] = x;
    a = K(1) / a;
    return {a, a * (-b)};
  }
  static constexpr K eval(const F &f, K x) noexcept { return f.fi * x + f.se; }
  static constexpr F unit = {K(1), K(0)};
  static constexpr bool commute = false;
};