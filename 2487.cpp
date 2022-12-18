#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    // stack<ListNode*> stk;
    // auto dummyHead = new ListNode(INT_MAX);
    // stk.push(dummyHead);
    // for (auto p = head; p; p = p->next) {
    //   while (stk.size() && stk.top()->val < p->val) {
    //     stk.pop();
    //   }
    //   stk.top()->next = p;
    //   stk.push(p);
    // }
    // return dummyHead->next;
    if (!head) return nullptr;
    head->next = removeNodes(head->next);
    return head->next && head->val < head->next->val ? head->next : head;
  }
};