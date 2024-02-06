//
// Created by qzz on 2024/1/12.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
      if (num1 == "0" || num2 == "0")return "0";
      const size_t num1_size = num1.size();
      const size_t num2_size = num2.size();
      std::string ans{};
      for (int i = num1_size - 1; i >= 0; --i) {
        int curr_num = num1[i] - '0';
        for (int j = num2_size - 1; j >= 0; --j) {
          int prod = curr_num * (num2[j] - '0');
          string prod_str = std::to_string(prod);
          for (int k = 0; k < (num1_size - 1 - i + num2_size - 1 - j); ++k) {
            prod_str.push_back('0');
          }
          ans = addStrings(ans, prod_str);
        }
      }

      return ans;
    }

    string addStrings(string num1, string num2) {
      const size_t num1_size = num1.size();
      const size_t num2_size = num2.size();
      string ans{};
      int i = num1_size - 1, j = num2_size - 1, add = 0;
      while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int sum = x + y + add;
        ans.push_back(sum % 10 + '0');
        add = sum / 10;
        --i;
        --j;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};

int main(int argc, char* argv[]) {
  string num1, num2;
  num1 = "2", num2 = "3";
  num1 = "123", num2 = "456";
  Solution s{};
  auto m = s.multiply(num1, num2);
  cout << m << endl;
  auto ans = s.addStrings(num1, num2);
  cout << ans << endl;
}
