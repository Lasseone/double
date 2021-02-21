#include <iostream>

#include "operation.h"
#include "univariate_function.h"

double get_val(const autodiff::UNIVARIATE_FUNCTION auto& function, double x){
  for(const auto& operation: function){
    x = operation->call(x);
  }

  return x;
}

double get_grad(const autodiff::UNIVARIATE_FUNCTION auto& function, double x){
  double dx = 1;
  for(const auto& operation: function){
    dx *= operation->grad(x);
    x = operation->call(x);
  }

  return dx;
}

int main(){
  int x = 0;
  
  autodiff::BloatedUnivariateFunction operations;
  
  operations.push_back(new autodiff::Addition(3));
  operations.push_back(new autodiff::Sin());
  
  std::cout << "val at x=" << x << " is " << get_val(operations, x) << "\n";
  std::cout << "grad at x=" << x << " is " << get_grad(operations, x) << "\n";

  return 0;
}
