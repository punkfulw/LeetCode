// OJ: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int curmax = nums[0];
        int n = nums.size();
        vector<int> cnt = nums;
        int curmin = INT_MAX;
        for (int i = n-1; i >= 0; i--){
            curmin = min(curmin, cnt[i]);
            cnt[i] = curmin;
        }
        int i = 1;
        for (; i < n; i++){
            if (curmax <= cnt[i])
                break;
            curmax = max(curmax, nums[i]);
        }
        return i;
    }
};
