#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;
// class Solution {
// public:
//     int rob(TreeNode *root) {
//         if (!root) return 0;
//         int money = root->val;
//         if (root->left) {
//             money += rob(root->left->left) + rob(root->left->right);
//         }
//         if (root->right) {
//             money += rob(root->right->left) + rob(root->right->right);
//         }
//         return max(money, rob(root->left) + rob(root->right));
//     }
// };
// class Solution {
// private:
//     unordered_map<TreeNode *, int> memo;

// public:
//     int rob(TreeNode *root) {
//         if (!root) return 0;
//         if (memo.count(root)) return memo[root];
//         int money = root->val;
//         if (root->left) {
//             money += rob(root->left->left) + rob(root->left->right);
//         }
//         if (root->right) {
//             money += rob(root->right->left) + rob(root->right->right);
//         }
//         return memo[root] = max(money, rob(root->left) + rob(root->right));
//     }
// };

class Solution {
private:
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        pair<int, int> ans;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans.first = max(left.first, left.second) + max(right.first, right.second);
        ans.second = root->val + left.first + right.first;
        return ans;
    }

public:
    int rob(TreeNode *root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};