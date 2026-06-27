#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    std::unordered_map<long long, int> cnt;
    for (int num : nums) {
      cnt[num]++;
    }

    int ans = 0;
    if (cnt[1] % 2 == 0) {
      ans = cnt[1] - 1;
    } else {
      ans = cnt[1];
    }

    cnt.erase(1);
    for(const auto& [num, _]: cnt){
        int res = 0;
        long long x = num;
        for(; (cnt.find(x) != cnt.end()) && cnt[x] > 1; x *= x){
            res += 2;
        }
        ans = std::max(ans, res + ((cnt.find(x) != cnt.end()) ? 1: -1));
    }

    return ans;
  }
};

int main() {
    Solution sl;
    std::vector<int> nums = {5, 4, 1, 2, 2};
    int ans = sl.maximumLength(nums);
    std::cout << ans << std::endl;
    return 0;
}