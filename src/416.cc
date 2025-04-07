#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
      return false;
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = target; j >= nums[i]; j--) {
        dp[j] = dp[j] || dp[j - nums[i]];
      }
    }
    return dp[target];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> nums = {1, 5, 11, 5};
  Solution s;
  cout << s.canPartition(nums) << endl;  // Output: true
  return 0;
}
