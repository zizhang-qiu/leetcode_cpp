#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  double minimumAverage(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int res = numeric_limits<int>::max();
    const size_t n = nums.size();
    for (size_t i = 0; i < n / 2; ++i) {
      res = std::min(res, nums[i] + nums[n - 1 - i]);
    }
    return static_cast<double>(res) / 2.0;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  vector nums = {7,8,3,4,15,13,4,1};
  double res = sl.minimumAverage(nums);
  std::cout << res << std::endl;
  return 0;
}
