#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    vector<int> row_count(m, 0);
    vector<int> col_count(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          row_count[i]++;
          col_count[j]++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1 && row_count[i] == 1 && col_count[j] == 1) {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sl;
  vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
  cout << sl.numSpecial(mat) << endl;

  return 0;
}
