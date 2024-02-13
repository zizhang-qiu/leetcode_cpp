//
// Created by qzz on 24-2-2.
//
#include <algorithm>
#include <vector>
#include <array>
#include <iostream>

using namespace std;

class Solution {
  public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
      int n = aliceValues.size();
      vector<tuple<int, int, int>> values;
      for (int i = 0; i < aliceValues.size(); i++) {
        values.emplace_back(aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]);
      }
      sort(values.begin(),
           values.end(),
           [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
             return get<0>(a) > get<0>(b);
           });
      int aliceSum = 0, bobSum = 0;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          aliceSum += get<1>(values[i]);
        }
        else {
          bobSum += get<2>(values[i]);
        }
      }

      if (aliceSum > bobSum) {
        return 1;
      }
      if (aliceSum == bobSum) {
        return 0;
      }
      return -1;
    }
};

int main(int argc, char* argv[]) {
  Solution sl{};
  vector<int> aliceValues = {1, 3};
  vector<int> bobValues = {2, 1};
  int ans = sl.stoneGameVI(aliceValues, bobValues);
  cout << ans << endl;
}
