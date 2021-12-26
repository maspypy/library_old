#pragma once

template <typename E>
struct Monoid {
  using F = function<E(E, E)>;
  F f;
  E unit;
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
  E unit;
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
Monoid<E> Monoid_reverse(Monoid<E> Mono) {
  auto rev_f = [=](E x, E y) -> E { return Mono.f(y, x); };
  return Monoid<E>({rev_f, Mono.unit, Mono.commute});
}

template <typename E>
Monoid<E> Monoid_add() {
  auto f = [](E x, E y) -> E { return x + y; };
  return Monoid<E>({f, 0, true});
}

template <typename E>
Monoid<E> Monoid_min(E INF) {
  auto f = [](E x, E y) -> E { return min(x, y); };
  return Monoid<E>({f, INF, true});
}

template <typename E>
Monoid<E> Monoid_max(E MINUS_INF) {
  auto f = [](E x, E y) -> E { return max(x, y); };
  return Monoid<E>({f, MINUS_INF, true});
}

template <typename E>
Monoid<pair<E, E>> Monoid_affine() {
  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E, E> {
    return {x.fi * y.fi, x.se * y.fi + y.se};
  };
  return Monoid<pair<E, E>>({f, mp(E(1), E(0)), false});
}
