class Solution {
public:
    bool hasSameDigits(string s) {
        const int N = s.length();

        vector<vector<int>> comb(N, vector<int>(N));
        for(int i = 0; i < N; ++i){
            comb[i][0] = 1;
            comb[i][i] = 1;
            for(int j = 1; j < i; ++j){
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 10;
            }
        }

        int lRem = 0;
        int rRem = 0;
        for(int i = 0; i < N - 1; ++i){
            lRem = (lRem + comb[N - 2][i] * (s[i] - '0')) % 10;
            rRem = (rRem + comb[N - 2][i] * (s[N - 1 - i] - '0')) % 10;
        }

        return (lRem == rRem);
    }
};