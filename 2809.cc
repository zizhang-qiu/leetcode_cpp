//
// Created by qzz on 2024/1/19.
//
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
      int n = static_cast<int>(nums1.size());
      std::vector<std::pair<int, int>> nums(n);
      for (int i = 0; i < n; ++i) {
        nums[i] = {nums1[i], nums2[i]};
      }
      std::sort(nums.begin(),
                nums.end(),
                [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
                  return lhs.second < rhs.second;
                });
      // for (int i = 0; i < n; ++i) {
      //   std::cout << nums[i].first << ", " << nums[i].second << endl;
      // }
      vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
      // dp[i][j] represents how many value can be decreased if operations are done to first i items for j times.
      for (int i = 1; i <= n; ++i) {
        const int b = nums[i - 1].second;
        const int a = nums[i - 1].first;
        for (int j = i; j > 0; --j) {
          dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + j * b + a);
        }
      }

      const int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
      const int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
      for (int i = 0; i <= n; ++i) {
        if (sum2 * i + sum1 - dp[n][i] <= x)return i;
      }
      return -1;
    }
};

int main(int argc, char* argv[]) {
  vector nums1 = {96, 27, 91, 66, 27, 62, 46, 69, 25, 100, 17, 79, 28, 83, 33, 51, 84, 29, 68, 68, 41};
  vector nums2 = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0};
  const int x = 396;
  Solution sl{};
  int ans = sl.minimumTime(nums1, nums2, x);
  cout << ans << endl;
}
