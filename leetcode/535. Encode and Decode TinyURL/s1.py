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
