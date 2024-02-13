#include <algorithm>
#include <functional>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void dfs(TreeNode *node, map<int, std::vector<pair<int, int>>> &map, int col,
           int row) {
    if (node->left) {
      dfs(node->left, map, col - 1, row + 1);
    }
    if (node->right) {
      dfs(node->right, map, col + 1, row + 1);
    }
    if (!map.count(col)) {
      map[col] = {{node->val, row}};
    } else {
      map[col].push_back({node->val, row});
    }
  }
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    // col, [val, row]
    map<int, std::vector<pair<int, int>>> m{};
    dfs(root, m, 0, 0);
    std::vector<std::vector<int>> ans{};
    for (auto [row, nodes] : m) {
      vector<int> temp;
      map<int, std::vector<int>> temp_map{};
      for (const auto p : nodes) {
        if(!temp_map.count(p.second)){
            temp_map[p.second] = {p.first};
        }else{
            temp_map[p.second].push_back(p.first);
        }
      }
      for(auto kv:temp_map){
        auto temp_vec = kv.second;
        std::sort(temp_vec.begin(), temp_vec.end(), std::less<>());
        temp.insert(temp.end(), temp_vec.begin(), temp_vec.end());
      }

      ans.push_back(temp);
    }
    return ans;
  }
};

int main(){

}