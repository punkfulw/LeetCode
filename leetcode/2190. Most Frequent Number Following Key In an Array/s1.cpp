// OJ: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution { 
public:
    int mostFrequent(vector<int>& nums, int key) {
        int cnt = 0, n = nums.size(), ans;
        map<int, int> mp;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == key)
                mp[nums[i + 1]]++;
        for (auto p: mp)
            if (p.second > cnt){
                cnt = p.second;
                ans = p.first;
            }
        return ans;
    }
};
