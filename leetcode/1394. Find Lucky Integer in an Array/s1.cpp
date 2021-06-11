// OJ: https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i: arr)
            mp[i]++;
        for(auto p: mp){
            if (p.first == p.second)
                ans = max(ans, p.first);
        }
        return ans;
    }
};
