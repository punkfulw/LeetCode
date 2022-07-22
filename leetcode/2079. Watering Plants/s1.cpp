// OJ: https://leetcode.com/problems/watering-plants/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int remain = capacity, n = plants.size(), ans = 0;
        for (int i = 0; i < n; i++){
            if (remain >= plants[i])
                ans++;
            else {
                remain = capacity;
                ans += i + 1 + i;
            }
            remain -= plants[i];
        }
        return ans;
    }
};
