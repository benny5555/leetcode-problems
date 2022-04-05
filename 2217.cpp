#include <bits/stdc++.h>

using namespace std;
class Solution {
 private:
  string build(const string& s, bool odd) {
    int n = s.size();
    n -= odd;
    string ans(s.begin(), s.end());
    for (int i = n - 1; i >= 0; --i) {
      ans.push_back(s[i]);
    }
    return ans;
  }

 public:
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    vector<long long> ans;
    int half = (intLength + 1) / 2;
    bool odd = intLength & 1;
    string mmin(half, '0'), mmax(half, '9');
    mmin[0] = '1';
    for (int num : queries) {
      string temp = to_string(stoll(mmin) + num - 1);
      if (temp.size() > mmax.size())
        ans.push_back(-1);
      else
        ans.push_back(stoll(build(temp, odd)));
    }
    return ans;
  }
};