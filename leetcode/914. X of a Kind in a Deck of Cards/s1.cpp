// OJ: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Author: github.com/punkfulw
// Time: O(NlogN) logN for the GCD function
// Space: O(N)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[10001] = {}, n = deck.size(), g = n;
        for (auto &i: deck)
            cnt[i] ++;
        
        for (auto &i: cnt){
            if (!i)
                continue;
            g = gcd(g, i);
        }
        
        return g >= 2;
    }
};
