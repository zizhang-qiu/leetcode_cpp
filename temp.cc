//
// Created by qzz on 2024/1/15.
//
#include <iostream>
#include <vector>

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
    delete head;          // Free the memory for the original head
    head = newHead;       // Update the head to the new head
  }
}

int main() {
  std::vector<int> values = {1, 2, 3};
  ListNode* head = nullptr;

  // Creating the linked list
  ListNode* current = nullptr;
  for (int value : values) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
      head = newNode;
      current = newNode;
    } else {
      current->next = newNode;
      current = newNode;
    }
  }

  std::cout << "Original Linked List: ";
  printLinkedList(head);

  // Changing the head to the second node
  changeHead(head);

  std::cout << "Modified Linked List: ";
  printLinkedList(head);

  // Freeing the memory
  current = head;
  while (current != nullptr) {
    ListNode* temp = current;
    current = current->next;
    delete temp;
  }

  return 0;
}