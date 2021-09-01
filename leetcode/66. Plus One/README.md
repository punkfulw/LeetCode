# [66. Plus One (Easy)](https://leetcode.com/problems/plus-one/)

<p>You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
  The digits are ordered from most significant to least significant in left-to-right order.
  The large integer does not contain any leading 0's.</p>

<p>Increment the large integer by one and return the resulting array of digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> digits = [1,2,3]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong> The array represents the integer 123.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> digits = [4,3,2,1]
<strong>Output:</strong> [4,3,2,2]
<strong>Explanation:</strong> The array represents the integer 4321.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> digits = [0]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Spotify](https://leetcode.com/company/spotify)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)
* [Add Binary (Easy)](https://leetcode.com/problems/add-binary/)
* [Plus One Linked List (Medium)](https://leetcode.com/problems/plus-one-linked-list/)
* [Add to Array-Form of Integer (Easy)](https://leetcode.com/problems/add-to-array-form-of-integer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/plus-one/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        for (int i = nums.size()-1; i >= 0; i--){
            nums[i]++;
            if (nums[i] < 10)
                break;
            nums[i] = 0;
        }
        if (nums[0] == 0)
            nums.insert(nums.begin(), 1);
        
        return nums;
    }
};
```
