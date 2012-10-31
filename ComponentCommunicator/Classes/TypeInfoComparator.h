#ifndef TypeInfoComparator_h
#define TypeInfoComparator_h

#include <typeinfo>

struct type_info_comparator {
  bool operator ()(const std::type_info* a, const std::type_info* b) const {
    return a->before(*b);
  }
};

#endif
