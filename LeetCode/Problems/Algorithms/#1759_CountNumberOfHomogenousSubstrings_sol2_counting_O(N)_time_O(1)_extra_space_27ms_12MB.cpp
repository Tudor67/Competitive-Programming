class Solution {
public:
    int countHomogenous(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;

        int res = 0;
        int len = 0;
        for(int i = 0; i < N; ++i){
            if(i == 0 || s[i - 1] != s[i]){
                len = 1;
            }else{
                len += 1;
            }
            res = (res + len) % MODULO;
        }

        return res;
    }
};