#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    for (int i = 0; i < nums.size(); ++i) {
      int max_num = *std::max_element(nums.begin(), nums.begin() + i);
      int min_num = *std::min_element(nums.begin() + i, nums.end());
      if (max_num - min_num <= k) {
        return i;
      }
    }
    return -1;
  }
};

int main(){
    Solution sl;
    std::vector<int> nums = {5, 0, 1, 4};
    int k = 3;
    int res = sl.firstStableIndex(nums, k);
    std::cout << res << "\n";
    return 0;
}