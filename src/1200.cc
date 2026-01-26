#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    int min_diff = std::numeric_limits<int>::max();
    vector<vector<int>> res;
    for (int i = 0; i < arr.size() - 1; i++) {
      int diff = arr[i + 1] - arr[i];
      if (diff < min_diff) {
        min_diff = diff;
        res.clear();
        res.push_back({arr[i], arr[i + 1]});
      } else if (diff == min_diff) {
        res.push_back({arr[i], arr[i + 1]});
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]){
  /* code */
  Solution s;
  vector<int> arr = {4, 2, 1, 3};
  vector<vector<int>> res = s.minimumAbsDifference(arr);
  for (auto& v : res) {
    for (auto& x : v) {
      cout << x << " ";
    }
    cout << endl;
    return 0;
  }
}
