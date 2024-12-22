#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        std::vector<int> nums(hi - lo + 1, 0);
        for(int i=0; i<hi-lo+ 1; ++i){
            nums[i] = lo + i;
        }

        auto get_weight = [](int num){
            int cnt = 0;
            while(num!=1){
                if(num%2 == 0){
                    num /= 2;
                }else{
                    num = 3 * num + 1;
                }
                ++cnt;
            }
            return cnt;
        };

        std::sort(nums.begin(), nums.end(),
        [get_weight](int a, int b){
            int a_weight = get_weight(a);
            int b_weight = get_weight(b);
            if (a_weight == b_weight){
                return a < b;
            }
            return a_weight < b_weight;
        });

        return nums[k - 1];
    }
};

int main(int argc, char const *argv[]){
    /* code */
    Solution sl;
    int ans = sl.getKth(7, 11, 4);
    std::cout << ans << std::endl;
    return 0;
}
