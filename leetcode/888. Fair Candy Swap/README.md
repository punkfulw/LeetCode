# [888. Fair Candy Swap (Easy)](https://leetcode.com/problems/fair-candy-swap/)

<p>Alice and Bob have candy bars of different sizes: <code>A[i]</code> is the size of the <code>i</code>-th bar of candy that Alice has, and <code>B[j]</code> is the size of the <code>j</code>-th bar of candy that Bob has.</p>

<p>Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total&nbsp;amount of candy.&nbsp; (<em>The total amount of candy&nbsp;a person has is the sum of the sizes of candy&nbsp;bars they have.</em>)</p>

<p>Return an integer array <code>ans</code>&nbsp;where <code>ans[0]</code> is the size of the candy bar that Alice must exchange, and <code>ans[1]</code> is the size of the candy bar that Bob must exchange.</p>

<p>If there are multiple answers, you may return any one of them.&nbsp; It is guaranteed an answer exists.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,1]</span>, B = <span id="example-input-1-2">[2,2]</span>
<strong>Output: </strong><span id="example-output-1">[1,2]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[1,2]</span>, B = <span id="example-input-2-2">[2,3]</span>
<strong>Output: </strong><span id="example-output-2">[1,2]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">[2]</span>, B = <span id="example-input-3-2">[1,3]</span>
<strong>Output: </strong><span id="example-output-3">[2,3]</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-4-1">[1,2,5]</span>, B = <span id="example-input-4-2">[2,4]</span>
<strong>Output: </strong><span id="example-output-4">[5,4]</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ul>
	<li><span><code>1 &lt;= A.length &lt;= 10000</code></span></li>
	<li><span><code>1 &lt;= B.length &lt;= 10000</code></span></li>
	<li><code><span>1 &lt;= A[i] &lt;= 100000</span></code></li>
	<li><code><span>1 &lt;= B[i] &lt;= 100000</span></code></li>
	<li>It is guaranteed that Alice and Bob have different total amounts of&nbsp;candy.</li>
	<li>It is guaranteed there exists an&nbsp;answer.</li>
</ul>
</div>
</div>
</div>
</div>


**Companies**:  
[Fidessa](https://leetcode.com/company/fidessa)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/fair-candy-swap/
// Author: github.com/punkfulw
// Time: O(A+B)
// Space: O(A)
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int a = accumulate(A.begin(), A.end(), 0), b = accumulate(B.begin(), B.end(), 0), dif = a - b; 
        unordered_map<int, int> mp;
        for (int i: A)
            mp[i]++;
 
        for (auto x: B){
            int tar = x + dif / 2;
            if (mp[tar])
                return {tar, x};
        }
        return {};
    }
};
```
