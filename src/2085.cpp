#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;

class Solution {
  public:
    int countWords(vector<string>& words1, vector<string>& words2) {
      unordered_map<string, std::array<int, 2>> map{};
      for (const auto word : words1) {
        if (map.count(word)) {
          map[word][0]++;
        }
        else {
          std::array<int, 2> arr = {1, 0};
          map[word] = arr;
        }
      }
      for (const auto word : words2) {
        if (map.count(word)) {
          map[word][1]++;
        }
        else {
          std::array<int, 2> arr = {0, 1};
          map[word] = arr;
        }
      }

      int res{};
      for (const auto kv : map) {
        if (kv.second == std::array<int, 2>{1, 1}) {
          ++res;
        }
      }
      return res;
    }
};

int main() {
  Solution s{};
  vector<string> t1 = {"leetcode", "is", "amazing", "as", "is"};
  vector<string> t2 = {"amazing", "leetcode", "is"};
  vector<string> t3 = {"b", "bb", "bbb"};
  vector<string> t4 = {"a", "aa", "aaa"};
  vector<string> t5 = {"a", "ab"};
  vector<string> t6 = {"a", "a", "a", "ab"};
  int res = s.countWords(t5, t6);
  std::cout << res << std::endl;
  return 0;
}
