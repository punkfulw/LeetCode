/ OJ: https://leetcode.com/problems/count-binary-substrings/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < s.size()-1; i++){
            if (s[i] == s[i+1])
                continue;
            else{
                int j = i+1;
                ans++;
                while (s[j] == s[j+1] && j-i <= i-pre){
                    j++;
                    ans++;
                }
                pre = i+1;
            }
        }
        return ans;
    }
};
