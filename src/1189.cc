#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    std::array<int, 26> m;
    std::fill(m.begin(), m.end(), 0);
    for (const char l : text) {
      m[l - 'a']++;
    }
    m['l' - 'a'] /= 2;
    m['o' - 'a'] /= 2;

    int ans = std::numeric_limits<int>::max();
    for (const char l : {'b', 'a', 'l', 'o', 'n'}) {
      ans = std::min(m[l - 'a'], ans);
    }
    return ans;
  }
};

int main() {
  Solution sl;
  int ans = sl.maxNumberOfBalloons("nlaebolko");
  std::cout << ans << "\n";
}