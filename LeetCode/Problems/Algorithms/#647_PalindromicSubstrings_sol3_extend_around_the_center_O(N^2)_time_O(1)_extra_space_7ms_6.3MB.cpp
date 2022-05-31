class Solution {
public:
    int countSubstrings(string s) {
        const int N = s.length();
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int delta: {0, 1}){
                int l = i;
                int r = i + delta;
                while(0 <= l && r < N && s[l] == s[r]){
                    l -= 1;
                    r += 1;
                    res += 1;
                }
            }
        }
        
        return res;
    }
};