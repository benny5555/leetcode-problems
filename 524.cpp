#include <bits/stdc++.h>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string ans;
        vector<int> len(26);
        vector<vector<pair<char *, string *>>> roll(26, vector<pair<char *, string *>>(dictionary.size()));
        for (int i = 0; i < dictionary.size(); ++i) {
            int ind = dictionary[i][0] - 'a';
            roll[ind][len[ind]].first = &dictionary[i][0];
            roll[ind][len[ind]++].second = &dictionary[i];
        }
        for (auto c : s) {
            c -= 'a';
            int size = len[c];
            len[c] = 0;
            for (int i = 0; i < size; ++i) {
                auto *next = roll[c][i].first + 1;
                cout << *next << endl;
                string *temp = roll[c][i].second;
                if (*next == 0) {
                    if (temp->size() > ans.size()) ans = *temp;
                    if (temp->size() == ans.size() && *temp < ans) ans = *temp;
                } else {
                    int ind = *next - 'a';
                    roll[ind][len[ind]].first = next;
                    roll[ind][len[ind]++].second = temp;
                }
            }
        }
        return ans;
    }
};

int main() {
    string s{"abpcplea"};
    vector<string> dictionary{"ale", "apple", "monkey", "plea"};
    Solution solution;
    cout << solution.findLongestWord(s, dictionary) << endl;
    return 0;
}