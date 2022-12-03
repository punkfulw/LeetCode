// OJ: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (auto t: time){
            int t1 = t % 60, target = (60 - t1) % 60;
            ans += mp[target];
            mp[t1]++;
        }
        return ans;
    }
};
