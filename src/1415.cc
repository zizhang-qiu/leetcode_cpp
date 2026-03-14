#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void Backtrack(int n, int k, string& path, int& count, string& result) {
    if (!result.empty()) {
      return;
    }

    if (static_cast<int>(path.size()) == n) {
      ++count;
      if (count == k) {
        result = path;
      }
      return;
    }

    for (char ch : {'a', 'b', 'c'}) {
      if (!path.empty() && path.back() == ch) {
        continue;
      }

      path.push_back(ch);
      Backtrack(n, k, path, count, result);
      path.pop_back();

      if (!result.empty()) {
        return;
      }
    }
  }

  string getHappyString(int n, int k) {
    string path;
    string result;
    int count = 0;
    Backtrack(n, k, path, count, result);
    return result;
  }
};

int main() {
    Solution s;
    int n = 3, k = 9;
    cout << s.getHappyString(n, k) << endl;
    return 0;
}