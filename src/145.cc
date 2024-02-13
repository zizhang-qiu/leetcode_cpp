//
// Created by qzz on 2024/2/12.
//
#include <vector>

using namespace std;
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
  void dfs(TreeNode* node, vector<int>& ans){
    if (node->left){
      dfs(node->left, ans);
    }
    if (node->right){
      dfs(node->right, ans);
    }
    ans.push_back(node->val);
  }
  vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> ans{};
    dfs(root, ans);
    return ans;
  }
};

int main(){
  
}