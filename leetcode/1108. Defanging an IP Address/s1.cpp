// OJ: https://leetcode.com/problems/defanging-an-ip-address/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string defangIPaddr(string address) {
        int ans_size = address.size() + 6;
        string ans (ans_size, ' ');
        int i {};
        for (int num = 0; num < ans_size; num++){
            if (address.at(i) != '.'){
                ans.at(num) = address.at(i);
                i++;
            }else{
                ans.at(num++) = '[';
                ans.at(num++) = '.';
                ans.at(num) = ']';
                i++;
            }
        }
        return ans;
    }
};
