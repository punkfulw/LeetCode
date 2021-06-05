// OJ: https://leetcode.com/problems/reformat-phone-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reformatNumber(string number) {
        string ans {};
        for (auto c:number)
            if (isdigit(c))
                ans.push_back(c);
        int n = ans.size();
        if (n <= 3)
            return ans;
        switch (n % 3){
            case 0: 
                for (int i = n-3; i > 0; i -= 3)
                    ans.insert(i, "-", 1);
                break;
            case 1:
                for (int i = n-4; i > 0; i -= 3)
                    ans.insert(i, "-", 1);
                ans.insert(ans.size() - 2, "-", 1);
                break;
            case 2:
                for (int i = n-2; i > 0; i -= 3)
                    ans.insert(i, "-", 1);
                break;
        }
        return ans;
    }
};
