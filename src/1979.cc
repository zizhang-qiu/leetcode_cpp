#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findGCD(vector<int>& nums) {
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    for (const int num : nums) {
      max = std::max(max, num);
      min = std::min(min, num);
    }

    int res;
    for (int i = min; i > 0; --i) {
      if (min % i == 0 && max % i == 0) {
        res = i;
        break;
      }
    }
    return res;
  }
};

int main() {
    Solution sl;
    std::vector<int> nums = {7, 5, 6, 8, 3};
    int res = sl.findGCD(nums);
    std::cout << res << "\n";
}