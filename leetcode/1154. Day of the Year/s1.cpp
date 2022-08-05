// OJ: https://leetcode.com/problems/day-of-the-year/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
        int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = d;
        for (int i = 0; i < m - 1; i++)
            ans += month[i];
        if (m > 2 && y % 4 == 0){
            if (y % 100 != 0)
                ans++;
            else 
                if (y % 400 == 0)
                    ans++;
        }
        return ans;
    }
};
