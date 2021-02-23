#ifndef AUTODIFF_UNIVARIATE_FUNCTION_H_
#define AUTODIFF_UNIVARIATE_FUNCTION_H_

#include "operation.h"

#include <vector>
#include <ranges>
#include <iterator>

namespace autodiff {

template <typename T>
concept UNIVARIATE_FUNCTION = 
  std::ranges::forward_range<T> &&
  OPERATION<std::ranges::range_value_t<T>>;

class OperationsLoader {
private:
  std::vector<Operation*> _operations; // this is a pain
  int _n_unaries;
  int _n_binaries;

public:
  void push(Operation*)
  int size()
  int get_n_unaries()
  int get_n_binaries()
};

class UnivariateFunction {
private:
  OperationsLoader _operations;
  
  std::vector<bool> _discriminants;
  std::vector<UnaryOperation> _unaries;
  std::vector<BinaryOperation> _binaries;

  bool _is_cache_updated = false;
  void _update_cache()

public:
  void push(Operation*)
  iterator begin()
  iterator end()

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

    iterator operator++()
    Operation operator*()
    bool operator==(const iterator&)
  };
  
};

}

#endif
