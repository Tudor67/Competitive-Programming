class Solution {
public:
    int numSub(string s) {
        const int N = s.length();
        const int MODULO = 1'000'000'007;

        int res = 0;
        int consecutiveOnes = 0;
        for(char c: s){
            if(c == '1'){
                consecutiveOnes += 1;
                res += consecutiveOnes;
                res %= MODULO;
            }else{
                consecutiveOnes = 0;
            }
        }

        return res;
    }
};