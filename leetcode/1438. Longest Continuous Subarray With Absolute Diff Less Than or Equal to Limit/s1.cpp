// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ans = 1;
        map<int, int> mn, mx;
        mn[nums[0]]++;
        mx[-nums[0]]++;

        for (int i = 0, j = 1; j < n; j++){
            int cur = nums[j];
            mn[cur]++;
            mx[-cur]++;
            while (abs(cur + mx.begin()->first) > limit || abs(mn.begin()->first - cur) > limit){
                int del = nums[i++];
                mn[del]--;
                mx[-del]--;
                if (mn[del] == 0)
                    mn.erase(del);
                if (mx[-del] == 0)
                    mx.erase(-del);
            }
            ans = max(ans, j - i + 1);  
        }
        
        return ans;
    }
};
