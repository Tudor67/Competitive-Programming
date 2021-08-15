class Solution {
public:
    string addStrings(string num1, string num2) {
        string numSum;
        int carry = 0;
        int i = (int)num1.size() - 1;
        int j = (int)num2.size() - 1;
        while(i >= 0 || j >= 0 || carry >= 1){
            int digit1 = (i >= 0 ? num1[i] - '0' : 0);
            int digit2 = (j >= 0 ? num2[j] - '0' : 0);
            int digitSum = digit1 + digit2 + carry;
            numSum += char('0' + digitSum % 10);
            carry = digitSum / 10;
            i -= 1;
            j -= 1;
        }
        reverse(numSum.begin(), numSum.end());
        return numSum;
    }
};