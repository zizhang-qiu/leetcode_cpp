#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countCompleteDayPairs(vector<int>& hours) {
    const int n = static_cast<int>(hours.size());
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int sum = hours[i] + hours[j];
        if (sum % 24 == 0 && sum > 0) {
          ++res;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  vector<int> hours = {12,12,30,24,24};
  int res = sl.countCompleteDayPairs(hours);
  printf("%d", res);
  return 0;
}
