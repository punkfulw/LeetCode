# [1880. Check if Word Equals Summation of Two Words (Easy)](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/)

<p>The <b>letter value</b> of a letter is its position in the alphabet <b>starting from 0</b> (i.e. <code>'a' -> 0</code>, <code>'b' -> 1</code>, <code>'c' -> 2</code>, etc.).</p>

<p>The <b>numerical value</b> of some string of lowercase English letters <code>s</code> is the <b>concatenation</b> of the <b>letter values</b> of each letter in <code>s</code>, 
  which is then <b>converted</b> into an integer.</p>
  
 <ul>
  <li>For example, if <code>s = "acb"</code>, we concatenate each letter's letter value, resulting in <code>"021"</code>. After converting it, we get <code>21</code>.</li>
</ul>

<p>You are given three strings <code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code>, 
  each consisting of lowercase English letters <code>'a'</code> through <code>'j'</code> <b>inclusive</b>.</p>
  
<p>Return <code>true</code><em> if the <b>summation</b> of the <b>numerical values</b> of </em><code>firstWord</code> <em>and</em>
  <code>secondWord</code> <em>equals the <b>numerical value</b> of </em><code>targetWord</code>,<em> or</em> <code>false</code><em> otherwise.</em></p>
  

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> firstWord = "acb", secondWord = "cba", targetWord = "cdb"
<strong>Output:</strong> true
<strong>Explanation: </strong> 
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> firstWord = "aaa", secondWord = "a", targetWord = "aab"
<strong>Output:</strong> false
<strong>Explanation: </strong> 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
<strong>Output:</strong> true
<strong>Explanation: </strong> 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aaaa" -> "0000" -> 0.
We return true because 0 + 0 == 0.

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= firstWord.length, secondWord.length, targetWord.length &lt;= 8</code></li>
  <li><code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code> consist of lowercase English letters from <code>'a'</code> to <code>'j'</code> <b>inclusive</b>.</li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)
## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a = 0, b = 0, c = 0;
        int n = firstWord.size()-1;
        int m = secondWord.size()-1;
        int k = targetWord.size()-1;
        
        for (int i = n; i >= 0; i--)
            a = a + ((firstWord[i]-'a') * pow(10, n - i));
        for (int i = m; i >= 0; i--)
            b = b + ((secondWord[i]-'a') * pow(10, m - i));
        for (int i = k; i >= 0; i--)
            c = c + ((targetWord[i]-'a') * pow(10, k - i));
        return a+b == c;
    }
};
```
