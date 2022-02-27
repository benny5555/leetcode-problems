#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    auto dummy = new ListNode(0, head);
    auto pre = dummy, cur = head;
    while (cur) {
      if (cur->val == val) {
        pre->next = cur->next;
        delete cur;
        cur = pre->next;
      } else {
        pre = pre->next;
        cur = cur->next;
      }
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};