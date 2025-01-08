#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestGoodInteger(string num) {
    int largest = -1;
    for (size_t i = 0; i < num.size() - 2; ++i) {
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
        largest = std::max(largest, num[i] - '0');
      }
    }
    if (largest == -1) {
      return "";
    }
    char digit = (char)largest + '0';
    std::string res{digit, digit, digit};
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  auto res = sl.largestGoodInteger("42352338");
  std::cout << res << std::endl;
  return 0;
}
