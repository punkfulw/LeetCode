// OJ: https://leetcode.com/problems/compare-version-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string s1, s2;

        while (!ss1.eof() || !ss2.eof()){ 
            if (!ss1.eof())
                getline(ss1, s1, '.');
            else
                s1 = "0";
            
            if (!ss2.eof())
                getline(ss2, s2, '.');
            else 
                s2 = "0";
                
            int a = stoi(s1), b = stoi(s2);
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            if (a == 0 && b == 0)
                continue;
        }
        return 0;
    }
};
