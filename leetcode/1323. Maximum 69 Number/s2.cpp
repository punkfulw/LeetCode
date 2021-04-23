// OJ: https://leetcode.com/problems/maximum-69-number
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};
