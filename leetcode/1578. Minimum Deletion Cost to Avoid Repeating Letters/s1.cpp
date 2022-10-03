// OJ: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int ans = 0, n = colors.size(), sum = time[0], mx = sum, cnt = 1;
        char pre = colors[0];
        
        for (int i = 1; i < n; i++){
            if (colors[i] == pre){
                sum += time[i];
                mx = max(mx, time[i]);
                cnt++;
            }
            else {
                if (cnt != 1)
                    ans += (sum - mx);
                sum = time[i];
                mx = sum;
                cnt = 1;
                pre = colors[i];
            }
        }
        if (cnt != 1)
            ans += (sum - mx);
        return ans;
    }
};
