#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool uniformArray(vector<int>& nums1) {
    int odds = 0;
    int evens = 0;
    int min_num = std::numeric_limits<int>::max();
    for (int num : nums1) {
      if (num % 2 == 1) {
        odds++;
      } else {
        evens++;
      }
      min_num = std::min(num, min_num);
    }

    // All the nums are odd or even
    if (odds == 0 || evens == 0) {
      return true;
    }

    // If there are odds and evens, we want nums2 all odd
    // thus the smallest num should be odd
    if (min_num % 2 == 1) {
      return true;
    }

    return false;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums1 = {2, 3};
  bool res = sl.uniformArray(nums1);
  std::cout << res << std::endl;
}