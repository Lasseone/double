#include "operation.h"

#include <cmath>

using namespace autodiff::operation;

inline double Sin::call(double x) const {
  return std::sin(x);
}

inline double Sin::grad(double x) const {
  return std::cos(x);
}

inline double Cos::call(double x) const {
  return std::cos(x);
}

inline double Cos::grad(double x) const {
  return -std::sin(x);
}

inline double Addition::call(double x) const {
  return x + _val;
}

inline double Addition::grad(double x) const {
  return 1;
}

inline double Subtraction::call(double x) const {
  return x - _val;
}

inline double Subtraction::grad(double x) const {
  return 1;
}
