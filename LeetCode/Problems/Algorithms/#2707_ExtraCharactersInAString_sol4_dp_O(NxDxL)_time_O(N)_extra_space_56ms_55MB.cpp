class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int N = s.length();

        // dp[i]: min number of extra characters left over when we break s[i .. N - 1] optimally
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            for(const string& WORD: dictionary){
                const int L = WORD.length();
                if(i + L - 1 < N){
                    if(equal(WORD.begin(), WORD.end(), s.begin() + i)){
                        dp[i] = min(dp[i], dp[i + L]);
                    }
                }
            }
        }
        
        return dp[0];
    }
};