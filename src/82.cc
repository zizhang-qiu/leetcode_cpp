//
// Created by qzz on 2024/1/15.
//

#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for singly-linked list.
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

ListNode* CreateList(const std::vector<int>& values) {
  ListNode* head = nullptr;
  ListNode* current = nullptr;

  for (const int value : values) {
    auto* new_node = new ListNode(value);

    if (head == nullptr) {
      // If the list is empty, set the new node as the head.
      head = new_node;
      current = new_node;
    }
    else {
      // Otherwise, append the new node to the end of the list.
      current->next = new_node;
      current = new_node;
    }
  }

  return head;
}

void PrintList(ListNode* head) {
  auto node = head;
  while (node != nullptr) {
    std::cout << node->val << ", ";
    node = node->next;
  }
  std::cout << std::endl;
}

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      std::unordered_map<int, bool> map;

      if (head == nullptr) return head;
      auto node = head;

      while (node != nullptr) {
        bool repeat = false;
        while (node->next != nullptr && node->next->val == node->val) {
          repeat = true;
          node->next = node->next->next;
        }
        if (repeat) {
          map[node->val] = true;
          if (node->next != nullptr) {
            node = node->next;
          }
          else {
            node = nullptr;
          }
        }
        else {
          map[node->val] = false;
          node->next == nullptr ? node = nullptr : node = node->next;
        }
      }

      auto n = head;
      while (n != nullptr) {
        while (n->next != nullptr && map[n->next->val]) {
          if (n->next->next != nullptr) {
            n->next = n->next->next;
          }
          else {
            n->next = nullptr;
          }
        }
        n = n->next;
      }
      if (map[head->val]) {
        if (head->next != nullptr) {
          ListNode* newHead = head->next;
          head->next = nullptr;
          delete head;
          head = newHead;
        }
        else {
          head = nullptr;
        }
      }
      return head;
    }
};

int main(int argc, char* argv[]) {
  std::vector values = {1, 1};
  auto head = CreateList(values);
  Solution s;
  head = s.deleteDuplicates(head);
  PrintList(head);
  return 0;
}
