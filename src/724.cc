#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


using namespace std;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (2 * sum + nums[i] == total) {
        return i;
      }
      sum += nums[i];
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << s.pivotIndex(nums) << endl;
  return 0;
}