// OJ: https://leetcode.com/problems/number-of-segments-in-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int ans = 0;
        while (ss >> s){
            ans++;
        }
        return ans;
    }
};
