#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        std::string ans = "";
        for (int i = 0; i < nums.size(); i++){
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};

int main(){
    Solution sol = Solution();
    vector<string> nums = {"01","10"};
    std::cout << sol.findDifferentBinaryString(nums) << std::endl;
    return 0;
}