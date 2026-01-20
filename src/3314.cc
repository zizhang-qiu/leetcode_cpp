#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    std::vector<int> res(nums.size(), -1);
    const size_t n = res.size();
    for (size_t i = 0; i < n; ++i) {
      const int num = nums[i];
      for (int j = 0; j < num; ++j) {
        if ((j | (j + 1)) == num) {
          res[i] = j;
          break;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution sl;
  auto res = sl.minBitwiseArray(std::vector<int>{11, 13, 31});
  for(const auto& x : res){
    std::cout << x << " ";
  }
  return 0;
}
