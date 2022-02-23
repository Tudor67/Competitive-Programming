class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int num = 1;
        for(int i = 2; (int)s.length() < n; ++i){
            s.append(s[i] - '0', char('0' + num));
            num = 3 - num;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};