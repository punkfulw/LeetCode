// OJ: https://leetcode.com/problems/car-pooling/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int road[1000] = {0};
        for (auto trip: trips){
            for (int i = trip[1]; i < trip[2]; i++){
                road[i] += trip[0];
                if (road[i] > capacity)
                    return false;
            }
        }
        return true;
    }
};
