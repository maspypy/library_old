#include "algebra/cntsum.hpp"
#include "algebra/affinegroup.hpp"

template <typename E>
struct CntSum_Affine_Lazy {
  using X_structure = CntSum<E>;
  using A_structure = AffineGroup<E>;
  using X = typename X_structure::value_type;
  using A = typename A_structure::value_type;
  static constexpr X act(const X &x, const A &a) {
    return {x.fi, x.fi * a.se + x.se * a.fi};
  }
};