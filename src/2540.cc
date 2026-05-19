#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    const int n = static_cast<int>(nums1.size());
    const int m = static_cast<int>(nums2.size());
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
      if (nums1[i] == nums2[j]) {
        return nums1[i];
      }
      if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
      }
    }
    return -1;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<int> nums2 = {2, 4};
  int res = sl.getCommon(nums1, nums2);
  std::cout << res << std::endl;
}