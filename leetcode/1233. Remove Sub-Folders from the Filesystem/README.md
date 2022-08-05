# [1233. Remove Sub-Folders from the Filesystem (Medium)](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/)

<p>Given a list of folders, remove all sub-folders in those folders and return in <strong>any order</strong> the folders after removing.</p>

<p>If a <code>folder[i]</code> is located within&nbsp;another <code>folder[j]</code>, it is called a&nbsp;sub-folder&nbsp;of it.</p>

<p>The format of a path is&nbsp;one or more concatenated strings of the form:&nbsp;<code>/</code>&nbsp;followed by one or more lowercase English letters. For example,&nbsp;<code>/leetcode</code>&nbsp;and&nbsp;<code>/leetcode/problems</code>&nbsp;are valid paths while an empty string and&nbsp;<code>/</code>&nbsp;are not.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
<strong>Output:</strong> ["/a","/c/d","/c/f"]
<strong>Explanation:</strong> Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> folder = ["/a","/a/b/c","/a/b/d"]
<strong>Output:</strong> ["/a"]
<strong>Explanation:</strong> Folders "/a/b/c" and "/a/b/d/" will be removed because they are subfolders of "/a".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> folder = ["/a/b/c","/a/b/ca","/a/b/d"]
<strong>Output:</strong> ["/a/b/c","/a/b/ca","/a/b/d"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= folder.length&nbsp;&lt;= 4 * 10^4</code></li>
	<li><code>2 &lt;= folder[i].length &lt;= 100</code></li>
	<li><code>folder[i]</code> contains only&nbsp;lowercase letters and '/'</li>
	<li><code>folder[i]</code> always starts with character '/'</li>
	<li>Each folder name is unique.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Author: github.com/punkfulw
// Time: O(NlogN * W)
// Space: O(NW)
class Solution {
public:
    vector<string> ans;
    void clean(string root, vector<string> &folder, int &j){
        int sz = root.size();
        while (j < folder.size() && folder[j].size() >= sz && folder[j].substr(0, sz) == root){
            if (folder[j].size() > sz && folder[j][sz] == '/')
                j++;
            else
                break;
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        for (int i = 0; i < folder.size(); ){
            ans.push_back(folder[i]);
            int j = i + 1;
            clean(folder[i], folder, j);
            i = j;
        }
        
        return ans;
    }
};
```
