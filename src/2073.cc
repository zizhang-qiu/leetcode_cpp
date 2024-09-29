#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int current_position = k;
    int num_steps = 0;
    while (current_position >= 0) {
      num_steps += 1;
      if (tickets[0] > 1) {
        std::rotate(tickets.begin(), tickets.begin() + 1, tickets.end());
        --tickets.back();
        if (current_position == 0) {
          current_position = tickets.size() - 1;
        } else {
          current_position -= 1;
        }
      } else {
        tickets.erase(tickets.begin());
        if (current_position == 0) {
          current_position = -1;
        } else {
          current_position -= 1;
        }
      }
    }
    return num_steps;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  vector tickets = {5, 1, 1, 1};
  int k = 0;
  Solution sl;
  int res = sl.timeRequiredToBuy(tickets, k);
  std::cout << res << std::endl;
  return 0;
}
