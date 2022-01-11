#include "alg/monoid_min.hpp"
#include "alg/monoid_set.hpp"

template <typename E, E INF, E none_val>
struct Lazy_Max_Set {
  using MX = Monoid_Max<E, INF>;
  using MA = Monoid_Set<E, none_val>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return (a==none_val ? x : a) ;}
};
