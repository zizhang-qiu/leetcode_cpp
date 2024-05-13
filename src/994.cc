#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int num_rot = 0;
    int num_total = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < grid.size(); i++) {       //row
      for (int j = 0; j < grid[0].size(); j++) {  //col
        if (grid[i][j] == 2) {
          ++num_rot;
        }
        if (grid[i][j] != 0) {
          ++num_total;
        }
      }
    }
    int num_steps = 0;
    while (num_rot != num_total) {
      int temp = num_rot;
      ++num_steps;
      std::vector<std::pair<int, int>> next_pos;
      for (int i = 0; i < grid.size(); i++) {       //row
        for (int j = 0; j < grid[0].size(); j++) {  //col
          if (grid[i][j] == 2) {
            if (grid[std::min(i + 1, m - 1)][j] != 0){
                  next_pos.push_back(std::make_pair(std::min(i + 1, m - 1), j));
            }
            if (grid[i][std::min(j + 1, n - 1)] != 0){
                  next_pos.push_back(std::make_pair(i, std::min(j + 1, n - 1)));
            }
            if (grid[std::max(i - 1, 0)][j] != 0){
                  next_pos.push_back(std::make_pair(std::max(i - 1, 0), j));
            }
            if (grid[i][std::max(j - 1, 0)] != 0){
                  next_pos.push_back(std::make_pair(i, std::max(j - 1, 0)));
            }
          }
          }
        }
        // Update grid
      for(const auto& pos : next_pos){
        grid[pos.first][pos.second] = 2;
      }
      // Count if no more rotting oranges
      num_rot = 0;
      for (int i = 0; i < grid.size(); i++) {       //row
        for (int j = 0; j < grid[0].size(); j++) {  //col
          if (grid[i][j] == 2) {
            ++num_rot;
          }
        }
      }
      if (num_rot == temp) {
        return -1;
      }
    }
    return num_steps;
  }
};

int main(int argc, char** argv) {
  Solution sl;
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  cout << sl.orangesRotting(grid) << endl;
  return 0;
}