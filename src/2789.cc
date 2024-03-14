
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxArrayValue(vector<int>& nums) {
    const size_t n = nums.size();
    if (n==1) {
        return nums[0];
    }
    long long sum = nums.back();
    for (size_t i = n - 1; i > 0; --i) {
      if (sum>=nums[i-1]) {
        sum += nums[i-1];
      }else{
        sum = nums[i-1];
      }
    }
    return sum;
  }
};

int main() {
  Solution sl{};
  vector<int> nums = {5, 3, 3};
  int ans = sl.maxArrayValue(nums);
  cout << ans;
}