#include <iostream>

#include "operation.h"
#include "univariate_function.h"

int main(){
  int x = 0;
  
  autodiff::UnivariateFunction operations;

  operations.push(autodiff::operation::Addition(3)); 
  operations.push(autodiff::operation::Sin()); 

  std::cout << "val at x=" << x << " is " << operations.val(x) << "\n";
  std::cout << "grad at x=" << x << " is " << operations.grad(x) << "\n";

  return 0;
}
