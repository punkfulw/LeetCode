# [1629. Slowest Key (Easy)](https://leetcode.com/problems/slowest-key/)

<p>A newly designed keypad was tested, where a tester pressed a sequence of n keys, one at a time.</p>

<p>You are given a string keysPressed of length n, where keysPressed[i] was the ith key pressed in the testing sequence, and a sorted list releaseTimes, where releaseTimes[i] was the time the ith key was released.
  Both arrays are 0-indexed. The 0th key was pressed at the time 0, and every subsequent key was pressed at the exact time the previous key was released.</p>

<p>The tester wants to know the key of the keypress that had the longest duration. 
  The ith keypress had a duration of releaseTimes[i] - releaseTimes[i - 1], and the 0th keypress had a duration of releaseTimes[0].</p>

<p>Note that the same key could have been pressed multiple times during the test, and these multiple presses of the same key may not have had the same duration.</p>

<p>Return the key of the keypress that had the longest duration. If there are multiple such keypresses, return the lexicographically largest key of the keypresses.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> releaseTimes = [9,29,49,50], keysPressed = "cbcd"
<strong>Output:</strong> c"
<strong>Explanation:</strong> The keypresses were as follows:
Keypress for 'c' had a duration of 9 (pressed at time 0 and released at time 9).
Keypress for 'b' had a duration of 29 - 9 = 20 (pressed at time 9 right after the release of the previous character and released at time 29).
Keypress for 'c' had a duration of 49 - 29 = 20 (pressed at time 29 right after the release of the previous character and released at time 49).
Keypress for 'd' had a duration of 50 - 49 = 1 (pressed at time 49 right after the release of the previous character and released at time 50).
The longest of these was the keypress for 'b' and the second keypress for 'c', both with duration 20.
'c' is lexicographically larger than 'b', so the answer is 'c'.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
<strong>Output:</strong> "a"
<strong>Explanation:</strong> The keypresses were as follows:
Keypress for 's' had a duration of 12.
Keypress for 'p' had a duration of 23 - 12 = 11.
Keypress for 'u' had a duration of 36 - 23 = 13.
Keypress for 'd' had a duration of 46 - 36 = 10.
Keypress for 'a' had a duration of 62 - 46 = 16.
The longest of these was the keypress for 'a' with duration 16.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>releaseTimes.length == n</code></li>
  <li><code>keysPressed.length == n</code></li>
  <li><code>2 &lt;= n &lt;= 1000</code></li>
  <li><code>1 &lt;= releaseTimes[i] &lt;= 10<sup>9</sup></code></li>
  <li><code>releaseTimes[i] &lt; releaseTimes[i+1]</code></li>
  <li>keysPressed contains only lowercase English letters.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/slowest-key/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    char slowestKey(vector<int>& r, string keys) {
        char ans = keys[0];
        int dur = r[0];
        
        for (int i = 1; i < r.size(); i++){
            if (r[i] - r[i-1] >= dur){
                if (r[i] - r[i-1] == dur)
                    ans = max(ans, keys[i]);
                else
                    ans = keys[i];
                dur = r[i] - r[i-1];
            }
        }
        return ans;
    }
};
```

```python3
# OJ: https://leetcode.com/problems/slowest-key/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def slowestKey(self, re: List[int], keys: str) -> str:
        ans, dur = keys[0], re[0]
        
        for i in range(1, len(re)):
            time = re[i] - re[i-1]
            if time > dur or (time == dur and keys[i] > ans):
                ans = keys[i]
                dur = re[i] - re[i-1]
        return ans
```
