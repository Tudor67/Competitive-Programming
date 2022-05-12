class Solution {
public:
    long long numberOfWays(string s) {
        const int N = s.length();
        const int TOTAL_ZEROS = count(s.begin(), s.end(), '0');
        const int TOTAL_ONES = count(s.begin(), s.end(), '1');
        
        long long res = 0;
        int prefZeros = (int)(s[0] == '0');
        int prefOnes = (int)(s[0] == '1');
        for(int i = 1; i + 1 < N; ++i){
            prefZeros += (int)(s[i] == '0');
            prefOnes += (int)(s[i] == '1');
            long long l = 0;
            long long r = 0;
            if(s[i] == '0'){
                l = prefOnes;
                r = TOTAL_ONES - prefOnes;
            }else{
                l = prefZeros;
                r = TOTAL_ZEROS - prefZeros;
            }
            res += (l * r);
        }
        
        return res;
    }
};