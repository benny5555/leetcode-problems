#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        auto dummy = new ListNode();
        auto head = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        while (list1) {
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        while (list2) {
            head->next = list2;
            list2 = list2->next;
            head = head->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};