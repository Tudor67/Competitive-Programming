class Solution {
public:
    long long numberOfWays(string s) {
        const int N = s.length();
        
        // dp01[i]: number of "01" subsequences (not substrings) in s[0 .. i]
        // dp10[i]: number of "10" subsequences (not substrings) in s[0 .. i]
        vector<long long> dp01(N);
        vector<long long> dp10(N);
        
        int prefZeros = (int)(s[0] == '0');
        int prefOnes = (int)(s[0] == '1');
        for(int i = 1; i < N; ++i){
            dp01[i] = dp01[i - 1];
            dp10[i] = dp10[i - 1];
            if(s[i] == '0'){
                dp10[i] += prefOnes;
            }else{
                dp01[i] += prefZeros;
            }
            prefZeros += (int)(s[i] == '0');
            prefOnes += (int)(s[i] == '1');
        }
        
        long long res = 0;
        for(int i = 2; i < N; ++i){
            if(s[i] == '0'){
                res += dp01[i - 1];
            }else{
                res += dp10[i - 1];
            }
        }
        
        return res;
    }
};