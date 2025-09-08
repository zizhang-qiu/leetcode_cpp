#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool ConsistZero(int n) {
    while (n) {
      int digit = n % 10;
      if (digit == 0) {
        return true;
      }
      n /= 10;
    }
    return false;
  }

  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n; i++) {
      if (!ConsistZero(i) && !ConsistZero(n - i)) {
        return {i, n - i};
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> res = s.getNoZeroIntegers(11);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
