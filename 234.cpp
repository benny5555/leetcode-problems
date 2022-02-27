#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  ListNode *myreverse(ListNode *head) {
    auto dummy = new ListNode(0, nullptr);
    ListNode *cur = head, *next;
    while (cur) {
      next = cur->next;
      cur->next = dummy->next;
      dummy->next = cur;
      cur = next;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }

 public:
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next) return true;
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    auto tail = myreverse(slow);
    while (head && tail) {
      if (head->val != tail->val) return false;
      head = head->next;
      tail = tail->next;
    }
    return true;
  }
};