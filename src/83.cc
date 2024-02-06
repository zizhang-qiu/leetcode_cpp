//
// Created by qzz on 2024/1/14.
//
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {
  }

  ListNode(int x) : val(x), next(nullptr) {
  }

  ListNode(int x, ListNode* next) : val(x), next(next) {
  }
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr)return head;
      auto node = head;
      while (node->next != nullptr) {
        while (node->next != nullptr && node->next->val == node->val) {
          node->next = node->next->next;
        }
        if (node->next != nullptr)node = node->next;
      }
      return head;
    }
};

int main(int argc, char* argv[]) {
  return 0;
}

