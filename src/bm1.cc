
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *ReverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *newhead = ReverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
  }
};

ListNode *vectorToLinkedList(const std::vector<int> &vec) {
  // 创建一个虚拟头节点
  ListNode *dummyHead = new ListNode(0);
  ListNode *current = dummyHead;

  // 遍历vector，为每个元素创建一个新节点，连接到链表中
  for (int value : vec) {
    current->next = new ListNode(value);
    current = current->next;
  }

  // 保存实际的头节点，并释放虚拟头节点
  ListNode *result = dummyHead->next;
  delete dummyHead;

  return result;
}

void printLinkedList(ListNode *head) {
  ListNode *current = head;

  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }

  std::cout << std::endl;
}

int main(){
    std::vector<int> nums = {1,2,3, 4, 5};
    auto head = vectorToLinkedList(nums);
    printLinkedList(head);
    Solution sl{};
    head = sl.ReverseList(head);
    printLinkedList(head);
}
