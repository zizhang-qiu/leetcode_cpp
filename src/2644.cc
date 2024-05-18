#include <vector>

#include <iostream>

using namespace std;

class Solution {
 public:
  int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    int highest_index = -1;
    int highest_score = -1;
    for (int i = 0; i < divisors.size(); ++i) {
      int score = 0;
      for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] % divisors[i] == 0) {
          ++score;
        }
      }
      if (score >= highest_score) {
        if (highest_index == -1) {
          highest_index = i;
        }
        if (highest_score == score && highest_index >= 0 &&
            divisors[highest_index] > divisors[i]) {
          highest_index = i;
        }
        if (score > highest_score) {
          highest_index = i;
        }
        highest_score = score;
      }
    }
    return divisors[highest_index];
  }
};

int main(int argc, char** argv) {
    Solution sl;
    vector<int> nums = {4, 7, 9, 3, 9};
    vector<int> devisors = {5, 2, 3};
    int res = sl.maxDivScore(nums, devisors);
    cout << res << endl;
    return 0;
}