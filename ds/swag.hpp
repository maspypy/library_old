#include "algebra/monoid.hpp"

template <typename E>
struct SWAG {
  using F = function<E(E, E)>;
  F f;
  E e;
  vc<E> dat;
  vc<E> cum_l;
  E cum_r;
  SWAG(Monoid<E> M) : f(M.f), e(M.unit), cum_l({M.unit}), cum_r(M.unit) {}

  void push(E x) {
    cum_r = f(cum_r, x);
    dat.eb(x);
  }

  void pop() {
    cum_l.pop_back();
    if (len(cum_l) == 0) {
      cum_l = {e};
      cum_r = e;
      while (len(dat) > 1) {
        cum_l.eb(f(dat.back(), cum_l.back()));
        dat.pop_back();
      }
      dat.pop_back();
    }
  }

  E prod() { return f(cum_l.back(), cum_r); }

  void debug() {
    print("dat", dat);
    print("cum_l", cum_l);
    print("cum_r", cum_r);
  }
};
