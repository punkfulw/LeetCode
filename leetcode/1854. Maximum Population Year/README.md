# [1854. Maximum Population Year (Easy)](https://leetcode.com/problems/maximum-population-year/)

<p>You are given a 2D integer array <code>logs</code> where each <code>logs[i] = [birth<code>i</code>, death<code>i</code>]</code> indicates the birth and death years of the <code>i<sup>th</sup></code> person.</p>

<p>The <b>population</b> of some year <code>x</code> is the number of people alive during that year. 
  The <code>i<sup>th</sup></code> person is counted in year <code>x</code>'s population if <code>x</code> is in the <b>inclusive</b> range <code>[birthi, deathi - 1]</code>.
  Note that the person is <b>not</b> counted in the year that they die.</p>

<p>Return <em>the <b>earliest</b> year with the <b>maximum population</b>.</em></p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> logs = [[1993,1999],[2000,2010]]
<strong>Output:</strong> 1993
<strong>Explanation: </strong> The maximum population is 1, and 1993 is the earliest year with this population.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> logs = [[1950,1961],[1960,1971],[1970,1981]]
<strong>Output:</strong> 1960
<strong>Explanation: </strong> 
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.
</pre>




<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= logs.length &lt;= 100</code></li>
  <li><code>1950 &lt;= birth<code>i</code> &lt; death<code>i</code> &lt;= 2050</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-population-year/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop (100, 0);
        
        for (int i = 0; i < logs.size(); i++){
            for (int j = logs[i][0]; j < logs[i][1]; j++){
                pop[j - 1950]++;
            }
        }
        int max = 0;
        int index = 0;
        for(int i = 0; i < 100; i++){
            if (pop[i] > max){
                max = pop[i];
                index = i;
            }
        }
        return index+1950;
    }
};
```
