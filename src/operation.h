#ifndef AUTODIFF_OPERATION_H_
#define AUTODIFF_OPERATION_H_

#include<concepts>

namespace autodiff {

template <typename T>
concept OPERATION = 
  requires(T t, double x){
    {t.call(x)} -> std::convertible_to<double>;
    {t.grad(x)} -> std::convertible_to<double>;
  };

class Operation {
public:
  virtual double call(double) const = 0
  virtual double grad(double) const = 0
  virtual bool is_binary() const = 0 // needed for runtime type checking
};

class UnaryOperation : public Operation {
public:
  bool is_binary()
};

class BinaryOperation : public Operation {
protected:
  double _val;

public:
  BinaryOperation(double val) : _val(val) {}
  bool is_binary()
};

class Addition : public BinaryOperation {
using BinaryOperation::BinaryOperation;
public:
  double call(double) const
  double grad(double) const
};

class Sin : public Operation {
public:
  double call(double) const
  double grad(double) const
};
}

#endif
