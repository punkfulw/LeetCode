// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(A)
class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {}, most = 0;
        for (auto c: s)
            most = ++cnt[c - 'a'] > cnt[most] ? c - 'a' : most;
        if (cnt[most] * 2 - 1 > s.size())
            return "";
        int i = 0;
        for (; cnt[most]; i += 2, cnt[most]--)
            s[i] = most + 'a';
        
        for (int j = 0; j < 26; j++){
            while (cnt[j]--){
                if (i >= s.size())
                    i = 1;
                s[i] = j + 'a';
                i += 2;
            }
        }
        return s;
    }
};
