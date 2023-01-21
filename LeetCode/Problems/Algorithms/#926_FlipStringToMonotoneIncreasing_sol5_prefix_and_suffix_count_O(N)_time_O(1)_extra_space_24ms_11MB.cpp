class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int N = s.length();

        int prefOnes = 0;
        int suffZeros = count(s.begin(), s.end(), '0');
        int res = min(suffZeros, N - suffZeros);
        for(int i = 0; i < N; ++i){
            int flips = prefOnes + suffZeros;
            res = min(res, flips);
            prefOnes += (int)(s[i] == '1');
            suffZeros -= (int)(s[i] == '0');
        }

        return res;
    }
};