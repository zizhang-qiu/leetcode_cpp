//
// Created by qzz on 2024/2/8.
//
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(const std::vector<int> &values) {
  if (values.empty()) {
    return nullptr;
  }

  auto root = new TreeNode(values[0]);
  std::queue<TreeNode *> nodes;
  nodes.push(root);

  size_t i = 1;
  while (!nodes.empty() && i < values.size()) {
    TreeNode *current = nodes.front();
    nodes.pop();

    if (i < values.size() && values[i] != INT_MIN) {
      current->left = new TreeNode(values[i]);
      nodes.push(current->left);
    }
    ++i;

    if (i < values.size() && values[i] != INT_MIN) {
      current->right = new TreeNode(values[i]);
      nodes.push(current->right);
    }
    ++i;
  }

  return root;
}

class Solution {
 public:
  bool isCousins(TreeNode *root, int x, int y) {
    std::vector<TreeNode *> q = {root};
    int layer = 1;
    // val, (father, layer)
    std::unordered_map<int, std::pair<int, int>> map;
    map[root->val] = {-1, 0};
    while (!q.empty()) {
      std::vector<TreeNode *> q2;
      for (auto fa : q) {
        if (fa->left) {
          q2.push_back(fa->left);
          map[fa->left->val] = {fa->val, layer};
        }
        if (fa->right) {
          q2.push_back(fa->right);
          map[fa->right->val] = {fa->val, layer};
        }
      }
      if (map.count(x) && map.count(y)) {
        break;
      }
      q = std::move(q2);
      ++layer;
    }
    auto [x_father, x_layer] = map.at(x);
    auto [y_father, y_layer] = map.at(y);
    return x_father != y_father && x_layer == y_layer;
  }
};

int main() {
  auto root = createTree({1, 2, 3, INT_MIN, 4, INT_MIN, 5});
  Solution sl{};
  bool ans = sl.isCousins(root, 5, 4);
  std::cout << ans << std::endl;
}