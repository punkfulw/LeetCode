# [100. Same Tree (Easy)](https://leetcode.com/problems/same-tree/)

<p>TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
  Design a class to encode a URL and decode a tiny URL.</p>

<p>There is no restriction on how your encode/decode algorithm should work. 
  You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
  <li>Solution() Initializes the object of the system.</li>
  <li>String encode(String longUrl) Returns a tiny URL for the given longUrl.</li>
  <li>String decode(String shortUrl) Returns the original long URL for the given shortUrl. 
    It is guaranteed that the given shortUrl was encoded by the same object.</li>
</ul>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> url = "https://leetcode.com/problems/design-tinyurl"
<strong>Output:</strong> "https://leetcode.com/problems/design-tinyurl"
<strong>Explanation:</strong>
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
  <li><code>1 &lt;= url.length &lt;= 10<sup>4</sup></code></li>
  <li>url is guranteed to be a valid URL.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Hash-Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/same-tree/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/encode-and-decode-tinyurl/discuss/100268/Two-solutions-and-thoughts
// Time: O(1)
// Space: O(d) different longUrl 
class Solution {
private:
    unordered_map<string, string> url2code, code2url;
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
public:
    string encode(string longUrl) {
        while (url2code.find(longUrl) == url2code.end())
        {
            random_shuffle(charset.begin(), charset.end());
            string tail = charset.substr(0, 6);
            if (code2url.find(tail) == code2url.end())
            {
                string shortUrl = "http://tinyurl.com/" + tail;
                url2code[longUrl] = shortUrl;
                code2url[tail] = longUrl;
            }
        }
        return url2code[longUrl];
    }
    string decode(string shortUrl) {
        int pos = shortUrl.find_last_of('/');
        return code2url[shortUrl.substr(pos + 1)];
    }
};
```

## Solution 1. -py

```python3
# OJ: https://leetcode.com/problems/same-tree/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/encode-and-decode-tinyurl/discuss/100268/Two-solutions-and-thoughts
# Time: O(1)
# Space: O(d) different longUrl 
class Codec:
    def __init__(self):
        self.alphabet = string.ascii_letters + '0123456789'
        self.url2code = {}
        self.code2url = {}
    
    def encode(self, longUrl: str) -> str:
        while longUrl not in self.url2code:
            tail = ''.join(random.choice(self.alphabet) for _ in range(6))
            if tail not in self.code2url:
                self.url2code[longUrl] = "http://tinyurl.com/" + tail
                self.code2url[tail] = longUrl
        return self.url2code[longUrl]

    def decode(self, shortUrl: str) -> str:
        return self.code2url[shortUrl[-6:]]       
```
