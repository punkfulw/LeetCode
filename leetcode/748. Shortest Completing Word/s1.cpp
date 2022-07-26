// OJ: https://leetcode.com/problems/shortest-completing-word/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
        int cnt[26] = {}, len = INT_MAX;
        for (auto c: l)
            if (isalpha(c))
                cnt[tolower(c) - 'a']++;
        string ans = "";
        for (auto s: words){
            if (s.size() > len)
                continue;
            
            int cnt2[26] = {};
            for (auto c: s)
                cnt2[c - 'a']++;
            int same = 1;
            for (int i = 0; i < 26; i++)
                if (cnt2[i] < cnt[i])
                    same = 0;
            if (same && s.size() < len){
                len = s.size();
                ans = s;
            }
        }
        return ans;
    }
};
