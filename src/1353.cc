/**
 * @file 1353.cc
 * @date 2025-07-07
 * @author qzz
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    int n = static_cast<int>(events.size());
    int max_day =
        std::max_element(events.begin(), events.end(),
                         [](const vector<int>& a, const vector<int>& b) {
                           return a[1] < b[1];
                         })
            ->at(1);
    // Sort events by start time
    std::sort(
        events.begin(), events.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    std::priority_queue<int, vector<int>, std::greater<int>> pq;
    int ans = 0;
    for (int i = 0, j = 0; i <= max_day; ++i) {
      while (j < n && events[j][0] <= i) {
        pq.push(events[j][1]);
        ++j;
      }
      while (!pq.empty() && pq.top() < i) {
        pq.pop();
      }
      if (!pq.empty()) {
        pq.pop();
        ++ans;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution solution;
  vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
  cout << solution.maxEvents(events) << endl;
  return 0;
}
