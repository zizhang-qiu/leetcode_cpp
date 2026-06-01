#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    const int n = static_cast<int>(s.size());
    std::vector<int> f(n), pre(n);
    f[0] = 1;
    for (int i = 0; i < minJump; ++i) {
      pre[i] = 1;
    }

    for (int i = minJump; i < n; ++i) {
      int left = i - maxJump, right = i - minJump;
      if (s[i] == '0') {
        int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
        f[i] = (total != 0);
      }
      pre[i] = pre[i - 1] + f[i];
    }
    return f[n - 1];
  }
};

int main() {
    std::string s = "011010";
    Solution sl;
    bool res = sl.canReach(s, 2, 3);
    std::cout << std::boolalpha << res << "\n";
    return 0;
}