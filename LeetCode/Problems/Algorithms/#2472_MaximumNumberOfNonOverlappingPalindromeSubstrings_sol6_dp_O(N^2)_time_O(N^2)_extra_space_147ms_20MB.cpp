class Solution {
public:
    int maxPalindromes(string s, int k) {
        const int N = s.length();

        vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if((s[i] == s[j]) && (len <= 2 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = true;
                }
            }
        }

        // dp[i]: max number of non-overlapping palindromes of length at least k
        //        in the suffix s[i .. N - 1]
        vector<int> dp(N + 1);
        for(int i = N - k; i >= 0; --i){
            dp[i] = dp[i + 1];
            for(int j = i + k - 1; j < N; ++j){
                if(isPalindrome[i][j]){
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                    break;
                }
            }
        }

        return dp[0];
    }
};