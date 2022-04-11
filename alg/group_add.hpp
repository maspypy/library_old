#pragma once
template <class X>
struct Group_Add {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return n * x; }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};
