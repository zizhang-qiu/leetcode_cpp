#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    int inc = 1;
    int time = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1])
        return false;
      else if (inc * (nums[i] - nums[i - 1]) < 0) {
        inc *= -1;
        ++time;
      }
    }
    return time == 2 && nums[1] > nums[0];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
