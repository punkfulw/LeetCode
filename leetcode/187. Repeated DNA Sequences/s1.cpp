// OJ: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string S) {
        vector<string> ans;
        if (S.size() < 10)
            return ans;
        string s = S.substr(0, 10);
        unordered_set<string> st, added;
        st.insert(s);
        for (int i = 10; i < S.size(); i++){
            s = s.substr(1, 9) + S[i];
            if (st.find(s) != st.end() && added.find(s) == added.end()){
                ans.push_back(s);
                added.insert(s);
            }   
            st.insert(s);
        }
        return ans;
    }
};
