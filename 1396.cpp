#include <bits/stdc++.h>
using namespace std;
class UndergroundSystem {
  unordered_map<int, pair<string, int>> in;
  unordered_map<string, pair<double, int>> route;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    in[id] = make_pair(stationName, t);
  }

  void checkOut(int id, string stationName, int t) {
    string route_name = in[id].first + "-" + stationName;
    route[route_name].first += t - in[id].second;
    route[route_name].second++;
    in.erase(id);
  }

  double getAverageTime(string startStation, string endStation) {
    string route_name = startStation + "-" + endStation;
    return route[route_name].first / route[route_name].second;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */