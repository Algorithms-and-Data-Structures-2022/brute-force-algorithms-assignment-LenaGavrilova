#include "assignment/subsets/bit_masking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"  // is_bit_set

namespace assignment {

  std::vector<std::vector<int>> SubsetsBitMasking::generate(const std::vector<int>& set) const {
    assert(set.size() <= 16);

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    // выделяем память
    auto subsets = std::vector<std::vector<int>>();

    for (int i = 0; i < num_subsets; i++) {
      auto sub_set = mask2indices(set, i);
      subsets.push_back(sub_set);
    }

    return subsets;
  }

}  // namespace assignment