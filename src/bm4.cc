#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  struct ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* vectorToLinkedList(const std::vector<int>& vec) {
  // 创建一个虚拟头节点
  ListNode* dummyHead = new ListNode(0);
  ListNode* current = dummyHead;

  // 遍历vector，为每个元素创建一个新节点，连接到链表中
  for (int value : vec) {
    current->next = new ListNode(value);
    current = current->next;
  }

  // 保存实际的头节点，并释放虚拟头节点
  ListNode* result = dummyHead->next;
  delete dummyHead;

  return result;
}

void printLinkedList(ListNode* head) {
  ListNode* current = head;

  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }

  std::cout << std::endl;
}

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param pHead1 ListNode类
   * @param pHead2 ListNode类
   * @return ListNode类
   */
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    // write code here
    if (pHead1 == nullptr) {
      return pHead2;
    }
    if (pHead2 == nullptr) {
      return pHead1;
    }

    ListNode* ptr1 = pHead1;
    ListNode* ptr2 = pHead2;
    std::vector<int> sorted_val;
    while (ptr1!=nullptr) {
        sorted_val.push_back(ptr1->val);
        ptr1 = ptr1->next;
    }
    while (ptr2 != nullptr) {
      sorted_val.push_back(ptr2->val);
      ptr2 = ptr2->next;
    }
    std::sort(sorted_val.begin(), sorted_val.end());
    ListNode* new_head = vectorToLinkedList(sorted_val);
    return new_head;
  }
};

int main() {
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<int> nums2 = {3, 3, 3};
  auto head1 = vectorToLinkedList(nums1);
  auto head2 = vectorToLinkedList(nums2);
  Solution sl{};
  auto head = sl.Merge(head1, head2);
  printLinkedList(head);
}
