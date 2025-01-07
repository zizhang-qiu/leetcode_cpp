#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countKeyChanges(string s) {
    if (s.empty()) {
      return 0;
    }
    std::transform(s.begin(), s.end(), s.begin(), std::tolower);
    int res = 0;
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        ++res;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[])
{
  Solution sl;
  int res = sl.countKeyChanges("aAbBcC");
  std::cout << res << std::endl;
  return 0;
}
