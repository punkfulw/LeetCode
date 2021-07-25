// OJ: https://leetcode.com/problems/largest-number-after-mutating-substring/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string cha = num;
        for (int i = 0; i < num.size(); i++){
            int j = i;
            while (j < num.size() && num[j]-'0' <= change[num[j]-'0']){
                num[j] = change[num[j]-'0']+'0';
                j++;
            }
            if (i != j && cha != num)
                break;
            while (i+1 < num.size() && num[i] == num[i+1])
                i++;
        }
        return num;
    }
};
