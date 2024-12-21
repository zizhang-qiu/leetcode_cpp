#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    std::sort(score.begin(), score.end(),
              [k](const std::vector<int>& a, const std::vector<int>& b) {
                return a[k] > b[k];
              });
    return score;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> score = {{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}};
  int k = 2;
  Solution sl;
  auto s = sl.sortTheStudents(score, k);
  for(const auto vec:s){
    for(const int i: vec){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
