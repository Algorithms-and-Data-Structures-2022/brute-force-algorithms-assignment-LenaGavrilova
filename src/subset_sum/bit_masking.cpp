#include "assignment/subset_sum/bit_masking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"  // is_bit_set, mask2indices

namespace assignment {

  std::vector<std::vector<int>> SubsetSumBitMasking::search(const std::vector<int>& set, int target_sum) const {
    assert(target_sum > 0 && set.size() <= 16);

    std::vector<std::vector<int>> indices;

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    for (int mask = 0; mask < num_subsets; mask++) {
      auto subset = mask2indices(set, mask);
      int sum = 0;
      for (int i = 0; i < subset.size(); i++) {
        sum += set[subset[i]];
        if (sum > target_sum) { break; }
      }
      if (sum == target_sum) { indices.push_back(subset); }
    }
    return indices;
  }

}  // namespace assignment