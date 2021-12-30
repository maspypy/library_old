#include "algebra/maxmonoid.hpp"

template <typename E, E INF = 1 << 30>
struct Max_Max_Lazy {
  using MX = MaxMonoid<E, INF>;
  using MA = MaxMonoid<E, INF>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return max(x, a); }
};
