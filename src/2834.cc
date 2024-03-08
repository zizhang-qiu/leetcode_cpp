#include <iostream>

class Solution {
public:
  using ll = long long;
  int minimumPossibleSum(ll n, ll target) {
    
    const int mod = 1e9 + 7;
    ll target_half = target / 2;
    if (n <= target_half) {
      return static_cast<ll>((1 + n) * n / 2 % mod);
    }
    return (static_cast<ll>((1 + target_half) * target_half / 2) +
            (static_cast<ll>(target) + target + (n - target_half) - 1) *
                (n - target_half) / 2) %
           mod;
  }
};

int main(int argc, char **argv) {
  Solution sl{};
  int ans = sl.minimumPossibleSum(2, 3);
  std::cout << ans << std::endl;
}