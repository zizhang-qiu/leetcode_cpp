//
// Created by qzz on 2024/1/15.
//
#include <iostream>
#include <numeric>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
  ListNode* current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

// Function to modify the head of the linked list
void changeHead(ListNode*& head) {
  if (head != nullptr && head->next != nullptr) {
    ListNode* newHead = head->next;
    head->next = nullptr;  // Disconnect the original head
    delete head;           // Free the memory for the original head
    head = newHead;        // Update the head to the new head
  }
}

int main() {
  std::vector nums = {56, 67, 18, 81, 95, 41, 39, 56, 63, 70, 56, 31, 84,
                      46, 28, 38, 27, 56, 13, 10, 58, 16, 85, 21, 63, 8};
  std::cout << std::accumulate(nums.begin(), nums.end(), 0);

  return 0;
}