#pragma once

template <typename E>
struct Monoid {
  using F = function<E(E, E)>;
  using G = function<E(E)>;
  F f;
  E unit;
  bool commute;
  bool has_inverse;
  G inverse;
};

template <typename E, typename OP, bool commute, bool OP_commute>
struct Monoid_OP {
  using F = function<E(E, E)>;
  using G = function<E(E, OP)>;
  using H = function<OP(OP, OP)>;
  F f;
  G g;
  H h;
  E unit;
  OP OP_unit;
};

template <typename E>
Monoid<E> Monoid_reverse(Monoid<E> Mono) {
  auto rev_f = [=](E x, E y) -> E { return Mono.f(y, x); };
  return Monoid<E>(
    {rev_f, Mono.unit, Mono.commute, Mono.has_inverse, Mono.inverse});
}

template <typename E>
Monoid<E> Monoid_add() {
  auto f = [](E x, E y) -> E { return x + y; };
  auto g = [](E x) -> E { return -x; };
  return Monoid<E>({f, 0, true, true, g});
}

template <typename E>
Monoid<E> Monoid_min(E INF) {
  auto f = [](E x, E y) -> E { return min(x, y); };
  return Monoid<E>({f, INF, true, false});
}

template <typename E>
Monoid<E> Monoid_max(E MINUS_INF) {
  auto f = [](E x, E y) -> E { return max(x, y); };
  return Monoid<E>({f, MINUS_INF, true, false});
}

template <typename E>
Monoid<pair<E, E>> Monoid_affine(bool has_inverse = false) {
  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E, E> {
    return {x.fi * y.fi, x.se * y.fi + y.se};
  };
  auto inv = [&](pair<E, E> x) -> pair<E, E> {
    // y = ax + b iff x = (1/a) y - (b/a)
    auto [a, b] = x;
    a = E(1) / a;
    return {a, a * (-b)};
  };
  return Monoid<pair<E, E>>({f, mp(E(1), E(0)), false, has_inverse, inv});
}
