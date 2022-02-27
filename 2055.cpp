#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
//         vector<int> ind;
//         for (int i = 0; s[i]; ++i) {
//             if (s[i] == '|') ind.push_back(i);
//         }
//         int n = ind.size();
//         vector<int> ans;
//         for (auto &query : queries) {
//             auto start = lower_bound(ind.begin(), ind.end(), query[0]) - ind.begin();
//             if (start == n) {
//                 ans.push_back(0);
//                 continue;
//             }
//             auto end = upper_bound(ind.begin(), ind.end(), query[1]) - ind.begin();
//             if (end == 0) {
//                 ans.push_back(0);
//                 continue;
//             }
//             --end;
//             if (start >= end) {
//                 ans.push_back(0);
//                 continue;
//             }
//             ans.push_back(ind[end] - ind[start] + 1 - (end - start + 1));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        vector<int> ans;
        int n = s.size();
        vector<int> right(n), left(n), cnt(n);
        int candle = -1, c = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') candle = i, ++c;
            left[i] = candle;
            cnt[i] = c;
        }
        candle = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') candle = i;
            right[i] = candle;
        }
        for (auto &query : queries) {
            int start = right[query[0]];
            int end = left[query[1]];
            if (start == -1 || end == -1) {
                ans.push_back(0);
                continue;
            }
            ans.push_back(start < end ? end - start + 1 - (cnt[end] - cnt[start] + 1) : 0);
        }
        return ans;
    }
};
int main() {
    string s{"***|**|*****|**||**|*"};
    vector<vector<int>> queries{{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    Solution solution;
    for (auto num : solution.platesBetweenCandles(s, queries)) cout << num << " ";
    cout << endl;
    return 0;
}