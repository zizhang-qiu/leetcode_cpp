#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
      ans = max(ans, j);
      if (ans == n - 1) {  // ans 已达到最大值
        return;
      }
      // 向右上/右/右下走一步
      for (int k = max(i - 1, 0); k < min(i + 2, m); k++) {
        if (grid[k][j + 1] > grid[i][j]) {
          dfs(k, j + 1);
        }
      }
      grid[i][j] = 0;
    };
    for (int i = 0; i < m; i++) {
      dfs(i, 0);  // 从第一列的任一单元格出发
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {
      {2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};

  Solution sl{};
  int ans = sl.maxMoves(grid);
  std::cout << ans;
}