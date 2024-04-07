class Solution {
public:
    int lengthOfLastWord(string s) {
        const int N = s.length();

        int lastWordLen = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            if(s[r] == ' '){
                l = r + 1;
            }else if(r == N - 1 || s[r + 1] == ' '){
                lastWordLen = r - l + 1;
            }
        }

        return lastWordLen;
    }
};