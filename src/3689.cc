#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  long long maxTotalValue(vector<int>& nums, int k) {
    int min_val = std::numeric_limits<int>::max();
    int max_val = std::numeric_limits<int>::min();
    for (int v : nums) {
      min_val = std::min(min_val, v);
      max_val = std::max(max_val, v);
    }
    return (long long)(max_val - min_val) * k;
  }
};

int main(){
    Solution sl;
    vector<int> nums = {1, 3, 2};
    int res = sl.maxTotalValue(nums, 2);
    std::cout << res << std::endl;
}