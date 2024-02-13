//
// Created by qzz on 2024/1/13.
//
#include <iostream>
#include <vector>
using namespace std;

void test_2_wei_bag_problems() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagweight = 4; // Max capacity of bag

  // dp vector.
  vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

  // initialize.
  for (int j = weight[0]; j <= bagweight; j++) {
    dp[0][j] = value[0];
  }

  for (int i = 1; i < weight.size(); i++) // iterate items
  {
    for (int j = 0; j <= bagweight; j++) // iterate bag capacity
    {
      if (j < weight[i]) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
  }

  cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
  test_2_wei_bag_problems();
  return 0;
}
