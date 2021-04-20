// OJ: https://leetcode.com/problems/unique-morse-code-words/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set <string> sets {};
        
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for (int i = 0; i < words.size(); i++){
            string topush;
            for (char c: words[i]){
                topush += morse[c-'a'];
            }
            sets.insert(topush);
        }
        return sets.size();
    }
};
