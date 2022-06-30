# [462. Minimum Moves to Equal Array Elements II (Easy)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

<p>Given an integer array <code>nums</code> of size <code>n</code>, return <em>the minimum number of moves required to make all array elements equal.</em></p>

<p>In one move, you can increment or decrement an element of the array by <code>1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation: </strong> 
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,10,2,9]
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == nums.length</code></li>
  <li><code>1</sup> &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>



**Related Topics**:  
[Math](https://leetcode.com/tag/math/)



## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int aver = nums[(n)/2];
        
        int ans = 0;
        for (int i: nums){
            ans += (abs(i - aver)); 
            cout << i << " " << ans << endl;
        }
        return ans;
    }
};
```

## Solution 2. two pointer


```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0, r = nums.size() - 1;
        while (l < r)
            ans += nums[r--] - nums[l++];

        return ans;
    }
};
```

