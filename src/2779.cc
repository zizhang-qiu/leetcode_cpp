#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    int res = 0, n = nums.size();
    std::sort(nums.begin(), nums.end());
    for(int i = 0, j=0; i < n; i++) {
        while (nums[i] - 2 * k > nums[j]) {
            j++;
        }
        res = std::max(res, i - j + 1);
    }
    return res;
  }
};

int main(int argc, char** argv) {
    Solution sl{};
    std::vector<int> nums = {4, 6, 1 ,2};
    std::cout << sl.maximumBeauty(nums, 2) << std::endl;
    return 0;
}