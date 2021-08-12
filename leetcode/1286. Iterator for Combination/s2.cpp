// OJ: https://leetcode.com/problems/iterator-for-combination/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/iterator-for-combination/discuss/789164/C%2B%2B-Using-Bit-manipulation-or-Detail-Explain
// Time:
//      CombinationIterator: O(len!)
//      next: O(1)
//      hasNext: O(1)
// Space: O(len!)
class CombinationIterator {
    set<string> helper (string s, int len){
        int mask = 1 << s.size();
        set<string> st;
        
        for (int no = 1; no < mask; no++){
            int num = no, i = 1;
            string cur = "";
            while (num){
                if (num & 1)
                    cur += s[i];
                i++;
                num >>= 1;
            }
            if (cur.size() == len)
                st.insert(cur);
        }
        return st;
    }
public:
    set<string> st;
    set<string>:: iterator cur; 
    CombinationIterator(string characters, int combinationLength) {
        this->st = helper(characters, combinationLength);
        this->cur = st.begin();
    }

    string next() {
        return *cur++;
    }
    
    bool hasNext() {
        return cur != st.end();
    }
};
