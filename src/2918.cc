#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0, sum2 = 0;
    long long zero1 = 0, zero2 = 0;
    for (int i : nums1) {
      sum1 += i;
      if (i == 0) {
        sum1++;
        zero1++;
      }
    }
    for (int i : nums2) {
      sum2 += i;
      if (i == 0) {
        sum2++;
        zero2++;
      }
    }
    if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
      return -1;
    }
    return max(sum1, sum2);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> nums1 = {3, 2, 0, 1, 0};
  vector<int> nums2 = {6, 5, 0};
  Solution sl;
  cout << sl.minSum(nums1, nums2) << endl;
  return 0;
}
