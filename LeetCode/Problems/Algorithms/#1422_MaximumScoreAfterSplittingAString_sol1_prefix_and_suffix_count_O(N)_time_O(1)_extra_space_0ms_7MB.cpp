class Solution {
public:
    int maxScore(string s) {
        const int N = s.length();

        int res = 0;
        int prefZeros = 0;
        int suffOnes = count(s.begin(), s.end(), '1');
        for(int i = 0; i + 1 < N; ++i){
            prefZeros += (int)(s[i] == '0');
            suffOnes -= (int)(s[i] == '1');
            res = max(res, prefZeros + suffOnes);
        }

        return res;
    }
};