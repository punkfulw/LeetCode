// OJ: https://leetcode.com/problems/k-concatenation-maximum-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int MOD = 1e9 + 7, n = arr.size();
        int pre = 0, suf = 0, sub = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0; 
        for (int i = 0; i < n; i++){
            cnt1 += arr[i];
            cnt2 += arr[n - 1 - i];
            cnt3 += arr[i];
            if (cnt3 < 0) cnt3 = 0;
            pre = max(pre, cnt1);
            suf = max(suf, cnt2);
            sub = max(sub, cnt3);
        }
        if (k == 1) 
            return sub % MOD;
        if (cnt1 > 0) 
            return ((k - 2) * (long long)cnt1 % MOD + pre + suf) % MOD;
        return max(sub, suf + pre) % MOD;
    }
};
