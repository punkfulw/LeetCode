# [164. Maximum Gap (Hard)](https://leetcode.com/problems/maximum-gap/)

<p>Given an integer array <code>nums</code>, return <em>the maximum difference between two successive elements in its sorted form. </em>
  If the array contains less than two elements, return <code>0</code>.</p>

<p>You must write an algorithm that runs in linear time and uses linear extra space.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [3,6,9,1]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [10]
<strong>Output:</strong> 0
<strong>Explanation: </strong>The array contains less than 2 elements, therefore return 0.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>



**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)


## Solution 1. Pigeon hole principle (Bucket sort)


```cpp
// OJ: https://leetcode.com/problems/maximum-gap/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/maximum-gap/discuss/50694/12ms-C%2B%2B-Suggested-Solution
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;
        int gap = max((u - l) / (n - 1), 1);
        int m = (u - l) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num : nums) {
            int k = (num - l) / gap;
            if (num < bucketsMin[k]) bucketsMin[k] = num;
            if (num > bucketsMax[k]) bucketsMax[k] = num;
        }
        int i = 0, j; 
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m) {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                j++;
            if (j == m) break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};
```

## Solution 2. Priority queue


```cpp
// OJ: https://leetcode.com/problems/maximum-gap/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int> q;
        int dif = 0;
        
        for (auto i: nums)
            q.push(i);
        while (!q.empty()){
            int a = q.top();
            q.pop();
            if (!q.empty()){
                int b = q.top();
                dif = max(dif, a-b);
            }
        }
        return dif;
    }
};
```

