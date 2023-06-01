#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *p1 = nullptr, *p2 = nullptr;
    for (auto p = head; p; p = p->next) {
      if (p2) p2 = p2->next;
      if (--k == 0) {
        p1 = p;
        p2 = head;
      }
    }
    swap(p1->val, p2->val);
    return head;
  }
};