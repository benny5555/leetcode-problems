#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  bool isprime(int x) {
    if (x <= 3) return x > 1;
    if (x % 6 != 1 && x % 6 != 5) return false;
    int square = sqrt(x);
    for (int i = 5; i <= square; i += 6) {
      if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
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
  int primePalindrome(int n) {
    if (n <= 10) {
      for (int i = n; 1; ++i) {
        if (isprime(i)) return i;
      }
    }
    int digit = floor(log10(n)) + 1;
    bool odd = (digit & 1) ? true : false;
    string base = to_string(n);
    string half, one{"1"};
    for (int i = 0, pivot = odd ? digit / 2 + 1 : digit / 2; i < pivot; ++i) {
      half.push_back(base[i]);
    }
    while (1) {
      long long temp = stol(build(half, odd));
      int pre_size = half.size();
      if (temp >= n) {
        if (isprime(temp)) return temp;
      }
      half = move(add(half, one));
      if (half.size() != pre_size) {
        odd ^= 1;
        if (!odd) {
          half = move(string(pre_size, '0'));
          half[0] = '1';
        }
      }
    }
    return 0;
  }
};

int main() {
  Solution solution;
  cout << solution.primePalindrome(13);
  return 0;
}