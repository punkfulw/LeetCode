# [258. Add Digits (Easy)](https://leetcode.com/problems/add-digits/)

<p>Given a non-negative integer <code>num</code>, repeatedly add all its digits until the result has only one digit, and return it.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 38
<strong>Output:</strong> 2 
<strong>Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
</pre>

<p><b>Follow up:</b><br>
Could you do it without any loop/recursion in O(1) runtime?</p>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number/)
* [Sum of Digits in the Minimum Number (Easy)](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/)

## Solution 1.
```cpp

// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        while (num > 9){
            int cnt = 0;
            while (num > 0){
                cnt += num % 10;
                num /= 10;
            }
            num = cnt;
        }
        return num;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C%2B%2B-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
```
