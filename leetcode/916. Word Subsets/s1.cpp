// OJ: https://leetcode.com/problems/word-subsets/
// Author: github.com/punkfulw
// Time: O((N + M) * W) 
// Space: O(1)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> mp(26), cur(26);
        for (auto s: words2){
            fill(cur.begin(), cur.end(), 0);
            for (auto c: s)
                cur[c - 'a']++;
            for (int i = 0; i < 26; i++)
                mp[i] = max(mp[i], cur[i]);
        }
        for (auto s: words1){
            fill(cur.begin(), cur.end(), 0);
            for (auto c: s)
                cur[c - 'a']++;
            int i = 0;
            for (; i < 26; i++)
                if (mp[i] > cur[i])
                    break;
            if (i == 26) ans.push_back(s);
        }
        return ans;
    }
};
