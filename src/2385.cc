#include <iostream>
#include <queue>
#include <unordered_map>
#include<vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* CreateTree(const std::vector<int>& values){
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> node_queue;
    node_queue.push(root);

    for (int i=1; i<values.size(); i+=2) {
        TreeNode* parent = node_queue.front();
        node_queue.pop();

        if (values[i] != -1) {
            parent -> left = new TreeNode(values[i]);
            node_queue.push(parent->left);
        }

        if (i + 1 < values.size() && values[i+1] != -1) {
            parent->right = new TreeNode(values[i + 1]);
            node_queue.push(parent->right);
        }
    }
    return root;
}

void levelOrderTraversal(TreeNode* root) {
  if (root == nullptr)
    return;

  std::queue<TreeNode*> nodeQueue;
  nodeQueue.push(root);

  while (!nodeQueue.empty()) {
    TreeNode* node = nodeQueue.front();
    nodeQueue.pop();
    std::cout << node->val << " ";

    if (node->left != nullptr)
      nodeQueue.push(node->left);
    if (node->right != nullptr)
      nodeQueue.push(node->right);
  }
}

class Solution {
 public:
  int amountOfTime(TreeNode* root, int start) {
    std::unordered_map<TreeNode*, std::vector<TreeNode*>> edges;

    TreeNode* s = nullptr;

    // Find all edges
    std::queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()){
        TreeNode* node = queue.front();
        queue.pop();

        if (node->val == start) {
            s = node;
        }

        if (node->left) {
            edges[node].push_back(node->left);
            edges[node->left].push_back(node);
            queue.push(node->left);
        }

        if (node->right) {
            edges[node].push_back(node->right);
            edges[node->right].push_back(node);
            queue.push(node->right);
        }
    }

    // BFS
    std::queue<TreeNode*> q;
    q.push(s);
    std::unordered_map<TreeNode*, int> used;
    used[s] = 1;

    int t = 0;
    std::queue<TreeNode*> q2;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        bool not_empty = false;
        // Find all nodes next to node.
        if (!edges[node].empty()) {
          for (const auto& n : edges[node]) {
            if (!used[n]) {
              q2.push(n);
              used[n] = 1;
              not_empty = true;
            }
          }
        }

        if (q.empty()) {
            if (!q2.empty()) {
                ++t;
                q = q2;
                q2 = std::queue<TreeNode*>();
            }
        }
    }
    return t;
  }
};

int main(){
  std::vector<int> nums = { 1, 2, -1, 3, -1, 4, -1, 5};
  auto root = CreateTree(nums);


  Solution sl;
  int res = sl.amountOfTime(root, 3);
  std::cout << res;
}