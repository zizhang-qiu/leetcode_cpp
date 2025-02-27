#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.empty()) {
      return {};
    }
    std::vector<std::vector<std::string>> res;
    auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
      return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
        return (acc << 1) ^ fn(num);
      });
    };

    std::unordered_map<std::array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);

    for (const auto& str : strs) {
      std::array<int, 26> m{};
      for (const auto& c : str) {
        ++m[c - 'a'];
      }
      mp[m].push_back(str);
    }

    for(const auto& kv: mp) {
      res.push_back(kv.second);
    }

    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto res = s.groupAnagrams(strs);
  for (const auto& v : res) {
    for (const auto& str : v) {
      cout << str << " ";
    }
    cout << endl;
  }
  return 0;
}
