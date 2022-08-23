// OJ: https://leetcode.com/problems/word-ladder/
// Author: github.com/punkfulw
// Time: O(N * W^2)
// Space: O(NW)
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& dic) {
        unordered_set<string> st(dic.begin(), dic.end());
        
        int seq = 1;
        queue<string> q;
        q.push(start);
        st.erase(start);
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                string s = q.front();
                q.pop();
                if (s == end)
                    return seq;
                for (auto &ch: s){
                    char tmp = ch;
                    for (char c = 'a'; c <= 'z'; c++){
                        ch = c;
                        if (st.find(s) != st.end()){
                            q.push(s);
                            st.erase(s);
                        }
                        ch = tmp;
                    }
                }
            }
            seq++;
        }    
        return 0;
    }
};
