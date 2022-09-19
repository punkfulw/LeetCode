// OJ: https://leetcode.com/problems/check-if-n-and-its-double-exist/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for (auto i: arr){
            if (mp[i]) return true;
            if (i % 2 == 0) 
                mp[i / 2]++;
            mp[i * 2]++;
        }
        return false;
    }
};
