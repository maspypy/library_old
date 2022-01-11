#include "alg/group_add.hpp"
#include "alg/group_mul.hpp"

template <typename E>
struct Lazy_Add_Mul {
  using MX = Group_Add<E>;
  using MA = Group_Mul<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return x * a; }
};
