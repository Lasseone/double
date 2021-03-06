#ifndef AUTODIFF_UNIVARIATE_FUNCTION_H_
#define AUTODIFF_UNIVARIATE_FUNCTION_H_

#include "operation/operation.h"
#include "fast_container.h"

namespace autodiff {
namespace univariate {

template <typename Container = FastContainer>
class Function {
private:
  Container _container;

public:
  void push(const operation::UnaryVar&);
  void push(const operation::BinaryVar&);
  
  double call(double) const;
  double grad(double) const;
};

}}

#endif
