class Solution {
public:
    int countHomogenous(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;

        int res = 0;
        int l = 0;
        while(l < N){
            int r = l + 1;
            while(r < N && s[l] == s[r]){
                r += 1;
            }
            
            long long len = r - l;
            res = (res + len * (len + 1) / 2) % MODULO;

            l = r;
        }

        return res;
    }
};