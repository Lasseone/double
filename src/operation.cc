#include "operation.h"

#include<cmath>

double autodiff::Sin::call(double x) const {
  return std::sin(x);
}

double autodiff::Sin::grad(double x) const {
  return std::cos(x);
}

double autodiff::Addition::call(double x) const {
  return x + _val;
}

double autodiff::Addition::grad(double x) const {
  return 1;
}
