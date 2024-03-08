class Solution {
public:
    int minimumLength(string s) {
        const int N = s.length();

        int l = 0;
        int r = N - 1;
        while(l < r && s[l] == s[r]){
            char targetChar = s[l];
            while(l <= r && s[l] == targetChar){
                l += 1;
            }
            while(l <= r && s[r] == targetChar){
                r -= 1;
            }
        }

        return r - l + 1;
    }
};