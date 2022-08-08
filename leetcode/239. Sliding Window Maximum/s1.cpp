// OJ: https://leetcode.com/problems/sliding-window-maximum/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if (i >= k){
                int exit = nums[i - k];
                mp[exit]--;
                if (mp[exit] == 0)
                    mp.erase(exit);
            }
            if (i >= k - 1)
                ans.push_back((mp.rbegin())->first);
        }
        return ans;
    }
};
