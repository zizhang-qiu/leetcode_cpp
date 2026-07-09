#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                    vector<vector<int>>& queries) {
    std::vector<int> tags(n, 0);
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] > maxDiff) {
        tags[i] = tags[i - 1] + 1;
      } else {
        tags[i] = tags[i - 1];
      }
    }

    std::vector<bool> res(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int x = queries[i][0], y = queries[i][1];
      res[i] = tags[x] == tags[y];
    }
    return res;
  }
};

int main() {
  Solution sl;
  int n = 4;
  std::vector<int> nums = {2, 5, 6, 8};
  int maxDiff = 2;
  std::vector<std::vector<int>> queries = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  std::vector<bool> ans = sl.pathExistenceQueries(n, nums, maxDiff, queries);
  for (auto a : ans) {
    std::cout << a << ", ";
  }
  std::cout << "\n";
  return 0;
}