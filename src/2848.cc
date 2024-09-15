#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    int num_points = 0;
    for(const auto& vec:nums){
        num_points = max(num_points, vec[1]);
    }

    std::vector<int> counter(num_points + 1);
    for(const auto& vec:nums){
        for(int i=vec[0]; i<=vec[1]; ++i){
            ++counter[i];
        }
    }

    int ans = 0;
    for(const int count:counter){
        ans += count > 0;
    }

    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sl;
  vector<vector<int>> nums = {{1, 3}, {5, 8}};
  auto ans = sl.numberOfPoints(nums);
  printf("%d", ans);
  return 0;
}
