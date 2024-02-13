//
// Created by qzz on 2024/1/20.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
      vector<string> ans;
      for (const auto& word : words) {
        const int n = static_cast<int>(word.size());
        if (n == 1 && word[0] != separator) {
          ans.push_back(word);
          continue;
        }
        int sep_idx = 0, last_sep_idx = 0;
        for (int i = 0; i < n; ++i) {
          if (word[i] == separator) {
            sep_idx = i;
            const auto sub_str = word.substr(last_sep_idx, sep_idx - last_sep_idx);
            if (!sub_str.empty())ans.push_back(sub_str);
            last_sep_idx = sep_idx + 1;
          }
        }

        if (sep_idx != n - 1) {
          const auto sub_str = word.substr(last_sep_idx, word.size() - last_sep_idx);
          if (!sub_str.empty())ans.push_back(sub_str);
        }
      }
      return ans;
    }
};

int main(int argc, char* argv[]) {
  Solution sl{};
  vector<string> words = {"b"};
  constexpr char separator = '|';
  auto ans = sl.splitWordsBySeparator(words, separator);
  for (const auto& a : ans) {
    std::cout << a << std::endl;
  }
}
