class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1 = stoi(num1);
        int i1 = stoi(num1.substr(num1.find('+') + 1));
        int r2 = stoi(num2);
        int i2 = stoi(num2.substr(num2.find('+') + 1));
        int r3 = r1 * r2 - i1 * i2;
        int i3 = r1 * i2 + r2 * i1;
        return to_string(r3) + "+" + to_string(i3) + "i";
    }
};