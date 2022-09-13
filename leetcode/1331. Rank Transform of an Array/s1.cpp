// OJ: https://leetcode.com/problems/rank-transform-of-an-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for (auto &i: arr)
            mp[i] = 1;
        int rank = 1;
        for (auto &p: mp)      
            p.second = rank++;
        
        for (int &i: arr)
            i = mp[i];

        return arr;
    }
};
