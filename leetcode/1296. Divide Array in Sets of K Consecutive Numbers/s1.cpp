// OJ: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for (auto &i: nums) mp[i]++;
        
        for (auto [first, num]: mp){
            if (num == 0)
                continue;
            for (int i = first; i < first + k; i++){
                if (mp[i] < num)
                    return false;
                mp[i] -= num;
            }
        }
        return true;
    }
};
