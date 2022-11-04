// OJ: https://leetcode.com/problems/buddy-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt[26] = {}, a = -1, b = -1, n = s.size(), same = 0;

        if (s.size() != goal.size())
            return false;

        for (int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] >= 2)
                same = 1;
            if (s[i] != goal[i]){
                if (a == -1)
                    a = i;
                else if (b == -1)
                    b = i;
                else 
                    return false;
            }
        }

        if (b == -1) {
            if (a == -1)
                return same;
            else
                return cnt[s[a] - 'a'] >= 2;
        }  
        else{
            swap(s[a], s[b]);
            return s == goal;
        }
    }
};
