#include <iostream>

#include "operation.h"
#include "univariate_function.h"

template <typename T>
double get_val(T& function, double x){
  for(auto& operation: function){
    x = operation.call(x);
  }

  return x;
}

template <typename T>
double get_grad(T& function, double x){
  double dx = 1;
  for(auto& operation: function){
    x *= operation.grad(x);
    x = operation.call(x);
  }

  return dx;
}

int main(){
  int x = 0;
  
  autodiff::UnivariateFunction operations;
  
  operations.push(new autodiff::Addition(3));
  operations.push(new autodiff::Sin());
  
  std::cout << "val at x=" << x << " is " << get_val(operations, x) << "\n";
  std::cout << "grad at x=" << x << " is " << get_grad(operations, x) << "\n";

  return 0;
}
