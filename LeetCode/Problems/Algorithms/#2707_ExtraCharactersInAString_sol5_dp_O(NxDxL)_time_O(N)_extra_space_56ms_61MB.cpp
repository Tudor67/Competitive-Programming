class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int N = s.length();
        const int D = dictionary.size();

        // dp[i]: min number of extra characters left over when we break up s[i .. N - 1] optimally
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            for(string& w: dictionary){
                if(s.compare(i, w.length(), w) == 0){
                    dp[i] = min(dp[i], dp[i + w.length()]);
                }
            }
        }

        return dp[0];
    }
};