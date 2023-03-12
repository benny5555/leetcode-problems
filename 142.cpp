#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next || !head->next->next) return nullptr;
    auto slow = head, fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    if (slow != fast) return nullptr;
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};