// OJ: https://leetcode.com/problems/largest-number/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(1)
class Solution {
public:
    string largestNumber(vector<int>& A) {
        sort(A.begin(), A.end(), [](int &a, int &b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);    
        });
        string ans = "";
        for (auto s: A) 
            ans += to_string(s);        
        return ans[0] == '0' ? "0" : ans;
    }
};
