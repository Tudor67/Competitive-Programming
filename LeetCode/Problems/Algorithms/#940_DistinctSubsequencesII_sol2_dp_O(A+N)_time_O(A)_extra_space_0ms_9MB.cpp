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
        int sum = 0;
        for(int i = 0; i < N; ++i){
            int temp = dp[s[i] - 'a'];
            dp[s[i] - 'a'] = (1 + sum) % MODULO;
            sum = (sum - temp + MODULO) % MODULO;
            sum = (sum + dp[s[i] - 'a']) % MODULO;
        }

        return sum;
    }
};