//
// Created by qzz on 2024/2/7.
//
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    std::vector<TreeNode *> q = {root};
    // Root is always 0;
    root->val = 0;

    while (!q.empty()) {
      int layer_sum = 0;
      std::vector<TreeNode *> q2;
      // First loop, get the sum of layer.
      for (auto fa : q) {
        if (fa->left) {
          q2.push_back(fa->left);
          layer_sum += fa->left->val;
        }
        if (fa->right) {
          q2.push_back(fa->right);
          layer_sum += fa->right->val;
        }
      }

      // Second loop, replace the value by subtracting sum of child from sum of layer.
      for (auto fa : q) {
        const int child_sum = (fa->left ? fa->left->val : 0) + (fa->right ? fa->right->val : 0);

        if (fa->left) {
          fa->left->val = layer_sum - child_sum;
        }
        if (fa->right) {
          fa->right->val = layer_sum - child_sum;
        }
      }
      q = std::move(q2);
    }
    return root;
  }
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

int main() {
  std::vector<int> nums = {5, 4, 9, 1, 10, INT_MIN, 7};
  auto root = createTree(nums);
}
