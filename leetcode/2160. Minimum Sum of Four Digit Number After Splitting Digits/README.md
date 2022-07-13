# [2160. Minimum Sum of Four Digit Number After Splitting Digits (Easy)](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/)

<p>You are given a <strong>positive</strong> integer <code>num</code> consisting of exactly four digits. Split <code>num</code> into two new integers <code>new1</code> and <code>new2</code> by using the <strong>digits</strong> found in <code>num</code>. <strong>Leading zeros</strong> are allowed in <code>new1</code> and <code>new2</code>, and <strong>all</strong> the digits found in <code>num</code> must be used.</p>

<ul>
	<li>For example, given <code>num = 2932</code>, you have the following digits: two <code>2</code>'s, one <code>9</code> and one <code>3</code>. Some of the possible pairs <code>[new1, new2]</code> are <code>[22, 93]</code>, <code>[23, 92]</code>, <code>[223, 9]</code> and <code>[2, 329]</code>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> possible sum of </em><code>new1</code><em> and </em><code>new2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 2932
<strong>Output:</strong> 52
<strong>Explanation:</strong> Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 4009
<strong>Output:</strong> 13
<strong>Explanation:</strong> Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1000 &lt;= num &lt;= 9999</code></li>
</ul>


**Similar Questions**:
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)

## Solution 1. 


```cpp
// OJ: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1)
class Solution {
public:
    int minimumSum(int num) {
        vector<int> cnt;
        while (num){
            cnt.push_back(num % 10);
            num /= 10;
        }
        sort(cnt.begin(), cnt.end());
        return 10 * (cnt[0] + cnt[1]) + cnt[2] + cnt[3];
    }
};
```

## Discuss

https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/discuss/1747007/
