#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
// class Solution {
//   ListNode* merge(vector<ListNode*> lists, int l, int r) {
//     if (l == r) return lists[l];
//     if (l > r) return nullptr;
//     int mid = (l + r) / 2;
//     return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
//   }
//   ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
//     auto dummy = new ListNode(), cur = dummy, cur1 = head1, cur2 = head2;
//     while (cur1 && cur2) {
//       if (cur1->val <= cur2->val) {
//         cur->next = cur1;
//         cur1 = cur1->next;
//       } else {
//         cur->next = cur2;
//         cur2 = cur2->next;
//       }
//       cur = cur->next;
//     }
//     if (cur1) {
//       cur->next = cur1;
//     } else if (cur2) {
//       cur->next = cur2;
//     }
//     return dummy->next;
//   }

//  public:
//   ListNode* mergeKLists(vector<ListNode*>& lists) {
//     return merge(lists, 0, lists.size() - 1);
//   }
// };
class Solution {
  struct node {
    int val;
    ListNode* p;
    bool operator>(const node& b) const { return val > b.val; }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<node, vector<node>, greater<node>> pq;
    for (auto l : lists) {
      if (l) {
        pq.push({l->val, l});
      }
    }
    auto dummy = new ListNode(), cur = dummy;
    while (pq.size()) {
      auto temp = pq.top();
      pq.pop();
      cur->next = temp.p;
      cur = cur->next;
      if (temp.p->next) {
        pq.push({temp.p->next->val, temp.p->next});
      }
    }
    return dummy->next;
  }
};