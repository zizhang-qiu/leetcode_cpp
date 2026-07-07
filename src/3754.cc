#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long sumAndMultiply(int n) {
    long long s = 0, pow10 = 1, x = 0;
    while (n > 0) {
      int digit = n % 10;
      n /= 10;
      s += digit;
      if (digit > 0) {
        x += digit * pow10;
        pow10 *= 10;
      }
    }
    return x * s;
  }
};

int main() {
    Solution sl;
    auto ans = sl.sumAndMultiply(10203004);
    std::cout << ans <<std::endl;
}