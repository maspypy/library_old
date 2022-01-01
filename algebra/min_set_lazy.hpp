#include "algebra/minmonoid.hpp"
#include "algebra/setmonoid.hpp"

template <typename E, E INF, E none_val=-1>
struct Min_Set_Lazy {
  using MX = MinMonoid<E, INF>;
  using MA = SetMonoid<E, none_val>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return (a==none_val ? x : a) ;}
};
