#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    auto dummy = new ListNode(-1, head);
    auto cur = dummy;
    while (cur->next && cur->next->next) {
      auto first = cur->next, second = cur->next->next;
      first->next = second->next;
      second->next = first;
      cur->next = second;
      cur = cur->next->next;
    }
    return dummy->next;
  }
};