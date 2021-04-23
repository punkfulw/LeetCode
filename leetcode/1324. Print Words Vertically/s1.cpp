// OJ: https://leetcode.com/problems/print-words-vertically/
// Author: github.com/punkfulw
// Time: O(S)
// Space: O(S)
class Solution {
public:
    vector<string> printVertically(string s) {
        int size {};
        int max {};
        
        for (char c: s){
            if (isalpha(c))
                size++;
            else
                size = 0;
            if (size > max)
                max = size;
        }
        vector<string> ans(max, "");
        int cnt = 0;
        
        for (int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                ans[cnt].push_back(s[i]);
                cnt++;
            }
            else{
                while (cnt < max){
                    ans[cnt].push_back(' ');
                    cnt++;
                }
            if (cnt == max)
                cnt = 0;
            }
        }
        
        for (int i = 0; i < max; i++){
            while (ans[i].back() == ' ')
                ans[i].pop_back();
        }
        return ans;
    }
};
