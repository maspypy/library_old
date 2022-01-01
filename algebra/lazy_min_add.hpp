#include "algebra/group_add.hpp"
#include "algebra/monoid_min.hpp"

template <typename E, E INF>
struct Min_Add_Lazy {
  using MX = MinMonoid<E, INF>;
  using MA = AddGroup<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { 
    return x + a;
  }
};