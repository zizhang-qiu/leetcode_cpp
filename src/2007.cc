#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    std::sort(changed.begin(), changed.end());
    std::vector<int> ans;
    std::unordered_map<int, int> count;
    for(const int a:changed){
        ++count[a];
    }

    for(const int a:changed){
        if (count[a] == 0) {
            continue;
        }
        --count[a];
        if (count[a*2]==0) {
            return {};
        }
        --count[a*2];
        ans.push_back(a);
    }

    return ans;
  }
};

int main(){
  vector changed = { 6, 3, 0, 1};
  auto ans = Solution{}.findOriginalArray(changed);
  for(const int num:ans){
    std::cout << num <<",";
  }
}