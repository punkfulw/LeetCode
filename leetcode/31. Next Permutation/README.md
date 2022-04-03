# [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)

<p>Implement <strong>next permutation</strong>, which rearranges numbers into the lexicographically next greater permutation of numbers.</p>

<p>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a></strong> and use only constant&nbsp;extra memory.</p>

<p>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.</p>

<p><code>1,2,3</code> → <code>1,3,2</code><br>
<code>3,2,1</code> → <code>1,2,3</code><br>
<code>1,1,5</code> → <code>1,5,1</code></p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/next-permutation
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {   
        int n = nums.size(), k, l; 
        for (k = n - 2; k >= 0; k--)
            if (nums[k] < nums[k+1])
                break;
        if (k < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            for (l = n - 1; l > k; l--)
            {
                if (nums[l] > nums[k])
                    break;
            }
            swap(nums[l], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
        return; 
    }
};
```
