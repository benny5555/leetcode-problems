#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    auto dummy = new ListNode(0);
    auto cur1 = head->next, cur2 = dummy;
    int temp = 0;
    while (cur1) {
      if (cur1->val == 0) {
        cur2->next = new ListNode(temp);
        temp = 0;
        cur2 = cur2->next;
      } else {
        temp += cur1->val;
      }
      cur1 = cur1->next;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};