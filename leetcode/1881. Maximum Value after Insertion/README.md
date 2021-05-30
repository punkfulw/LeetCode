# [1881. Maximum Value after Insertion (Medium)](https://leetcode.com/problems/maximum-value-after-insertion/)

<p>You are given a very large integer <code>n</code>, represented as a string, and an integer digit <code>x</code>. 
  The digits in <code>n</code> and the digit <code>x</code> are in the <b>inclusive</b> range <code>[1, 9]</code>, and <code>n</code> may represent a <b>negative</b> number.</p>

<p>You want to <b>maximize</b> <code>n</code><b>'s numerical value</b> by inserting <code>x</code> anywhere in the decimal representation of <code>n</code>.
  You <b>cannot</b> insert <code>x</code> to the left of the negative sign.</p>

<ul>
  <li>For example, if <code>n = 73</code> and <code>x = 6</code>, it would be best to insert it between <code>7</code> and <code>3</code>, making <code>n = 763</code>.</li>
  <li>If <code>n = -55</code> and <code>x = 2</code>, it would be best to insert it before the first <code>5</code>, making <code>n = -255</code>.</li>
</ul>

<p>Return <em>a string representing the <b>maximum</b> value of n after the insertion.</em></p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> n = "99", x = 9
<strong>Output:</strong> "999"
<strong>Explanation: </strong> The result is the same regardless of where you insert 9.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = "-13", x = 2
<strong>Output:</strong> "-123"
<strong>Explanation: </strong> You can make n one of {-213, -123, -132}, and the largest of those three is -123.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n.length &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= x &lt;= 9</code></li>
  <li>The digits in <code>n</code> are in the range <code>[1, 9]</code>.</li>
  <li><code>n</code> is a valid representation of an integer.</li>
  <li>In the case of a negative <code>n</code>, it will begin with <code>'-'</code>.</li>
</ul>



**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/maximum-value-after-insertion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maxValue(string n, int x) {
        int m = n.size();
        char a = x+'0';
        if (n[0] == '-'){
            for (int i = 1; i < m; i++){
                if (n[i]-'0' > x){
                    n.insert(i, 1, a);
                    break;
                }
            }
            if (n.size() == m)
                n.append(1, a);
        }
        else{
            for (int i = 0; i < m; i++){
                if (n[i]-'0' < x){
                    n.insert(i, 1, a);
                    break;
                    cout << n;
                }
            }
            if (n.size() == m)
                n.append(1, a);
        }
        return n;
    }
};
```
