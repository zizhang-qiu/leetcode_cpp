//
// Created by qzz on 2024/1/23.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    int alternatingSubarray(vector<int>& nums) {
      const int size = nums.size();
      int maxLength = -1;
      for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
          auto subArray = vector<int>(nums.begin() + i, nums.begin() + j + 1);
          if (isSubarrayLegal(subArray)) {
            maxLength = std::max(maxLength, j - i + 1);
          }
        }
      }
      return maxLength;
    }

    bool isSubarrayLegal(const vector<int>& subArray) {
      if (subArray.size() == 1) { return true; }
      for (int i = 0; i < subArray.size(); ++i) {
        if (subArray[i] - subArray[0] != i % 2) {
          return false;
        }
      }
      return true;
    }
};

int main(int argc, char* argv[]) {
  Solution sl{};
  vector<int> nums = {2,3,4,3,4};
  int ans = sl.alternatingSubarray(nums);
  cout << ans << endl;
}
