//
// Created by qzz on 2024/1/13.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Solution {
  public:
    string repeatLimitedString(const string& s, int repeatLimit) {
      constexpr int num_alpha = 26;
      std::array<int, num_alpha> count{};
      count.fill(0);
      for(const auto& c:s) {
        count[c-'a']++;
      }
      // for(int i=0; i<26; ++i) {
      //   std::cout << count[i] << ",";
      // }
      // std::cout << std::endl;
      std::string res{};
      int num_repeat = 0;
      for(int i = num_alpha-1, j =num_alpha-2; i>=0 && j >=0;) {
        if(count[i] == 0) {
          num_repeat = 0;
          --i;
        }else if (num_repeat < repeatLimit) {
          count[i]--;
          res.push_back('a'+i);
          ++num_repeat;
        }else if (j >=i || count[j] == 0) {
          --j;
        }else {
          count[j]--;
          res.push_back('a'+j);
          num_repeat = 0;
        }
      }
      return res;
    }



};

int main(int argc, char* argv[]) {
  string s;
  s = "cczazcc";
  s = "aababab";
  int repeatLimit = 2;
  Solution so;
  auto res = so.repeatLimitedString(s, repeatLimit);
  cout << res << endl;
}
