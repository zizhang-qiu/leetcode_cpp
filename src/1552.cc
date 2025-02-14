#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool check(int x, const vector<int>& position, int m) {
    int pre = position[0];
    int cnt = 1;
    for (int i = 1; i < position.size(); ++i) {
      if (position[i] - pre >= x) {
        pre = position[i];
        ++cnt;
      }
    }
    return cnt >= m;
  }

  int maxDistance(vector<int>& position, int m) {
    std::sort(position.begin(), position.end());
    int left = 1, right = position.back() - position[0], ans = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (check(mid, position, m)) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  vector<int> position = {1, 2, 3, 4, 7};
  int m = 3;
  int res = sl.maxDistance(position, m);
  printf("%d\n", res);
  return 0;
}
