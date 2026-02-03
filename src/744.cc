#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    auto it = std::find_if(letters.begin(), letters.end(),
                           [target](char c) { return c > target; });
    return it == letters.end() ? letters[0] : *it;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<char> letters = {'c', 'f', 'j'};
  char target = 'a';
  cout << s.nextGreatestLetter(letters, target) << endl;
  return 0;
}
