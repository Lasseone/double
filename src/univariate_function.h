#ifndef AUTODIFF_UNIVARIATE_FUNCTION_H_
#define AUTODIFF_UNIVARIATE_FUNCTION_H_

#include "operation.h"

#include <vector>
#include <ranges>

namespace autodiff {

template <typename T>
concept UNIVARIATE_FUNCTION = 
  std::ranges::forward_range<T> &&
  OPERATION<std::ranges::range_value_t<T>>;

using BloatedUnivariateFunction = std::vector<Operation*>;

}

#endif
