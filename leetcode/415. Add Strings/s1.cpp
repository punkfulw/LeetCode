class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans {};
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry {};
        
        while (i >= 0 || j >= 0 || carry){
            int sum {};
            if (i >= 0){
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0){
                sum += num2[j] - '0';
                j--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum + '0');
         }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
