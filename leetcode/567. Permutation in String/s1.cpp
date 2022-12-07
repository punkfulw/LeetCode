// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/punkfulw
// Time: O(s2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n)
            return false;
        vector<int> cnt1(26), cnt2(26);
        
        for (auto &c: s1)
            cnt1[c - 'a']++;
        
        for (int i = 0; i < m; i++){
            char c = s2[i];
            cnt2[c - 'a']++;
            if (i >= n)
                cnt2[s2[i - n] - 'a']--; 
            
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }
};
