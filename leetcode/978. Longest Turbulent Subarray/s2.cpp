// OJ: https://leetcode.com/problems/longest-turbulent-subarray/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/longest-turbulent-subarray/discuss/221929/C%2B%2BJava-6-lines-flip-the-sign
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 0;
        for (int cur = 0, i = 0; i < arr.size()-1; i++, cur *= -1){
            if (arr[i] > arr[i + 1])
                cur = cur > 0 ? cur + 1 : 1;
            else if (arr[i] < arr[i + 1])
                cur = cur < 0 ? cur - 1 : -1;
            else 
                cur = 0;
            ans = max(ans, abs(cur));
        }
        return ans + 1;
    }
};
