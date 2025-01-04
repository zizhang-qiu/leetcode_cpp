#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class MyCalendarThree {
 public:
  MyCalendarThree() {}

  int book(int start, int end) {
    int ans = 0;
    int maxBook = 0;
    cnt[start]++;
    cnt[end]--;
    for (auto& [_, freq] : cnt) {
      maxBook += freq;
      ans = max(maxBook, ans);
    }
    return ans;
  }

 private:
  std::map<int, int> cnt;
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
