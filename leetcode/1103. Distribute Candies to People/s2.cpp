// OJ: https://leetcode.com/problems/distribute-candies-to-people/
// Author: github.com/punkfulw
// Time: O(sqrt(candies))
// Space: O(1)
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans (num_people, 0);
        int i = 0, candy = 1;
        while (candies > 0){
            ans[i++] += min(candy, candies);
            candies -= candy;
            candy++;
            if (i >= num_people) i = 0;  
        }
        return ans;
    }
};
