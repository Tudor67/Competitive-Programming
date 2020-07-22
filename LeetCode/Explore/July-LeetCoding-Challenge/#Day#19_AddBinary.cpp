class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for(int i = 0; i < max(a.size(), b.size()); ++i){
            int digit1 = (i < a.length() ? a[i] - '0' : 0);
            int digit2 = (i < b.length() ? b[i] - '0' : 0);
            int digit_sum = carry + digit1 + digit2;
            sum.push_back(char(digit_sum % 2 + '0'));
            carry = digit_sum / 2;
        }
        if(carry > 0){
            sum.push_back(char(carry + '0'));
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};