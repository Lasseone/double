#ifndef AUTODIFF_UNIVARIATE_FUNCTION_H_
#define AUTODIFF_UNIVARIATE_FUNCTION_H_

#include "operation.h"

#include <vector>
#include <iterator>

namespace autodiff {


class UnivariateFunction {
/* 
  stores data in slow _operations until begin() is called
  at which point data is stored in a faster format and cached
*/

private:
  std::vector<Operation*> _operations;
  int _n_unaries = 0;
  int _n_binaries = 0;
  
  std::vector<bool> _discriminants_cache; // unary: false, binary: true
  std::vector<UnaryOperation> _unaries_cache;
  std::vector<BinaryOperation> _binaries_cache;

  bool _is_cache_updated = false;
  void _update_cache();

public:
  class iterator {
  private:
    std::vector<bool>::iterator _discriminant;
    std::vector<UnaryOperation>::iterator _unary_operation;
    std::vector<BinaryOperation>::iterator _binary_operation;

  public:
    iterator(
        std::vector<bool>::iterator discriminant,
        std::vector<UnaryOperation>::iterator unary_operation, 
        std::vector<BinaryOperation>::iterator binary_operation) :
          _discriminant(discriminant),
          _unary_operation(unary_operation),
          _binary_operation(binary_operation) {}

    const iterator& operator++();
    const Operation& operator*();
    bool operator==(const iterator&);
    bool operator!=(const iterator&);
  };

  void push(Operation*);
  iterator begin();
  iterator end();
};

}

#endif
