// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size();
        int candidates[3] = {arr[sz/4], arr[sz/2], arr[sz*3/4]};
        for (auto cand: candidates){
            auto st = lower_bound(arr.begin(), arr.end(), cand);
            auto ed = upper_bound(arr.begin(), arr.end(), cand);
            if (distance(st, ed) * 4 > sz)
                return cand;
        }
        return -1;
    }
};
