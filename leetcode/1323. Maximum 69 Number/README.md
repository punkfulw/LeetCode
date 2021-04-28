# [1323. Maximum 69 Number (Easy)](https://leetcode.com/problems/maximum-69-number)

<p>Given a positive integer <code>num</code> consisting only of digits 6 and 9.</p>

<p>Return the maximum number you can get by changing <strong>at most</strong> one digit (6 becomes 9, and 9 becomes 6).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 9669
<strong>Output:</strong> 9969
<strong>Explanation:</strong> 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.&nbsp;
The maximum number is 9969.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 9996
<strong>Output:</strong> 9999
<strong>Explanation:</strong> Changing the last digit 6 to 9 results in the maximum number.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = 9999
<strong>Output:</strong> 9999
<strong>Explanation:</strong> It is better not to apply any change.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>4</sup></code></li>
	<li><code>num</code>'s digits are 6 or 9.</li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-69-number
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int maximum69Number (int num) {
        int ans = num;
        int size = 1;
        int index {};
        
        while (ans > 0){
            if (ans % 10 == 6)
                index = size;
            ans /= 10;
            size++;
        }
        if (index == 0)
            return num;
        return num + 3 * pow(10, index-1);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-69-number
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};
```
