#include <bits/stdc++.h>
using namespace std;
class Encrypter {
 private:
  unordered_map<char, string> enc;
  unordered_map<string, int> cnt;

 public:
  Encrypter(vector<char>& keys, vector<string>& values,
            vector<string>& dictionary) {
    for (int i = 0; i < keys.size(); ++i) {
      enc[keys[i]] = values[i];
    }
    for (auto& word : dictionary) {
      ++cnt[encrypt(word)];
    }
  }

  string encrypt(string word1) {
    string ans;
    for (auto c : word1) {
      if (!enc.count(c)) return "";
      ans += enc[c];
    }
    return ans;
  }

  int decrypt(string word2) { return cnt[word2]; }
};