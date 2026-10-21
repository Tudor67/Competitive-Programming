class Solution {
public:
    int distinctSubseqII(string s) {
        const int N = s.length();
        const int A = 26;
        const int MODULO = 1'000'000'007;

        // At index i:
        // dp[c - 'a']: number of distinct non-empty subsequences of s[0 .. i]
        //              with last char c
        vector<int> dp(A);
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(char c = 'a'; c <= 'z'; ++c){
                sum = (sum + dp[c - 'a']) % MODULO;
            }
            dp[s[i] - 'a'] = (1 + sum) % MODULO;
        }

        int res = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            res = (res + dp[c - 'a']) % MODULO;
        }

        return res;
    }
};