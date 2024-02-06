//
// Created by qzz on 2024/1/25.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
      int ans = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (checkKSetBits(i, k)) {
          ans += nums[i];
        }
      }
      return ans;
    }

    bool checkKSetBits(int i, int k) {
      if (i == 0) {
        return k <= 0;
      }
      int num_set_bits = 0;
      while (i > 0) {
        if (i & 1) {
          num_set_bits += 1;
          if (num_set_bits > k) {
            break;
          }
        }
        i >>= 1;
      }
      return num_set_bits == k;
    }
};

int main(int argc, char* argv[]) {
  Solution sl{};
  vector<int> nums = {4, 3, 2, 1};
  int k = 2;
  int ans = sl.sumIndicesWithKSetBits(nums, k);
  cout << ans << endl;
}
