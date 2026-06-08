#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    std::vector<int> res(n, pivot);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < pivot) {
        res[left] = nums[i];
        ++left;
      } else if (nums[i] > pivot) {
        res[right] = nums[i];
        --right;
      }
    }
    std::reverse(res.begin() + right + 1, res.end());
    return res;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
  auto res = sl.pivotArray(nums, 10);
  for (int x : res) {
    std::cout << x << ", ";
  }
}