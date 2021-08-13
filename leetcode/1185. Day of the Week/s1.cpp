// OJ: https://leetcode.com/problems/day-of-the-week/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string daysInWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int days = 0;
        
        for (int i = 1971; i < year; i++){
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                days++;
            days += 365;
        }
        for (int i = 0; i < month-1; i++){
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                daysInMonth[1] = 29;
            days += daysInMonth[i];
        }
        days += day - 1;
        return daysInWeek[(days+5) % 7];
    }
};
