// OJ: https://leetcode.com/problems/find-the-highest-altitude/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest {};
        int current {};
        
        for (int i: gain){
            current += i;
            if (current > highest)
                highest = current;
        }
        return highest;
    }
};
