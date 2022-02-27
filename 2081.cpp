#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  string k_num(long long x, int k) {
    string ans;
    while (x) {
      ans.push_back(x % k + '0');
      x /= k;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  string k_num(const string &s, int k) {
    string ans;
    long long x = stoll(s);
    while (x) {
      ans.push_back(x % k);
      x /= k;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  bool ispalin(const string &s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }
  bool ispalin(long long x) {
    int ori = x, rev = 0;
    while (x) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    return ori == rev;
  }
  string build(const string &s, bool odd) {
    int n = s.size();
    if (odd) --n;
    string ans(s);
    for (int i = n - 1; i >= 0; --i) ans.push_back(ans[i]);
    return ans;
  }
  string add(const string &a, const string &b) {
    string ans;
    for (int i = a.size() - 1, j = b.size() - 1, flag = 0;
         i >= 0 || j >= 0 || flag; --i, --j) {
      int x = i >= 0 ? a[i] - '0' : 0, y = j >= 0 ? b[j] - '0' : 0;
      int temp = x + y + flag;
      if (temp > 9) {
        temp -= 10;
        flag = 1;
      } else
        flag = 0;
      ans.push_back(temp + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

 public:
  long long kMirror(int k, int n) {
    string half = "1", one = "1";
    bool odd = false;
    long long ans = 0;
    long long temp = 1;
    while (n && temp < 10) {
      string t = move(k_num(temp, k));
      if (ispalin(t)) ans += temp, --n;
      ++temp;
    }
    while (n) {
      string base = move(build(half, odd));
      if (ispalin(base) && ispalin(k_num(base, k))) {
        ans += stoll(base);
        --n;
      }
      int pre_size = half.size();
      half = move(add(half, one));
      if (half.size() != pre_size) {
        odd ^= 1;
        if (!odd) {
          half = move(string(pre_size, '0'));
          half[0] = '1';
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  cout << solution.kMirror(7, 17);
  return 0;
}