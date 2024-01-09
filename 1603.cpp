#include <bits/stdc++.h>
using namespace std;
class ParkingSystem {
  int ceiling[4]{}, now[4]{};

 public:
  ParkingSystem(int big, int medium, int small) {
    ceiling[1] = big;
    ceiling[2] = medium;
    ceiling[3] = small;
  }

  bool addCar(int carType) {
    if (++now[carType] > ceiling[carType]) {
      return false;
    }
    return true;
  }
};