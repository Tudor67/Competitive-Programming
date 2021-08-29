class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1, i1;
        int r2, i2;
        char plusSign;
        istringstream(num1) >> r1 >> plusSign >> i1;
        istringstream(num2) >> r2 >> plusSign >> i2;
        int r3 = r1 * r2 - i1 * i2;
        int i3 = r1 * i2 + r2 * i1;
        return to_string(r3) + "+" + to_string(i3) + "i";
    }
};