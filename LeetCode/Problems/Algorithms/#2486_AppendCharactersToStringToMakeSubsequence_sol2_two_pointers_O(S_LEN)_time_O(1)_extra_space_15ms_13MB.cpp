class Solution {
public:
    int appendCharacters(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();

        int tIndex = 0;
        for(int i = 0; i < S_LEN; ++i){
            if(tIndex < T_LEN && s[i] == t[tIndex]){
                tIndex += 1;
            }
        }

        return T_LEN - tIndex;
    }
};