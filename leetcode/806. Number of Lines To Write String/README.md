# [806. Number of Lines To Write String (Easy)](https://leetcode.com/problems/number-of-lines-to-write-string/)

<p>You are given a string <code>s</code> of lowercase English letters and an array <code>widths</code> denoting <b>how many pixels wide</b> each lowercase English letter is.
  Specifically, <code>widths[0]</code> is the width of <code>'a'</code>, <code>widths[1]</code> is the width of <code>'b'</code>, and so on..</p>

<p>You are trying to write <code>s</code> across several lines, where <b>each line is no longer than</b> <code>100</code> <b>pixels</b>. 
  Starting at the beginning of <code>s</code>, write as many letters on the first line such that the total width does not exceed <code>100</code> pixels. 
  Then, from where you stopped in s, continue writing as many letters as you can on the second line. 
  Continue this process until you have written all of <code>s</code>.</p>

<p>Return <em>an array </em><code>result</code> <em>of length 2 where:</em></p>
<ul>
  <li><code>result[0]</code> <em>is the total number of lines.</em></li>
  <li><code>result[1]</code> <em>is the width of the last line in pixels.</em></li>
</ul>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz"
<strong>Output:</strong> [3,60]
<strong>Explanation:</strong> You can write s as follows:
abcdefghij  // 100 pixels wide
klmnopqrst  // 100 pixels wide
uvwxyz      // 60 pixels wide
There are a total of 3 lines, and the last line is 60 pixels wide.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "bbbcccdddaaa"
<strong>Output:</strong> [2,4]
<strong>Explanation: </strong>You can write s as follows:
bbbcccdddaa  // 98 pixels wide
a            // 4 pixels wide
There are a total of 2 lines, and the last line is 4 pixels wide.
</pre>

widths.length == 26
2 <= widths[i] <= 10
1 <= s.length <= 1000
s contains only lowercase English letters.


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>widths.length == 26</code></li>
  <li><code>2 &lt;= widths[i] &lt;= 10</code></li>
  <li><code>1 &lt;= s.length &lt;= 1000</code></li>
  <li><code>s</code> contains only lowercase English letters.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)



## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/number-of-lines-to-write-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 1, w = 0;
        
        for (auto c: s){
            int cur = widths[c-'a'];
            if (w + cur > 100){
                row++;
                w = cur;
            }
            else
                w += cur;
        }
        return {row, w};
    }
};
```

