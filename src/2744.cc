//
// Created by qzz on 2024/1/17.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int maximumNumberOfStringPairs(vector<string>& words) {
      if (words.empty())return 0;
      int res = 0;
      for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
          if (isStringPair(words[i], words[j])) ++res;
        }
      }
      return res;
    }

    bool isStringPair(const string& lhs, const string& rhs) {
      if (lhs.size() != rhs.size())return false;
      for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[rhs.size() - 1 - i])return false;
      }
      return true;
    }
};

int main() {
  Solution sl;
  // string s = "123";
  // bool is = sl.isStringPair(s, "321");
  // std::cout << is << std::endl;
  vector<string> words = {"cd", "ac", "dc", "ca", "zz"};
  int res = sl.maximumNumberOfStringPairs(words);
  cout << res << endl;
}
