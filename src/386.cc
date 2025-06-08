#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    std::vector<int> ret(n);
    int num = 1;
    for (int i = 0; i < n; ++i) {
      ret[i] = num;
      if (num * 10 <= n) {
        num *= 10;
      } else {
        while (num % 10 == 9 || num + 1 > n) {
          num /= 10;
        }
        ++num;
      }
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  auto ret = Solution().lexicalOrder(13);
  for (const int n : ret) {
    std::cout << n << ", ";
  }
  return 0;
}
