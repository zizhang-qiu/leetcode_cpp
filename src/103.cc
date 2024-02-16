#include <queue>
#include <utility>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<vector<int>> res;
    bool from_left = true;
    deque<TreeNode *> q{};
    q.push_back(root);
    while (!q.empty()) {
      vector<int> level_res;
      deque<TreeNode *> q2{};
      while (!q.empty()) {
        auto node = q.front();
        q.pop_front();
        level_res.push_back(node->val);
        if (from_left) {
          if (node->left) {
            q2.push_front(node->left);
          }
          if (node->right) {
            q2.push_front(node->right);
          }
        } else {
          if (node->right) {
            q2.push_front(node->right);
          }
          if (node->left) {
            q2.push_front(node->left);
          }
        }
      }
      res.push_back(level_res);
      q = std::move(q2);
      from_left = !from_left;
    }
    return res;
  }
};

int main(){
    
}