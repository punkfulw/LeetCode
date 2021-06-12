// OJ: https://leetcode.com/problems/maximum-number-of-balloons/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for (auto c: text)
            mp[c]++;
        return min({mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']});
    }
};
