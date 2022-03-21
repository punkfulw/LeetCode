// OJ: https://leetcode.com/problems/partition-labels/
// Author: github.com/punkfulw
// Time: O(S)
// Space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        int last[26];
        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;
        
        int window = 1, Atleast = 0;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int lastPos = last[c - 'a'];
            Atleast = max(Atleast, lastPos);  
            if (i == Atleast)
            {
                ans.push_back(window);
                window = 1;
                Atleast = i + 1;
            }
            else 
                window++;
        } 
        return ans;
    }
};
