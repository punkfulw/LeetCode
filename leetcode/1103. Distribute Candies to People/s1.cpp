// OJ: https://leetcode.com/problems/distribute-candies-to-people/
// Author: github.com/punkfulw
// Time: O(sqrt(candies) + n)
// Space: O(1)
class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans (n, 0);
        for (int i = 0; candies > 0; i++){
            ans[i % n] += min(candies, i + 1);
            candies -= i + 1;
        }
        return ans;
    }
};
