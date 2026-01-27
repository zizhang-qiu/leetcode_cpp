#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(int n, vector<vector<int>>& edges) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, 2 * w);
    }

    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (u == n - 1) {
        return dist[u];
      }

      if (visited[u]) {
        continue;
      }

      visited[u] = true;

      for (const auto& [v, w] : graph[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  int n = 4;
  vector<vector<int>> edges = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
  std::cout << s.minCost(n, edges) << std::endl;
  return 0;
}
