class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int N = s.length();
        int ones = count(s.begin(), s.end(), '1');
        return string(ones - 1, '1') + string(N - ones, '0') + string(1, '1');
    }
};