#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* CreateList(const std::vector<int>& vals) {
  ListNode dummy;
  ListNode* tail = &dummy;

  for (int num : vals) {
    tail->next = new ListNode(num);
    tail = tail->next;
  }

  return dummy.next;
}

void DeleteList(ListNode* head) {
  while (head != nullptr) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }
}

class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int pos = 0;
    if (head->next == nullptr) {
      return {-1, -1};
    }

    ListNode* prev = head;
    ListNode* node = head->next;
    std::vector<int> pos_vec;
    while (node->next != nullptr) {
      if ((node->val < prev->val && node->val < node->next->val) ||
          (node->val > prev->val && node->val > node->next->val)) {
        pos_vec.push_back(pos);
      }
      prev = node;
      node = node->next;
      ++pos;
    }
    if (pos_vec.size() < 2) {
      return {-1, -1};
    }

    int max_dist = pos_vec.back() - pos_vec[0];
    int min_dist = std::numeric_limits<int>::max();
    for (int i = 0; i < pos_vec.size() - 1; ++i) {
      min_dist = std::min(pos_vec[i + 1] - pos_vec[i], min_dist);
    }
    return {min_dist, max_dist};
  }
};

int main() {
    ListNode* head = CreateList({5, 3, 1 ,2 ,5, 1, 2});
    Solution sl;
    auto ans = sl.nodesBetweenCriticalPoints(head);
    std::cout << ans[0] << ", " << ans[1] << "\n";
    DeleteList(head);
}
