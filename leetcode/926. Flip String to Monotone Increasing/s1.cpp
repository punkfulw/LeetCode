// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ans {};
        int cnt1 {};
        
        for (auto c: S){
            if (c == '0')
                ans = min(++ans, cnt1);
            else
                cnt1++;
        }
        return ans;
    }
};
