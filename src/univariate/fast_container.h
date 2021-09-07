#ifndef AUTODIFF_CONTAINER_H_
#define AUTODIFF_CONTAINER_H_

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
  class const_iterator {
  private:
    std::vector<bool>::const_iterator _discriminant;
    std::vector<operation::UnaryVar>::const_iterator _unary;
    std::vector<operation::BinaryVar>::const_iterator _binary;

  public:
    const_iterator(
        std::vector<bool>::const_iterator discriminant,
        std::vector<operation::UnaryVar>::const_iterator unary, 
        std::vector<operation::BinaryVar>::const_iterator binary) :
          _discriminant(discriminant),
          _unary(unary),
          _binary(binary) {};

    const const_iterator& operator++();
    const operation::Operation& operator*() const;
    bool operator==(const const_iterator&) const;
    bool operator!=(const const_iterator&) const;
  };

  void push(const operation::UnaryVar&);
  void push(const operation::BinaryVar&);

  const_iterator begin() const;
  const_iterator end() const;
};

}}

#endif
