#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <deque>
#include <bitset>
#include <queue>
#include <sstream>
//#include<format>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() :
        val(0), next(nullptr) {
    }
    ListNode(int x) :
        val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) :
        val(x), next(next) {
    }
};