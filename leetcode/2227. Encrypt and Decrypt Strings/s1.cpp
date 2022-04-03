// OJ: https://leetcode.com/problems/encrypt-and-decrypt-strings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/encrypt-and-decrypt-strings/discuss/1909025/JavaC%2B%2BPython-Two-Hashmaps-with-Explanation
// Time:
//      Encrypter: O(N) 
//      encrypt: O(word1) 
//      decrypt: O(1)
// Space: O(N)
class Encrypter {
public:
    map<string, int> de;
    map<char, string> en;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dic) {
        for (int i = 0; i < keys.size(); i++)
            en[keys[i]] = values[i];
        for (int i = 0; i < dic.size(); i++)
            de[encrypt(dic[i])]++;
    }
    
    string encrypt(string word1) {
        string newS = "";
        for (auto c: word1)
            newS += en[c];
        return newS;
    }

    
    int decrypt(string word2) {
        return de[word2];
    }
};
