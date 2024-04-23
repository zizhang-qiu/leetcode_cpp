#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    const int n = static_cast<int>(customers.size());
    int sum = 0;
    for(int i=0; i< n; ++i){
        sum += customers[i] * (1 - grumpy[i]);
    }

    int cur_value = 0;
    for( int i=0; i< minutes; ++i){
        cur_value += customers[i] * grumpy[i];
    }

    int res_value = cur_value;

    for(int i=minutes; i< n; ++ i){
        cur_value += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
        res_value = std::max(res_value, cur_value);
    }

    return sum + res_value;
  }
};

int main(int argc, char** argv) {
    Solution sl;
    std::vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    std::vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    int res = sl.maxSatisfied(customers, grumpy, minutes);
    std::cout << res;
}