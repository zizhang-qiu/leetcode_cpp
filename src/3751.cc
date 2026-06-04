#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int waviness(int x) {
    if (x < 100) {
      return 0;
    }

    int digits[10];
    int n = 0;

    while (x > 0) {
      digits[n++] = x % 10;
      x /= 10;
    }

    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) {
      if ((digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) ||
          (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])) {
        ++cnt;
      }
    }

    return cnt;
  }

  int totalWaviness(int num1, int num2) {
    int ans = 0;
    for (int num = num1; num <= num2; ++num) {
      ans += waviness(num);
    }
    return ans;
  }
};

int main() {
  Solution sl;
  int num1 = 120, num2 = 130;
  int res = sl.totalWaviness(120, 130);
  std::cout << res << std::endl;
}