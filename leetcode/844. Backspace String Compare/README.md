# [844. Backspace String Compare (Easy)](https://leetcode.com/problems/backspace-string-compare/)

<p>Given two&nbsp;strings&nbsp;<code>S</code>&nbsp;and <code>T</code>,&nbsp;return if they are equal when both are typed into empty text editors. <code>#</code> means a backspace character.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-1-1">"ab#c"</span>, T = <span id="example-input-1-2">"ad#c"</span>
<strong>Output: </strong><span id="example-output-1">true
</span><span><strong>Explanation</strong>: Both S and T become "ac".</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-2-1">"ab##"</span>, T = <span id="example-input-2-2">"c#d#"</span>
<strong>Output: </strong><span id="example-output-2">true
</span><span><strong>Explanation</strong>: Both S and T become "".</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-3-1">"a##c"</span>, T = <span id="example-input-3-2">"#a#c"</span>
<strong>Output: </strong><span id="example-output-3">true
</span><span><strong>Explanation</strong>: Both S and T become "c".</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-4-1">"a#c"</span>, T = <span id="example-input-4-2">"b"</span>
<strong>Output: </strong><span id="example-output-4">false
</span><span><strong>Explanation</strong>: S becomes "c" while T becomes "b".</span>
</pre>

<p><span><strong>Note</strong>:</span></p>

<ol>
	<li><code><span>1 &lt;= S.length &lt;= 200</span></code></li>
	<li><code><span>1 &lt;= T.length &lt;= 200</span></code></li>
	<li><span><code>S</code>&nbsp;and <code>T</code> only contain&nbsp;lowercase letters and <code>'#'</code> characters.</span></li>
</ol>

<p><strong>Follow up:</strong></p>

<ul>
	<li>Can you solve it in <code>O(N)</code> time and <code>O(1)</code> space?</li>
</ul>
</div>
</div>
</div>
</div>


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int ix = 0, jx = 0;
        while (true)
        {
            while (i >= 0 && (ix || s[i] == '#'))
            {
                s[i] == '#'? ix++ : ix--;
                i--;
            }
            
            while (j >= 0 && (jx || t[j] == '#'))
            {
                t[j] == '#'? jx++ : jx--;
                j--;
            }
            
            if (i < 0 || j < 0 || s[i] != t[j])
                break;
            i--, j--;
        }
        return i == -1 && j == -1;
    }
};
```


## Solution 1. -py


```python3
# OJ: https://leetcode.com/problems/backspace-string-compare/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j = len(s) - 1, len(t) - 1 
        ix, jx = 0, 0
        
        while True:
            while i >= 0 and (ix or s[i] == '#'):
                if s[i] == '#':
                    ix += 1
                else: 
                    ix -= 1
                i -= 1
            while j >= 0 and (jx or t[j] == '#'):
                if t[j] == '#':
                    jx += 1
                else: 
                    jx -= 1
                j -= 1
            if (i < 0 or j < 0 or s[i] != t[j]):
                break;
            i -= 1
            j -= 1
        return i == -1 and j == -1
```
