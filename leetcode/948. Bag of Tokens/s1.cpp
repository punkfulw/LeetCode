// OJ: https://leetcode.com/problems/bag-of-tokens/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0, r = tokens.size() - 1, score = 0, ans = 0;
        sort(tokens.begin(), tokens.end());
        while (l <= r){
            if (power >= tokens[l]){
                power -= tokens[l++];
                score++;
                ans = max(ans, score);
            }
            else {
                if (score <= 0)
                    break;
                score--;
                power += tokens[r--];
            }
        }
        return ans;
    }
};
