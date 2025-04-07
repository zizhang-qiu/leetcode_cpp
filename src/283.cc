#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    while (right < n) {
      if (nums[right] != 0) {
        swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
