#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }

    vector<int> degree(n, 0);
    unordered_map<int, vector<int>> m;
    vector<int> res;
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i][0];
      int v = edges[i][1];
      degree[u]++;
      degree[v]++;
      m[u].push_back(v);
      m[v].push_back(u);
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      res.clear();
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        int t = q.front();
        q.pop();
        res.push_back(t);
        degree[t]--;
        for (auto j : m[t]) {
          degree[j]--;
          if (degree[j] == 1) {
            q.push(j);
          }
        }
      }
    }

    return res;
  }
};

int main() {
  int n = 4;
  vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
  Solution sl{};
  auto res = sl.findMinHeightTrees(n, edges);
  for(const int r:res){
    std::cout << r << std::endl;
  }
}