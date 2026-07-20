#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    const int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> ret(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int index1 = (i * n + j + k) % (m * n);
        ret[index1 / n][index1 % n] = grid[i][j];
      }
    }
    return ret;
  }
};

int main() {
  Solution sl;
  std::vector<std::vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto res = sl.shiftGrid(grid, 1);
  for (const auto& g : res) {
    for (int i : g) {
      std::cout << i << ", ";
    }
    std::cout << "\n";
  }
}