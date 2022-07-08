# [345. Reverse Vowels of a String (Easy)](https://leetcode.com/problems/reverse-vowels-of-a-string/)

<p>Write a function that takes a string as input and reverse only the vowels of a string.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"hello"</span>
<strong>Output: </strong><span id="example-output-1">"holle"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"leetcode"</span>
<strong>Output: </strong><span id="example-output-2">"leotcede"</span></pre>
</div>

<p><b>Note:</b><br>
The vowels does not include the letter "y".</p>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Reverse String (Easy)](https://leetcode.com/problems/reverse-string/)

## Solution 1. Two pointer

```cpp
// OJ: https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool vowel(char c){
        c = toupper(c);
        return c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
    }
    string reverseVowels(string s) {
        int i = 0, n = s.size(), j = n - 1;
        while (i < j){
            while (i < n && vowel(s[i]))
                i++;
            while (j >= 0 && vowel(s[j]))
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};
```
