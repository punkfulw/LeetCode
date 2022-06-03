// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), ans = 0, cnt1[2] = {0, 0}, cnt2[2] = {0, 0};
        string s1 (n, '0'), s2(n, '1');
        for (int i = 0; i < n; i++){
            s1[i] = i % 2 ? '1' : '0';
            s2[i] = i % 2 ? '0' : '1';
        }
        
        for (int i = 0; i < n; i++){
            if (s1[i] != s[i])
                if (s1[i] == '1') cnt1[0]++;
                else cnt1[1]++;
            else 
                if (s2[i] == '1') cnt2[0]++;
                else cnt2[1]++;
        }
        
        if (cnt1[0] != cnt1[1] && cnt2[0] != cnt2[1])
            ans = -1;
        else if (cnt1[0] == cnt1[1] && cnt2[0] == cnt2[1])
            ans = min(cnt1[0], cnt2[0]);
        else
            ans = cnt1[0] != cnt1[1] ? cnt2[0] : cnt1[0];
        return ans;
    }
};
