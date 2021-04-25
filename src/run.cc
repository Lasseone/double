#include <iostream>

#include "univariate/univariate_function.h"
#include "operation/operation.h"

int main(){
  int x = 0;
  
  autodiff::univariate::Function operations;

  operations.push(autodiff::operation::Addition(3)); 
  operations.push(autodiff::operation::Sin()); 

  std::cout << "val at x=" << x << " is " << operations.call(x) << "\n";
  std::cout << "grad at x=" << x << " is " << operations.grad(x) << "\n";

  return 0;
}
