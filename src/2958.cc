#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    int left = 0;
    int ans = 0;
    int right = -1;
    for(; left<nums.size(); ++left){
        if(left > 0){
            --m[nums[left-1]];
        }
        while(right + 1 < nums.size() && m[nums[right + 1]] < k){
            ++right;
            ++m[nums[right]];
        }
        ans = std::max(ans, right - left + 1);
    }
    return ans;
  }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;
    int ans = Solution().maxSubarrayLength(nums, k);
    std::cout << ans << std::endl;
}