// OJ: https://leetcode.com/problems/maximum-value-after-insertion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maxValue(string n, int x) {
        int m = n.size();
        char a = x+'0';
        if (n[0] == '-'){
            for (int i = 1; i < m; i++){
                if (n[i]-'0' > x){
                    n.insert(i, 1, a);
                    break;
                }
            }
            if (n.size() == m)
                n.append(1, a);
        }
        else{
            for (int i = 0; i < m; i++){
                if (n[i]-'0' < x){
                    n.insert(i, 1, a);
                    break;
                    cout << n;
                }
            }
            if (n.size() == m)
                n.append(1, a);
        }
        return n;
    }
};
