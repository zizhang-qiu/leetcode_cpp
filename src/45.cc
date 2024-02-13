//
// Created by qzz on 2024/1/14.
//
#include <vector>
#include <array>
#include <iostream>
using namespace std;

class Solution {
  public:
    int jump(vector<int>& nums) {
      if (nums.size() == 1) return 0;
      int curDistance = 0; // 当前覆盖最远距离下标
      int ans = 0; // 记录走的最大步数
      int nextDistance = 0; // 下一步覆盖最远距离下标
      for (int i = 0; i < nums.size(); i++) {
        nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖最远距离下标
        if (i == curDistance) {
          // 遇到当前覆盖最远距离下标
          ans++; // 需要走下一步
          curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
          if (nextDistance >= nums.size() - 1) break; // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
        }
      }
      return ans;
    }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector nums = {2, 3, 0, 1, 4};
  int ans = s.jump(nums);
  cout << ans << endl;
}
