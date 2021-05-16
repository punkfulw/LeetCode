# [1051. Height Checker (Easy)](https://leetcode.com/problems/height-checker/)

<p>A school is trying to take an annual photo of all the students. 
  The students are asked to stand in a single file line in <b>non-decreasing order</b> by height.
  Let this ordering be represented by the integer array <code>expected</code> where <code>expected[i]</code> is the expected height of the <code>i<sup>th</sup></code> student in line.</p>

<p>You are given an integer array <code>heights</code> representing the <b>current order</b> that the students are standing in.
  Each <code>heights[i]</code> is the height of the <code>i<sup>th</sup></code> student in line (<b>0-indexed</b>).</p>

<p>Return <em>the <b>number of indices</b> where</em> <code>heights[i] != expected[i]</code>.</p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> heights = [1,1,4,2,1,3]
<strong>Output:</strong> 3
<strong>Explanation: </strong> 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [5,1,2,3,4]
<strong>Output:</strong> 5
<strong>Explanation: </strong> 
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> heights = [1,2,3,4,5]
<strong>Output:</strong> 0
<strong>Explanation: </strong> 
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= heights.length &lt;= 100</code></li>
  <li><code>1 &lt;= heights[i] &lt;= 100</code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/)



## Solution 1.
sort funtion

```cpp
// OJ: https://leetcode.com/problems/height-checker/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> exp = heights;
        sort(exp.begin(), exp.end());
        int ans = 0;
        for (int i = 0; i < exp.size(); i++){
            if (exp[i] != heights[i])
                ans++;
        }
        return ans;
    }
};
```

## Solution 2.
counting sort

```cpp
// OJ: https://leetcode.com/problems/height-checker/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt[101] {};
        
        for (auto i: heights){
            cnt[i]++;
        }
        
        int index = 0, ans = 0;
        for (int i = 1; i <= 100; i++){
            while (cnt[i] > 0){
                if (i != heights[index++])
                    ans++;
                cnt[i]--;
            }
        }
        return ans;
    }
};


```
