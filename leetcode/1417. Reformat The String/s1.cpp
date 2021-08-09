// OJ: https://leetcode.com/problems/reformat-the-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string reformat(string s) {
        string dig, num;
        for (auto c: s){
            if (isdigit(c))
                dig += c;
            else
                num += c;
        }
        if (abs(int(dig.size() - num.size()))>1)
            return "";
        return reform(dig, num);
    }
    string reform(string lon, string sho){
        if (lon.size() < sho.size())
            swap(lon, sho);
        string ans;
        for (int i = 0; i < lon.size(); i++){
            ans += lon[i];
            if (i >= sho.size())
                continue;
            ans += sho[i];
        }
        return ans;
    }
};
