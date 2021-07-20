# [477. Total Hamming Distance (Medium)](https://leetcode.com/problems/total-hamming-distance/)

<p>The Hamming distance between two integers is the number of positions at which the corresponding bits are different.</p>

<p>Given an integer array <code>nums</code>, return <em>the sum of <b>Hamming distances</b> between all the pairs of the integers in </em><code>nums</code>.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [4,14,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [4,14,4]
<strong>Output:</strong> 4
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/total-hamming-distance/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/total-hamming-distance/discuss/96243/Share-my-O(n)-C%2B%2B-bitwise-solution-with-thinking-process-and-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if (n < 2)
            return 0;
        int* zeroOne = new int[2];
        while (true){
            int cnt = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for (int i = 0; i < n; i++){
                if (nums[i] == 0)
                    cnt++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if (cnt == n)
                return ans;
        }
    }
};
```
