#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    const int m = static_cast<int>(board.size());
    const int n = static_cast<int>(board[0].size());
    int count = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') &&
            (j == 0 || board[i][j - 1] != 'X')) {
          ++count;
        }
      }
    }
    return count;
  }
};

int main(int argc, char** argv) {
  Solution sl{};
  vector<vector<char>> board = {
      {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
  int res = sl.countBattleships(board);
  cout << res << endl;
  return 0;
}