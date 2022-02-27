#include "leetcode.h"
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     ListNode *sortLinkedList(ListNode *head) {
//         auto cur = head;
//         multimap<int, ListNode *> m;
//         while (cur) {
//             m.insert(make_pair(cur->val, cur));
//             cur = cur->next;
//         }
//         auto dummy = new ListNode(0, nullptr);
//         cur = dummy;
//         for (auto iter : m) {
//             cur->next = iter.second;
//             cur = cur->next;
//         }
//         cur->next = nullptr;
//         head = dummy->next;
//         delete dummy;
//         return head;
//     }
// };
class Solution {
public:
    ListNode *sortLinkedList(ListNode *head) {
        ListNode *cur = head, *pre = nullptr;
        while (cur) {
            if (cur->val < 0 && pre) {
                pre->next = cur->next;
                cur->next = head;
                head = cur;
                cur = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};