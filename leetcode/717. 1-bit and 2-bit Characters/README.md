# [717. 1-bit and 2-bit Characters (Easy)](https://leetcode.com/problems/1-bit-and-2-bit-characters/)

<p>We have two special characters. The first character can be represented by one bit <code>0</code>. The second character can be represented by two bits (<code>10</code> or <code>11</code>).  </p>

<p>Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
bits = [1, 0, 0]
<b>Output:</b> True
<b>Explanation:</b> 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
bits = [1, 1, 1, 0]
<b>Output:</b> False
<b>Explanation:</b> 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>1 &lt;= len(bits) &lt;= 1000</code>.</li>
<li><code>bits[i]</code> is always <code>0</code> or <code>1</code>.</li>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Gray Code (Medium)](https://leetcode.com/problems/gray-code/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        for (; i < n; i++){
            if (bits[i] == 1){
                if (i == n - 2)
                    return false;
                i++;
            }
        }
        return true;
    }
};
```


## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = n - 2, cnt = 0;
        while (i >= 0 and bits[i] == 1){
            cnt++;
            i--;
        }
        
        return cnt % 2 == 0;
    }
};
```
