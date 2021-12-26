#pragma once

template <typename E>
struct Monoid {
  using F = function<E(E, E)>;
  F f;
  E E_unit;
  bool commute;
};

template <typename E, typename OP, bool commute, bool OP_commute>
struct Monoid_OP {
  using F = function<E(E, E)>;
  using G = function<E(E, OP)>;
  using H = function<OP(OP, OP)>;
  F f;
  G g;
  H h;
  E E_unit;
  OP OP_unit;
};

template <typename E>
struct Group {
  using F = function<E(E, E)>;
  using G = function<E(E)>;
  F f;
  E E_unit;
  G inv;
  bool commute;
};

template <typename E>
Monoid<E> Monoid_min(E unit) {
  auto f = [](E x, E y) -> E { return min(x, y); };
  return Monoid<E>({f, unit, true});
}