// OJ: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string generateTheString(int n) {
        string ans (n, 'a');
        
        if(n % 2 == 0){
            ans.pop_back();
            ans.push_back('z');
        }
        return ans;
    }
};
