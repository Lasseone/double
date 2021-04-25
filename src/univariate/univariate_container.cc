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

FastContainer::const_iterator FastContainer::begin() const {
  return const_iterator(_discriminants.cbegin(), _unaries.cbegin(), _binaries.cbegin());
}

FastContainer::const_iterator FastContainer::end() const {
  return const_iterator(_discriminants.cend(), _unaries.cend(), _binaries.cend());
}

const FastContainer::const_iterator& 
FastContainer::const_iterator::operator++(){
  if(*_discriminant){
    _binary++;
  } else {
    _unary++;
  }
  _discriminant++;
  
  return *this;
}

const operation::Operation& 
FastContainer::const_iterator::operator*() const {
  if(*_discriminant){
    return reinterpret_cast<const operation::Binary&>(*_binary);
  } else {
    return reinterpret_cast<const operation::Unary&>(*_unary);
  }
}

bool FastContainer::const_iterator::operator==(const const_iterator& other) const {
  return _discriminant == other._discriminant;
}

bool FastContainer::const_iterator::operator!=(const const_iterator& other) const {
  return !(*this == other);
}

}}
