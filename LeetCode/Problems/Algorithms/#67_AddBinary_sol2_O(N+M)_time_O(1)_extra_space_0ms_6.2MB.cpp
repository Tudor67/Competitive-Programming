class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        
        int carry = 0;
        int i = (int)a.length() - 1;
        int j = (int)b.length() - 1;
        while(i >= 0 || j >= 0 || carry > 0){
            int aDigit = (i >= 0 ? a[i] - '0' : 0);
            int bDigit = (j >= 0 ? b[j] - '0' : 0);
            int digitSum = aDigit + bDigit + carry;
            sum.push_back((digitSum % 2) + '0');
            carry = digitSum / 2;
            i -= 1;
            j -= 1;
        }
        
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};