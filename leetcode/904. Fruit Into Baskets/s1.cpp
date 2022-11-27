// OJ: https://leetcode.com/problems/fruit-into-baskets/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int ans = 0, i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;
        while (j < n){
            while (j < n && mp.size() <= 2){
                mp[nums[j]]++;
                j++;
            }
            ans = max(ans, j - i - 1);
            while (mp.size() > 2){
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                
                i++;
            }
        }
        ans = max(ans, j - i);
        return ans;
    }
};
