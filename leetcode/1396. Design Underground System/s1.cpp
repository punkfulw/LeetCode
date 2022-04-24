// OJ: https://leetcode.com/problems/design-underground-system/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(N)
class UndergroundSystem {
public:
    map<pair<string, string>, vector<int>> time;
    map<int, pair<string, int>> info;
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        info[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto inf = info[id];
        int spend = t - inf.second;
        time[{inf.first, stationName}].push_back(spend);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = 0;
        for (auto t: time[{startStation, endStation}])
            sum += t;
        return sum / time[{startStation, endStation}].size();
    }
};
