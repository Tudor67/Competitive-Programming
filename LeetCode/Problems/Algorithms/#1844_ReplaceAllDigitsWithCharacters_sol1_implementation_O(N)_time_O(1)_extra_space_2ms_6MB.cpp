class Solution {
public:
    string replaceDigits(string s) {
        const int N = s.length();
        for(int i = 1; i < N; i += 2){
            s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};