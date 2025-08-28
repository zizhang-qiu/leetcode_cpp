#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    const size_t m = mat.size();
    const size_t n = mat[0].size();
    vector<int> result;
    result.reserve(m * n);

    for (int d = 0; d < m + n - 1; ++d) {
      vector<int> intermediate;

      // 确定对角线起点
      int r = (d < n) ? 0 : d - n + 1;
      int c = (d < n) ? d : n - 1;

      // 收集对角线元素
      while (r < m && c >= 0) {
        intermediate.push_back(mat[r][c]);
        ++r;
        --c;
      }

      // 偶数对角线反转
      if (d % 2 == 0) {
        std::reverse(intermediate.begin(), intermediate.end());
      }

      result.insert(result.end(), intermediate.begin(), intermediate.end());
    }

    return result;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
