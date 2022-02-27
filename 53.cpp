#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int maxSubArray(vector<int> &nums) {
//         int temp = 0;
//         int ans = INT_MIN;
//         for (int num : nums) {
//             temp = max(temp + num, num);
//             ans = max(temp, ans);
//         }
//         return ans;
//     }
// };
class Solution {
private:
    struct node {
        int left_sum, right_sum, range_sum, max_sum;
        node(int a, int b, int c, int d) :
            left_sum(a), right_sum(b), range_sum(c), max_sum(d) {
        }
    };
    node up_sum(node &l, node &r) {
        int range = l.range_sum + r.range_sum,
            left = max(l.left_sum, l.range_sum + r.left_sum),
            right = max(r.right_sum, r.range_sum + l.right_sum),
            mmax = max(max(l.max_sum, r.max_sum), l.right_sum + r.left_sum);
        return node(left, right, range, mmax);
    }
    node build(vector<int> &arr, int l, int r) {
        if (l == r) return node(arr[l], arr[l], arr[l], arr[l]);
        int mid = (l + r) / 2;
        auto left = build(arr, l, mid), right = build(arr, mid + 1, r);
        return up_sum(left, right);
    }

public:
    int maxSubArray(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1).max_sum;
    }
};