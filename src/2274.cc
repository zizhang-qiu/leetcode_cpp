#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    special.push_back(bottom - 1);
    special.push_back(top + 1);
    std::sort(special.begin(), special.end());

    int n = special.size();
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      ans = std::max(ans, special[i + 1] - special[i] - 1);
    }
    return ans;
  }
};

int main(int argc, char const *argv[])
{
  Solution sl;
  int ans = sl.maxConsecutive(2, 9, vector<int>{4,6});
  std::cout << ans << std::endl;
  return 0;
}
