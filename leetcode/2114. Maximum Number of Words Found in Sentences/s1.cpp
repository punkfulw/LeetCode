// OJ: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        
        for (auto &s: sentences){
            int cnt = 0;
            for (auto c: s)
                if (c == ' ')
                    cnt++;
            ans = max(cnt + 1, ans);
        }
        return ans;
    }
};
