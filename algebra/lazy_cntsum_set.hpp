#include "algebra/group_cntsum.hpp"
#include "algebra/monoid_set.hpp"

template <typename E>
struct Lazy_CntSum_Affine {
  using X_structure = Group_CntSum<E>;
  using A_structure = Monoid_Set<E>;
  using X = typename X_structure::value_type;
  using A = typename A_structure::value_type;
  static constexpr X act(const X &x, const A &a) {
    if(a == A_structure::unit) return x;
    return {x.fi, x.fi * a};
  }
};