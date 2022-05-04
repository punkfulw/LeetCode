// OJ: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/1023235/C%2B%2B4-approaches-a-variation-of-two-sum
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp;
        
        for (auto i: nums)
        {
            int match = k - i;
            if (mp[match])
            {
                ans++;
                mp[match]--;
            }  
            else
                mp[i]++;
        }
        return ans;
    }
};
