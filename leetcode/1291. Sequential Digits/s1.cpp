// OJ: https://leetcode.com/problems/sequential-digits/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {  
        vector<int> ans;
        string start = to_string(low), end = to_string(high), digit = "123456789";
        int len = start.size(), mx_len = end.size();

        for (int l = len; l <= mx_len; l++){
            for (int i = 0; i < 10 - l; i++){
                string s = digit.substr(i, l);
                int cur = stoi(s);
                if (cur >= low && cur <= high)
                    ans.push_back(cur);
            }
        }
        return ans;    
    }
};
