#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool dfs(TreeNode* tree_node, ListNode* list_node) {
    if (list_node == NULL)
      return true;
    if(tree_node == NULL)
      return false;
    if(tree_node->val != list_node->val)
      return false;
    return dfs(tree_node->left, list_node->next) || dfs(tree_node->right, list_node->next);
  }

  bool isSubPath(ListNode* head, TreeNode* root) {
    if(root == NULL)
      return false;
    return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
