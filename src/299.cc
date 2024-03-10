#include <iostream>

#include <array>
#include <string>
#include <unordered_map>


using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    int a = 0, b = 0;
    std::array<int, 10> map = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<int> non_match_indices;
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++a;
      } else {
        map[secret[i] - '0']++;
        non_match_indices.push_back(i);
      }
    }
    for (const int idx : non_match_indices) {
      auto cur_char = guess[idx];
      if (map[cur_char - '0'] > 0) {
        map[cur_char - '0']--;
        ++b;
      }
    }
    string ans = std::to_string(a) + "A" + std::to_string(b) + "B";
    return ans;
  }
};

int main(int argc, char** argv) {
  string secret = "1123";
  string guess = "0111";
  Solution sl{};
  auto ans = sl.getHint(secret, guess);
  cout << ans << endl;
}