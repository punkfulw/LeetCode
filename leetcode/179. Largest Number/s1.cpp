// OJ: https://leetcode.com/problems/largest-number/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(NW)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> A;
        for (auto i: nums)
            A.push_back(to_string(i));
        
        sort(A.begin(), A.end(), [](string &a, string &b){
            return a + b > b + a;    
        });
        string ans = "";
        for (auto s: A) ans += s;        
        return ans[0] == '0' ? "0" : ans;
        
    }
};
