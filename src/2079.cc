#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int wateringPlants(vector<int>& plants, int capacity) {
    int n = plants.size();
    int cur_plant = 0;
    int cur_capacity = capacity;
    int n_steps = 0;
    bool start = false;
    while(cur_plant < n){
        if (start) {
            n_steps += cur_plant;
        }
        if (cur_capacity >= plants[cur_plant]) {
            cur_capacity -= plants[cur_plant];
            cur_plant++;
            n_steps++;
            start = false;
        } else {
            n_steps += cur_plant;
            cur_capacity = capacity;
            start = true;
        }
    }
    return n_steps;
  }
};

int main(int argc, char** argv) {
    Solution sl;
    vector<int> plants = {2, 2, 3, 3};
    int capacity = 5;
    cout << sl.wateringPlants(plants, capacity) << endl;
    return 0;
}