#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head || !head->next || !head->next->next) return false;
    auto slow = head, fast = head;
    do {
      slow = slow->next;
      fast = fast->next->next;
      if (!fast || !fast->next) return false;
    } while (slow != fast);
    return true;
  }
};