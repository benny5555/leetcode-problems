#include <bits/stdc++.h>
using namespace std;
class Bitset {
 public:
  string bit = "";
  string rev = "";
  int count1 = 0;
  int flipp = 0;
  int n;

  Bitset(int size) {
    for (int i = 0; i < size; i++) {
      bit += '0';
      rev += '1';
    }
    n = size;
  }

  void fix(int idx) {
    if (flipp % 2 == 0) {
      if (bit[idx] == '0') count1++;
      bit[idx] = '1';
      rev[idx] = '0';
    } else {
      if (bit[idx] == '1') count1--;
      bit[idx] = '0';
      rev[idx] = '1';
    }
  }

  void unfix(int idx) {
    if (flipp % 2 == 0) {
      if (bit[idx] == '1') count1--;
      bit[idx] = '0';
      rev[idx] = '1';
    } else {
      if (bit[idx] == '0') count1++;
      bit[idx] = '1';
      rev[idx] = '0';
    }
  }

  void flip() { flipp++; }

  bool all() {
    if (flipp % 2) {
      if (n - count1 == bit.size()) return true;
      return false;
    } else {
      if (count1 == rev.size()) return true;
      return false;
    }
  }

  bool one() {
    if (flipp % 2) {
      if (n - count1) return true;
    } else {
      if (count1) return true;
    }
    return false;
  }

  int count() {
    if (flipp % 2) return n - count1;
    return count1;
  }

  string toString() { return flipp % 2 ? rev : bit; }
};
/*
class Bitset {
public:
    string bit = "";
    string rev = "";
    int count1 = 0;
    int flipp = 0;
    int n;

    Bitset(int size) {
        for(int i=0; i<size; i++) {
            bit += '0';
            rev += '1';
        }
        n = size;
    }

    void fix(int idx) {
        if(flipp%2==0) {
            if(bit[idx] == '0') count1++;
            bit[idx] = '1';
            rev[idx] = '0';
        } else {
            if(bit[idx] == '1') count1--;
            bit[idx] = '0';
            rev[idx] = '1';
        }
    }

    void unfix(int idx) {
        if(flipp%2==0)
        {
            if(bit[idx] == '1') count1--;
            bit[idx] = '0';
            rev[idx] = '1';
        } else {
            if(bit[idx] == '0') count1++;
            bit[idx] = '1';
            rev[idx] = '0';
        }
    }

    void flip() {
        flipp++;
    }

    bool all() {
        if(flipp%2){
            if(n - count1 == bit.size()) return true;
                return false;
        } else {
            if(count1 == rev.size()) return true;
                return false;
        }
    }

    bool one() {
        if(flipp%2){
            if(n-count1) return true;
        }
        else
        {
            if(count1) return true;
        }
        return false;
    }

    int count() {
        if(flipp%2) return n-count1;
        return count1;
    }

    string toString() {
        return flipp%2 ? rev : bit;
    }
};
*/