#ifndef AUTODIFF_OPERATION_H_
#define AUTODIFF_OPERATION_H_

#include<concepts>

namespace autodiff {

template <typename T>
concept OPERATION = 
  requires(T t, double x){
    {t->call(x)} -> std::convertible_to<double>;
    {t->grad(x)} -> std::convertible_to<double>;
  };

class Operation {
public:
  virtual double call(double) const = 0;
  virtual double grad(double) const = 0;
};

class Addition : public Operation {
private:
  double _val;

public:
  Addition(double val) : _val(val) {}
  double call(double) const;
  double grad(double) const;
};

class Sin : public Operation {
public:
  double call(double) const;
  double grad(double) const;
};
}

#endif
