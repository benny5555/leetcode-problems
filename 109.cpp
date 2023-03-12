#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  ListNode* mid(ListNode* head, ListNode* end) {
    auto slow = head, fast = head;
    for (; fast->next != end && fast->next->next != end;
         fast = fast->next->next, slow = slow->next) {
    }
    return slow;
  }

 public:
  TreeNode* sortedListToBST(ListNode* left, ListNode* right = nullptr) {
    if (left == right) {
      return nullptr;
    }
    auto m = mid(left, right);
    auto root = new TreeNode(m->val);
    root->left = sortedListToBST(left, m);
    root->right = sortedListToBST(m->next, right);
    return root;
  }
};