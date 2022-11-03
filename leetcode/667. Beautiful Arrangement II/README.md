# [667. Beautiful Arrangement II (Medium)](https://leetcode.com/problems/beautiful-arrangement-ii/)

<p>
Given two integers <code>n</code> and <code>k</code>, you need to construct a list which contains <code>n</code> different positive integers ranging from <code>1</code> to <code>n</code> and obeys the following requirement: <br>

Suppose this list is [a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ... , a<sub>n</sub>], then the list [|a<sub>1</sub> - a<sub>2</sub>|, |a<sub>2</sub> - a<sub>3</sub>|, |a<sub>3</sub> - a<sub>4</sub>|, ... , |a<sub>n-1</sub> - a<sub>n</sub>|] has exactly <code>k</code> distinct integers.
</p>

<p>
If there are multiple answers, print any of them.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> n = 3, k = 1
<b>Output:</b> [1, 2, 3]
<b>Explanation:</b> The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> n = 3, k = 2
<b>Output:</b> [1, 3, 2]
<b>Explanation:</b> The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The <code>n</code> and <code>k</code> are in the range 1 &lt;= k &lt; n &lt;= 10<sup>4</sup>.</li>
</ol>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Beautiful Arrangement (Medium)](https://leetcode.com/problems/beautiful-arrangement/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l = 1, r = n;
        
        while (k){
            if (k & 1)
                ans.push_back(l++);
            else
                ans.push_back(r--);
            k--;
        }
        
        while (l <= r)
            ans.push_back(l++);
        
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l = 1, r = k + 1;
        
        while (l <= r){
            ans.push_back(l++);
            if (l <= r)
                ans.push_back(r--);
        }
        
        for (int i = k + 2; i <= n; ++i)
            ans.push_back(i);
        
        return ans;
    }
};

```
