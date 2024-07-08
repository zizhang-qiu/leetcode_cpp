
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkMove(vector<vector<char>>& board, int rMove, int cMove,
                 char color) {
    auto check = [&](int dx, int dy, char color) {
      int x = rMove + dx;
      int y = cMove + dy;
      int step = 1;

      while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (step == 1) {
          if (board[x][y] == '.' || board[x][y] == color) {
            return false;
          }
        } else {
          if (board[x][y] == '.') {
            return false;
          }
          if (board[x][y] == color) {
            return true;
          }
        }
        ++step;
        x += dx;
        y += dy;
      }
      return false;
    };

    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};  // 行改变量
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};  // 列改变量

    for(int i=0; i<8; ++i){
        if (check(dx[i], dy[i], color)) {
            return true;
        }
    }
    return false;
  }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<char>> board = {
        {'.','.','.','B','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'W','B','B','.','W','W','W','B'},{'.','.','.','B','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','W','.','.','.','.'}
    };
    std::cout << std::boolalpha << s.checkMove(board, 4, 3, 'B');
    return 0;
}