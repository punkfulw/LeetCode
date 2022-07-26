# [748. Shortest Completing Word (Easy)](https://leetcode.com/problems/shortest-completing-word/)

<p>
Find the minimum length word from a given dictionary <code>words</code>, which has all the letters from the string <code>licensePlate</code>.  Such a word is said to <i>complete</i> the given string <code>licensePlate</code>
</p><p>
Here, for letters we ignore case.  For example, <code>"P"</code> on the <code>licensePlate</code> still matches <code>"p"</code> on the word.
</p><p>
It is guaranteed an answer exists.  If there are multiple answers, return the one that occurs first in the array.
</p><p>
The license plate might have the same letter occurring multiple times.  For example, given a <code>licensePlate</code> of <code>"PP"</code>, the word <code>"pair"</code> does not complete the <code>licensePlate</code>, but the word <code>"supper"</code> does.
</p><p>

</p><p><b>Example 1:</b><br>
</p><pre><b>Input:</b> licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
<b>Output:</b> "steps"
<b>Explanation:</b> The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
<b>Output:</b> "pest"
<b>Explanation:</b> There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li><code>licensePlate</code> will be a string with length in range <code>[1, 7]</code>.</li>
<li><code>licensePlate</code> will contain digits, spaces, or letters (uppercase or lowercase).</li>
<li><code>words</code> will have a length in the range <code>[10, 1000]</code>.</li>
<li>Every <code>words[i]</code> will consist of lowercase letters, and have length in range <code>[1, 15]</code>.</li>
</ol>
<p></p>

**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-completing-word/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
        int cnt[26] = {}, len = INT_MAX;
        for (auto c: l)
            if (isalpha(c))
                cnt[tolower(c) - 'a']++;
        string ans = "";
        for (auto s: words){
            if (s.size() > len)
                continue;
            
            int cnt2[26] = {};
            for (auto c: s)
                cnt2[c - 'a']++;
            int same = 1;
            for (int i = 0; i < 26; i++)
                if (cnt2[i] < cnt[i])
                    same = 0;
            if (same && s.size() < len){
                len = s.size();
                ans = s;
            }
        }
        return ans;
    }
};
```
