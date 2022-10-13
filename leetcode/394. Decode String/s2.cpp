// OJ: https://leetcode.com/problems/decode-string/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/394.%20Decode%20String/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string sol(string &s, int &i){
        string ans = "";
        while (i < s.size() && s[i] != ']'){
            if (isdigit(s[i])){
                int mul = 0;
                while (isdigit(s[i]))
                    mul = 10 * mul + (s[i++] - '0');
                i++;
                string tail = sol(s, i);
                i++;
                for (int i = 0; i < mul; i++)
                    ans += tail;
            }
            else
                ans += s[i++];
        }
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return sol(s, i);
    }
};
