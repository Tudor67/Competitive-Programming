class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();

        int res = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            size_t firstPos = s.find(c);
            size_t lastPos = s.rfind(c);
            if(firstPos == string::npos){
                continue;
            }

            unsigned int visMask = 0;
            for(int i = (int)firstPos + 1; i <= (int)lastPos - 1; ++i){
                visMask |= (1 << (s[i] - 'a'));
            }

            res += popcount(visMask);
        }

        return res;
    }
};