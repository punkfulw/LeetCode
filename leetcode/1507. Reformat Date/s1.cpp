// OJ: https://leetcode.com/problems/reformat-date/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string reformatDate(string date) {
        string ans;
        unordered_map<string, string> mp = 
                  {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
                  {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
                  {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        if (date.size() == 13)
            return date.substr(9, 4) + '-' + mp[date.substr(5, 3)] + '-' + date.substr(0,2); 
        else
            return date.substr(8, 4) + '-' + mp[date.substr(4, 3)] + '-' + '0' + date.substr(0,1); 
                                                
    }
};
