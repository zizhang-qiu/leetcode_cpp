#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
      ans = max(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> nums = {3, 5, 2, 3};
  cout << s.minPairSum(nums) << endl;
  return 0;
}
