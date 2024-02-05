//
// Created by qzz on 2024/2/5.
//
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
 public:
  int maxResult(vector<int> &nums, int k) {
    const int n = static_cast<int>(nums.size());
    // dp[i] stores max score when reaching position i.
    vector<int> dp(n);
    dp[0] = nums[0];

    deque<int> queue;
    queue.push_back(0);

    for (int i = 1; i < n; ++i) {
      while (!queue.empty()
             && queue.front() < i - k) {
        queue.pop_front();
      }

      dp[i] = dp[queue.front()] + nums[i];

      while (!queue.empty()
             && dp[queue.back()] <= dp[i]) {
        queue.pop_back();
      }
      queue.push_back(i);
    }
    return dp[n - 1];
  }
};

int main() {
  vector nums = {1,-1,-2,4,-7,3};
  int k = 2;
  Solution sl{};
  int ans = sl.maxResult(nums, k);
  cout << ans << endl;
}