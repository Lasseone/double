#ifndef AUTODIFF_OPERATION_H_
#define AUTODIFF_OPERATION_H_

#include<variant>

namespace autodiff::operation {

class Operation {
public:
  virtual double call(double) const = 0;
  virtual double grad(double) const = 0;
  virtual bool is_binary() const = 0; // needed for runtime type checking
};

class Unary : public Operation {
public:
  virtual bool is_binary() const;
};

class Binary : public Operation {
protected:
  double _val;

public:
  Binary(double val) : _val(val) {};
  virtual bool is_binary() const;
};


class Sin : public Unary {
public:
  double call(double) const;
  double grad(double) const;
};

class Cos : public Unary {
public:
  double call(double) const;
  double grad(double) const;
};

class Addition : public Binary {
public:
  using Binary::Binary;
  
  double call(double) const;
  double grad(double) const;
};

class Subtraction : public Binary {
public:
  using Binary::Binary;

  double call(double) const;
  double grad(double) const;
};

// these must be updated with any new s
using UnaryVar = std::variant<Sin, Cos>;
using BinaryVar = std::variant<Addition, Subtraction>;

struct Call {
  // callable to call Operation::call with std::visit
  double x;
  Call(double x) : x(x) {};
  
  template <typename T>
  double operator()(const T& op){
    return op.call(x);
  }
};

struct Grad {
  // callable to call Operation::grad with std::visit
  double x;
  Grad(double x) : x(x) {};
  
  template <typename T>
  double operator()(const T& op){ 
    return op.grad(x);
  }
};

}
#endif
