#include "univariate_function.h"
#include "operation/operation.h"

namespace autodiff {
namespace univariate {

template <typename T>
void Function<T>::push(const operation::UnaryVar& operation){
  _container.push(operation);
}

template <typename T>
void Function<T>::push(const operation::BinaryVar& operation){
  _container.push(operation);
}

template <typename T>
double Function<T>::call(double x) {
  for(auto& operation: _container){
    x = operation.call(x);
  }
  
  return x;
}

template <typename T>
double Function<T>::grad(double x) {
  double dx = 1;
  for(auto& operation: _container){
    dx *= operation.grad(x);
    x = operation.call(x);
  }
  
  return dx;
}

template class Function<FastContainer>;

}}
