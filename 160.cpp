#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    auto p = headA, q = headB;
    while (p != q) {
      if (!p)
        p = headB;
      else
        p = p->next;
      if (!q)
        q = headA;
      else
        q = q->next;
    }
    if (!q || !p) return nullptr;
    return p;
  }
};