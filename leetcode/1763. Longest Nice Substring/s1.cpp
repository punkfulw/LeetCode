// OJ: https://leetcode.com/problems/longest-nice-substring/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n - 1; i++){
            int cnt[26][2] = {};
            for (int j = i; j < n; j++){
                cnt[tolower(s[j]) - 'a'][(bool)islower(s[j])] = 1;
                int k = 0;
                for (; k < 26; k++)
                    if (cnt[k][0] + cnt[k][1] == 1)
                        break;
                if (k == 26 && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }  
        }
        return ans;
    }
};
