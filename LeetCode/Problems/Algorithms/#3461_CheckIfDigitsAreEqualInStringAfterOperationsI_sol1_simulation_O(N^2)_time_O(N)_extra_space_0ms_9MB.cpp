class Solution {
public:
    bool hasSameDigits(string s) {
        const int N = s.length();

        for(int step = 1; step <= N - 2; ++step){
            for(int i = 0; i < N - step; ++i){
                s[i] = char('0' + (s[i] - '0' + s[i + 1] - '0') % 10);
            }
        }

        return (s[0] == s[1]);
    }
};