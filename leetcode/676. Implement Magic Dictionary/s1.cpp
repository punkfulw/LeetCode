// OJ: https://leetcode.com/problems/implement-magic-dictionary/
// Author: github.com/punkfulw
// Time:
//   buildDict: O(N) 
//   search: O(N^W) Where W is the length of words
// Space: O(N)
class MagicDictionary {
public:
    MagicDictionary() {
    }
    unordered_map<int, vector<string>> mp;
    
    void buildDict(vector<string> dictionary) {
        for (auto &s: dictionary){
            int len = s.size();
            mp[len].push_back(s);
        }
    }
    
    bool search(string searchWord) {
        int len = searchWord.size();
        for (auto &s: mp[len]){
            int dif = 0;
            for (int i = 0; i < len; i++)
                if (s[i] != searchWord[i])
                    dif++;
            if (dif == 1)
                return true;
        }
        return false;
    }
};
