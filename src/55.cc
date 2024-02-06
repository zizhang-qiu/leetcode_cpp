//
// Created by qzz on 2024/1/17.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canJump(vector<int>& nums) {
      const int size = nums.size();
      int rightmost = 0;
      for (int i = 0; i < size; ++i) {
        if (i <= rightmost) {
          rightmost = max(rightmost, i + nums[i]);
          if (rightmost >= size - 1)return true;
        }
      }
      return false;
    }
};

int main(int argc, char* argv[]) {

}

