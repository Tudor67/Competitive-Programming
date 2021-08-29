class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1, i1;
        int r2, i2;
        sscanf(num1.c_str(), "%d+%di", &r1, &i1);
        sscanf(num2.c_str(), "%d+%di", &r2, &i2);
        int r3 = r1 * r2 - i1 * i2;
        int i3 = r1 * i2 + r2 * i1;
        return to_string(r3) + "+" + to_string(i3) + "i";
    }
};