// OJ: https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> s;
        unordered_map<string, int> mp;
        stringstream ss1(s1), ss2(s2);
        string word;
        
        while (ss1 >> word)
            mp[word]++;
        while (ss2 >> word)
             mp[word]++;
        for (auto it: mp){
            if (it.second == 1)
                s.push_back(it.first);
        }

        return s;
    }
};
