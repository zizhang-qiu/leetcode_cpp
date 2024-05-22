#include <iostream>
#include <map>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> m;
    for (const auto& match : matches) {
      m[match[0]];
      m[match[1]]++;
    }
    vector<vector<int>> res(2);

    for (const auto& [k, v] : m) {
      if (v <= 1) {
        res[v].push_back(k);
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  Solution sl;
  vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6},  {5, 7},
                                 {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
  auto res = sl.findWinners(matches);
  for (const auto& v : res) {
    for (const auto& n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}