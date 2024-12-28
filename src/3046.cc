#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPossibleToSplit(vector<int>& nums) {
    std::unordered_map<int, int> count;
    for (const int n : nums) {
      ++count[n];
      if (count[n] > 2) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {1, 1, 1, 1};
  Solution sl;
  bool res = sl.isPossibleToSplit(nums);
  std::cout << res << std::endl;
  return 0;
}
