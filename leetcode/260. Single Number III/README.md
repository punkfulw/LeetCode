# [260. Single Number III (Medium)](https://leetcode.com/problems/single-number-iii/)

<p>Given an integer array <code>nums</code>, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
  You can return the answer in <b>any order</b>.</p>

<p>You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> <code>nums = [1,2,1,3,2,5]</code>
<strong>Output:</strong> <code>[3,5]</code>
</pre>


<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> <code>nums = [-1,0]</code>
<strong>Output:</strong> <code>[-1,0]</code>
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> <code>nums = [0,1]</code>
<strong>Output:</strong> <code>[1,0]</code>
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
  <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
  <li>Each integer in <code>nums</code> will appear twice, only two integers will appear once.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Single Number (Easy)](https://leetcode.com/problems/single-number/)
* [Single Number II (Medium)](https://leetcode.com/problems/single-number-ii/)

## Solution 1. set

```cpp
// OJ: https://leetcode.com/problems/single-number-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(S) S = set size
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)
            return {nums[0], nums[1]};
        unordered_set<int> st;
        
        for (int i: nums){
            if (st.count(i))
                st.erase(i);
            else
                st.insert(i);
        }
        vector<int> ans;
        for(auto i: st)
            ans.push_back(i);
        return ans;
    }
};
```

## Solution 2. XOR

```cpp
// OJ: https://leetcode.com/problems/single-number-iii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C%2B%2BJava-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long dif = 0;
        for (int num: nums) dif ^= num;
        dif &= -dif; 
        
        vector<int> ans(2, 0);
        for (int num: nums)
            ans[!(num & dif)] ^= num;
        return ans;
    }
};
```
