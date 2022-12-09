// OJ: https://leetcode.com/problems/design-underground-system/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(N)
class UndergroundSystem {
public:
    UndergroundSystem() {}
    
    unordered_map<int, pair<string, int>> id2info; // id -> {station, time};
    map<pair<string, string>, pair<double, int>> station; // {sta1, sta2} -> {time, cntTrip};
    
    void checkIn(int id, string stationName, int t) {
        id2info[id] = {stationName, t};
    }
    
    void checkOut(int id, string to, int end) {
        auto [from, start] = id2info[id];
        station[{from, to}].first += (end - start);
        station[{from, to}].second++;
    }
    
    double getAverageTime(string from, string to) {
        return station[{from, to}].first / station[{from, to}].second;
    }
};
