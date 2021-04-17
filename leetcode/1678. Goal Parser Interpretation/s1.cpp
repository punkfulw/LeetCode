// OJ: https://leetcode.com/problems/goal-parser-interpretation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); i++){
            if (command[i] == 'G'){
                ans.push_back('G');
            }
            else if (command[i] == '('){
                if (command[i+1] == ')')
                    ans.push_back('o');
                else{
                    ans.push_back('a');
                    ans.push_back('l');
                    i += 2;
                }                
            }
        }
        return ans;
    }
};
