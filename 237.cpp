#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  void deleteNode(ListNode* node) {
    auto next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
  }
};