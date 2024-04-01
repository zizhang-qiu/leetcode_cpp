#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string finalString(string s) {
    std::string ans{};
    int num_consecutive_i = 0;
    for (const char c : s) {
      if (c != 'i') {
        if (num_consecutive_i % 2 == 1) {
          std::reverse(ans.begin(), ans.end());
        }
        num_consecutive_i=0;
         ans.push_back(c);
      } else {
        num_consecutive_i++;
      }
    }
    if (num_consecutive_i % 2 == 1) {
      std::reverse(ans.begin(), ans.end());
    }
    return ans;
  }
  
};

int main(int argc, char** argv) {
  Solution sl{};
  auto ans = sl.finalString("poiinter");
  std::cout << ans << std::endl;
}