#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    int n = nums.size();
    int res = 1000;
    int mn = 1000;
    vector<int> left(n);
    for (int i = 1; i < n; ++i) {
      left[i] = mn = min(nums[i - 1], mn);
    }

    int right = nums[n - 1];
    for (int i = n - 2; i > 0; --i) {
      if (left[i] < nums[i] && nums[i] > right) {
        res = min(res, left[i] + nums[i] + right);
      }
      right = min(right, nums[i]);
    }
    return res < 1000 ? res : -1;
  }
};

int main(int argc, char** argv) {}