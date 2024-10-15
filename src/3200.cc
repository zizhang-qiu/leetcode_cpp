#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int calculateHeight(int num_balls_odd, int num_balls_even) {
    int layer = 0;
    while (num_balls_odd >= 0 && num_balls_even >= 0) {
      int next_layer = layer + 1;
      if (next_layer % 2 == 1) {
        num_balls_odd -= next_layer;
        layer += num_balls_odd >= 0;
      } else {
        num_balls_even -= next_layer;
        layer += num_balls_even >= 0;
      }
    }
    return layer;
  }

  int maxHeightOfTriangle(int red, int blue) {
    int r = red, b = blue;
    int res1 = calculateHeight(red, blue);
    int res2 = calculateHeight(blue, red);
    int res = std::max(res1, res2);
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  int res = sl.maxHeightOfTriangle(2, 10);
  printf("%d", res);
  return 0;
}
