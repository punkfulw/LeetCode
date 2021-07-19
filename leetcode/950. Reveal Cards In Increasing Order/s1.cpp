// OJ: https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ans(n);
        int pos = 0, jump = 0, i = 0;
        while (count(ans.begin(), ans.end(), 0)){
            while (ans[i] != 0)
                i = (i+1) % n;
            if (!(jump%2))
                ans[i] = deck[pos++];
            jump++;
            i = (i+1) % n;
        }
        return ans;
    }
};
