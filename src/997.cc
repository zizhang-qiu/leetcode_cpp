#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    if(trust.empty() && n==1){
      return 1;
    }
    std::vector<std::vector<bool>> is_believed(n, std::vector<bool>(n, false));
    std::vector<bool> has_any_belief(n, false);
    for (const auto& t : trust) {
      has_any_belief[t[0] - 1] = true;
      is_believed[t[1] - 1][t[0] - 1] = true;
    }

    for (int i = 0; i < n; ++i) {
      is_believed[i][i] = true;
    }

    bool all_have_belief = true;
    for (const bool b : has_any_belief) {
      if (b) {
        all_have_belief = false;
        break;
      }
    }
    if (all_have_belief) {
      return -1;
    }

    for (int i = 1; i <= n; ++i) {
      auto is_this_person_believed = is_believed[i - 1];
      bool all_true = std::all_of(is_this_person_believed.begin(),
                                  is_this_person_believed.end(),
                                  [](const bool v) { return v; });
      if (all_true) {
        if (!has_any_belief[i - 1]) {
          return i;
        }
      }
    }

    return -1;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  int n = 1;
  vector<vector<int>> trust = {};
  int judge = sl.findJudge(n, trust);
  printf("%d", judge);
  return 0;
}
