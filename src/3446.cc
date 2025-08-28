#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // Convert n_th element in diagonal to its index in the matrix
  std::pair<int, int> diagonal_elem_to_index(int diagonal_index, int n,
                                             int num_rows) {
    int start_row =
        diagonal_index < num_rows ? num_rows - diagonal_index - 1 : 0;
    int start_col =
        diagonal_index < num_rows ? 0 : diagonal_index - num_rows + 1;
    for (int i = 0; i < n; i++) {
      ++start_row;
      ++start_col;
    }
    return {start_row, start_col};
  }

  std::vector<int> get_nth_diagonal(const std::vector<std::vector<int>>& grid,
                                    int n) {
    std::vector<int> diagonal;
    const int num_diagonals = 2 * grid.size() - 1;
    auto [row, col] = diagonal_elem_to_index(n, 0, grid.size());
    while (row < grid.size() && col < grid.size()) {
      diagonal.push_back(grid[row][col]);
      ++row;
      ++col;
    }
    return diagonal;
  }

  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    const size_t n = grid.size();
    const int num_diagonals = 2 * n - 1;
    std::vector<std::vector<int>> diagonals(num_diagonals);
    for (size_t i = 0; i < num_diagonals; i++) {
      diagonals[i] = get_nth_diagonal(grid, i);
    }
    for (auto& diagonal : diagonals) {
      std::cout << "diagonal: ";
      for (auto e : diagonal) {
        std::cout << e << " ";
      }
      std::cout << std::endl;
    }
    for (size_t i = 0; i < num_diagonals; i++) {
      if (i < n) {
        std::sort(diagonals[i].begin(), diagonals[i].end(),
                  std::greater<int>());
      } else {
        std::sort(diagonals[i].begin(), diagonals[i].end(), std::less<int>());
      }
    }
    for (auto& diagonal : diagonals) {
      std::cout << "diagonal: ";
      for (auto e : diagonal) {
        std::cout << e << " ";
      }
      std::cout << std::endl;
    }
    std::vector<vector<int>> result(n, vector<int>(n));
    for (size_t i = 0; i < num_diagonals; ++i) {
      auto [row, col] = diagonal_elem_to_index(i, 0, n);
      for (size_t j = 0; j < diagonals[i].size(); ++j) {
        result[row + j][col + j] = diagonals[i][j];
      }
    }
    std::cout << "result: " << std::endl;
    for (auto row : result) {
      for (auto e : row) {
        std::cout << e << " ";
      }
      std::cout << std::endl;
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
  s.sortMatrix(grid);
  return 0;
}
