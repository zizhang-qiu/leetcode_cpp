#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  int minTimeBetweenTwoPoints(const std::vector<int>& start,
                              const std::vector<int>& end) {
    const int x0 = start[0], y0 = start[1];
    const int x1 = end[0], y1 = end[1];
    const int delta_x = std::abs(x0 - x1);
    const int delta_y = std::abs(y0 - y1);
    int diag_len = std::min(delta_x, delta_y);
    int remainder = std::max(delta_x, delta_y) - diag_len;
    return diag_len + remainder;
  }

  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    if (points.size() == 1) {
      return 0;
    }
    int res = 0;
    for (int i = 1; i < points.size(); i++) {
      res += minTimeBetweenTwoPoints(points[i - 1], points[i]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int res = s.minTimeToVisitAllPoints(std::vector<vector<int>>{std::vector<int>{3, 2}, std::vector<int>{-2, 2}});
  std::cout << res << std::endl;
  return 0;
}
