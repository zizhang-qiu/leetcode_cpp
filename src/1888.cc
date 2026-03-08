#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


class Solution {
public:

    int minFlips(string s) {
        int n = s.size();
        std::string s2 = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = n;

        int left = 0;

        for (int right = 0; right < 2 * n; right++){
            char expect1 = (right % 2) ? '1': '0'; // 010101
            char expect2 = (right % 2) ? '0': '1'; // 101010
            
        }

        
    }
};

int main(){
    
}