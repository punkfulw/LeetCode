// OJ: https://leetcode.com/problems/distance-between-bus-stops/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& nums, int start, int end) {
        int ttl = accumulate(nums.begin(), nums.end(), 0), cnt = 0, n = nums.size();
        while (start % n != end)
            cnt += nums[(start++) % n];
        
        return min(cnt, ttl - cnt);
    }
};
