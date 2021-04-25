#ifndef AUTODIFF_UNIVARIATE_CONTAINER_H_
#define AUTODIFF_UNIVARIATE_CONTAINER_H_

#include <operation/operation.h>

#include <vector>
#include <iterator>

namespace autodiff {
namespace univariate {

class FastContainer {
/*
  _discriminants determines the ordering of the operations.
  For example, if _discriminants stores {true, true, false, true, false}
  then the order of operations is
  {_binaries[0], _binaries[1], _unaries[0], _binaries[2], _unaries[1]}
  
  UnaryVar and BinaryVar have enormously different sizes, so they
  are separated for cache efficiency
*/
private:
  std::vector<bool> _discriminants; // false: Unary, true: Binary
  std::vector<operation::UnaryVar> _unaries;
  std::vector<operation::BinaryVar> _binaries;

public:
  class iterator {
  private:
    std::vector<bool>::iterator _discriminant;
    std::vector<operation::UnaryVar>::iterator _unary;
    std::vector<operation::BinaryVar>::iterator _binary;

  public:
    iterator(
        std::vector<bool>::iterator discriminant,
        std::vector<operation::UnaryVar>::iterator unary, 
        std::vector<operation::BinaryVar>::iterator binary) :
          _discriminant(discriminant),
          _unary(unary),
          _binary(binary) {};

    const iterator& operator++();
    const operation::Operation& operator*() const;
    bool operator==(const iterator&) const;
    bool operator!=(const iterator&) const;
  };

  void push(const operation::UnaryVar&);
  void push(const operation::BinaryVar&);

  iterator begin();
  iterator end();
};


}}

#endif
