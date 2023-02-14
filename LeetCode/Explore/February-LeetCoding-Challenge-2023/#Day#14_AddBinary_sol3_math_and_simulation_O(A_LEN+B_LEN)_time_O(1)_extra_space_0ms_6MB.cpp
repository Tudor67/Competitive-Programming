class Solution {
public:
    string addBinary(string a, string b) {
        const int A_LEN = a.length();
        const int B_LEN = b.length();

        string res;

        int aIndex = A_LEN - 1;
        int bIndex = B_LEN - 1;
        int carry = 0;
        while(aIndex >= 0 || bIndex >= 0 || carry >= 1){
            int aDigit = (aIndex >= 0 ? a[aIndex] - '0' : 0);
            int bDigit = (bIndex >= 0 ? b[bIndex] - '0' : 0);
            int sum = aDigit + bDigit + carry;
            res.push_back(char('0' + (sum % 2)));
            carry = sum / 2;
            aIndex -= 1;
            bIndex -= 1;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};