#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    if (votes.size() == 1) {
      return votes[0];
    }

    const int num_teams = static_cast<int>(votes[0].size());
    std::unordered_map<char, std::vector<int>> counts;

    for (const std::string& str : votes) {
      for (size_t i = 0; i < str.size(); ++i) {
        char team = str.at(i);
        if (counts.find(team) == counts.end()) {
          counts[team] = std::vector<int>(num_teams, 0);
        }
        ++counts.at(team)[i];
      }
    }

    std::vector<std::pair<char, std::vector<int>>> my_map;
    for (const auto& p : counts) {
      my_map.push_back(p);
    }

    std::sort(my_map.begin(), my_map.end(),
              [](const std::pair<char, std::vector<int>>& a,
                 const std::pair<char, std::vector<int>>& b) {
                if (a.second == b.second) {
                  return a.first < b.first;
                }
                return a.second > b.second;
              });
    std::string ans;
    for(const auto& p: my_map){
      ans.push_back(p.first);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  std::vector<std::string> votes = {"WXYZ","XYZW"};
  Solution sl;
  auto ans = sl.rankTeams(votes);
  std::cout << ans << std::endl;
  return 0;
}
