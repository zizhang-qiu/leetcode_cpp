#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    using ll = long long;
    ll mod = 1e9 + 7;

    std::vector<std::vector<std::vector<ll>>> dp(
        zero + 1, std::vector<std::vector<ll>>(one + 1, std::vector<ll>(2)));

    for (int i = 0; i <= std::min(zero, limit); ++i) {
      dp[i][0][0] = 1;
    }

    for (int i = 0; i <= std::min(one, limit); ++i) {
      dp[0][i][1] = 1;
    }

    for (int i = 1; i <= zero; i++) {
      for (int j = 1; j <= one; j++) {
        if (i > limit) {
          dp[i][j][0] =
              dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
        } else {
          dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
        }
        dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
        if (j > limit) {
          dp[i][j][1] =
              dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
        } else {
          dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
        }
        dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
      }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % mod;
  }
};

int main() {
  Solution s;
  cout << s.numberOfStableArrays(1, 2, 1) << endl;
  return 0;
}