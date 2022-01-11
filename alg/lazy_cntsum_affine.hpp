#include "alg/group_cntsum.hpp"
#include "alg/group_affine.hpp"

template <typename E>
struct Lazy_CntSum_Affine {
  using X_structure = Group_CntSum<E>;
  using A_structure = Group_Affine<E>;
  using X = typename X_structure::value_type;
  using A = typename A_structure::value_type;
  static constexpr X act(const X &x, const A &a) {
    return {x.fi, x.fi * a.se + x.se * a.fi};
  }
};