#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minimumCost(int m, int n, vector<int>& horizontalCut,
                        vector<int>& verticalCut) {
    std::sort(horizontalCut.begin(), horizontalCut.end());
    std::sort(verticalCut.begin(), verticalCut.end());
    long long h = 1, v = 1;
    long long res = 0;
    while (!horizontalCut.empty() || !verticalCut.empty()) {
      if (verticalCut.empty() || (!horizontalCut.empty() &&
                                  horizontalCut.back() > verticalCut.back())) {
        res += horizontalCut.back() * h;
        horizontalCut.pop_back();
        ++v;
      } else {
        res += verticalCut.back() * v;
        verticalCut.pop_back();
        ++h;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  int m=3, n=2;
  std::vector<int> horizontalCut = {1, 3};
  std::vector<int> verticalCut = {5};
  Solution sl;
  long long res = sl.minimumCost(m, n, horizontalCut, verticalCut);
  std::cout << res << std::endl;
  return 0;
}
