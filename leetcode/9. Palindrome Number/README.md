# [9. Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)

<p>Given an integer <code>x</code>, return <code>true</code> if <code>x</code> is palindrome integer.</p>

<p>An integer is a <b>palindrome</b> when it reads the same backward as forward. For example, <code>121</code> is palindrome while <code>123</code> is not.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 121
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> -121
<strong>Output:</strong> false
<strong>Explanation:</strong> From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 10
<strong>Output:</strong> false
<strong>Explanation:</strong> Reads 01 from right to left. Therefore it is not a palindrome.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> -101
<strong>Output:</strong> false
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>-2<sup>31</sup> &lt;= x &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p><strong>Follow up:</strong></p>

<p>Could you solve it without converting the integer to a string?</p>


**Companies**:  
[JPMorgan](https://leetcode.com/company/jpmorgan), [Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Yahoo](https://leetcode.com/company/yahoo), [Tencent](https://leetcode.com/company/tencent)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindrome-number/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/palindrome-number/discuss/5165/An-easy-c%2B%2B-8-lines-code-(only-reversing-till-half-and-then-compare)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0))
            return false;
        int n = 0;
        while (x > n){
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n == x || n/10 == x;
    }
};
```

## Solution 2. stack

```cpp
// OJ: https://leetcode.com/problems/palindrome-number/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/palindrome-number/discuss/5165/An-easy-c%2B%2B-8-lines-code-(only-reversing-till-half-and-then-compare)
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        stack<int> stk;
        
        int n = x;
        while (n > 0){
            stk.push(n % 10);
            n /= 10;
        }
        while (x > 0){
            //cout << stk.top();
            if (x % 10 != stk.top())
                return false;
            x /= 10;
            stk.pop();
        }
        
        return true;
    }
};
```
