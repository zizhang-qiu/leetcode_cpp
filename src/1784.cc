#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkOnesSegment(string s) { return s.find("01") == string::npos; }
};

int main() {
  Solution sol;
  string s = "110";
  cout << sol.checkOnesSegment(s) << endl;
  return 0;
}