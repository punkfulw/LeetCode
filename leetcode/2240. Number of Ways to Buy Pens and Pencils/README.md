# [2240. Number of Ways to Buy Pens and Pencils (Medium)](https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/)

<p>You are given an integer <code>total</code> indicating the amount of money you have. You are also given two integers <code>cost1</code> and <code>cost2</code> indicating the price of a pen and pencil respectively. You can spend <strong>part or all</strong> of your money to buy multiple quantities (or none) of each kind of writing utensil.</p>

<p>Return <em>the <strong>number of distinct ways</strong> you can buy some number of pens and pencils.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> total = 20, cost1 = 10, cost2 = 5
<strong>Output:</strong> 9
<strong>Explanation:</strong> The price of a pen is 10 and the price of a pencil is 5.
- If you buy 0 pens, you can buy 0, 1, 2, 3, or 4 pencils.
- If you buy 1 pen, you can buy 0, 1, or 2 pencils.
- If you buy 2 pens, you cannot buy any pencils.
The total number of ways to buy pens and pencils is 5 + 3 + 1 = 9.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> total = 5, cost1 = 10, cost2 = 10
<strong>Output:</strong> 1
<strong>Explanation:</strong> The price of both pens and pencils are 10, which cost more than total, so you cannot buy any writing utensils. Therefore, there is only 1 way: buy 0 pens and 0 pencils.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= total, cost1, cost2 &lt;= 10<sup>6</sup></code></li>
</ul>


**Similar Questions**:
* [Find Three Consecutive Integers That Sum to a Given Number (Medium)](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/)
* [Count Integers With Even Digit Sum (Easy)](https://leetcode.com/problems/count-integers-with-even-digit-sum/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0ll;
        for (int i = 0; i <= total / cost1; i++){
            int remain = total - i * cost1;
            ans += (remain / cost2 + 1);
        }
        return ans;
    }
};
```



## Discuss

https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/discuss/1953859/
