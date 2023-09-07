class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int N = s.length();

        // dp[i]: min cost for s[i ..]
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            for(const string& WORD: dictionary){
                const int L = WORD.length();
                if(s.compare(i, L, WORD) == 0){
                    dp[i] = min(dp[i], dp[i + L]);
                }
            }
        }

        return dp[0];
    }
};