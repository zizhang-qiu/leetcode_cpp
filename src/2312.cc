#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>


class Solution {
 public:
  long long sellingWood(int m, int n, std::vector<std::vector<int>>& prices) {
    auto pair_hash = [fn=std::hash<int>()](const std::pair<int, int>& p){
        return (fn(p.first) << 16) ^ fn(p.second);
    };

    std::unordered_map<std::pair<int, int>, int, decltype(pair_hash)> value(0, pair_hash);
    
    std::vector<std::vector<long long>> memo(m + 1, std::vector<long long>(n + 1, -1));

    std::function<long long(int, int)> dfs = [&](int x, int y) {
      if (memo[x][y] != -1) {
        return memo[x][y];
      }

      long long ret = value.count({x, y}) ? value[{x, y}] : 0;
      if (x > 1) {
        for (int i = 1; i < x; ++i) {
          ret = std::max(ret, dfs(i, y) + dfs(x - i, y));
        }
      }
      if (y > 1) {
        for (int j = 1; j < y; ++j) {
          ret = std::max(ret, dfs(x, j) + dfs(x, y - j));
        }
      }
      return memo[x][y] = ret;
    };

    for (int i=0; i<prices.size(); ++i){
        value[{prices[i][0], prices[i][1]}] = prices[i][2];
    }

    return dfs(m, n);
  }
};

int main(){
    
}