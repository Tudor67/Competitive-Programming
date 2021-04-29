class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        string s;
        while(n != 0){
            s += char('0' + n % 3);
            n /= 3;
        }
        reverse(s.begin(), s.end());
        return (s[0] == '1' && 1 + count(s.begin() + 1, s.end(), '0') == (int)s.length());
    }
};