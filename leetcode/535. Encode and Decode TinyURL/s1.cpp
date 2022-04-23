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
