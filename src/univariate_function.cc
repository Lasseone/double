#include "univariate_function.h"
#include "operation.h"

#include <memory>
#include <iostream>

namespace autodiff {

void UnivariateFunction::push(const operation::UnaryVar& x){
  _discriminants.push_back(false);
  _unaries.push_back(x);
}

void UnivariateFunction::push(const operation::BinaryVar& x){
  _discriminants.push_back(true);
  _binaries.push_back(x);
}

UnivariateFunction::iterator UnivariateFunction::begin(){
  return iterator(_discriminants.begin(), _unaries.begin(), _binaries.begin());
}

UnivariateFunction::iterator UnivariateFunction::end(){
  return iterator(_discriminants.end(), _unaries.end(), _binaries.end());
}

const UnivariateFunction::iterator& UnivariateFunction::iterator::operator++(){
  if(*_discriminant){
    _binary++;
  } else {
    _unary++;
  }
  _discriminant++;
  
  return *this;
}

const operation::Operation& UnivariateFunction::iterator::operator*(){
  if(*_discriminant){
    return reinterpret_cast<const operation::Binary&>(*_binary);
  } else {
    return reinterpret_cast<const operation::Unary&>(*_unary);
  }
}

bool UnivariateFunction::iterator::operator==(const iterator& other){
  return _discriminant == other._discriminant;
}

bool UnivariateFunction::iterator::operator!=(const iterator& other){
  return !(*this == other);
}

double UnivariateFunction::val(double x){
  for(auto& operation: *this){
    x = operation.call(x);
  }
  
  return x;
}

double UnivariateFunction::grad(double x){
  double dx = 1;
  for(auto& operation: *this){
    dx *= operation.grad(x);
    x = operation.call(x);
  }
  
  return dx;
}

}
