#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& grid, int k) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    std::vector<std::pair<int, int>>
        points;  // Stores the coordinates of each point
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        points.emplace_back(i, j);
      }
    }

    std::sort(
        points.begin(), points.end(),
        [&grid](const std::pair<int, int>& a, const std::pair<int, int>& b) {
          return grid[a.first][a.second] < grid[b.first][b.second];
        });  // Sort the points by their values in descending order

    std::vector<std::vector<int>> costs(
        m, std::vector<int>(n, std::numeric_limits<int>::max()));  // DP table
    for (int t = 0; t <= k; ++t) {
      int min_cost = std::numeric_limits<int>::max();
      for (int i = 0, j = 0; i < points.size(); ++i) {
        min_cost = std::min(min_cost, costs[points[i].first][points[i].second]);
        // If the current point is the same as the next point, skip it
        if (i + 1 < points.size() &&
            grid[points[i].first][points[i].second] ==
                grid[points[i + 1].first][points[i + 1].second]) {
          continue;
        }
        // Update the DP table for the current point and its neighbors
        for (int r = j; r <= i; r++) {
          costs[points[r].first][points[r].second] = min_cost;
        }
        j = i + 1;
      }

      for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
          // Initialize the DP table for the last point
          if (i == m - 1 && j == n - 1) {
            costs[i][j] = 0;
            continue;
          }

          if (i != m - 1) {
            costs[i][j] =
                std::min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
          }

          if (j != n - 1) {
            costs[i][j] =
                std::min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
          }
        }
      }
    }

    return costs[0][0];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  std::vector<std::vector<int>> grid = {{1, 3, 3}, {2, 5, 4}, {4, 3, 5}};
  int k = 2;
  std::cout << s.minCost(grid, k) << std::endl;
  return 0;
}
