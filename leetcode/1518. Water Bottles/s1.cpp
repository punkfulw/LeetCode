// OJ: https://leetcode.com/problems/water-bottles/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange){
            ans += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return ans;
    }
};
