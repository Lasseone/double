#include "univariate_container.h"
#include "operation/operation.h"

namespace autodiff {
namespace univariate {

void FastContainer::push(const operation::UnaryVar& x){
  _discriminants.push_back(false);
  _unaries.push_back(x);
}

void FastContainer::push(const operation::BinaryVar& x){
  _discriminants.push_back(true);
  _binaries.push_back(x);
}

FastContainer::iterator FastContainer::begin() {
  return iterator(_discriminants.begin(), _unaries.begin(), _binaries.begin());
}

FastContainer::iterator FastContainer::end(){
  return iterator(_discriminants.end(), _unaries.end(), _binaries.end());
}

const FastContainer::iterator& 
FastContainer::iterator::operator++(){
  if(*_discriminant){
    _binary++;
  } else {
    _unary++;
  }
  _discriminant++;
  
  return *this;
}

const operation::Operation& 
FastContainer::iterator::operator*() const {
  if(*_discriminant){
    return reinterpret_cast<const operation::Binary&>(*_binary);
  } else {
    return reinterpret_cast<const operation::Unary&>(*_unary);
  }
}

bool FastContainer::iterator::operator==(const iterator& other) const {
  return _discriminant == other._discriminant;
}

bool FastContainer::iterator::operator!=(const iterator& other) const {
  return !(*this == other);
}

}}
