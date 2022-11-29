// OJ: https://leetcode.com/problems/capitalize-the-title/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss;
        string s, ans;
        ss << title;
        
        while (ss >> s){
            if (s.size() <= 2){
                for (auto &c: s)
                    c = tolower(c);
            }
            else {
                s[0] = toupper(s[0]);
                for (int i = 1; i < s.size(); ++i)
                    s[i] = tolower(s[i]);
            }
            ans += s + " ";
        }
        ans.pop_back();
        return ans;
    }
};
