#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int prev = max(arr[0], arr[1]);
    if (k == 1) {
      return prev;
    }
    int consecutive = 1;
    int maxNum = prev;
    int length = arr.size();
    for (int i = 2; i < length; i++) {
      int curr = arr[i];
      if (prev > curr) {
        consecutive++;
        if (consecutive == k) {
          return prev;
        }
      } else {
        prev = curr;
        consecutive = 1;
      }
      maxNum = max(maxNum, curr);
    }
    return maxNum;
  }
};

int main(int argc, char** argv) {
  vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
  int k = 2;
  Solution sl{};
  int res = sl.getWinner(arr, k);
  cout << res << endl;
  return 0;
}