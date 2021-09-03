# [1664. Ways to Make a Fair Array (Medium)](https://leetcode.com/problems/ways-to-make-a-fair-array/)

<p>You are given an integer array&nbsp;<code>nums</code>. You can choose <strong>exactly one</strong> index (<strong>0-indexed</strong>) and remove the element. Notice that the index of the elements may change after the removal.</p>

<p>For example, if <code>nums = [6,1,7,4,1]</code>:</p>

<ul>
	<li>Choosing to remove index <code>1</code> results in <code>nums = [6,7,4,1]</code>.</li>
	<li>Choosing to remove index <code>2</code> results in <code>nums = [6,1,4,1]</code>.</li>
	<li>Choosing to remove index <code>4</code> results in <code>nums = [6,1,7,4]</code>.</li>
</ul>

<p>An array is <strong>fair</strong> if the sum of the odd-indexed values equals the sum of the even-indexed values.</p>

<p>Return the <em><strong>number</strong> of indices that you could choose such that after the removal, </em><code>nums</code><em> </em><em>is <strong>fair</strong>. </em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,6,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Remove index 0: [1,6,4] -&gt; Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -&gt; Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -&gt; Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -&gt; Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;You can remove any index and the remaining array is fair.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;You cannot make a fair array after removing any index.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. LtoR RtoL


```cpp
// OJ: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        vector<int> LtoR = nums, RtoL = nums;
        for (int i = 2; i < n; i++){
            LtoR[i] += LtoR[i - 2];
            RtoL[n-1-i] += RtoL[n-1-i+2];
        }
        
        for (int i = 0; i < n; i++){
            int r = 0, l = 0;
            if (i >= 1)
                l += LtoR[i-1];
            if (i < n - 2)
                l += RtoL[i+2];
            if (i >= 2)
                r += LtoR[i-2];
            if (i < n - 1)
                r += RtoL[i+1];
            if (l == r)
                cnt++;
        }
        return cnt;
    }
};
```

## Solution 2. 


```cpp
// OJ: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/ways-to-make-a-fair-array/discuss/944355/C%2B%2B-O(N)-Time-O(1)-Space-PrefixSuffix-Sum
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        int evenSuffix = 0, evenPrefix = 0, oddSuffix = 0, oddPrefix = 0;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) 
                evenSuffix += nums[i];
            else 
                oddSuffix += nums[i];
        }
        
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) 
                evenSuffix -= nums[i];
            else 
                oddSuffix -= nums[i];
            cnt += (evenSuffix + oddPrefix) == (evenPrefix + oddSuffix);
            if (i % 2 == 0) 
                evenPrefix += nums[i];
            else
                oddPrefix += nums[i];
        }
        return cnt;
    }
};
```
