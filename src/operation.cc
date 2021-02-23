#include "operation.h"

#include<cmath>

using namespace autodiff;

bool UnaryOperation::is_binary() const {
  return false;
}

bool BinaryOperation::is_binary() const {
  return true;
}

double Sin::call(double x) const {
  return std::sin(x);
}

double Sin::grad(double x) const {
  return std::cos(x);
}

double Addition::call(double x) const {
  return x + _val;
}

double Addition::grad(double x) const {
  return 1;
}
