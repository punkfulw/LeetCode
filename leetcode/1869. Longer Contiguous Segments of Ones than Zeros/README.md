# [1869. Longer Contiguous Segments of Ones than Zeros (Easy)](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

<p>Given a binary string <code>s</code>, return <code>true</code> <em>if the <b>longest</b> contiguous segment of </em><code>1</code><em>s is <b>strictly longer</b> than the 
  <b>longest</b> contiguous segment of </em><code>0</code><em>s in </em><code>s</code>. Return <code>false</code> <em>otherwise.</em></p>

<ul>
  <li>For example, in <code>s = "110100010"</code> the longest contiguous segment of <code>1</code>s has length <code>2</code>, and the longest contiguous segment of <code>0</code>s has length <code>3</code>.</li>
</ul>

<p>Note that if there are no <code>0</code>s, then the longest contiguous segment of <code>0</code>s is considered to have length <code>0</code>. The same applies if there are no <code>1</code>s.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1101"
<strong>Output:</strong> true
<strong>Explanation: </strong> 
The longest contiguous segment of 1s has length 2: "1101"
The longest contiguous segment of 0s has length 1: "1101"
The segment of 1s is longer, so return true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "111000"
<strong>Output:</strong> false
<strong>Explanation: </strong> 
The longest contiguous segment of 1s has length 3: "111000"
The longest contiguous segment of 0s has length 3: "111000"
The segment of 1s is not longer, so return false.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "110100010"
<strong>Output:</strong> false
<strong>Explanation: </strong> 
The longest contiguous segment of 1s has length 2: "110100010"
The longest contiguous segment of 0s has length 3: "110100010"
The segment of 1s is not longer, so return false.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 100</code></li>
  <li><code>s[i]</code> is either <code>0'</code> or <code>'1'</code>.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointer](https://leetcode.com/tag/two-pointers/)


## Solution 1.
```cpp
// OJ: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0;
        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                cnt0 = 0;
                cnt1++;
                one = max(one, cnt1);
            }
            else{
                cnt1 = 0;
                cnt0++;
                zero = max(zero, cnt0);
            }
        }
        return one > zero;        
    }
};
```
