class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        fill(s.begin(), s.begin() + ones - 1, '1');
        fill(s.begin() + ones - 1, s.end(), '0');
        s.back() = '1';
        return s;
    }
};