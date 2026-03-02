#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    std::vector<int> max_right(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 1) {
          max_right[i] = j;
          break;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int k = -1;
      for (int j = i; j < n; ++j) {
        if (max_right[j] <= i) {
          ans += j - i;
          k = j;
          break;
        }
      }
      if (k != -1) {
        for (int j = k; j > i; --j) {
          swap(max_right[j], max_right[j - 1]);
        }
      } else {
        return -1;
      }
    }
    return ans;
  }
};

int main() {
    std::vector<std::vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};  
    Solution sl;    
    int ans = sl.minSwaps(grid);
    std::cout << ans << std::endl;
    return 0;
}