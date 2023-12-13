class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        const int N = s.length();
        
        int res = 1;
        
        int consPairs = 0;
        int l = 0;
        for(int r = 1; r < N; ++r){
            consPairs += (int)(s[r - 1] == s[r]);
            while(consPairs >= 2){
                consPairs -= (int)(s[l] == s[l + 1]);
                l += 1;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};