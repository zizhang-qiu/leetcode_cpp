#include <algorithm>
#include <map>
#include <queue>
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<TreeNode *> q{};
    vector<vector<int>> ans;
    map<int, vector<int>> m;
    m[0] = {root->val};
    q.push_back(root);
    int level = 0;
    while (!q.empty()) {
      vector<TreeNode *> new_q;
      for (const auto node : q) {
        if (node->left) {
          if (m.count(level + 1)) {
            m[level + 1].push_back(node->left->val);
          } else {
            m[level + 1] = {node->left->val};
          }
          new_q.push_back(node->left);
        }
        if (node->right) {
          if (m.count(level + 1)) {
            m[level + 1].push_back(node->right->val);
          } else {
            m[level + 1] = {node->right->val};
          }
          new_q.push_back(node->right);
        }
      }
      q = std::move(new_q);
      ++level;
    }
    for (const auto &kv : m) {
      ans.push_back(kv.second);
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {}