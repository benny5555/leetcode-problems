#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
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
};