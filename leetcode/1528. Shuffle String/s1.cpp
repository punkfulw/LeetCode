// OJ: https://leetcode.com/problems/shuffle-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        for (int i = 0; i < s.size(); i++){
            ans[(indices.at(i))] = s.at(i); 
        }
        return ans;
    }
};
