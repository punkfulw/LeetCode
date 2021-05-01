# [970. Powerful Integers (Medium)](https://leetcode.com/problems/powerful-integers/)

<p>Given three integers <code>x</code>, <code>y</code>, and <code>bound</code>, 
return <em>a list of all the <b>powerful integers</b> that have a value less than or equal to</em> <code>bound</code>.</p>

<p>An integer is <b>powerful</b> if it can be represented as <code>x<sup>i</sup> + y<sup>j</sup></code> for some integers <code>i >= 0</code> and <code>j >= 0</code>.</p>

<p>You may return the answer in <b>any order</b>.&nbsp; In your answer, each value should occur <b>at most once</b>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>x = <span id="example-input-1-1">2</span>, y = <span id="example-input-1-2">3</span>, bound = <span id="example-input-1-3">10</span>
<strong>Output: </strong><span id="example-output-1">[2,3,4,5,7,9,10]</span>
<strong>Explanation: </strong>
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>x = <span id="example-input-2-1">3</span>, y = <span id="example-input-2-2">5</span>, bound = <span id="example-input-2-3">15</span>
<strong>Output: </strong><span id="example-output-2">[2,4,6,8,10,14]</span>
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 100</code></li>
	<li><code>1 &lt;= y&nbsp;&lt;= 100</code></li>
	<li><code>0 &lt;= bound&nbsp;&lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)  [Math](https://leetcode.com/tag/math/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/powerful-integers/
// Author: github.com/punkfulw
// Time: O(log_x^bound * log_y^bound)
// Space: O(log_x^bound * log_y^bound)
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for (int i = 1; i < bound; i *= x){
            for (int j = 1; j < bound; j *= y){
                if (i + j <= bound)
                    s.insert(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
