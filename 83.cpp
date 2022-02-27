#include <bits/stdc++.h>
using namespace std;
#include "leetcode.h"
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto p = head, q = head;
    while (q) {
      while (q && q->val == p->val) q = q->next;
      auto cur = p->next;
      p->next = q;
      p = q;
      while (cur != p) {
        auto del = cur;
        cur = cur->next;
        delete del;
      }
    }
    return head;
  }
};