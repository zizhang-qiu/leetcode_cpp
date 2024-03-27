#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
 public:
  static constexpr int mod = 1e9 + 7;
  using ll = long long;

  int countWays(vector<vector<int>>& ranges) {
    std::sort(ranges.begin(), ranges.end(),
              [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
                return lhs[0] < rhs[0];
              });
    const int n = ranges.size();
    ll res = 1;
    for (int i = 0; i < n;) {
      int r = ranges[i][1];
      int j = i + 1;
      while (j < n && ranges[j][0] <= r) {
        r = std::max(r, ranges[j][1]);
        ++j;
      }

      res = res * 2 % mod;
      i = j;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> ranges = {{1, 3}, {10, 20}, {2, 5}, {4, 8}};
  Solution sl{};
  int res = sl.countWays(ranges);
  std::cout << res;
}