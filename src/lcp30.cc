//
// Created by qzz on 2024/2/6.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

class Solution {
 public:
  int magicTower(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int>> q;
    ll hp = 1, delay = 0;
    int ans = 0;
    for (const int num : nums) {
      if (num < 0) {
        q.push(num);
      }
      hp += num;
      if (hp <= 0) {
        ++ans;
        delay += q.top();
        hp -= q.top();
        q.pop();
      }
    }
    hp += delay;
    return hp <= 0 ? -1 : ans;
  }
};

int main() {
  Solution sl{};
  vector nums = {100, 100, 100, -250, -60, -140, -50, -50, 100, 150};
  int ans = sl.magicTower(nums);
  cout << ans << endl;
}