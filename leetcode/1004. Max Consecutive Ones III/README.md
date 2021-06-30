# [1004. Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)

<p>Given a binary array <code>nums</code> and an integer <code>k</code>, 
  return <em>the maximum number of consecutive </em><code>1</code><em><em>'s in the array if you can flip at most </em><code>k</code> <code>0</code>'s.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,1,1,0,0,0,1,1,1,1,0]</span>, K = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">6</span>
<strong>Explanation: </strong>
[1,1,1,0,0,<u><strong>1</strong>,1,1,1,1,<strong>1</strong></u>]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]</span>, K = <span id="example-input-2-2">3</span>
<strong>Output: </strong><span id="example-output-2">10</span>
<strong>Explanation: </strong>
[0,0,<u>1,1,<b>1</b>,<strong>1</strong>,1,1,1,<strong>1</strong>,1,1</u>,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
  <li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)


## Solution 1. Queue

```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(k)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        queue<int> q;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
            cnt++;
            if (nums[i] == 0){
                if (k == 0){
                    while (q.front() != 0){
                        cnt--;
                        q.pop();
                    }
                    cnt--;
                    q.pop();
                }
                else
                    k--;
            }
            ans = max(ans, cnt);
        }
        return ans; 
    }
};
```
