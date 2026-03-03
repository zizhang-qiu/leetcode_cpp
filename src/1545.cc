#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  std::string invertBinary(std::string s) {
    std::string res;
    for (char c : s) {
      res += (c == '0') ? '1' : '0';
    }
    return res;
  }

  std::string reverseInvertBinary(std::string s) {
    std::string res = invertBinary(s);
    std::reverse(res.begin(), res.end());
    return res;
  }

  char findKthBit(int n, int k) {
    if (n == 1)
      return '0';
    int i = 1;
    const std::string s0 = "0";
    std::string s = s0;
    while (i < n) {
      s += "1" + reverseInvertBinary(s);
      i++;
    }
    // std::cout << s << std::endl;
    return s[k - 1];
  }
};

int main() {
    Solution sl;
    int n = 2;
    int k = 3;
    cout << sl.findKthBit(n, k) << endl;
    return 0;
}