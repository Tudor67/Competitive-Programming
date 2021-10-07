class Solution {
public:
    string longestNiceSubstring(string s) {
        const int N = s.length();
        int startPos = 0;
        int maxLen = 0;
        for(int i = 0; i + maxLen < N; ++i){
            int lowMask = 0;
            int upMask = 0;
            for(int j = i; j < N; ++j){
                if(islower(s[j])){
                    lowMask |= (1 << (s[j] - 'a'));
                }else{
                    upMask |= (1 << (s[j] - 'A'));
                }
                if(lowMask == upMask){
                    int len = j - i + 1;
                    if(len > maxLen){
                        startPos = i;
                        maxLen = len;
                    }
                }
            }
        }
        return s.substr(startPos, maxLen);
    }
};