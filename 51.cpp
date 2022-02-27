#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<int> col, diag1, diag2;
    vector<vector<string>> ans;
    vector<int> queens;
    void dfs(int row, int n) {
        if (row == n) {
            vector<string> temp;
            for (int i = 0; i < n; ++i) {
                string line(n, '.');
                line[queens[i]] = 'Q';
                temp.push_back(line);
            }
            ans.push_back(temp);
        } else {
            for (int i = 0; i < n; ++i) {
                int cur_diag1 = i - row, cur_diag2 = i + row;
                if (col.count(i) || diag1.count(cur_diag1) || diag2.count(cur_diag2)) continue;
                queens[row] = i;
                col.insert(i);
                diag1.insert(cur_diag1);
                diag2.insert(cur_diag2);
                dfs(row + 1, n);
                diag2.erase(cur_diag2);
                diag1.erase(cur_diag1);
                col.erase(i);
                queens[row] = -1;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        queens = vector<int>(n, -1);
        dfs(0, n);
        return ans;
    }
};