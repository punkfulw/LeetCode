// OJ: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans {};
        
        for (int i = 0; i < word.size(); i++){
            if (word[i] == 'a'){
                int j = i;
                int maxs = 0;
                char current = 'a';
                while (j < word.size() && word[j] >= current){ 
                    current = word[j];
                    maxs++;
                    j++;
                }
                
                string s = word.substr(i, j-i);
                if (word[j-1] == 'u' && s.find('e') != string::npos && s.find('i') != string::npos && s.find('o') != string::npos)
                    ans = max(maxs, ans);
                i = j-1;
             }
            
        }
        return ans;  
    }
};
