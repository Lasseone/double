#include "operation.h"

#include <cmath>

using namespace autodiff::operation;

bool Unary::is_binary() const {
  return false;
}

bool Binary::is_binary() const {
  return true;
}

double Sin::call(double x) const {
  return std::sin(x);
}

double Sin::grad(double x) const {
  return std::cos(x);
}

double Cos::call(double x) const {
  return std::cos(x);
}

double Cos::grad(double x) const {
  return -std::sin(x);
}

double Addition::call(double x) const {
  return x + _val;
}

double Addition::grad(double x) const {
  return 1;
}

double Subtraction::call(double x) const {
  return x - _val;
}

double Subtraction::grad(double x) const {
  return 1;
}
