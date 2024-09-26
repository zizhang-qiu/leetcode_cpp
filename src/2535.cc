#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int differenceOfSum(vector<int>& nums) {
    int elem_sum = std::accumulate(nums.begin(), nums.end(), 0);
    const auto get_num_sum = [](int num) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      return sum;
    };
    int num_sum = 0;
    for (const int num : nums) {
      num_sum += get_num_sum(num);
    }
    return std::abs(elem_sum - num_sum);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  vector nums = {1, 15, 6, 3};
  int res = sl.differenceOfSum(nums);
  printf("%d", res);
  return 0;
}
