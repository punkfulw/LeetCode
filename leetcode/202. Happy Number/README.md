# [202. Happy Number (Easy)](https://leetcode.com/problems/happy-number/)

<p>Write an algorithm to determine if a number <code>n</code> is "happy".</p>

<p>A <b>happy number</b> is a number defined by the following process:</p>
  
<ul>
  <li>Starting with any positive integer, replace the number by the sum of the squares of its digits.</li>
  <li>Repeat the process until the number equals 1 (where it will stay), or it <b>loops endlessly in a cycle</b> which does not include 1.</li>
  <li>Those numbers for which this process <b>ends in 1</b> are happy.</li>
</ul>

<p>Return <code>true</code><em> if </em><code>n</code><em> is a happy number, and </em><code>false</code> <em>if not</em>.</p>

<p><strong>Example 1:&nbsp;</strong></p>

<pre><strong>Input:</strong> n = 19
<strong>Output:</strong> true
<strong>Explanation: 
</strong>1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong>Example 2:&nbsp;</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[JPMorgan](https://leetcode.com/company/jpmorgan), [Nutanix](https://leetcode.com/company/nutanix), [Google](https://leetcode.com/company/google), [Pinterest](https://leetcode.com/company/pinterest)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Linked List Cycle (Easy)](https://leetcode.com/problems/linked-list-cycle/)
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)
* [Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)

## Solution 1. Floyd Cycle detection (two pointer)

```cpp
// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int helper(int n){
        int cur = 0;
        while (n > 0){
            int tmp = (n % 10);
            cur +=  tmp * tmp;
            n /= 10;
        }
        return cur;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do{
            slow = helper(slow);
            fast = helper(helper(fast));
            if (fast == 1)
                return true;
        }while (slow != fast);
        return false;
    }
};
```
