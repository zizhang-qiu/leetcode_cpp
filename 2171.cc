//
// Created by qzz on 2024/1/18.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

class Solution {
  public:
    long long minimumRemoval(vector<int>& beans) {
      if (beans.size() == 1)return 0;
      int n = beans.size();
      std::sort(beans.begin(), beans.end());
      vector<ll> suffix_sums(n + 1);
      ll suf_sum = 0;
      for (int i = n - 1; i >= 0; --i) {
        suf_sum += beans[i];
        suffix_sums[i] = suf_sum;
      }
      ll ans = suffix_sums[0];
      ll pre_sum = 0;
      for (int i = 0; i < n; ++i) {
        ans = min(ans, pre_sum + suffix_sums[i + 1] - (ll)beans[i] * (n - i - 1));
        pre_sum += beans[i];
      }
      return ans;
    }
};

int main() {
  vector beans = {4, 1, 6, 5}; // {1, 4, 5, 6}
  Solution sl;
  auto ans = sl.minimumRemoval(beans);
  cout << ans << endl;
}
