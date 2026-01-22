#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isNonDecreasing(const vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) {
      return true;
    }
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1])
        return false;
    }
    return true;
  }

  std::vector<int> reconstructVec(const vector<int>& nums, int idx) {
    std::vector<int> res;
    for (int i = 0; i < idx; ++i) {
      res.push_back(nums[i]);
    }
    res.push_back(nums[idx] + nums[idx + 1]);
    for (int i = idx + 2; i < nums.size(); ++i) {
      res.push_back(nums[i]);
    }
    return res;
  }

  int minimumPairRemoval(vector<int>& nums) {

    if (isNonDecreasing(nums)) {
      return 0;
    }
    int res = 0;
    while (!isNonDecreasing(nums)) {
      int min_idx = 0;
      int min_sum = std::numeric_limits<int>::max();
      for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] + nums[i + 1] < min_sum) {
          min_idx = i;
          min_sum = nums[i] + nums[i + 1];
        }
      }
      nums = reconstructVec(nums, min_idx);
      ++res;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  int res = sl.minimumPairRemoval(vector<int>{1, 2, 2});
  std::cout << res << std::endl;
  return 0;
}
