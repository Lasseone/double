#ifndef AUTODIFF_OPERATION_H_
#define AUTODIFF_OPERATION_H_

namespace autodiff {

class Operation {
public:
  virtual double call(double) const = 0;
  virtual double grad(double) const = 0;
  virtual bool is_binary() const = 0; // needed for runtime type checking
};

class UnaryOperation : public Operation {
public:
  virtual bool is_binary() const;
};

class BinaryOperation : public Operation {
protected:
  double _val;

public:
  BinaryOperation(double val) : _val(val) {}
  virtual bool is_binary() const;
};


class Sin : public UnaryOperation {
public:
  double call(double) const;
  double grad(double) const;
};

class Addition : public BinaryOperation {
public:
  using BinaryOperation::BinaryOperation;
  
  double call(double) const;
  double grad(double) const;
};
}

#endif
