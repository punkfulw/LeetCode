// OJ: https://leetcode.com/problems/distribute-candies/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(s.size(), candyType.size()/2);
    }
};
