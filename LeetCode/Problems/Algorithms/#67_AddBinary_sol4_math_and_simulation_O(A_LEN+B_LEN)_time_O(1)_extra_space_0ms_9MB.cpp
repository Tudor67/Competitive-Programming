class Solution {
public:
    string addBinary(string a, string b) {
        const int A_LEN = a.length();
        const int B_LEN = b.length();

        string sum;
        sum.reserve(max(A_LEN, B_LEN) + 1);

        int carry = 0;
        for(int i = A_LEN - 1, j = B_LEN - 1; i >= 0 || j >= 0; --i, --j){
            int aBit = (i >= 0 ? a[i] - '0' : 0);
            int bBit = (j >= 0 ? b[j] - '0' : 0);
            int bitSum = (aBit + bBit + carry);
            sum.push_back(bitSum % 2 + '0');
            carry = bitSum / 2;
        }

        if(carry > 0){
            sum.push_back('1');
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }
};