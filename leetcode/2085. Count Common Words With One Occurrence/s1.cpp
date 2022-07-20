// OJ: https://leetcode.com/problems/count-common-words-with-one-occurrence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        int ans = 0;
        for (auto s: words1)
            mp[s] += mp[s] == 0 ? 1 : -10;   
        for (auto s: words2)
            mp[s] += mp[s] == 1 ? 1 : -10;
        for (auto p: mp)
            if (p.second == 2)
                ans++;
        return ans;
    }
};
