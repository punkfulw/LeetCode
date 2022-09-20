# [1360. Number of Days Between Two Dates (Easy)](https://leetcode.com/problems/number-of-days-between-two-dates/)

<p>Write a program to count the number of days between two dates.</p>

<p>The two dates are given as strings, their format is <code>YYYY-MM-DD</code>&nbsp;as shown in the examples.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> date1 = "2019-06-29", date2 = "2019-06-30"
<strong>Output:</strong> 1
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> date1 = "2020-01-15", date2 = "2019-12-31"
<strong>Output:</strong> 15
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given dates are valid&nbsp;dates between the years <code>1971</code> and <code>2100</code>.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-days-between-two-dates/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int month[13] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int convert(string date){
        int year = stoi(date.substr(0, 4)), 
            mon = stoi(date.substr(5, 2)), 
            day = stoi(date.substr(8, 2));
        day += (year - 1) * 365 + (year - 1) / 4 + (year - 1) / 400 - (year - 1) / 100;
        for (int i = 1; i < mon; i++)
            day += month[i];
        if (year % 400 == 0 || year % 4 == 0 && year % 100 && mon > 2)
            day++;
        return day;
    }
    int daysBetweenDates(string date1, string date2) {
        int a = convert(date1), b = convert(date2);
        return abs(a - b);
    }
};
```

