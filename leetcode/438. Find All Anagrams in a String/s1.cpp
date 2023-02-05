// OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: github.com/punkfulw
// Time: O(M + N) 
// Space: O(R)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> cnt1(26), cnt2(26);
        int n = s.size(), m = p.size();
        
        for (auto c: p)
            cnt1[c - 'a']++;
        
        for (int i = 0; i < n; i++){
            cnt2[s[i] - 'a']++;
            if (i >= m)
                cnt2[s[i - m] - 'a']--;
            if (cnt2 == cnt1)
                ans.push_back(i - m + 1);            
        }           
        return ans;
    }
};
