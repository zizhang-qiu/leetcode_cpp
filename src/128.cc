#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty())
      return 0;
    std::sort(nums.begin(), nums.end());
    int start = nums[0];
    int max_len = 1;
    int len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        ++len;
      } else if (nums[i] == nums[i - 1]) {
        continue;
      } else {
        max_len = std::max(max_len, len);
        len = 1;
      }
    }
    return std::max(max_len, len);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  cout << s.longestConsecutive(nums) << endl;
  return 0;
}