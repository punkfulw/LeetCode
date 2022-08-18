# [819. Most Common Word (Easy)](https://leetcode.com/problems/most-common-word/)

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

**Example:**

**Input:**   
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = \["hit"\]
**Output:** "ball"  
**Explanation:**   
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.   
Note that words in the paragraph are not case sensitive, 
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

**Note:**

*   `1 <= paragraph.length <= 1000`.
*   `1 <= banned.length <= 100`.
*   `1 <= banned[i].length <= 10`.
*   The answer is unique, and written in lowercase (even if its occurrences in `paragraph` may have uppercase symbols, and even if it is a proper noun.)
*   `paragraph` only consists of letters, spaces, or the punctuation symbols `!?',;.`
*   There are no hyphens or hyphenated words.
*   Words only consist of letters, never apostrophes or other punctuation symbols.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/most-common-word/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(W)
class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        int n = para.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n;){
            string s = "";
            while (i < n && isalpha(para[i])) 
                s.push_back(tolower(para[i++]));
            while (i < n && !isalpha(para[i])) 
                i++;
            mp[s]++;
        }
        for (auto b: banned)
            mp[b] = 0;
        int mx = 0;
        string ans;
        for (auto p: mp)
            if (p.second > mx){
                mx = p.second;
                ans = p.first;
            }
        return ans;
    }
};
```
