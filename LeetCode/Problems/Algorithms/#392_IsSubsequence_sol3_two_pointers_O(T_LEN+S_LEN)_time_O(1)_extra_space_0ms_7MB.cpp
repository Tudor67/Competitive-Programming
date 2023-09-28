class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();

        int sIndex = 0;
        for(int tIndex = 0; tIndex < T_LEN && sIndex < S_LEN; ++tIndex){
            if(s[sIndex] == t[tIndex]){
                sIndex += 1;
            }
        }

        return (sIndex == S_LEN);
    }
};