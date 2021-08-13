# [1185. Day of the Week (Easy)](https://leetcode.com/problems/day-of-the-week/)

<p>Given a date, return the corresponding day of the week for that date.</p>

<p>The input is given as three integers representing the <code>day</code>, <code>month</code> and <code>year</code> respectively.</p>

<p>Return the answer as one of the following values&nbsp;<code>{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> day = 31, month = 8, year = 2019
<strong>Output:</strong> "Saturday"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> day = 18, month = 7, year = 1999
<strong>Output:</strong> "Sunday"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> day = 15, month = 8, year = 1993
<strong>Output:</strong> "Sunday"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given dates are valid&nbsp;dates between the years <code>1971</code> and <code>2100</code>.</li>
</ul>

**Companies**:  
[United Health Group](https://leetcode.com/company/united-health-group)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
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
```
