#include "univariate_function.h"
#include "operation.h"

using UF = autodiff::UnivariateFunction;

void autodiff::OperationsLoader::push(Operation* x){
  if(x.is_binary()) {
    _n_binaries++;
  } else {
    _n_unaries++;
  }
  _operations.push_back(x);
}

int autodiff::OperationsLoader::size(){
  return _operations.size();
}

int autodiff::OperationsLoader::get_n_unaries(){
  return _n_unaries;
}

int autodiff::OperationsLoader::get_n_binaries(){
  return _n_binaries;
}

void UF::_update_cache(){
  _discriminants = std::vector<bool>(_operations.size());
  _unaries = std::vector<UnaryOperation>(_operations.get_n_unaries());
  _binaries = std::vector<BinaryOperation>(_operations.get_n_binaries());
  
  auto unary = _unaries.begin();
  auto binary = _binaries.begin();
  for(int i=0; i<_operations.size(); i++){
    
  }
}

void UF::push(Operation* x){
  _operations.push(x);
  _is_cache_updated = false;
}

UF::iterator UF::begin(){
  if(not _is_cache_updated()){
    update_cache();
  }

  return iterator(_discriminants.begin(), _unaries.begin(), _binaries.begin());
}

UF::iterator UF::end(){
  return iterator(_discriminants.end(), _unaries.end(), _binaries.end());
}

bool UF::iterator::operator==(const iterator& other){
  return _discriminant == other._discriminant;
}
