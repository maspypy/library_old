
struct Monoid_XorBasis {
  using value_type = vc<int>;
  using X = value_type;
  static X op(X x, X y) {
    for (auto&& v: y) {
      for (auto&& w: x) chmin(v, v ^ w);
      if (v) x.eb(v);
    }
    return x;
  }
  static const X unit;
  static constexpr bool commute = true;
};
const vc<int> Monoid_XorBasis::unit;