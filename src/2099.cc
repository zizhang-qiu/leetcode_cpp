#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < nums.size(); i++) {
      vec.push_back(std::make_pair(nums[i], i));
    }
    std::sort(vec.begin(), vec.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.first > b.first;
              });
    std::sort(vec.begin(), vec.begin() + k,
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second < b.second;
              });
    std::vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(vec[i].first);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {2, 1, 3, 3};
  int k = 2;
  Solution s;
  auto res = s.maxSubsequence(nums, k);
  for (auto i : res) {
    cout << i << " ";
  }
  return 0;
}
