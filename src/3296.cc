#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        const int maxWorkerTimes = *max_element(workerTimes.begin(), workerTimes.end());
        ll left = 1, right = static_cast<ll>(maxWorkerTimes) * mountainHeight * (mountainHeight + 1) / 2;
        ll ans = 0;
        constexpr float eps = 1e-7;

        while (left <= right){
            ll mid = (left + right) / 2;
            ll cnt = 0;
            for (int t : workerTimes) {
                ll work = mid / t;
                ll k = (-1.0 + sqrt(1 + 8.0 * work)) / 2 + eps;
                cnt += k;
            }
            if (cnt >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> workerTimes = {2, 1, 1};
    int mountainHeight = 4;
    cout << s.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
    return 0;
}