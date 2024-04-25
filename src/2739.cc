// author: qzz
// contact: q873264077@gmail.com
// file: 2739.cc
// time: 2024/04/25 10:56



#include <iostream>

class Solution {
 public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int dist = 0;
    int used_tank = 0;
    while (mainTank > 0) {
        --mainTank;
        dist += 10;
        ++used_tank;
        if(used_tank == 5){
            if (additionalTank > 0) {
                --additionalTank;
                ++mainTank;
                used_tank = 0;
            }
        }
    }
    return dist;
  }
};

int main(int argc, char** argv) {
    Solution sl;
    int res = sl.distanceTraveled(1, 2);
    std::cout << res;
    return 0;
}