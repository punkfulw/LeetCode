// OJ: https://leetcode.com/problems/find-the-town-judge/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trusted[1001] = {};
        
        for (auto t: trust){
            trusted[t[1]]++;
            trusted[t[0]]--;
        }
        
        for (int i = 1; i <= 1000; i++)
            if (trusted[i] == n - 1)
                return i;
        return -1;
    }
};
