#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                         vector<int>& waterStartTime,
                         vector<int>& waterDuration) {
    const int num_land = static_cast<int>(landStartTime.size());
    const int num_water = static_cast<int>(waterStartTime.size());
    // land -> water
    int cur_time = 0;
    int res = std::numeric_limits<int>::max();
    for (int i = 0; i < num_land; ++i) {
      cur_time = landStartTime[i] + landDuration[i];
      for (int j = 0; j < num_water; ++j) {
        int cur_time2 = cur_time;
        if (cur_time < waterStartTime[j]) {
          cur_time2 = waterStartTime[j];
        }
        res = std::min(cur_time2 + waterDuration[j], res);
      }
    }

    // water -> land
    for (int j = 0; j < num_water; ++j) {
      cur_time = waterStartTime[j] + waterDuration[j];
      for (int i = 0; i < num_land; ++i) {
        int cur_time2 = cur_time;
        if (cur_time < landStartTime[i]) {
          cur_time2 = landStartTime[i];
        }
        res = std::min(cur_time2 + landDuration[i], res);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  std::vector<int> landStartTime = {5};
  std::vector<int> landDuration = {3};
  std::vector<int> waterStartTime = {1};
  std::vector<int> waterDuration = {10};
  int res = sl.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
  std::cout << res << "\n";
  return 0;
}
