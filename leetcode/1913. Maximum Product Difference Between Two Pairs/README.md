# [1913. Maximum Product Difference Between Two Pairs (Easy)](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)

<p>The <strong>product difference</strong> between two pairs <code>(a, b)</code> and <code>(c, d)</code> is defined as <code>(a * b) - (c * d)</code>.</p>

<ul>
	<li>For example, the product difference between <code>(5, 6)</code> and <code>(2, 7)</code> is <code>(5 * 6) - (2 * 7) = 16</code>.</li>
</ul>

<p>Given an integer array <code>nums</code>, choose four <strong>distinct</strong> indices <code>w</code>, <code>x</code>, <code>y</code>, and <code>z</code> such that the <strong>product difference</strong> between pairs <code>(nums[w], nums[x])</code> and <code>(nums[y], nums[z])</code> is <strong>maximized</strong>.</p>

<p>Return <em>the <strong>maximum</strong> such product difference</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,6,2,7,4]
<strong>Output:</strong> 34
<strong>Explanation:</strong> We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,5,9,7,4,8]
<strong>Output:</strong> 64
<strong>Explanation:</strong> We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>4 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1, max2;
        int min1, min2;
        max1 = *max_element(nums.begin(), nums.end());
        nums.erase(max_element(nums.begin(), nums.end()));
        max2 = *max_element(nums.begin(), nums.end());
        nums.erase(max_element(nums.begin(), nums.end()));
        min1 = *min_element(nums.begin(), nums.end());
        nums.erase(min_element(nums.begin(), nums.end()));
        min2 = *min_element(nums.begin(), nums.end());
        nums.erase(min_element(nums.begin(), nums.end()));
        
        return max1 * max2 - min1 * min2;
    }
};
```


## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= min2){
                if (nums[i] <= min1){
                    min2 = min1;
                    min1 = nums[i];
                }
                else
                    min2 = nums[i];
            }
            if (nums[i] >= max2){
                if (nums[i] >= max1){
                    max2 = max1;
                    max1 = nums[i];
                }
                else
                    max2 = nums[i];
            }
        }
        return max1 * max2 - min1 * min2;
    }
};


```
