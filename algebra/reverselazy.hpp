#include "algebra/reversemonoid.hpp"

template <typename Lazy>
struct ReverseLazy {
  using MX = typename Lazy::X_structure;
  using MA = typename Lazy::A_structure;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return Lazy::act(x, a); }
};
