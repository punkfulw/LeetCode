// OJ: https://leetcode.com/problems/car-pooling/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int road[1001] = {};
        for (auto trip: trips){
            road[trip[1]] += trip[0];
            road[trip[2]] -= trip[0];
        }
        for (int i = 0; i < 1001 && capacity >= 0; i++)
            capacity -= road[i];
        return capacity >= 0;
    }
};
