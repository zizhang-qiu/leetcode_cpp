//
// Created by qzz on 2024/1/15.
//
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      const int size = nums.size();
      vector<vector<int>> res;
      backtrack(res, nums, 0, size);
      return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
      if (first == len) {
        res.push_back(output);
        return;
      }

      for (int i = first; i < len; ++i) {
        std::swap(output[i], output[first]);
        backtrack(res, output, first + 1, len);
        std::swap(output[i], output[first]);
      }
    }
};

int main(int argc, char* argv[]) {
  vector nums = {1,2,3};
  auto res = Solution().permute(nums);

}
