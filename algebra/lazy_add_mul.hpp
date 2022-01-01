#include "algebra/group_add.hpp"
#include "algebra/group_mul.hpp"

template <typename E>
struct Add_Mul_Lazy {
  using MX = AddGroup<E>;
  using MA = MulGroup<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return x * a; }
};
