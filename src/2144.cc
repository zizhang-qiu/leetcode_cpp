#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    std::sort(cost.begin(), cost.end(), std::greater<>());
    int remained = static_cast<int>(cost.size());
    int res = 0, idx = 0;
    while (remained > 0) {
      if (remained >= 3) {
        res += cost[idx] + cost[idx + 1];
        idx += 3;
        remained -= 3;
      } else {
        for (; idx < cost.size(); ++idx) {
          res += cost[idx];
          --remained;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sl;
  std::vector<int> cost = {6, 5, 7, 9, 2, 2};
  int res = sl.minimumCost(cost);
  std::cout << res << std::endl;
}