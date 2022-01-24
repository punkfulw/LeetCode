// OJ: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> mp;
        for (auto i :nums)
            mp[i]++;
        
        vector<int> res;
        for (auto i : nums)
            if (mp[i] == 1 && !mp.count(i + 1) && !mp.count(i - 1))
                res.push_back(i);
        return res;
    }
};
