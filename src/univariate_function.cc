#include "univariate_function.h"
#include "operation.h"

using UF = autodiff::UnivariateFunction;

void UF::_update_cache(){
  _discriminants_cache = std::vector<bool>(_operations.size());
  _unaries_cache = std::vector<UnaryOperation>(_n_unaries);
  _binaries_cache = std::vector<BinaryOperation>(_n_binaries);
  
  auto unary = _unaries_cache.begin();
  auto binary = _binaries_cache.begin();
  for(int i=0; i<_operations.size(); i++){
    if(_operations[i]->is_binary()){
      *binary++ = *dynamic_cast<BinaryOperation*>(_operations[i]);
    } else {
      *unary++ = *dynamic_cast<UnaryOperation*>(_operations[i]);
    }
    _discriminants_cache[i] = _operations[i]->is_binary();
  }
}

void UF::push(Operation* x){
  if(x->is_binary()){
    _n_binaries++;
  } else {
    _n_unaries++;
  }
  _is_cache_updated = false;
  _operations.push_back(x);
}

UF::iterator UF::begin(){
  if(not _is_cache_updated){
    _update_cache();
    _is_cache_updated = true;
  }
  
  return iterator(_discriminants_cache.begin(), _unaries_cache.begin(), _binaries_cache.begin());
}

UF::iterator UF::end(){
  if(not _is_cache_updated){
    _update_cache();
    _is_cache_updated = true;
  }
  return iterator(_discriminants_cache.end(), _unaries_cache.end(), _binaries_cache.end());
}

const UF::iterator& UF::iterator::operator++(){
  if(*_discriminant){
    _binary_operation++;
  } else {
    _unary_operation++;
  }
  _discriminant++;
  
  return *this;
}

const autodiff::Operation& UF::iterator::operator*(){
  if(*_discriminant){
    return *_binary_operation;
  } else {
    return *_unary_operation;
  }
}

bool UF::iterator::operator==(const iterator& other){
  return _discriminant == other._discriminant;
}

bool UF::iterator::operator!=(const iterator& other){
  return !(*this == other);
}
