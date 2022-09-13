// OJ: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool check(int (&left)[26], int (&right)[26]){
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 26; i++){
            if (left[i]) cnt1++;
            if (right[i]) cnt2++;
        }
        return cnt1 == cnt2;
    }
    int numSplits(string s) {
        int left[26] = {}, right[26] = {}, n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
            right[s[i] - 'a']++;
        for (int i = 0; i < n - 1; i++){
            char c = s[i];
            right[c - 'a']--;
            left[c - 'a']++;
            ans += check(left, right);
        }
        return ans;
    }
};
